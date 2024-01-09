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

#define PORT_F_ODR (uint32_t* const) (0x40021400 + 0x14)
#define BITMASK ~0x07

void vLEDFeedback_ShowGeneratedNumbers(sLED_t *psLED, uint8_t *u8RandomNumbers,
		uint8_t u8Round)
{
	uint8_t u8LED;
	for (uint8_t i = 0; i < u8Round; ++i)
	{
		u8LED = u8RandomNumbers[i];
		HAL_Delay(100);
		HAL_GPIO_WritePin(psLED[u8LED].LED_Port, psLED[u8LED].u16LED_PIN,
				GPIO_PIN_SET);
		HAL_Delay(400);
		HAL_GPIO_WritePin(psLED[u8LED].LED_Port, psLED[u8LED].u16LED_PIN,
				GPIO_PIN_RESET);
	}
}

void vLEDFeedback_ShowVictory(void)
{
	uint32_t u32MaskedNumber;

	for (uint8_t i = 0; i < 3; ++i)
	{
		for (uint8_t y = 0; y <= 2; ++y)
		{
			u32MaskedNumber = *PORT_F_ODR & BITMASK;
			*PORT_F_ODR = (1 << y) | u32MaskedNumber;
			HAL_Delay(100);
		}
	}
	u32MaskedNumber = *PORT_F_ODR & BITMASK;
	*PORT_F_ODR = u32MaskedNumber;
}

void vLEDFeedback_ShowGameOver(void)
{
	uint32_t u32MaskedNumber;

	for (uint8_t y = 0; y <= 2; ++y)
	{
		u32MaskedNumber = *PORT_F_ODR & BITMASK;
		*PORT_F_ODR = 0x07 | u32MaskedNumber;
		HAL_Delay(200);
		*PORT_F_ODR = 0x00 | u32MaskedNumber;
		HAL_Delay(200);
	}
}

void vLEDFeedback_ShowLED(uint8_t u8LEDIndex)
{
	uint8_t u8LED_index = 0x01 << u8LEDIndex;
	uint32_t u32MaskedNumber = *PORT_F_ODR & BITMASK;
	*PORT_F_ODR = u8LED_index | u32MaskedNumber;
	HAL_Delay(200);
	*PORT_F_ODR = 0x00 | u32MaskedNumber;
}

