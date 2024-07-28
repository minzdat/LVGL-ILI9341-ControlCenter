#include "../../lv_examples.h"
#include "lv_example_lodepng.h"

#if LV_USE_LODEPNG && LV_USE_IMAGE && LV_BUILD_EXAMPLES

void lv_example_lodepng_1(void)
{
    LV_IMAGE_DECLARE(img_wink_png);
    lv_obj_t * img;

    img = lv_image_create(lv_scr_act());
    lv_image_set_src(img, &img_wink_png);
    lv_obj_align(img, LV_ALIGN_LEFT_MID, 20, 0);

    img = lv_image_create(lv_scr_act());
    lv_image_set_src(img, "C:/Dev_minz/ProjectSubject-1/ArduinoLibraries/libraries/lvgl/examples/libs/lodepng/wink.png");
    lv_obj_align(img, LV_ALIGN_RIGHT_MID, -20, 0);
}

#endif
