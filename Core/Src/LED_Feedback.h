/*
 * game_gui.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Katharina Peter
 */

#ifndef SRC_LED_FEEDBACK_H_
#define SRC_LED_FEEDBACK_H_

#include <stdint.h>
#include "stm32f7xx_hal.h"


typedef struct
{
	GPIO_TypeDef* LED_Port;
	uint16_t u16LED_PIN;
} sLED_t;


void showGeneratedNumbers(sLED_t* psLED, uint8_t* u8RandomNumbers, uint8_t u8Round);
void showVictory();
void showLED_GameOver();
void showLED_ButtonPress(void* const u16Index);

#endif /* SRC_LED_FEEDBACK_H_ */
