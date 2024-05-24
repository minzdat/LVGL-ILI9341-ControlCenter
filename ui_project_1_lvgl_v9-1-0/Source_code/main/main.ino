#include <lvgl.h>
#include <SPI.h>

#if LV_USE_TFT_ESPI
#include <TFT_eSPI.h>
#endif

#include "ui.h"

#define TFT_HOR_RES   320
#define TFT_VER_RES   240

#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

#if LV_USE_LOG != 0
void my_print( lv_log_level_t level, const char * buf ) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}
#endif

TFT_eSPI tft = TFT_eSPI();

void touch_calibrate() {
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.println("Touch corners as indicated");
  tft.setTextFont(1);
  tft.println();
  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

  Serial.println();
  Serial.println("// Use this calibration code in setup():");
  Serial.print("  uint16_t calData[5] = ");
  Serial.print("{ ");

  for (uint8_t i = 0; i < 5; i++) {
    Serial.print(calData[i]);
    if (i < 4) Serial.print(", ");
  }

  Serial.println(" };");
  Serial.print("  tft.setTouch(calData);");
  Serial.println();
  Serial.println();

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("Calibration complete!");
  tft.println("Calibration code sent to Serial port.");

  delay(4000);
}

void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data) {
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

    Serial.print("X: ");
    Serial.print(x);
    Serial.print(", Y: ");
    Serial.println(y);
  }
}

unsigned int lvgl_tick_cb() {
  return millis();
}

void setup() {
  Serial.begin(115200);

  tft.init();
  tft.setRotation(3); 
  touch_calibrate();
  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.begin( 115200 );
  Serial.println( LVGL_Arduino );

  lv_init();

  lv_tick_set_cb(lvgl_tick_cb);

  #if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print );
  #endif

  lv_display_t * disp;
  #if LV_USE_TFT_ESPI
    disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf));
  #else
    disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
  #endif

  lv_indev_t * indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER); 
  lv_indev_set_read_cb(indev, my_touchpad_read);
  
  lv_obj_t *label = lv_label_create( lv_scr_act() );
  lv_label_set_text( label, "Hello Arduino, I'm LVGL!" );
  lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );

  ui_init();

  Serial.println( "Setup done" );
}

void loop() {
  lv_task_handler(); 
  delay(5); 
}