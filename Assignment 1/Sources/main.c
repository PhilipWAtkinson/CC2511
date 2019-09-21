/* ###################################################################
**     Filename    : main.c
**     Project     : Assignment 1
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-09-02, 18:03, # CodeGen: 0
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
#include "Input.h"
#include "BitIoLdd1.h"
#include "Logic1.h"
#include "BitIoLdd2.h"
#include "Logic2.h"
#include "BitIoLdd3.h"
#include "Logic3.h"
#include "BitIoLdd4.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
int counter = 1;
/*void logicoutput(a,b,c){
	Logic1_SetVal(a);
	Logic2_SetVal(b);
	Logic3_SetVal(c);
}
*/
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
	  while(Input_GetVal() == 1){
		  counter = counter + 1;
		  if(counter > 6){
			  counter = 1;
		  }
		  Logic1_SetVal();
		  Logic2_SetVal();
		  Logic3_SetVal();
	  }
	  while(Input_GetVal() == 0){
		  if(counter == 1){
			  Logic1_SetVal();
			  Logic2_ClrVal();
			  Logic3_SetVal();
		  }
		  if(counter == 2){
			  Logic1_ClrVal();
			  Logic2_ClrVal();
			  Logic3_SetVal();
		  }
		  if(counter == 3){
			  Logic1_SetVal();
			  Logic2_SetVal();
			  Logic3_ClrVal();
		  }
		  if(counter == 4){
			  Logic1_ClrVal();
			  Logic2_SetVal();
			  Logic3_ClrVal();
		  }
		  if(counter == 5){
			  Logic1_SetVal();
			  Logic2_ClrVal();
			  Logic3_ClrVal();
		  }
		  if(counter == 6){
			  Logic1_ClrVal();
			  Logic2_ClrVal();
			  Logic3_ClrVal();
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
