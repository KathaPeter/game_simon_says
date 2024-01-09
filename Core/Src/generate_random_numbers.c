/*****************************************************************************************************
  *
  * @file           : generated_numbers.c
  * @brief          : Generates a random number.
  *
  * Created by Katharina Peter on 12/18/2023.
  * Copyright @ 2023 Katharina Peter. All rights reserved.
  *
*****************************************************************************************************/


#include "generate_random_numbers.h"

#include <stdlib.h>
#include <time.h>

uint8_t u8GenerateRandomNumber(void)
{
	//srand(0);  TODO set real random seed (timestamp, temperature, ..)
	return rand() % 3;
}







