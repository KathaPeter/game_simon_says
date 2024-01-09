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

/**
 *  @brief: Shows the LED sequence for the current game round.
 *
 *  @param: psLED: Pointer to array to get all informations of each individual LED.
 *  @param: u8RandomNumbers: Pointer to array to show the LED sequence for the current game round.
 *  @param: u8Round: Current game round.
 *
 */
void vLEDFeedback_ShowGeneratedNumbers(sLED_t* psLED, uint8_t* u8RandomNumbers, uint8_t u8Round);

/**
 *  @brief: LED light show in the event of a victory.
 *
 */
void vLEDFeedback_ShowVictory(void);

/**
 *  @brief: LED light show in the event of a game over.
 *
 */
void vLEDFeedback_ShowGameOver(void);

/**
 *  @brief: Lights up one LED with the duration of 200ms.
 *
 *	@param: u8LEDIndex: Index of LED which should light up.
 */
void vLEDFeedback_ShowLED(uint8_t u8LEDIndex);

#endif /* SRC_LED_FEEDBACK_H_ */
