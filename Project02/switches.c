/*
 * switches.c
 *
 *  Created on: Feb 19, 2026
 *      Author: olive
 */

#include "macros.h"

char prev_s1 = HIGH;
char prev_s2 = HIGH;

void Switches_Process(void) {
    char s1 = LOW;
    char s2 = LOW;
    if (P4IN & SW1) {
        s1 = HIGH;
    }
    if (P2IN & SW2) {
        s2 = HIGH;
    }

    if (start_sequence == SELECTION) { // run selection logic
        if (s1 == LOW && prev_s1 == HIGH) { // trigger on falling edge of SW1
            shape_selection++; // increment shape
            if (shape_selection > TRIANGLE) { // wrap around logic
                shape_selection = CIRCLE;
            }
            unsigned int i = 0;
            for (; i < 4; i++) { // clear indicator
                display_line[i][SELECTION_COLUMN] = ' ';
            }
            display_line[shape_selection][SELECTION_COLUMN] = 'X';
            display_changed = TRUE;
        }
        if (s2 == LOW && prev_s2 == HIGH) {
            start_sequence = DELAY;
            timing = 0;
            unsigned int i = 0;
            for (; i < 4; i++) { // clear indicator
                display_line[i][SELECTION_COLUMN] = ' ';
            }
            for (i = 0; i < 4; i++) { // remove other things
                if (i != shape_selection) {
                    strcpy(display_line[i], "          ");
                }
            }
            display_changed = TRUE;
        }
    }

    prev_s1 = s1;
    prev_s2 = s2;
}
