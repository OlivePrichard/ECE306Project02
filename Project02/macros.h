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

#endif /* MACROS_H_ */
