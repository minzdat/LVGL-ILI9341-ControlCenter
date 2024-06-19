// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: ui_demo_lvgl

#include "../ui.h"

void ui_Screen4_screen_init(void)
{
    ui_Screen4 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label9 = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, 0);
    lv_obj_set_y(ui_Label9, -90);
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "Device Control");

    ui_TabView1 = lv_tabview_create(ui_Screen4, LV_DIR_LEFT, 60);
    lv_obj_set_width(ui_TabView1, 320);
    lv_obj_set_height(ui_TabView1, 190);
    lv_obj_set_x(ui_TabView1, 0);
    lv_obj_set_y(ui_TabView1, 25);
    lv_obj_set_align(ui_TabView1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_TabView1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TabView1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_TabView1, lv_color_hex(0x00D0FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TabView1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TabView1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_TabView1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(lv_tabview_get_tab_btns(ui_TabView1), 10,  LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(lv_tabview_get_tab_btns(ui_TabView1), 10,  LV_PART_ITEMS | LV_STATE_DEFAULT);

    ui_TabPage1 = lv_tabview_add_tab(ui_TabView1, "Living");

    ui_Button7 = lv_btn_create(ui_TabPage1);
    lv_obj_set_width(ui_Button7, 50);
    lv_obj_set_height(ui_Button7, 50);
    lv_obj_set_x(ui_Button7, -80);
    lv_obj_set_y(ui_Button7, -20);
    lv_obj_set_align(ui_Button7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button7, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_Button7);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "On");

    ui_Button8 = lv_btn_create(ui_TabPage1);
    lv_obj_set_width(ui_Button8, 50);
    lv_obj_set_height(ui_Button8, 50);
    lv_obj_set_x(ui_Button8, -80);
    lv_obj_set_y(ui_Button8, 50);
    lv_obj_set_align(ui_Button8, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button8, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_Button8);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "Off");

    ui_Arc2 = lv_arc_create(ui_TabPage1);
    lv_obj_set_width(ui_Arc2, 120);
    lv_obj_set_height(ui_Arc2, 120);
    lv_obj_set_x(ui_Arc2, 30);
    lv_obj_set_y(ui_Arc2, 20);
    lv_obj_set_align(ui_Arc2, LV_ALIGN_CENTER);
    lv_arc_set_value(ui_Arc2, 50);


    ui_Image9 = lv_img_create(ui_TabPage1);
    lv_img_set_src(ui_Image9, &ui_img_2024947378);
    lv_obj_set_width(ui_Image9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image9, 90);
    lv_obj_set_y(ui_Image9, -60);
    lv_obj_set_align(ui_Image9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image9, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_TabPage2 = lv_tabview_add_tab(ui_TabView1, "Bed");

    ui_Label12 = lv_label_create(ui_TabPage2);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, -90);
    lv_obj_set_y(ui_Label12, -30);
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "Temp");

    ui_Label13 = lv_label_create(ui_TabPage2);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, -90);
    lv_obj_set_y(ui_Label13, 10);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "Speed");

    ui_Label14 = lv_label_create(ui_TabPage2);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label14, -90);
    lv_obj_set_y(ui_Label14, 50);
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "On/Off");

    ui_Slider1 = lv_slider_create(ui_TabPage2);
    lv_slider_set_value(ui_Slider1, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider1) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider1, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Slider1, 150);
    lv_obj_set_height(ui_Slider1, 10);
    lv_obj_set_x(ui_Slider1, 30);
    lv_obj_set_y(ui_Slider1, -30);
    lv_obj_set_align(ui_Slider1, LV_ALIGN_CENTER);


    ui_Slider2 = lv_slider_create(ui_TabPage2);
    lv_slider_set_value(ui_Slider2, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider2) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider2, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Slider2, 150);
    lv_obj_set_height(ui_Slider2, 10);
    lv_obj_set_x(ui_Slider2, 30);
    lv_obj_set_y(ui_Slider2, 10);
    lv_obj_set_align(ui_Slider2, LV_ALIGN_CENTER);


    ui_Switch1 = lv_switch_create(ui_TabPage2);
    lv_obj_set_width(ui_Switch1, 50);
    lv_obj_set_height(ui_Switch1, 25);
    lv_obj_set_x(ui_Switch1, -30);
    lv_obj_set_y(ui_Switch1, 50);
    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);


    ui_Image10 = lv_img_create(ui_TabPage2);
    lv_img_set_src(ui_Image10, &ui_img_1046260344);
    lv_obj_set_width(ui_Image10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image10, 90);
    lv_obj_set_y(ui_Image10, -60);
    lv_obj_set_align(ui_Image10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image10, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_TabPage3 = lv_tabview_add_tab(ui_TabView1, "Bath");

    ui_Roller2 = lv_roller_create(ui_TabPage3);
    lv_roller_set_options(ui_Roller2, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller2, 100);
    lv_obj_set_width(ui_Roller2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_Roller2, -60);
    lv_obj_set_y(ui_Roller2, 0);
    lv_obj_set_align(ui_Roller2, LV_ALIGN_CENTER);

    ui_Button10 = lv_btn_create(ui_TabPage3);
    lv_obj_set_width(ui_Button10, 50);
    lv_obj_set_height(ui_Button10, 50);
    lv_obj_set_x(ui_Button10, 60);
    lv_obj_set_y(ui_Button10, 50);
    lv_obj_set_align(ui_Button10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button10, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button10, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label15 = lv_label_create(ui_Button10);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "Click");

    ui_Dropdown2 = lv_dropdown_create(ui_TabPage3);
    lv_obj_set_width(ui_Dropdown2, 100);
    lv_obj_set_height(ui_Dropdown2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown2, 60);
    lv_obj_set_y(ui_Dropdown2, -20);
    lv_obj_set_align(ui_Dropdown2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Dropdown2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags



    ui_Image11 = lv_img_create(ui_TabPage3);
    lv_img_set_src(ui_Image11, &ui_img_1270191234);
    lv_obj_set_width(ui_Image11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image11, 90);
    lv_obj_set_y(ui_Image11, -60);
    lv_obj_set_align(ui_Image11, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image11, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button6 = lv_btn_create(ui_Screen4);
    lv_obj_set_width(ui_Button6, 40);
    lv_obj_set_height(ui_Button6, 40);
    lv_obj_set_x(ui_Button6, -130);
    lv_obj_set_y(ui_Button6, -95);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button6, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button6, &ui_img_back_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button7, ui_event_Button7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button8, ui_event_Button8, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);

}
