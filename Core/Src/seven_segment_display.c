/*
 * seven_segment_display.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Katharina Peter
 */
#include "seven_segment_display.h"

#define PORT_E_ODR (uint32_t * const) (0x40021000 + 0x14)
#define BITMASK ~0xF580

static const uint32_t u32LookUp[10] = {61824, 40960, 50560, 58624, 46080, 29952, 13696, 57344, 62848, 62720};

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


