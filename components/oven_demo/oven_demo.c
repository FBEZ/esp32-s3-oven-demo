#include <stdio.h>
#include "oven_demo.h"
#include "oven_demo_layout.h"
#include "lvgl.h"

static lv_obj_t * screen_on;
static lv_obj_t * screen_off;

void create_screen_off(void);
void create_screen_on(void);

//Callbacks
void switch_screen_to_on_cb(lv_event_t * e);
void switch_screen_to_off_cb(lv_event_t * e);

void oven_demo(){
    create_screen_on();
}

void create_screen_off(void){
    screen_off = lv_obj_create(NULL);
    lv_scr_load(screen_off);
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(BACKGROUND_COLOR), 0);
    lv_obj_t * button = lv_obj_create(screen_off);
    lv_obj_set_style_bg_color(button, lv_color_hex(TEXT_COLOR_MUTED),LV_PART_MAIN);
    lv_obj_add_event_cb(button,switch_screen_to_on_cb,LV_EVENT_CLICKED, NULL);
    lv_obj_t * label = lv_label_create(button);
    lv_label_set_text(label,"tiokano");
    lv_obj_center(label);
    
}

void create_screen_on(void){
    screen_on = lv_obj_create(NULL);
    lv_scr_load(screen_on);
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(BACKGROUND_COLOR), 0);
    lv_obj_t * button = lv_obj_create(screen_on);
    lv_obj_set_style_bg_color(button, lv_color_hex(0xFFFFFF),LV_PART_MAIN);
    lv_obj_add_event_cb(button,switch_screen_to_off_cb,LV_EVENT_CLICKED, NULL);
    lv_obj_t * label = lv_label_create(button);
    lv_label_set_text(label,"kanukanu");
    lv_obj_center(label);
    
}


/*CALLBACK FUNCTIONS*/
void switch_screen_to_on_cb(lv_event_t * e){
    create_screen_on();
    lv_obj_del(screen_off);
}

void switch_screen_to_off_cb(lv_event_t * e){
    create_screen_off();
    lv_obj_del(screen_on);
}

