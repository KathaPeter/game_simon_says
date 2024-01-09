/*****************************************************************************************************
  *
  * @file           : generated_numbers.c
  * @brief          : handles the generation of a new random number and appends it to the history of
  * 				  all previously generated random numbers within a game round.
  *
  * Created by Katharina Peter on 12/18/2023.
  * Copyright @ 2023 Katharina Peter. All rights reserved.
  *
*****************************************************************************************************/

#include "simon_says.h"

void SimonSays_Init(sGameData_t* sGame)
{
	sGame->u8Round = 0;
	sGame->eCurrentState = INGAME;
}


