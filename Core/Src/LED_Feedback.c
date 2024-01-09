/*****************************************************************************************************
  *
  * @file           : generated_numbers.c
  * @brief          : Handles various LED light shows.
  *
  * Created by Katharina Peter on 12/18/2023.
  * Copyright @ 2023 Katharina Peter. All rights reserved.
  *
*****************************************************************************************************/

#include "LED_Feedback.h"

#define PORT_F_ODR (uint32_t * const) (0x40021400 + 0x14)
#define BITMASK ~0x07

/**
 *  @brief: Shows the LED sequence for the current game round.
 *
 *  @param: psLED: Allows access to the characteristics of each individual LED.
 *  @param: u8RandomNumbers: Sequence of numbers the LED sequence for the current game round.
 *  @param: u8Round: Current game round.
 *
 */
void showGeneratedNumbers(sLED_t* psLED, uint8_t* u8RandomNumbers, uint8_t u8Round)
{
	uint8_t u8LED;
	for(uint8_t i = 0; i < u8Round; ++i)
	{
		u8LED = u8RandomNumbers[i];
		HAL_Delay(100);
		HAL_GPIO_WritePin(psLED[u8LED].LED_Port, psLED[u8LED].u16LED_PIN, GPIO_PIN_SET);
		HAL_Delay(400);
		HAL_GPIO_WritePin(psLED[u8LED].LED_Port, psLED[u8LED].u16LED_PIN, GPIO_PIN_RESET);
	}
}

/**
 *  @brief: LED light show in the event of a victory.
 *
 */
void showVictory(void)
{
	uint32_t u32MaskedNumber;

	for(uint8_t i = 0; i < 3; ++i)
	{
		for(uint8_t y = 0; y <= 2; ++y)
		{
			u32MaskedNumber = *PORT_F_ODR & BITMASK;
			*PORT_F_ODR = (1 << y) | u32MaskedNumber;
			HAL_Delay(100);
		}
	}
	u32MaskedNumber = *PORT_F_ODR & BITMASK;
	*PORT_F_ODR = u32MaskedNumber;
}

/**
 *  @brief: LED light show in the event of a game over.
 *
 */
void showLED_GameOver(void)
{
		uint32_t u32MaskedNumber;

		for(uint8_t y = 0; y <= 2; ++y)
		{
			u32MaskedNumber = *PORT_F_ODR & BITMASK;
			*PORT_F_ODR = 0x07 | u32MaskedNumber;
			HAL_Delay(200);
			*PORT_F_ODR = 0x00 | u32MaskedNumber;
			HAL_Delay(200);
		}
}

/**
 *  @brief: Handles the illumination in the length of 200ms of an addressed individual LED.
 *
 *	@param: u8LED: LED, which should light up.
 */
void showLED_ButtonPress(void* const pvIndex)
{
	if(pvIndex != NULL)
	{
		uint8_t u8LED_index = 0x01 << *(uint8_t*)pvIndex;
		uint32_t u32MaskedNumber;

		u32MaskedNumber = *PORT_F_ODR & BITMASK;
		*PORT_F_ODR = u8LED_index | u32MaskedNumber;
		HAL_Delay(200);
		*PORT_F_ODR = 0x00 | u32MaskedNumber;
	}
}



