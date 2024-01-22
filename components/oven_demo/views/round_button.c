#include "round_button.h"
#include "oven_demo_layout.h"

lv_obj_t * create_round_button(lv_obj_t * parent, char * symbol){

    lv_obj_t * round_button = lv_obj_create(parent);
    lv_obj_t * round_label = lv_label_create(round_button);

    lv_label_set_text(round_label, symbol);
    lv_obj_set_style_text_color(round_label,lv_color_hex(TEXT_COLOR),0);
    lv_obj_remove_style_all(round_button);
    //lv_obj_remove_style_all(label);
    lv_obj_set_style_radius(round_button,LV_RADIUS_CIRCLE,0);
    lv_obj_set_style_bg_opa(round_button, LV_OPA_100,0);
    lv_obj_set_style_bg_color(round_button,lv_color_hex(TEXT_COLOR_MUTED),0);
    lv_obj_set_style_border_width(round_button,0, 0);
    lv_obj_set_size(round_button,DEFAULT_BUTTON_SIZE,DEFAULT_BUTTON_SIZE);
    lv_obj_center(round_label);


    return round_button;
}