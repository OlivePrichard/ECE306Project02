/*
 * globals.h
 *
 *  Created on: Feb 9, 2026
 *      Author: Olive Prichard
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

  // Global Variables
volatile char slow_input_down;
extern char display_line[4][11];
extern char *display[4];
unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
extern volatile unsigned int Time_Sequence;
extern volatile char one_time;
unsigned int test_value;
char chosen_direction;
char change;

unsigned int wheel_move;
char forward;

int start_sequence;
int run_sequence;
int shape_selection;
int shape_count;
unsigned int timing;

#endif /* GLOBALS_H_ */
