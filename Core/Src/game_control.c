/*****************************************************************************************************
 *
 * @file           : game_control.c
 * @brief          : The present implementation is responsible for the handling and processing
 * 				  of user inputs via buttons, including the debouncing treatment of the buttons.
 *
 * Created by Katharina Peter on 12/18/2023.
 * Copyright @ 2023 Katharina Peter. All rights reserved.
 *
 *****************************************************************************************************/

#include "game_control.h"

/**
 *  @brief: Handles the debouncing of user inputs via buttons and turns on the associated LED corresponding
 *  		to the pressed button. This function is only exited, when a button has been successfully debounced.
 *
 *  @param: psButtons: Allows access to the characteristics of each individual button.
 *
 *  @returns:  Index of pressed button.
 */
static int8_t s8GetDebouncedButton(sButton_t* psButtons);

/**
 *  @brief: Checks whether a button has been successfully debounced or not.
 *
 *  @param: psButtons: Allows access to the debounce characteristic of the button.
 *
 *  @returns:  1: Button is succesfully debounced.
 *  		   0: Button has not yet been debounced.
 */
static uint8_t bCheckButtonDebounced(sButton_t* psButtons);


int8_t s8GameControl_GetUserInput(sButton_t* psButtons, void (*vShowSignalOnButtonPress_Callback)(void*))
{
	int8_t i8IndexPressedButton = s8GetDebouncedButton(psButtons);
	vShowSignalOnButtonPress_Callback(&i8IndexPressedButton);
	return i8IndexPressedButton;
}

static int8_t s8GetDebouncedButton(sButton_t* psButtons)
{
	do
	{
		if (HAL_GPIO_ReadPin(psButtons[0].BTN_Port, psButtons[0].u16BTN_PIN)
				== GPIO_PIN_SET)
		{
			if (bCheckButtonDebounced(&psButtons[0]) != (0))
			{
				return 0;
			}
			psButtons[1].debounce = 0;
			psButtons[2].debounce = 0;
		}
		else
		{
			psButtons[0].debounce = 0;
		}

		if (HAL_GPIO_ReadPin(psButtons[1].BTN_Port, psButtons[1].u16BTN_PIN)
				== GPIO_PIN_SET)
		{
			if (bCheckButtonDebounced(&psButtons[1]) != (0))
			{
				return 1;
			}
			psButtons[0].debounce = 0;
			psButtons[2].debounce = 0;
		}
		else
		{
			psButtons[1].debounce = 0;
		}

		if (HAL_GPIO_ReadPin(psButtons[2].BTN_Port, psButtons[2].u16BTN_PIN)
				== GPIO_PIN_SET)
		{
			if (bCheckButtonDebounced(&psButtons[2]) != (0))
			{
				return 2;
			}
			psButtons[0].debounce = 0;
			psButtons[1].debounce = 0;
		}
		else
		{
			psButtons[2].debounce = 0;
		}

	} while (1);
}

static uint8_t bCheckButtonDebounced(sButton_t* psButtons)
{
	if (++psButtons->debounce >= 10)
	{
		//reset and return index of successfully debounced Button
		psButtons->debounce = 0;
		return 1;
	}
	return 0;
}


