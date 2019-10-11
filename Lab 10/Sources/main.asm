/**
 * CC2511 Lab 10
 */

	.text 			/* The "text" section of the executable is where code is placed. */
	.align	2 		/* Make sure the starting address is a multiple of 2. */
	.global	main 	/* Declare "main" as a global symbol (callable from other files). */
  .syntax unified /* Enable Thumb2 instruction set support */

/* Main function */
main:
	push {lr}  /* The return address is in the "link register" (lr). Preserve it by pushing it to the stack. */

	/* Write your code here */

	ldr r1, =0x40048038 /*Set SIM_SCCGC5 to 0x3e00 in r1*/
	movw r2, #0x3e00 /**/
	str r2, [r1] /**/


/*initialise blue*/
	ldr r1, =0x40049008 /*Set Port A to 0x100 in r2*/
	movw r2, #0x100 /**/
	str r2, [r1] /**/

	ldr r1, =0x400FF014 /*Set GPIOC_PDOR to 0x8*/
	movw r2, #0x4 /**/
	str r2, [r1] /**/

	ldr r1, =0x400FF000 //
	movw r2, #1<<2 //
	str r2, [r1] // Turn blue off

mov r2, #1

mainloop:
	add r2, #1

	ldr r1, =500000

blinkloop1: //
	sub r1, #1 //
	cmp r1, #0 //
	bne blinkloop1 // Wait

blueon:
	ldr r3, =0x400FF000 //
	ldr r4, =0 //
	str r4, [r3] // Turn blue on

		ldr r1, =500000

blinkloop2: //
	sub r1, #1 //
	cmp r1, #0 //
	bne blinkloop2 // Wait

blueoff:
	ldr r3, =0x400FF000 //
	ldr r4, =100 //
	str r4, [r3] // Turn blue off

b mainloop





	pop {pc}  /* Return from this function, by popping the return address into the program counter (pc) */
