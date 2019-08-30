/* ###################################################################
**     Filename    : main.c
**     Project     : Lab 5
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-08-30, 06:16, # CodeGen: 0
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
#include "AS1.h"
#include "ASerialLdd1.h"
#include "TU1.h"
#include "Input.h"
#include "BitIoLdd1.h"
#include "Blue.h"
#include "BitIoLdd2.h"
#include "Red.h"
#include "PwmLdd1.h"
#include "Green.h"
#include "PwmLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
AS1_TComData c;
int Red_duty = 0;
int Green_duty = 0;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
 for(;;) {
	  if (AS1_RecvChar(&c) == ERR_OK){
/*		  if (c == ' '){
			 PORTC_PCR0 ^= 0b00000010;
		  }
		  */
			 if (c == 'r'){
			  Red_duty = Red_duty+13107;
		 }
			 if (c == 'R'){
			  Red_duty = Red_duty-13107;
		 }
			 if (Red_duty < 0){
				Red_duty = 0;
	     }
			 if (Red_duty > 65535){
				Red_duty = 65535;
		 }
			  Red_SetRatio16(Red_duty);
		 if (c == 'g'){
			Green_duty = Green_duty+13107;
	 }
		 if (c == 'G'){
			Green_duty = Green_duty-13107;
	 }
		 if (Green_duty < 0){
			Green_duty = 0;
     }
		 if (Green_duty > 65535){
			Green_duty = 65535;
	 }
		 Green_SetRatio16(Green_duty);
	}
 }
/*		  if (Input_GetVal() == 1){
			 Blue_ClrVal();
		  }
		  if(Input_GetVal() == 0){
			  Blue_SetVal();
		  }
*/


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
