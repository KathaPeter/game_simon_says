/*
 * game_control.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Katharina Peter
 */

#ifndef SRC_GAME_CONTROL_H_
#define SRC_GAME_CONTROL_H_

#include <stdint.h>
#include "stm32f7xx_hal.h"

/**
 * @brief no opaque struct for all button informations.
 */
typedef struct
{
	GPIO_TypeDef* BTN_Port;
	uint16_t u16BTN_PIN;
	uint8_t debounce;
} sButton_t;

/**
 *  @brief: Waits for user inputs and calls the given callback-function with the index
 *  		of the pressed button.
 *
 *  @param: psButtons: Pointer to array of all buttons.
 *  @param: vShowSignalOnButtonPress_Callback: Callback that gets called for corresponding pressed button.
 *  										   This callback gets passed the index of the pressed button.
 *
 *  @returns:  Index of pressed button.
 */
uint8_t u8GameControl_GetUserInput(sButton_t* psButtons, void (*vShowSignalOnButtonPress_Callback)(uint8_t u8ButtonIndex));

#endif /* SRC_GAME_CONTROL_H_ */
