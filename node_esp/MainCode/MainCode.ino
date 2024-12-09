// Thư viện cần thiết
#include "esp_task_wdt.h"
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "AsyncUDP.h" 
#include <ArduinoJson.h>
#include <DHT11.h>
#include <MQUnifiedsensor.h>

/************************Hardware Related Macros************************************/
#define         Board                   ("ESP-32") // Wemos ESP-32 or other board, whatever have ESP32 core.

//https://www.amazon.com/HiLetgo-ESP-WROOM-32-Development-Microcontroller-Integrated/dp/B0718T232Z (Although Amazon shows ESP-WROOM-32 ESP32 ESP-32S, the board is the ESP-WROOM-32D)
#define         Pin                     (36) //check the esp32-wroom-32d.jpg image on ESP32 folder 

/***********************Software Related Macros************************************/
#define         Type                    ("MQ-2") //MQ2 or other MQ Sensor, if change this verify your a and b values.
#define         Voltage_Resolution      (3.3) // 3V3 <- IMPORTANT. Source: https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
#define         ADC_Bit_Resolution      (12) // ESP-32 bit resolution. Source: https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
#define         RatioMQ2CleanAir        (9.83) //RS / R0 = 9.83 ppm
/*****************************Globals***********************************************/
MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);
/*****************************Globals***********************************************/

// ID và password WiFi
const char* ssid = "Minz";
const char* password = "12345678";

// Thiết lập NTP client
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7 * 3600, 60000);

// Thiết lập OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define OLED_SDA 21
#define OLED_SCL 22
Adafruit_SSD1306 oledDisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// LED pin
#define LED_PWM_PIN 2
#define LED_PIN 15
#define LED_ALERT 26
// DHT pin
#define DHT11_GPIO 32
// BTN pin
#define BTN_GPIO 19

// Semaphore
SemaphoreHandle_t xSemaphoreButton;
// TaskHandle

// Biến toàn cục thời gian
int hoursOLED = 0;
int minutesOLED = 0;
int secondsOLED = 0;
int getTime = 0;

// Thiết lập UDP nhận dữ liệu 
AsyncUDP udp;
bool alertValue = false;
int arcValue = 50;
int btn7Value = 0;
int btn8Value = 0;

// Biến đếm số lần nhấn nút
int countPressBtn = -1;
volatile bool buttonPressed = false; // Biến cờ được cập nhật trong ISR
volatile unsigned long lastDebounceTime = 0; // Thời gian nhấn gần nhất
const unsigned long debounceDelay = 200;    // Độ trễ debounce (200ms)

// Giá trị cảm biến
int temperature = 0;
int humidity = 0;
float ppm = 0;

void SetUpOLED();
void InitOLEDSystem();
void OLEDIntoSystem();
void SetUpWIFI();
void initMQ2();
void updateDisplayTime(int* hours, int* minutes, int* seconds);
void handleUdpPacket(AsyncUDPPacket packet);

void OLEDDisplayTask(void *pvParameters);
void IRAM_ATTR handleButtonPress();
void semaphoreButtonTask(void *pvParameters __attribute__((unused)));
void UDPListenerSendTask(void *pvParameters); 
void LEDBrightnessTask(void *pvParameters);
void ReadDHT11Task(void *pvParameters);
void Mq2Task(void *parameter);

void setup() {
  Serial.begin(115200); 

  // Khởi tạo OLED
  SetUpOLED();

  // Thiết lập task watchdog
  esp_task_wdt_init(10, true); 

  // Hiển thị trạng thái đang kết nối Wifi
  InitOLEDSystem();

  // Khởi tạo WiFi
  SetUpWIFI();

  // Hiển thị Wifi connected
  OLEDIntoSystem();

  // Khởi tạo NTP client
  timeClient.begin();
  updateDisplayTime(&hoursOLED, &minutesOLED, &secondsOLED);

  // Khởi tạo Semaphore
  xSemaphoreButton = xSemaphoreCreateBinary();
  if (xSemaphoreButton == NULL) {
    Serial.println("Failed to create semaphore");
  }

  // Khởi tạo Pin
  pinMode(BTN_GPIO, INPUT_PULLUP); 
  pinMode(LED_PWM_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_ALERT, OUTPUT);

 // Gắn ISR cho nút bấm
  attachInterrupt(digitalPinToInterrupt(BTN_GPIO), handleButtonPress, FALLING);

  //Khởi tạo chân LED và PWM
  ledcSetup(0, 5000, 8);           // Thiết lập kênh PWM 0 với tần số 5 kHz và độ phân giải 8 bit
  ledcAttachPin(LED_PWM_PIN, 0);       // Gắn chân LED vào kênh PWM 0
  ledcWrite(0, 255);               // Đặt giá trị PWM của kênh 0 là 255 (sáng nhất)

  // Khởi tạo tasks
  xTaskCreatePinnedToCore(OLEDDisplayTask, "OLED Task", 2048, NULL, 3, NULL, 0);  
  xTaskCreatePinnedToCore(semaphoreButtonTask, "Button Semaphore Task", 2048, NULL, 3, NULL, 0); 
  xTaskCreatePinnedToCore(ReadDHT11Task, "Read DHT11 Task", 4096, NULL, 3, NULL, 1);
  xTaskCreatePinnedToCore(Mq2Task, "MQ2 Task", 4096, NULL, 3, NULL, 0);
  xTaskCreatePinnedToCore(UDPListenerSendTask, "UDP Listener Task", 4096, NULL, 3, NULL, 0); 
  xTaskCreatePinnedToCore(LEDBrightnessTask, "LED Brightness Task", 2048, NULL, 3, NULL, 0);
}

void loop() {
  // vTaskDelay(pdMS_TO_TICKS(1000));
}

//Hàm kết nối WIFI
void SetUpWIFI(){ 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

//Hàm cập nhật thời gian thực từ NTP client
void updateDisplayTime(int* hours, int* minutes, int* seconds) {
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  *hours = (epochTime % 86400L) / 3600;
  *minutes = (epochTime % 3600) / 60;
  *seconds = epochTime % 60;
}

//Hàm khởi tạo màn hình OLED
void SetUpOLED(){
  Wire.begin(OLED_SDA, OLED_SCL);
  if (!oledDisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  Serial.println("Setup OLED");
  oledDisplay.clearDisplay();
  oledDisplay.setTextSize(1);
  oledDisplay.setTextColor(SSD1306_WHITE);
}

void InitOLEDSystem(){
  oledDisplay.clearDisplay();
  oledDisplay.setTextSize(2);
  oledDisplay.setCursor(0, 10);
  oledDisplay.print("Loading...");
  oledDisplay.display();

  vTaskDelay(pdMS_TO_TICKS(1000));

  oledDisplay.clearDisplay();
  oledDisplay.setTextSize(1);
  oledDisplay.setCursor(0, 10);
  oledDisplay.print("Connecting Wifi...");
  oledDisplay.display();
}

void OLEDIntoSystem(){
  oledDisplay.clearDisplay();
  oledDisplay.setTextSize(1);
  oledDisplay.setCursor(0, 0);
  oledDisplay.print("WiFi Connected!");

  oledDisplay.setCursor(0, 10);
  oledDisplay.print("SSID: ");
  oledDisplay.println(ssid);
  oledDisplay.setCursor(0, 20);
  oledDisplay.print("Password: ");
  oledDisplay.println(password);
  oledDisplay.display();

  vTaskDelay(pdMS_TO_TICKS(1000));
}

// Task hiển thị trên màn hình OLED
void OLEDDisplayTask(void *pvParameters) {
  for (;;) {
    Serial.println("OLEDDisplayTask");
   
    switch (countPressBtn) {
      case 1:
        updateDisplayTime(&hoursOLED, &minutesOLED, &secondsOLED);
        
        oledDisplay.clearDisplay();
        oledDisplay.setTextSize(2);
        oledDisplay.setCursor(0, 10);
        oledDisplay.print(hoursOLED);
        oledDisplay.print(":");
        if (minutesOLED < 10) oledDisplay.print("0");
        oledDisplay.print(minutesOLED);
        oledDisplay.print(":");
        if (secondsOLED < 10) oledDisplay.print("0");
        oledDisplay.print(secondsOLED);
        oledDisplay.display();
        break;

      case 2:
        // Hiển thị giá trị nhiệt độ và độ ẩm DHT
        oledDisplay.clearDisplay();
        oledDisplay.setTextSize(1);
        oledDisplay.setCursor(0, 10);
        oledDisplay.print("Temp: ");
        oledDisplay.print(temperature); // Giá trị nhiệt độ
        oledDisplay.print("C ");
        oledDisplay.print("Hum: ");
        oledDisplay.print(humidity); // Giá trị độ ẩm
        oledDisplay.print("%");
        oledDisplay.display();
        break;

      case 3:
        // Hiển thị giá trị MQ2
        oledDisplay.clearDisplay();
        oledDisplay.setTextSize(1);
        oledDisplay.setCursor(0, 10);
        oledDisplay.print("MQ: ");
        oledDisplay.print(ppm); // Giá trị MQ2
        oledDisplay.print(" ppm");
        oledDisplay.display();
        break;

      default:
        oledDisplay.clearDisplay();
        oledDisplay.setTextSize(2);
        oledDisplay.setCursor(0, 10);
        oledDisplay.print("Welcome !");
        oledDisplay.display();
        break;
    }
    vTaskDelay(pdMS_TO_TICKS(100)); 
  }
}

void IRAM_ATTR handleButtonPress() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 100) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(xSemaphoreButton, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken) {
      portYIELD_FROM_ISR();
    }
  }
  last_interrupt_time = interrupt_time;
}

void semaphoreButtonTask(void *pvParameters __attribute__((unused))) {
  int buttonPressCount = 0;

  for (;;) {
    Serial.println("semaphoreButtonTask");
    // Đợi tín hiệu từ ISR (được gửi khi nút nhấn)
    if (xSemaphoreTake(xSemaphoreButton, portMAX_DELAY) == pdTRUE) {
      unsigned long startTime = millis();
      buttonPressCount = 1;

      // Kiểm tra số lần nhấn nút trong vòng 1 giây
      while (millis() - startTime < 1000) {
        // Kiểm tra nếu semaphore được gửi thêm lần nữa trong 1 giây
        if (xSemaphoreTake(xSemaphoreButton, 0) == pdTRUE) {
          buttonPressCount++;
        }
        vTaskDelay(pdMS_TO_TICKS(10)); // Chờ để giảm tải CPU
      }

      // Ghi nhận số lần nhấn vào biến
      countPressBtn = buttonPressCount;
      Serial.print("Button pressed ");
      Serial.print(countPressBtn);
      Serial.println(" time(s) in 1 second");
    }
  }
}

// Hàm task đọc nhiệt độ và độ ẩm
void ReadDHT11Task(void *pvParameters) {
    // Khởi tạo cảm biến DHT11
    DHT11 dht11(DHT11_GPIO); 

    while (true) {
      Serial.println("ReadDHT11Task");
      // Đọc giá trị nhiệt độ và độ ẩm
      int result = dht11.readTemperatureHumidity(temperature, humidity);

      // Kiểm tra kết quả
      if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");
      } else {
          Serial.println(DHT11::getErrorString(result));
      }

      // Delay 2 giây giữa các lần đọc
      vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

// Function to initialize the MQ-2 sensor
void initMQ2() {
 //Init the serial port communication - to debug the library
  delay(10);

  //Set math model to calculate the PPM concentration and the value of constants
  MQ2.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ2.setA(987.99); MQ2.setB(-2.162); // Configure the equation to to calculate H2 concentration
  
  /*
    Exponential regression:
    Gas    | a      | b
    H2     | 987.99 | -2.162
    LPG    | 574.25 | -2.222
    CO     | 36974  | -3.109
    Alcohol| 3616.1 | -2.675
    Propane| 658.71 | -2.168
  */

  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ2.init(); 
 
  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ2.setRL(10);
  */
  /*****************************  MQ CAlibration ********************************************/ 
  // Explanation: 
   // In this routine the sensor will measure the resistance of the sensor supposedly before being pre-heated
  // and on clean air (Calibration conditions), setting up R0 value.
  // We recomend executing this routine only on setup in laboratory conditions.
  // This routine does not need to be executed on each restart, you can load your R0 value from eeprom.
  // Acknowledgements: https://jayconsystems.com/blog/understanding-a-gas-sensor
  Serial.print("Calibrating please wait.");
  float calcR0 = 0;
  for(int i = 1; i<=10; i ++)
  {
    MQ2.update(); // Update data, the arduino will read the voltage from the analog pin
    calcR0 += MQ2.calibrate(RatioMQ2CleanAir);
    Serial.print(".");
  }
  MQ2.setR0(calcR0/10);
  Serial.println("  done!.");
  
  if(isinf(calcR0)) {Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(calcR0 == 0){Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply"); while(1);}
  /*****************************  MQ CAlibration ********************************************/ 
  //MQ2.serialDebug(true); uncomment if you want to print the table on the serial port
}

// Task to read the MQ-2 sensor
void Mq2Task(void *parameter) {
    initMQ2();

    while (true) {
      Serial.println("Mq2Task");
      MQ2.update();
      ppm = MQ2.readSensor();
      Serial.print("MQ-2 Gas Concentration: ");
      Serial.print(ppm);
      Serial.println(" PPM");
      vTaskDelay(pdMS_TO_TICKS(2000)); // Delay 2 second
    }
}

// Xử lý gói tin UDP
void handleUdpPacket(AsyncUDPPacket packet) {
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, packet.data());

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  if (doc.containsKey("arcValue") || doc.containsKey("valueButton7") || doc.containsKey("valueButton8")) {
    arcValue = doc["arcValue"];
    btn7Value = doc["valueButton7"];
    btn8Value = doc["valueButton8"];
    Serial.print("Received arcValue: ");
    Serial.println(arcValue);
    Serial.print("Received valueButton7: ");
    Serial.println(btn7Value);
    Serial.print("Received valueButton8: ");
    Serial.println(btn8Value);

  }
  else if (doc.containsKey("alertValue"))
  {
    alertValue = doc["alertValue"];
    Serial.print("Received alertValue: ");
    Serial.println(alertValue);
  } 
  else {
    Serial.println("No arcValue found in the packet");
  }

  packet.printf("Got %u bytes of data", packet.length());
}

// Task lắng nghe UDP
void UDPListenerSendTask(void *pvParameters) {
  if (udp.listen(1234)) {
    Serial.print("UDP Listening on IP: ");
    Serial.println(WiFi.localIP());
    udp.onPacket([](AsyncUDPPacket packet) {
      handleUdpPacket(packet);
    });
  }

  for (;;) {
    Serial.println("UDPListenerSendTask");
    
    // Create a JSON document
    StaticJsonDocument<128> doc;

    // Add slider value and arc value to the JSON document
    doc["temperature"] = temperature;
    doc["humidity"] = humidity;
    doc["ppm"] = ppm;

    // Serialize JSON document to a string
    char jsonStr[128];
    serializeJson(doc, jsonStr);

    // Send the JSON string via UDP broadcast
    udp.broadcast(jsonStr);
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}

// Task điều chỉnh độ sáng LED
void LEDBrightnessTask(void *pvParameters) {
  for (;;) {
    Serial.println("LEDBrightnessTask");
    int brightness = map(arcValue, 0, 100, 0, 255);  // Chuyển đổi giá trị arcValue từ 0-100 sang 0-255
    ledcWrite(0, brightness);                        // Gửi giá trị độ sáng tới kênh PWM 0

    if (alertValue) {
      digitalWrite(LED_ALERT, HIGH);  // Bật LED
      vTaskDelay(pdMS_TO_TICKS(200));                 // Đợi 1 giây trước khi cập nhật lại
      digitalWrite(LED_ALERT, LOW);   // Tắt LED
      vTaskDelay(pdMS_TO_TICKS(500));                 // Đợi 1 giây trước khi cập nhật lại
    }
    else
    {
      digitalWrite(LED_ALERT, LOW);   // Tắt LED
    }

    if (btn7Value == 2 && btn8Value == 0) {
      digitalWrite(LED_PIN, HIGH);  // Bật LED
    } 
    else if (btn7Value == 0 && btn8Value == 2) {
      digitalWrite(LED_PIN, LOW);   // Tắt LED
    }
    else {
      // Không thực hiện gì
    }

    vTaskDelay(pdMS_TO_TICKS(100));                 // Đợi 1 giây trước khi cập nhật lại
  }
}