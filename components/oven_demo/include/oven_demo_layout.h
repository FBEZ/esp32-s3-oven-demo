#ifndef OVEN_DEMO_LAYOUT_H
#define OVEN_DEMO_LAYOUT_H

/*COLORS*/

#define BACKGROUND_COLOR 0x282424
#define TEXT_COLOR 0xFFFFFF
#define TEXT_COLOR_MUTED 0x6B6161
#define TAB_BORDER_COLOR_SELECTED 0xAAA1A1

#define KNOB_GRADIENT_START 0xAAA1A1
#define KNOB_GRADIENT_END   0xFF0000

#define GET_RED(NUMBER)   (uint16_t)(((NUMBER)>>16) & 0xFF)
#define GET_BLUE(NUMBER)  (uint16_t)(((NUMBER)>>8)  & 0xFF)
#define GET_GREEN(NUMBER) (uint16_t)(((NUMBER))     & 0xFF)


/*DIMENSIONS AND APPEARANCES*/

#define SECONDS_BAR_LENGTH 150
#define KNOB_RADIUS 200
#define MEAS_TEMP_HEIGHT 100
#define TIMER_TAB_UPPER_LOWER_SIZE_PX 130
#define ICON_DEFAULT_OPA LV_OPA_30

/*CONFIGURATIONS*/

#define MINIMUM_TEMPERATURE 0
#define MAXIMUM_TEMPERATURE 250
#define MEASURED_TEMPERATURE_DEFAULT_C 135
#define MEASURED_TEMPERATURE_DEFAULT_F (MEASURED_TEMPERATURE_DEFAULT_C*18+320)/10

#endif