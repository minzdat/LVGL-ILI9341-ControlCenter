SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    screens/ui_Screen3.c
    screens/ui_Screen4.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_smartwatch_png.c
    images/ui_img_temperature_png.c
    images/ui_img_electricity_png.c
    images/ui_img_2085094990.c
    images/ui_img_temperaturev2_png.c
    images/ui_img_humidity_png.c)

add_library(ui ${SOURCES})
