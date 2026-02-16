/*
 * display.c
 *
 *  Created on: Feb 9, 2026
 *      Author: Olive Prichard
 */
#include "macros.h"

void Display_Process(void){
  if(update_display){
    update_display = 0;
    if(display_changed){
      display_changed = 0;
      Display_Update(0,0,0,0);
    }
  }
}
