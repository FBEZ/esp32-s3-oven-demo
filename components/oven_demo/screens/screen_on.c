#include "screen_on.h"
#include "oven_demo_layout.h"

lv_obj_t * create_screen_on(lv_event_cb_t switch_screen_cb){
    lv_obj_t * screen_on = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_on, lv_color_hex(BACKGROUND_COLOR), 0);
    lv_obj_t * button = lv_obj_create(screen_on);
    lv_obj_set_style_bg_color(button, lv_color_hex(0xFFFFFF),LV_PART_MAIN);
    lv_obj_add_event_cb(button,switch_screen_cb,LV_EVENT_CLICKED, NULL);
    lv_obj_t * label = lv_label_create(button);
    lv_label_set_text(label,"kanukanu pddio");
    lv_obj_center(label);
    return screen_on;
    
}