/*
 * measure_distance.c
 *
 *  Created on: Feb 22, 2024
 *      Author: Radwan
 */

#include "HAL/lcd.h"
#include "HAL/US.h"
#include "Atmega32_Registers.h"

int main(void){

	LCD_init();

	SREG |= (1<<7); /*Enable global interrupt I-bit*/
	Ultrasonic_init();
	uint16 distance=0;


	LCD_moveCursor(0,1);
	LCD_displayString("Distance=   cm");

	while(1){


			LCD_moveCursor(0,10);
			distance= Ultrasonic_readDistance();
			LCD_intgerToString(distance);
			if (distance<100)
			{
				LCD_displayCharacter(' ');
			}




	}
}

