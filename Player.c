/*
 * Player.c
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#include "Player.h"

void call(aCall* theCall, aPlayer* thePlayer)
{
	theCall->letter = 'A'+(rand()%26);
	theCall->number = (rand()%9);
	if(65<= theCall->letter && theCall->letter <=90 && 0<= theCall->number && theCall->number<=9)
	{
	thePlayer->currCall = theCall;
	printf("The call is %c%d\n", theCall->letter, theCall->number);fflush(stdout);
	}
	else
	{
		printf("Invalid call, please pick a new ball\n");fflush(stdout);
	}
}
