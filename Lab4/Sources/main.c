/* ###################################################################
**     Filename    : main.c
**     Project     : Lab4
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-08-24, 05:45, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Blue.h"
#include "BitIoLdd1.h"
#include "Red.h"
#include "BitIoLdd2.h"
#include "Green.h"
#include "BitIoLdd3.h"
#include "AS1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "string.h"
AS1_TComData c;

void send_string(const char *str) {
size_t len, i; // a size_t is an unsigned integer
len = strlen(str); // returns the number of chars in str
byte err; for (i = 0; i < len; i++) { // send this character
	do {
		err = AS1_SendChar(str[i]);
	} while (err != ERR_OK);
}
}







/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  //Enable the port control module
   SIM_SCGC5 |= 0x3E00;
   //Initialise LEDs to off
   Red_SetVal();
   Green_SetVal();
   Blue_SetVal();
   /* Write your code here */
   for(;;) {
 	  if(AS1_RecvChar(&c) == ERR_OK){
 	  if (c == 'r'){
       //Red
       Red_NegVal();
       send_string("Red LED toggled\n\r");
 	  }
 	  if (c == 'b'){
       //Blue
       Blue_NegVal();
       send_string("Blue LED toggled\n\r");
 	  }
 	  if (c == 'g'){
       //Green
       Green_NegVal();
       send_string("Green LED toggled\n\r");
 	  }
 	  if (c == 'o'){
 		  //turn all off
		 Blue_SetVal();
		 Red_SetVal();
		 Green_SetVal();
		 send_string("All LEDs turned off\n\r");
 	  }
 	  }
   }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
