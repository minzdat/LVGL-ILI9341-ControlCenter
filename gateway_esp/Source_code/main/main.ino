#include <ArduinoJson.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui.h"
#include "WiFi.h"
#include "AsyncUDP.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

const char *ssid = "Minz";
const char *password = "12345678";

// Thiết lập NTP client
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7 * 3600, 60000);

#define TFT_HOR_RES   320
#define TFT_VER_RES   240

TFT_eSPI tft = TFT_eSPI();
AsyncUDP udp;

// Biến toàn cục thời gian
int hoursTFT = 0;
int minutesTFT = 0;
int secondsTFT = 0;

// Giá trị cảm biến
float temperature;
float humidity;
float ppm;

// LED pin
#define LED_PIN 2
#define BUZZER_PIN 14

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
  // Get the value
  int sliderValue = lv_slider_get_value(ui_Slider1);
  int arcValue = lv_arc_get_value(ui_Arc2);
  int valueButton7 = lv_obj_get_state(ui_Button7);
  int valueButton8 = lv_obj_get_state(ui_Button8);

  // Serial.print("valueButton7");
  // Serial.println(valueButton7);
  // Serial.print("valueButton8");
  // Serial.println(valueButton8);

  // Create a JSON document
  StaticJsonDocument<128> doc;

  // Add slider value and arc value to the JSON document
  doc["sliderValue"] = sliderValue;
  doc["arcValue"] = arcValue;
  doc["valueButton7"] = valueButton7;
  doc["valueButton8"] = valueButton8;

  // Serialize JSON document to a string
  char jsonStr[128];
  serializeJson(doc, jsonStr);

  // Send the JSON string via UDP broadcast
  udp.broadcast(jsonStr);
}

// Task định kỳ gửi dữ liệu qua UDP
void UDPSendTask(void *pvParameters) {
  for (;;) {
    Serial.println("UDPSendTask");
    send_data_UDP();                          // Gửi dữ liệu qua UDP
    vTaskDelay(pdMS_TO_TICKS(500));          // Đợi 1 giây trước khi gửi tiếp
  }
}

void get_data_UDP(AsyncUDPPacket packet)
{
  DynamicJsonDocument doc(128); 
  DeserializationError error = deserializeJson(doc, packet.data()); 

  if (!error) {
    temperature = doc["temperature"]; 
    humidity = doc["humidity"]; 
    ppm = doc["ppm"]; 

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

// Hàm hiển thị trạng thái trên màn hình TFT
void displayStatus(const char *message)
{
  tft.fillScreen(TFT_BLACK); // Xóa màn hình
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Màu chữ trắng, nền đen
  tft.setTextSize(2); // Kích thước chữ
  tft.setCursor(10, 100); // Vị trí chữ
  tft.print(message);
}

// Hàm hiển thị thông tin chi tiết WiFi
void displayWiFiInfo()
{
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  
  tft.setCursor(10, 50);
  tft.print("WiFi Connected!");

  tft.setCursor(10, 100);
  tft.print("SSID: ");
  tft.print(ssid);

  tft.setCursor(10, 150);
  tft.print("IP: ");
  tft.print(WiFi.localIP());

  vTaskDelay(pdMS_TO_TICKS(1000));
}

// Hàm kết nối WiFi
void connectWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  displayStatus("Connecting to WiFi...");
  // Thử kết nối cho đến khi thành công
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connecting to WiFi...");
    delay(1000); // Chờ 1 giây trước khi thử lại
  }

  // Kết nối thành công
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Hiển thị thông tin WiFi trên màn hình
  displayWiFiInfo();
}

void setupUDP()
{
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

//Hàm cập nhật thời gian thực từ NTP client
void updateDisplayTime(int* hours, int* minutes, int* seconds) {
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  *hours = (epochTime % 86400L) / 3600;
  *minutes = (epochTime % 3600) / 60;
  *seconds = epochTime % 60;
}

// Task kiểm tra giá trị và điều khiển Buzzer
void CheckAndAlertTask(void *pvParameters) {
  int countCheckThresHold = 99;
  // Khởi tạo Pin
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  for (;;) {
    Serial.println("CheckAndAlertTask");
    if (switch1_state) {
      if (ppm > slider_value_mq2 | temperature > slider_value_temp) {
        
        countCheckThresHold = 0;

        Serial.println("Alert: Value exceeds threshold!");
        Serial.printf("PPM: %f, Temperature: %f\n", ppm, temperature);

        digitalWrite(BUZZER_PIN, HIGH);  

        digitalWrite(LED_PIN, HIGH);  // Bật LED
        vTaskDelay(pdMS_TO_TICKS(200));                 // Đợi 1 giây trước khi cập nhật lại
        digitalWrite(LED_PIN, LOW);   // Tắt LED
        vTaskDelay(pdMS_TO_TICKS(500));  

        bool alertValue = true;
        // Create a JSON document
        StaticJsonDocument<128> doc;
        // Add slider value and arc value to the JSON document
        doc["alertValue"] = alertValue;
        // Serialize JSON document to a string
        char jsonStr[128];
        serializeJson(doc, jsonStr);
        // Send the JSON string via UDP broadcast
        udp.broadcast(jsonStr);

      } 
      else {
        if (countCheckThresHold<=10)
        {
          digitalWrite(BUZZER_PIN, LOW);  

          bool alertValue = false;
          // Create a JSON document
          StaticJsonDocument<128> doc;
          // Add slider value and arc value to the JSON document
          doc["alertValue"] = alertValue;
          // Serialize JSON document to a string
          char jsonStr[128];
          serializeJson(doc, jsonStr);
          // Send the JSON string via UDP broadcast
          udp.broadcast(jsonStr);

          digitalWrite(LED_PIN, LOW);   // Tắt LED
          countCheckThresHold++;
        }
      }
    } 
    else {
      if (countCheckThresHold<=10)
      {
        digitalWrite(BUZZER_PIN, LOW);  

        bool alertValue = false;
        // Create a JSON document
        StaticJsonDocument<128> doc;
        // Add slider value and arc value to the JSON document
        doc["alertValue"] = alertValue;
        // Serialize JSON document to a string
        char jsonStr[128];
        serializeJson(doc, jsonStr);
        // Send the JSON string via UDP broadcast
        udp.broadcast(jsonStr);
        
        digitalWrite(LED_PIN, LOW);   // Tắt LED
        countCheckThresHold++;
      }
    }

    vTaskDelay(pdMS_TO_TICKS(500)); // Kiểm tra mỗi 0.5 giây
  }
}

void setup()
{
  Serial.begin(115200);

  tft.init();
  tft.setRotation(3); 
  uint16_t calData[5] = { 457, 3425, 351, 3285, 1 };
  tft.setTouch(calData);

  // Hiển thị trạng thái ban đầu
  displayStatus("Initializing...");
  vTaskDelay(pdMS_TO_TICKS(1000));

 // Kết nối WiFi
  connectWiFi();

  // Khởi tạo UDP
  setupUDP();

  // Khởi tạo NTP client
  timeClient.begin();

  // Khởi tạo thư viện lvgl
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
  displayStatus("Setup Done!");

  //  Khởi tạo thời gian ban đầu get từ server
  updateDisplayTime(&hoursTFT, &minutesTFT, &secondsTFT);
  update_clock(ui_Image7, ui_Image6, ui_Image5, hoursTFT, minutesTFT, secondsTFT);

  xTaskCreate(UDPSendTask, "UDPSendTask", 4096, NULL, 1, NULL);
  xTaskCreate(CheckAndAlertTask, "CheckAndAlertTask", 4096, NULL, 1, NULL);

}

void loop()
{
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}