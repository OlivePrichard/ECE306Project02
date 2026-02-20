//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//  Jim Carlson
//  Jan 2023
//  Built with Code Composer Version: CCS12.4.0.00007_win64
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  <string.h>
#include  "macros.h"

// Function Prototypes
//void main(void);
//void Init_Conditions(void);
//void Display_Process(void);
//void Init_LEDs(void);
//void Carlson_StateMachine(void);


//void main(void){
void main(void){
//    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    shape_selection = CIRCLE;

//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
//
//------------------------------------------------------------------------------
  PM5CTL0 &= ~LOCKLPM5;
// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings

  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_Timers();                       // Initialize Timers
  Init_LCD();                          // Initialize LCD
//  enable_backlight();
//P2OUT &= ~RESET_LCD;
  // Place the contents of what you want on the display, in between the quotes
// Limited to 10 characters per line
  strcpy(display_line[0], "  SELECT  ");
  strcpy(display_line[1], "X CIRCLE  ");
  strcpy(display_line[2], "  FIGURE-8");
  strcpy(display_line[3], "  TRIANGLE");
  display_changed = TRUE;
//  Display_Update(0,0,0,0);

  wheel_move = 0;
  forward = TRUE;

//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  unsigned int prev_time = Time_Sequence;
  while(ALWAYS) {                      // Can the Operating system run
      if (prev_time != Time_Sequence) {
          prev_time = Time_Sequence;
          timing++;
      }
      if (start_sequence == DELAY && timing > 300) {
          timing = 0;
          start_sequence = RUNNING;
      }
      if (start_sequence == RUNNING) {
          Shape_StateMachine();
      }
    Carlson_StateMachine();            // Run a Time Based State Machine
    Switches_Process();                // Check for switch state change
    Display_Process();                 // Update Display
//    P3OUT ^= TEST_PROBE;               // Change State of TEST_PROBE OFF
  }
//------------------------------------------------------------------------------

}
