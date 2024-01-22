#ifndef ROUND_BUTTON_H
#define ROUND_BUTTON_H

#include "lvgl.h"

/**
 * @brief Create a round button object
 * 
 * @param parent parent of the button
 * @param symbol a selection of LV_SYMBOL_xxx
 * @return lv_obj_t* 
 */
lv_obj_t * create_round_button(lv_obj_t * parent, char * symbol);

#endif