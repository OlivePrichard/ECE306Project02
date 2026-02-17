/*
 * ports.c
 *
 *  Created on: Feb 9, 2026
 *      Author: Olive Prichard
 */

#include "macros.h"

void Init_Ports(void) {
    Init_Port1();
    Init_Port2();
    Init_Port3();
    Init_Port4();
    Init_Port5();
    Init_Port6();
}

void Init_Port1(void) {    // Configure Port 1

    P1SEL0 =   0x00;       // GPIO
    P1SEL0 =   0x00;

    P1DIR  =   0x00;       // INPUT
    P1OUT  =   0x00;       // LOW

    // Pin 0
    P1SEL0 &= ~RED_LED;    // GPIO
    P1SEL1 &= ~RED_LED;
    P1OUT  &= ~RED_LED;    // LOW
    P1DIR  |=  RED_LED;    // OUTPUT

    // Pin 1
    P1SELC |=  V_A1_SEEED; // ADC

    // Pin 2
    P1SELC |=  V_DETECT_L; // ADC

    // Pin 3
    P1SELC |=  V_DETECT_R; // ADC

    // Pin 4
    P1SELC |=  V_A4_SEEED; // ADC

    // Pin 5
    P1SELC |=  V_THUMB;    // ADC

    // Pin 6
    P1SEL0 |=  UCA0RXD;    // UART 0 RX
    P1SEL1 &= ~UCA0RXD;

    // Pin 7
    P1SEL0 |=  UCA0TXD;    // UART 0 TX
    P1SEL1 &= ~UCA0TXD;
}

void Init_Port2(void) {     // Configure Port 2

    P2SEL0 =   0x00;        // GPIO
    P2SEL0 =   0x00;

    P2DIR  =   0x00;        // INPUT
    P2OUT  =   0x00;        // LOW

    // Pin 0
    P2SEL0 &= ~RESET_LCD;   // GPIO
    P2SEL1 &= ~RESET_LCD;
    P2OUT  &= ~RESET_LCD;   // LOW
    P2DIR  |=  RESET_LCD;   // OUTPUT

    // Pin 1
    P2SEL0 &= ~CHECK_BAT;   // GPIO
    P2SEL1 &= ~CHECK_BAT;
    P2OUT  &= ~CHECK_BAT;   // LOW
    P2DIR  |=  CHECK_BAT;   // OUTPUT

    // Pin 2
    P2SEL0 &= ~IR_LED;      // GPIO
    P2SEL1 &= ~IR_LED;
    P2OUT  &= ~IR_LED;      // LOW
    P2DIR  |=  IR_LED;      // OUTPUT

    // Pin 3
    P2SEL0 &= ~SW2;         // GPIO
    P2SEL1 &= ~SW2;
    P2OUT  |=  SW2;         // PULLUP
    P2DIR  &= ~SW2;         // INPUT
    P2REN  |=  SW2;         // PULLUP ENABLE

    // Pin 4
    P2SEL0 &= ~IOT_RUN_RED; // GPIO
    P2SEL1 &= ~IOT_RUN_RED;
    P2OUT  &= ~IOT_RUN_RED; // LOW
    P2DIR  |=  IOT_RUN_RED; // OUTPUT

    // Pin 5
    P2SEL0 &= ~DAC_ENB;     // GPIO
    P2SEL1 &= ~DAC_ENB;
    P2OUT  |=  DAC_ENB;     // HIGH
    P2DIR  |=  DAC_ENB;     // OUTPUT

    // Pin 6
    P2SEL0 &= ~LFXOUT;      // 32768 XTOL OUT
    P2SEL1 |=  LFXOUT;

    // Pin 7
    P2SEL0 &= ~LFXIN;       // 32768 XTOL IN
    P2SEL1 |=  LFXIN;
}

void Init_Port3(void) {      // Configure Port 3

    P3SEL0 =   0x00;         // GPIO
    P3SEL0 =   0x00;

    P3DIR  =   0x00;         // INPUT
    P3OUT  =   0x00;         // LOW

    // Pin 0
    // TODO: FIX THIS
    P3SEL0 &= ~TEST_PROBE;   // GPIO
    P3SEL1 &= ~TEST_PROBE;
    P3DIR  &= ~TEST_PROBE;   // INPUT

    // Pin 1
    P3SELC |=  OA2O;         // OA20

    // Pin 2
    P3SELC |=  OA2N;         // OA2-

    // Pin 3
    P3SELC |=  OA2P;         // OA2+

    // Pin 4
    // TODO: FIX THIS
    P3SEL0 &= ~SMCLK_OUT;    // GPIO
    P3SEL1 &= ~SMCLK_OUT;
    P3DIR  &= ~SMCLK_OUT;    // INPUT

    // Pin 5
    // TODO: FIX THIS
    P3SEL0 &= ~DAC_CNTL;     // GPIO
    P3SEL1 &= ~DAC_CNTL;
    P3DIR  &= ~DAC_CNTL;     // INPUT

    // Pin 6
    // TODO: FIX THIS
    P3SEL0 &= ~IOT_LINK_GRN; // GPIO
    P3SEL1 &= ~IOT_LINK_GRN;
    P3DIR  &= ~IOT_LINK_GRN; // INPUT

    // Pin 7
    // TODO: FIX THIS
    P3SEL0 &= ~IOT_EN;      // GPIO
    P3SEL1 &= ~IOT_EN;
    P3DIR  &= ~IOT_EN;      // INPUT
}

void Init_Port4(void) {     // Configure Port 4

    P4SEL0 =   0x00;        // GPIO
    P4SEL0 =   0x00;

    P4DIR  =   0x00;        // INPUT
    P4OUT  =   0x00;        // LOW

    // Pin 0
    P4SEL0 &= ~DAC_CNTL1;   // GPIO
    P4SEL1 &= ~DAC_CNTL1;
    P4OUT  &= ~DAC_CNTL1;   // LOW
    P4DIR  |=  DAC_CNTL1;   // OUTPUT

    // Pin 1
    P4SEL0 &= ~SW1;         // GPIO
    P4SEL1 &= ~SW1;
    P4OUT  |=  SW1;         // PULLUP
    P4DIR  &= ~SW1;         // INPUT
    P4REN  |=  SW1;         // PULLUP ENABLE

    // Pin 2
    P4SEL0 |=  UCA1RXD;     // UART 1 RX
    P4SEL1 &= ~UCA1RXD;

    // Pin 3
    P4SEL0 |=  UCA1TXD;     // UART 1 TX
    P4SEL1 &= ~UCA1TXD;

    // Pin 4
    P4SEL0 &= ~UCB1_CS_LCD; // GPIO
    P4SEL1 &= ~UCB1_CS_LCD;
    P4OUT  |=  UCB1_CS_LCD; // HIGH
    P4DIR  |=  UCB1_CS_LCD; // OUTPUT

    // Pin 3
    P4SEL0 |=  UCB1CLK;     // SPI 1 CLK
    P4SEL1 &= ~UCB1CLK;

    // Pin 3
    P4SEL0 |=  UCB1SIMO;    // SPI 1 MOSI
    P4SEL1 &= ~UCB1SIMO;

    // Pin 3
    P4SEL0 |=  UCB1SOMI;    // SPI 1 MISO
    P4SEL1 &= ~UCB1SOMI;
}

void Init_Port5(void) {  // Configure Port 5

    P5SEL0 =   0x00;     // GPIO
    P5SEL0 =   0x00;

    P5DIR  =   0x00;     // INPUT
    P5OUT  =   0x00;     // LOW

    // Pin 1
    P5SELC |=  V_BAT;    // ADC

    // Pin 2
    P5SELC |=  V_5_0;    // ADC

    // Pin 3
    P5SELC |=  V_DAC;    // ADC

    // Pin 4
    P5SELC |=  V_3_3;    // ADC

    // Pin 5
    // TODO: FIX THIS
    P5SEL0 &= ~IOT_BOOT; // GPIO
    P5SEL1 &= ~IOT_BOOT;
    P5DIR  &= ~IOT_BOOT; // INPUT
}

void Init_Port6(void) {      // Configure Port 6

    P6SEL0 =   0x00;         // GPIO
    P6SEL0 =   0x00;

    P6DIR  =   0x00;         // INPUT
    P6OUT  =   0x00;         // LOW

    // Pin 0
    P6SEL0 &= ~LCD_BACKLITE; // GPIO
    P6SEL1 &= ~LCD_BACKLITE;
    P6OUT  &= ~LCD_BACKLITE; // LOW
    P6DIR  |=  LCD_BACKLITE; // OUTPUT

    // Pin 1
    P6SEL0 &= ~R_FORWARD;    // GPIO
    P6SEL1 &= ~R_FORWARD;
    P6OUT  &= ~R_FORWARD;    // LOW
    P6DIR  |=  R_FORWARD;    // OUTPUT

    // Pin 2
    P6SEL0 &= ~R_REVERSE;    // GPIO
    P6SEL1 &= ~R_REVERSE;
    P6OUT  &= ~R_REVERSE;    // LOW
    P6DIR  |=  R_REVERSE;    // OUTPUT

    // Pin 3
    P6SEL0 &= ~L_FORWARD;    // GPIO
    P6SEL1 &= ~L_FORWARD;
    P6OUT  &= ~L_FORWARD;    // LOW
    P6DIR  |=  L_FORWARD;    // OUTPUT

    // Pin 4
    P6SEL0 &= ~L_REVERSE;    // GPIO
    P6SEL1 &= ~L_REVERSE;
    P6OUT  &= ~L_REVERSE;    // LOW
    P6DIR  |=  L_REVERSE;    // OUTPUT

    // Pin 5
    // TODO: FIX THIS
    P6SEL0 &= ~P6_5;         // GPIO
    P6SEL1 &= ~P6_5;
    P6DIR  &= ~P6_5;         // INPUT

    // Pin 6
    P6SEL0 &= ~GRN_LED;      // GPIO
    P6SEL1 &= ~GRN_LED;
    P6OUT  &= ~GRN_LED;      // LOW
    P6DIR  |=  GRN_LED;      // OUTPUT
}
