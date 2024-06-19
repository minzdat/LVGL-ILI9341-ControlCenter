// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: ui_demo_lvgl

#ifndef _UI_DEMO_LVGL_UI_H
#define _UI_DEMO_LVGL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"

void seconds_turn_around_Animation(lv_obj_t * TargetObject, int delay);
void minutes_turn_around_Animation(lv_obj_t * TargetObject, int delay);
void hours_turn_around_Animation(lv_obj_t * TargetObject, int delay);
void start_screen_2_Animation(lv_obj_t * TargetObject, int delay);
void bar_loading_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
void ui_event_Screen1(lv_event_t * e);
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Container1;
extern lv_obj_t * ui_Label20;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_Container2;
extern lv_obj_t * ui_Spinner2;
extern lv_obj_t * ui_Label21;
extern lv_obj_t * ui_Container3;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_Panel1;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
void ui_event_Button2(lv_event_t * e);
extern lv_obj_t * ui_Button2;
void ui_event_Button3(lv_event_t * e);
extern lv_obj_t * ui_Button3;
extern lv_obj_t * ui_Label17;
extern lv_obj_t * ui_Label18;
extern lv_obj_t * ui_Label19;
// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
void ui_event_Screen2(lv_event_t * e);
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Label7;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_Image5;
extern lv_obj_t * ui_Image6;
extern lv_obj_t * ui_Image7;
void ui_event_Button4(lv_event_t * e);
extern lv_obj_t * ui_Button4;
// SCREEN: ui_Screen3
void ui_Screen3_screen_init(void);
extern lv_obj_t * ui_Screen3;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label3;
void ui_event_Button5(lv_event_t * e);
extern lv_obj_t * ui_Button5;
// SCREEN: ui_Screen4
void ui_Screen4_screen_init(void);
extern lv_obj_t * ui_Screen4;
extern lv_obj_t * ui_Label9;
extern lv_obj_t * ui_TabView1;
extern lv_obj_t * ui_TabPage1;
void ui_event_Button7(lv_event_t * e);
extern lv_obj_t * ui_Button7;
extern lv_obj_t * ui_Label10;
void ui_event_Button8(lv_event_t * e);
extern lv_obj_t * ui_Button8;
extern lv_obj_t * ui_Label11;
extern lv_obj_t * ui_Arc2;
extern lv_obj_t * ui_Image9;
extern lv_obj_t * ui_TabPage2;
extern lv_obj_t * ui_Label12;
extern lv_obj_t * ui_Label13;
extern lv_obj_t * ui_Label14;
extern lv_obj_t * ui_Slider1;
extern lv_obj_t * ui_Slider2;
extern lv_obj_t * ui_Switch1;
extern lv_obj_t * ui_Image10;
extern lv_obj_t * ui_TabPage3;
extern lv_obj_t * ui_Roller2;
extern lv_obj_t * ui_Button10;
extern lv_obj_t * ui_Label15;
extern lv_obj_t * ui_Dropdown2;
extern lv_obj_t * ui_Image11;
void ui_event_Button6(lv_event_t * e);
extern lv_obj_t * ui_Button6;
// SCREEN: ui_Screen5
void ui_Screen5_screen_init(void);
extern lv_obj_t * ui_Screen5;
extern lv_obj_t * ui_Container4;
extern lv_obj_t * ui_Label24;
extern lv_obj_t * ui_Image8;
extern lv_obj_t * ui_Panel7;
void ui_event_Button9(lv_event_t * e);
extern lv_obj_t * ui_Button9;
void ui_event_Button12(lv_event_t * e);
extern lv_obj_t * ui_Button12;
void ui_event_Button13(lv_event_t * e);
extern lv_obj_t * ui_Button13;
extern lv_obj_t * ui_Label25;
extern lv_obj_t * ui_Label26;
extern lv_obj_t * ui_Label27;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_2085094990);    // assets/smart-home.png
LV_IMG_DECLARE(ui_img_smartwatch_png);    // assets/smartwatch.png
LV_IMG_DECLARE(ui_img_temperature_png);    // assets/temperature.png
LV_IMG_DECLARE(ui_img_electricity_png);    // assets/electricity.png
LV_IMG_DECLARE(ui_img_clock_png);    // assets/clock.png
LV_IMG_DECLARE(ui_img_seconds_png);    // assets/seconds.png
LV_IMG_DECLARE(ui_img_minus_png);    // assets/minus.png
LV_IMG_DECLARE(ui_img_back_png);    // assets/back.png
LV_IMG_DECLARE(ui_img_temperaturev2_png);    // assets/temperaturev2.png
LV_IMG_DECLARE(ui_img_humidity_png);    // assets/humidity.png
LV_IMG_DECLARE(ui_img_2024947378);    // assets/living-room.png
LV_IMG_DECLARE(ui_img_1046260344);    // assets/bed-room.png
LV_IMG_DECLARE(ui_img_1270191234);    // assets/bath-room.png






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
