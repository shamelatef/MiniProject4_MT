/*
 * US.c
 *
 *  Created on: Feb 22, 2024
 *      Author: Radwan
 */

#include "US.h"
#include "../MCAL/icu.h"
#include "../MCAL/gpio.h"
#include <util/delay.h>

uint16 g_timeHigh = 0;
uint8 g_edgeCount = 0;

void Ultrasonic_init(void){

	ICU_ConfigType Config = {F_CPU_8,RAISING};
	ICU_init(&Config);
	ICU_setCallBack(Ultrasonic_edgeProcessing);


	GPIO_setupPinDirection(US_TRIGGER_PIN_PORTID,US_TRIGGER_PINID,PIN_OUTPUT);
}


void Ultrasonic_Trigger(void){

	GPIO_writePin(US_TRIGGER_PIN_PORTID,US_TRIGGER_PINID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(US_TRIGGER_PIN_PORTID,US_TRIGGER_PINID,LOGIC_LOW);

}



uint16 Ultrasonic_readDistance(void){
	uint16 a_distance;
	Ultrasonic_Trigger();

	//Ultrasonic_Trigger();

	a_distance = 0.017*g_timeHigh;

	return a_distance;

}



void Ultrasonic_edgeProcessing(void){
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		/* Detect rising edge */


		ICU_setEdgeDetectionType(RAISING);
		ICU_clearTimerValue();

		g_edgeCount=0;

	}


}


