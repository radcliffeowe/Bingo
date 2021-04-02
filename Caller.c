/*
 * Caller.c
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#include <stdio.h>

#include "Caller.h"

void maxCalls(int calls, Caller* aCaller)
{
	if(calls>0)
	{
		aCaller->maxNumOfCalls = calls;
	}
	else
	{
		printf("please play at least 1 turn\n");fflush(stdout);
	}
}

void callBingo(Caller* aCaller)
{
	aCaller->bingo = true;
}
