/*
 * LinkedList.c
 *
 *  Created on: Feb 12, 2021
 *      Author: radcl
 */

#include "LinkedList.h"

bool isEmpty(LLNode* lp)
{
	bool ans = false;
	if(lp->payP == (Result*)0)
	{
		ans = true;
	}
	return ans;
}

LLNode* makeEmptyLinkedList()
{
	LLNode* lp = (LLNode*) malloc(sizeof(LLNode));
	lp->next = (struct LLNode*)0;
	lp->prev = (struct LLNode*)0;
	lp->payP = (Result*)0;

	return lp;
}

void savePayload(LLNode* lp, Result* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty(lp))
	{
		lp->payP = mp;
	}
	else
	{
		LLNode* temp = lp;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode* newList = makeEmptyLinkedList();
		newList->payP = mp;
		temp->next = (struct LLNode*)newList;
		newList->prev = (struct LLNode*) temp;
	}
}

void printHistory(LLNode* hp)
{
	puts("Printing history");
	if(hp->payP ==(Result*)0)
		    {
		         puts("Empty list");
		    }
		    else
		    {
		    //traverse the list, printing as we go
	        LLNode* temp = hp;
	        while(temp->next)
	        {
	        	Result* theResultP = temp->payP;
	        	aCall* theCall = theResultP->aCallP;
	        	if(theResultP->wasMatch)
	        	{
	        		printf("The call was %c%d and a match was found in row %d, column %d\n", theCall->letter, theCall->number, theResultP->row, theResultP->col);
	        		fflush(stdout);
	        	}
	        	else
	        	{
	        		printf("The call was %c%d, no match was found\n", theCall->letter, theCall->number);fflush(stdout);
	        	}
	            temp=(LLNode*)temp->next;
	        }
	        Result* finalResultP = temp->payP;
	        aCall* theCall = finalResultP->aCallP;
	        if(temp->payP->wasMatch)
	        {
	        	printf("The call was %c%d and a match was found in row %d, column %d\n", theCall->letter, theCall->number, finalResultP->row, finalResultP->col);
	        	fflush(stdout);
	        }
	        else
	        {
	        	printf("The call was %c%d, no match was found\n", theCall->letter, theCall->number);fflush(stdout);
	        }
	        printf("GAME OVER\n");fflush(stdout);
		    }// SHOULD BE THREE CALLS
}




