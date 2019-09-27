/* ###################################################################
**     Filename    : main.c
**     Project     : Lab 7
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-09-21, 07:04, # CodeGen: 0
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
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
#include "TU1.h"
#include "Blue.h"
#include "PwmLdd1.h"
#include "Red.h"
#include "PwmLdd3.h"
#include "Green.h"
#include "PwmLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "stdio.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	char input [20];
 	volatile int redpwm = 0;
	volatile int greenpwm = 0;
	volatile int bluepwm = 0;
	int index;
/*-----------------------------------------------------------------------------------------------------------*/
	void initialdisplay(void){
	  Term1_MoveTo(0,0);
	     Term1_Cls(); /*clear terminal and move cursor to top left*/
	     for(index = 0;index<60;index++){
	   	  Term1_SendChar('-');      /* Build the display */
	     }

	     Term1_MoveTo(5,1);
	     Term1_SendStr("Status");

	     Term1_MoveTo(33,1);
	     Term1_SendStr("How to use");

	     Term1_MoveTo(20,4);
	     Term1_SendStr("'Red n' sets red to n out 255");

	     Term1_MoveTo(4,4);
	     Term1_SendStr("Red:");

	     Term1_MoveTo(9,4);
	     Term1_SendStr("---");

	     Term1_MoveTo(20,7);
	     Term1_SendStr("'Green n' sets green to n out 255");

	     Term1_MoveTo(2,7);
	     Term1_SendStr("Green:");

	     Term1_MoveTo(9,7);
	     Term1_SendStr("---");

	     Term1_MoveTo(20,10);
	     Term1_SendStr("'Blue n' sets blue to n out 255");

	     Term1_MoveTo(3,10);
	     Term1_SendStr("Blue:");

	     Term1_MoveTo(9,10);
	     Term1_SendStr("---");


	     for(index = 2;index<12;index++){
	   	  Term1_MoveTo(0,index);
	   	  Term1_SendChar('|');
	   	  Term1_MoveTo(15,index);
	   	  Term1_SendChar('|');
	   	  Term1_MoveTo(60,index);
	   	  Term1_SendChar('|');
	     }
	     Term1_MoveTo(0,12);
	     for(index = 0;index<60;index++){
	   	  Term1_SendChar('-');
	     }

	     Term1_SendChar('\n');
	     Term1_SendChar('\r');
	     Term1_SendStr("Note: Case sensitive");
	     Term1_SendChar('\n');
	     Term1_SendChar('\r');
	     Term1_SendStr("Command Prompt:");
	     Term1_MoveTo(0,19);
	     Term1_SendStr("The command prompt section is cleared after each input");
	     Term1_MoveTo(0,15);
	}
/*------------------------------------------------------------------------------------*/
	void delay(int time){
		int counter;
		  for(counter = 0; counter <time; counter++){
		  }
	}
/*---------------------------------------------------------------------------------------*/
	void redinput(redpwm){
		  if(redpwm<0||redpwm>255){
			 Term1_SendStr("Have I seen you at Total Tools before? ..... put something better in.");
			 Term1_SendChar('\n');
			 Term1_SendChar('\r');
			 delay(4000000);
		  }
		  else{
		  Term1_SendStr("Setting red duty cycle to ");
		  Term1_SendNum(redpwm);
		  Term1_SendStr(" out of 255");
		  Term1_SendChar('\n');
		  Term1_SendChar('\r');
		  delay(3500000);
		  Red_SetRatio8(redpwm);
		  if(redpwm>=100){
			  Term1_MoveTo(9,4);
			  Term1_SendNum(redpwm);
			  Term1_MoveTo(0,16);
		  }
		  if(redpwm<100 && redpwm>9){
			  Term1_MoveTo(9,4);
			  Term1_SendNum(redpwm);
			  Term1_SendChar('-');
			  Term1_MoveTo(0,16);
		  }
		  if(redpwm<=9){
			  Term1_MoveTo(9,4);
			  Term1_SendNum(redpwm);
			  Term1_SendStr("--");
			  Term1_MoveTo(0,16);
		  }
		  }
	}
/*---------------------------------------------------------------------------------------*/
	void greeninput(greenpwm){
		  if(greenpwm<0||greenpwm>255){
			 Term1_SendStr("This is an LED, not a solar panel, it gives off light, not absorb it!");
			 Term1_SendChar('\n');
			 Term1_SendChar('\r');
			 delay(10000000);
		  }
		  else{
		  Term1_SendStr("Setting green duty cycle to ");
		  Term1_SendNum(greenpwm);
		  Term1_SendStr(" out of 255");
		  Term1_SendChar('\n');
		  Term1_SendChar('\r');
		  delay(3500000);
		  Green_SetRatio8(greenpwm);
		  if(greenpwm>=100){
			  Term1_MoveTo(9,7);
			  Term1_SendNum(greenpwm);
			  Term1_MoveTo(0,16);
		  }
		  if(greenpwm<100 && greenpwm>9){
			  Term1_MoveTo(9,7);
			  Term1_SendNum(greenpwm);
			  Term1_SendChar('-');
			  Term1_MoveTo(0,16);
		  }
		  if(greenpwm<=9){
			  Term1_MoveTo(9,7);
			  Term1_SendNum(greenpwm);
			  Term1_SendStr("--");
			  Term1_MoveTo(0,16);
		  }
		  }
	}
/*------------------------------------------------------------------------------------------*/
	void blueinput(bluepwm){
		  if(bluepwm<0||bluepwm>255){
			 Term1_SendStr("You can't use a duty cycle like that bunge");
			 Term1_SendChar('\n');
			 Term1_SendChar('\r');
			 delay(3500000);
		  }
		  else{
		  Term1_SendStr("Setting blue duty cycle to ");
		  Term1_SendNum(bluepwm);
		  Term1_SendStr(" out of 255");
		  Term1_SendChar('\n');
		  Term1_SendChar('\r');
		  delay(3500000);
		  Blue_SetRatio8(bluepwm);
		  if(bluepwm>=100){
			  Term1_MoveTo(9,10);
			  Term1_SendNum(bluepwm);
			  Term1_MoveTo(0,16);
		  }
		  if(bluepwm<100 && bluepwm>9){
			  Term1_MoveTo(9,10);
			  Term1_SendNum(bluepwm);
			  Term1_SendChar('-');
			  Term1_MoveTo(0,16);
		  }
		  if(bluepwm<=9){
			  Term1_MoveTo(9,10);
			  Term1_SendNum(bluepwm);
			  Term1_SendStr("--");
			  Term1_MoveTo(0,16);
		  }
		  }
	}

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */







initialdisplay();
 for(;;) {
 /*Read input from user and display back what they entered*/
	  Term1_ReadLine(&input);
	  Term1_SendStr("Your input: ");
	  Term1_SendStr(&input);
	  Term1_SendChar('\n');
	  Term1_SendChar('\r');
	  Term1_SendStr("Output: ");
/*Handle different inputs*/
	  if(sscanf(input, "Red %i", &redpwm) == 1){
		  redinput(redpwm);
	  }
	  if(sscanf(input, "Green %i", &greenpwm) == 1){
		  greeninput(greenpwm);
	 	  }
	  if(sscanf(input, "Blue %i", &bluepwm) == 1){
		  blueinput(bluepwm);
	  }
	  if(sscanf(input, "Red %i", &redpwm) == 0 && sscanf(input, "Green %i", &greenpwm) == 0 && sscanf(input, "Blue %i", &bluepwm) == 0){
		  Term1_SendStr("Come on Bussie, the program can't handle that");
		  Term1_SendChar('\n');
		  Term1_SendChar('\r');
		  delay(4500000);
	  }
  /*Clear command prompt section of display for next entry*/
	  Term1_MoveTo(0,17);
	  Term1_EraseLine();
	  Term1_MoveTo(0,16);
	  Term1_EraseLine();
	  Term1_MoveTo(0,15);
	  Term1_EraseLine();
	  Term1_MoveTo(0,15);
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
