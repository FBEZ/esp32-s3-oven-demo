idf_component_register(SRCS "oven_demo.c" "screens/screen_on.c" "screens/screen_off.c" "views/round_button.c"
                    INCLUDE_DIRS "include" "screens/include" "views/include"
                    REQUIRES "lvgl" "led_strip"
                    )
