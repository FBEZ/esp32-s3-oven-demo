#include <stdio.h>
#include "oven_demo.h"
#include "oven_demo_layout.h"
#include "screens/include/screen_on.h"
#include "screens/include/screen_off.h"
#include "lvgl.h"
#include "led_strip.h"


/*RGB LED DEFINITIONS*/
#define LED_STRIP_BLINK_GPIO 4
#define LED_STRIP_LED_NUMBERS 1
#define LED_STRIP_RMT_RES_HZ  (10 * 1000 * 1000)


static lv_obj_t * screen_on;
static lv_obj_t * screen_off;
led_strip_handle_t led_rgb;


//Callbacks
void switch_screen_to_on_cb(lv_event_t * e);
void switch_screen_to_off_cb(lv_event_t * e);

/*GLOBAL STYLES*/
lv_style_t style_buttons;


void setup_demo(){

    // FONTS and STYLES
    LV_FONT_DECLARE(roboto_regular_50);
    LV_FONT_DECLARE(roboto_regular_20);
    LV_FONT_DECLARE(roboto_regular_30);
    LV_FONT_DECLARE(roboto_regular_80);



    // LED SETUP
    led_strip_config_t strip_config = {
        .strip_gpio_num = LED_STRIP_BLINK_GPIO,   // The GPIO that connected to the LED strip's data line
        .max_leds = LED_STRIP_LED_NUMBERS,        // The number of LEDs in the strip,
        .led_pixel_format = LED_PIXEL_FORMAT_GRB, // Pixel format of your LED strip
        .led_model = LED_MODEL_WS2812,            // LED strip model
        .flags.invert_out = false,                // whether to invert the output signal
    };
    led_strip_rmt_config_t rmt_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT,        // different clock source can lead to different power consumption
        .resolution_hz = LED_STRIP_RMT_RES_HZ, // RMT counter clock frequency
        .flags.with_dma = false,               // DMA feature is available on ESP target like ESP32-S3
    };
    led_strip_new_rmt_device(&strip_config, &rmt_config, &led_rgb);
    led_strip_clear(led_rgb);
    
}


void oven_demo(){
    setup_demo();
    screen_off=create_screen_off(switch_screen_to_on_cb);
    lv_scr_load(screen_off);
}



/*CALLBACK SCREEN SWITCHING FUNCTIONS*/
void switch_screen_to_on_cb(lv_event_t * e){
    screen_on=create_screen_on(switch_screen_to_off_cb);
    lv_scr_load(screen_on);
    lv_obj_del(screen_off);
}

void switch_screen_to_off_cb(lv_event_t * e){
    screen_off=create_screen_off(switch_screen_to_on_cb);
    lv_scr_load(screen_off);
    lv_obj_del(screen_on);
}

