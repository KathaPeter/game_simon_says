/*
 * game_control.h
 *
 *  Created on: Dec 18, 2023
 *      Author: DynamicAdaptiveCode
 */

#ifndef SRC_GAME_CONTROL_H_
#define SRC_GAME_CONTROL_H_

#include <stdint.h>
#include "stm32f7xx_hal.h"

/**
 * @brief no opaque struct for...
 */
typedef struct
{
	GPIO_TypeDef* BTN_Port;
	uint16_t u16BTN_PIN;
	uint8_t debounce;
} sButton_t;

int8_t s8GameControl_GetUserInput(sButton_t* psButtons, void (*vShowSignalOnButtonPress_Callback)(void*));

#endif /* SRC_GAME_CONTROL_H_ */
