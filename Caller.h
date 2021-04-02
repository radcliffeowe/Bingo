/*
 * Caller.h
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#ifndef CALLER_H_
#define CALLER_H_

#include <stdbool.h>

typedef struct
{
	char letter;
	int number;
}aCall;

typedef struct
{
	int maxNumOfCalls;
	bool bingo;
}Caller;

void callBingo();

aCall* randCall();

void maxCalls(int maxCalls, Caller* aCaller);

#endif /* CALLER_H_ */
