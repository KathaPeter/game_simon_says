/*****************************************************************************************************
  *
  * @file           : generated_numbers.c
  * @brief          : handles the generation of a new random number and appends it to the history of
  * 				  all previously generated random numbers within a game round.
  *
  * Created by Katharina Peter on 12/17/2023.
  * Copyright @ 2023 Katharina Peter. All rights reserved.
  *
*****************************************************************************************************/
#include "seven_segment_display.h"

#define PORT_E_ODR (uint32_t * const) (0x40021000 + 0x14)
#define BITMASK ~0xF580

static const uint32_t u32LookUp[10] = {0xF180, 0xA000, 0xC580, 0xE500, 0xB400, 0x7500, 0x3580, 0xE000, 0xF580, 0xF500};

int8_t s8Segment_SetDisplay(uint8_t u8Number)
{
	if(u8Number > 9)
	{
		return -1;
	}

    uint32_t const u32MaskedNumber = *PORT_E_ODR & BITMASK;
    *PORT_E_ODR = u32LookUp[u8Number] | u32MaskedNumber;

    return 0;
}


