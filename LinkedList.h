/*
 * LinkedList.h
 *
 *  Created on: Feb 12, 2021
 *      Author: radcl
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Caller.h"

typedef struct
{
	bool wasMatch;
	int row;
	int col;
	aCall* aCallP;
}Result;

typedef struct
{
	struct LLNode* next;
	struct LLNode* prev;
	Result* payP;
}LLNode;

LLNode* makeEmptyLinkedList();
void savePayload(LLNode* lp, Result* mp);
bool isEmpty(LLNode* lp);
void printHistory(LLNode* hp);

#endif /* LINKEDLIST_H_ */
