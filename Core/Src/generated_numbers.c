/*****************************************************************************************************
  *
  * @file           : generated_numbers.c
  * @brief          : Handles the generation of a new random number and appends it to the history of
  * 				  all previously generated random numbers within a game round.
  *
  * Created by Katharina Peter on 12/18/2023.
  * Copyright @ 2023 Katharina Peter. All rights reserved.
  *
*****************************************************************************************************/


#include "generated_numbers.h"
#include <stdlib.h>
#include <time.h>

static uint8_t generateRandomNumber(void);

/**
 *  @brief: Writes generated number into the sequence of random numbers generated so far in a game round.
 *
 *  @param: u8RandomNumbers: List of all random numbers generated in the game so far.
 *  @param: u8Size: Size of list u8RandomNumbers.
 *  @param: u8Round: Current game round.
 *
 */
void generateNextSequence(uint8_t* u8RandomNumbers, uint8_t u8Size, uint8_t u8Round)
{
	if(u8Round <= u8Size)
	{
		u8RandomNumbers[--u8Round] = generateRandomNumber();
	}
}


/**
 *  @brief: Generates one random number.
 *
 *  @return: Returns one random number.
 *
 */
static uint8_t generateRandomNumber(void)
{
	//srand(0);  TODO set real random seed (timestamp, temperature, ..)
	return rand() % 3;
}







