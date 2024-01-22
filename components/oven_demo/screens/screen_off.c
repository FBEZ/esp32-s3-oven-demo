#include "screen_off.h"
#include "oven_demo_layout.h"
#include "round_button.h"

lv_obj_t * create_screen_off(lv_event_cb_t switch_screen_cb){
    


    lv_obj_t * screen_off = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_off, lv_color_hex(BACKGROUND_COLOR), 0);
    
    lv_obj_t * column_container = lv_obj_create(screen_off);
    lv_obj_set_size(column_container, 300, 300);
    lv_obj_align_to(column_container, screen_off, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_flex_flow(column_container, LV_FLEX_FLOW_COLUMN);

    lv_obj_t * time_label = lv_label_create(column_container);
    lv_label_set_text(time_label, "questa");

    lv_obj_t * switch_button = create_round_button(column_container, LV_SYMBOL_AUDIO);
    lv_obj_add_event_cb(switch_button,switch_screen_cb,LV_EVENT_CLICKED, NULL);

    return screen_off;
}