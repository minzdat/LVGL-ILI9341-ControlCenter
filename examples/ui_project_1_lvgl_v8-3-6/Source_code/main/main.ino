#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui.h"

#define TFT_HOR_RES   320
#define TFT_VER_RES   240

TFT_eSPI tft = TFT_eSPI();

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

void setup()
{
  Serial.begin(115200);

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
}