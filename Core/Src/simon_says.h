/*
 * simon_says.h
 *
 *  Created on: Dec 18, 2023
 *      Author: DynamicAdaptiveCode
 */

#ifndef SRC_SIMON_SAYS_H_
#define SRC_SIMON_SAYS_H_

#include <stdint.h>

#define MAX_ROUNDS 9
#define NUMBER_CONTROLS 3

typedef enum
{
	INGAME = 0,
	GAME_WON,
	GAME_OVER,
} eState_t;

typedef struct
{
	uint8_t u8Round;
	uint8_t u8RandomNumbers[MAX_ROUNDS];
	uint8_t u8UserInputs[MAX_ROUNDS];
	eState_t eCurrentState;
} sGameData_t;

void SimonSays_Init(sGameData_t* sGame);

#endif /* SRC_SIMON_SAYS_H_ */
