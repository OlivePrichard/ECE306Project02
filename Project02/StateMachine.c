/*
 * StateMachine.c
 *
 *  Created on: Feb 16, 2026
 *      Author: olive
 */

#include "macros.h"

void Carlson_StateMachine(void){

    switch(Time_Sequence){
      case 250:                        //
        if(one_time){
          Init_LEDs();
//          lcd_BIG_mid();
          display_changed = 1;
          one_time = 0;
        }
        Time_Sequence = 0;             //
        break;
      case 200:                        //
        if(one_time){
//          P1OUT &= ~RED_LED;            // Change State of LED 4
          P6OUT |= GRN_LED;            // Change State of LED 5
          one_time = 0;
        }
        break;
      case 150:                         //
        if(one_time){
          P1OUT |= RED_LED;            // Change State of LED 4
          P6OUT &= ~GRN_LED;            // Change State of LED 5
          one_time = 0;
        }
        break;
      case 100:                         //
        if(one_time){
//          lcd_4line();
//          lcd_BIG_bot();
          P6OUT |= GRN_LED;            // Change State of LED 5
          display_changed = 1;
          one_time = 0;
        }
        break;
      case  50:                        //
        if(one_time){
          one_time = 0;
        }
        break;                         //
      default: break;
    }
}

void L_Motor_On(void) {
    P6OUT |=  L_FORWARD;
}

void L_Motor_Off(void) {
    P6OUT &= ~L_FORWARD;
}

void R_Motor_On(void) {
    P6OUT |=  R_FORWARD;
}

void R_Motor_Off(void) {
    P6OUT &= ~R_FORWARD;
}

unsigned int motor_timing;
unsigned int L_speed;
unsigned int R_speed;
void MotorControl(void) {
    if (motor_timing == 0) {
        L_Motor_On();
        R_Motor_On();
    }
    if (motor_timing == L_speed) {
        L_Motor_Off();
    }
    if (motor_timing == R_speed) {
        R_Motor_Off();
    }
    motor_timing++;
    if (motor_timing >= 100) motor_timing = 0;
}

void Circle(void) {
    L_speed = CIRCLE_OUTER;
    R_speed = CIRCLE_INNER;
    if (timing > CIRCLE_TIMING) {
        shape_selection = STOP;
    }
}

void Figure_Eight(void) {
    if (timing == FIGURE_EIGHT_TIMING) {
        timing = 0;
        run_sequence = !run_sequence;
        shape_count++;
        if (shape_count >= 4) shape_selection = STOP;
    }

    if (run_sequence == TURNING_RIGHT) {
        L_speed = FIGURE_OUTER;
        R_speed = FIGURE_INNER;
    } else {
        L_speed = FIGURE_INNER;
        R_speed = FIGURE_OUTER;
    }
}

void Triangle(void) {
    if (run_sequence == STRAIGHT && timing == TRIANGLE_STRAIGHT) {
        timing = 0;
        run_sequence = PIVOT;
    }
    else if (run_sequence == PIVOT && timing == TRIANGLE_TURN) {
        timing = 0;
        run_sequence = STRAIGHT;
        shape_count++;
        if (shape_count >= 6) shape_selection = STOP;
    }

    if (run_sequence == STRAIGHT) {
        L_speed = STRAIGHT_SPEED;
        R_speed = STRAIGHT_SPEED;
    } else {
        L_speed = PIVOT_OUTER;
        R_speed = PIVOT_INNER;
    }
}

void Shape_StateMachine(void) {
    MotorControl();
    switch (shape_selection) {
    case CIRCLE:
        Circle();
        break;
    case FIGURE_EIGHT:
        Figure_Eight();
        break;
    case TRIANGLE:
        Triangle();
        break;
    case STOP:
        L_speed = ZERO_POWER;
        R_speed = ZERO_POWER;
        break;
    }
}
