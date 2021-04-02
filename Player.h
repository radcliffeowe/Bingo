/*
 * Player.h
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdbool.h>
#include <stdio.h>
#include "Board.h"
#include "Space.h"
#include "Caller.h"

typedef struct
{
	aCall* currCall;
}aPlayer;

void call(aCall*, aPlayer*);

#endif /* PLAYER_H_ */
