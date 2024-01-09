/*
 * simon_says.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Katharina Peter
 */

#ifndef SRC_SIMON_SAYS_H_
#define SRC_SIMON_SAYS_H_

#include <stdint.h>

#define MAX_ROUNDS 9

typedef enum
{
	INGAME = 0,
	GAME_WON,
	GAME_OVER,
} eGameState_t;

typedef struct
{
	uint8_t u8Round;
	uint8_t u8RandomNumbers[MAX_ROUNDS];
	uint8_t u8UserInputs[MAX_ROUNDS];
	eGameState_t eCurrentState;
} sGameData_t;

/**
 *  @brief: Initializes and resets all essential game data to start or restart a game.
 *
 *  @param: sGame: Pointer to sGameData_t structure.
 *
 */
void vSimonSays_Init(sGameData_t* sGame);

#endif /* SRC_SIMON_SAYS_H_ */
