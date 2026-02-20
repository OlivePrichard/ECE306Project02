/*
 * macros.h
 *
 *  Created on: Feb 9, 2026
 *      Author: Olive Prichard
 */
#include "msp430.h"
#include "functions.h"
#include "globals.h"
#include "LCD.h"
#include "ports.h"

#ifndef MACROS_H_
#define MACROS_H_


#define ALWAYS                  (1)
#define RESET_STATE             (0)
#define RED_LED              (0x01) // RED LED 0
#define GRN_LED              (0x40) // GREEN LED 1
#define TEST_PROBE           (0x01) // 0 TEST PROBE
#define TRUE                 (0x01) //

#define USE_GPIO             (0x00)
#define USE_SMCLK            (0x01)

#define SELECTION            (0x00)
#define DELAY                (0x01)
#define RUNNING              (0x02)

#define SELECTION_COLUMN     (0x00)
#define CIRCLE               (0x01)
#define FIGURE_EIGHT         (0x02)
#define TRIANGLE             (0x03)
#define STOP                 (0x04)

#define LOW                  (0x00)
#define HIGH                 (0x01)

#define CIRCLE_INNER           (15)
#define CIRCLE_OUTER          (100)
#define FIGURE_INNER           (10)
#define FIGURE_OUTER          (100)
#define PIVOT_INNER             (0)
#define PIVOT_OUTER           (100)
#define STRAIGHT_SPEED        (100)

#define CIRCLE_TIMING         (1500)
#define FIGURE_EIGHT_TIMING   (480)
#define TRIANGLE_STRAIGHT     (100)
#define TRIANGLE_TURN         (140)

#define TURNING_RIGHT        (0x00)
#define TURNING_LEFT         (0x01)

#define STRAIGHT             (0x00)
#define PIVOT                (0x01)

#define ZERO_POWER              (0)

#endif /* MACROS_H_ */
