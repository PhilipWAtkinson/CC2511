/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MK20D5.h"
#include "MK20D5_simple.h"

static int i = 0;

int main(void)
{
	//Enable the port control module
	SIM_SCGC5 |= 0x300;

	//Initialise LEDs
	PORTC_PCR3 = 0x100;
	PORTD_PCR4 = 0x100;
	PORTA_PCR2 = 0x100;
	GPIOC_PDDR = (1<<3);
	GPIOD_PDDR = (1<<4);
	GPIOA_PDDR = (1<<2);

	int counter;
	for (counter = 0; counter < 2000000; counter++) {
	    Set_LED(1,0,0); //RED
				}
	for (counter = 0; counter < 2000000; counter++) {
		Set_LED(0,1,0); //GREEN
					}
	for (counter = 0; counter < 2000000; counter++) {
		Set_LED(0,0,1); //BLUE
					}
	for (counter = 0; counter < 2000000; counter++) {
		Set_LED(1,1,0); //YELLOW
					}
	for (counter = 0; counter < 2000000; counter++) {
		Set_LED(1,0,1); //PURPLE
					}
	for (counter = 0; counter < 2000000; counter++) {
		Set_LED(0,1,1); //CYAN
					}
	for (counter = 0; counter < 2000000; counter++) {
		Set_LED(1,1,1); //WHITE
					}

    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
void Set_LED(R,G,B)
{
	if(R==0)
	{
		GPIOC_PDOR = (1<<3);
	}
	else
	{
		GPIOC_PDOR = 0;
	}
	if(G==0)
	{
		GPIOD_PDOR = (1<<4);
	}
	else
	{
		GPIOD_PDOR = 0;
	}
	if(B==0)
	{
		GPIOA_PDOR = (1<<2);
	}
	else
	{
		GPIOD_PDOR = 0;
	}

}
