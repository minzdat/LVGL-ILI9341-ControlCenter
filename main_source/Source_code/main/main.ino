#include <ArduinoJson.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui.h"
#include "WiFi.h"
#include "AsyncUDP.h"

const char *ssid = "The Binh";
const char *password = "03030303";

#define TFT_HOR_RES   320
#define TFT_VER_RES   240

TFT_eSPI tft = TFT_eSPI();
AsyncUDP udp;

void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
{
  int32_t x, y;
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1));
  for (y = area->y1; y <= area->y2; y++) {
    for (x = area->x1; x <= area->x2; x++) {
      tft.pushColor(color_p->full);
      color_p++;
    }
  }
  tft.endWrite();
  lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
  uint16_t x = 0, y = 0; 
  bool pressed = tft.getTouch(&x, &y);

  if (pressed) {
    tft.fillCircle(x, y, 2, TFT_BLACK);
  }

  if (!pressed) {
    data->state = LV_INDEV_STATE_RELEASED;
  } else {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = x;
    data->point.y = y;
  }
}

void send_data_UDP()
{
  // Get the value of the slider
  int sliderValue = lv_slider_get_value(ui_Slider1);

  // Get the value of the arc (if applicable)
  // Example: Calculate the percentage of the arc
  int arcValue = lv_arc_get_value(ui_Arc2);

  // Create a JSON document
  StaticJsonDocument<128> doc;

  // Add slider value and arc value to the JSON document
  doc["sliderValue"] = sliderValue;
  doc["arcValue"] = arcValue;

  // Serialize JSON document to a string
  char jsonStr[128];
  serializeJson(doc, jsonStr);

  // Send the JSON string via UDP broadcast
  udp.broadcast(jsonStr);
}
 

void get_data_UDP(AsyncUDPPacket packet)
{
  DynamicJsonDocument doc(128); 
  DeserializationError error = deserializeJson(doc, packet.data()); 

  if (!error) {
    float temperature = doc["temperature"]; 
    float humidity = doc["humidity"]; 

    char tempStr[16];
    char humStr[16];
    dtostrf(temperature, 5, 1, tempStr); 
    dtostrf(humidity, 5, 1, humStr);

    lv_label_set_text(ui_Label2, tempStr);
    lv_label_set_text(ui_Label3, humStr);
  } else {
    Serial.println("Failed to parse JSON");
  }
}

void setupUDP()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("WiFi Failed");
    while (1)
    {
      delay(1000);
    }
  }

  if (udp.listen(1234))
  {
    Serial.print("UDP Listening on IP: ");
    Serial.println(WiFi.localIP());
    udp.onPacket([](AsyncUDPPacket packet) {
      Serial.print("UDP Packet Type: ");
      Serial.print(packet.isBroadcast() ? "Broadcast" : packet.isMulticast() ? "Multicast" : "Unicast");
      Serial.print(", From: ");
      Serial.print(packet.remoteIP());
      Serial.print(":");
      Serial.print(packet.remotePort());
      Serial.print(", To: ");
      Serial.print(packet.localIP());
      Serial.print(":");
      Serial.print(packet.localPort());
      Serial.print(", Length: ");
      Serial.print(packet.length());
      Serial.print(", Data: ");
      Serial.write(packet.data(), packet.length());
      
      get_data_UDP(packet);

      Serial.println();
      packet.printf("Got %u bytes of data", packet.length());
    });
  }
}

void setup()
{
  Serial.begin(115200);

  setupUDP();

  tft.init();
  tft.setRotation(3); 
  uint16_t calData[5] = { 457, 3425, 351, 3285, 1 };
  tft.setTouch(calData);

  lv_init();

  static lv_disp_draw_buf_t draw_buf;
  static lv_color_t buf[TFT_HOR_RES * 10];
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_HOR_RES * 10);

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = TFT_HOR_RES;
  disp_drv.ver_res = TFT_VER_RES;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);
  
  ui_init();

  Serial.println("Setup done");
}

void loop()
{
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);

  send_data_UDP();
}