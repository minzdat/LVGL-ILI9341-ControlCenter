SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    screens/ui_Screen3.c
    screens/ui_Screen4.c
    screens/ui_Screen5.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_2085094990.c
    images/ui_img_smartwatch_png.c
    images/ui_img_temperature_png.c
    images/ui_img_electricity_png.c
    images/ui_img_clock_png.c
    images/ui_img_seconds_png.c
    images/ui_img_minus_png.c
    images/ui_img_back_png.c
    images/ui_img_temperaturev2_png.c
    images/ui_img_humidity_png.c
    images/ui_img_2024947378.c
    images/ui_img_1046260344.c
    images/ui_img_1270191234.c)

add_library(ui ${SOURCES})
