/*
 * US.h
 *
 *  Created on: Feb 22, 2024
 *      Author: Radwan
 */

#ifndef US_H_
#define US_H_
#include "../std_types.h"
#include "../MCAL/gpio.h"

#define US_TRIGGER_PIN_PORTID PORTB_ID
#define US_TRIGGER_PINID PIN5_ID

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);

#endif /* US_H_ */
