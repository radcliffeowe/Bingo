/*
 * Production.c
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#include "Production.h"
#include "Player.h"
#include "Board.h"
#include "Space.h"
#include "Caller.h"
#include "LinkedList.h"

bool production(int argc, char* argv[])
{
	bool answer = true;
	int nCalls = -1;
	if(argc <=1) //no interesting information
			{
				puts("Didn't find any arguments.");
				fflush(stdout);
				answer = false;
			}
			else //there is interesting information
			{
				printf("Found %d arguments.\n", argc);
				fflush(stdout);
				long aL=-1L;


				for(int i = 1; i<argc; i++) //don't want to read argv[0]
				{//argv[i] is a string
					//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
					switch(i)
					{
					case 1:

						//this is the number of calls

						aL= strtol(argv[i], NULL, 10);
						nCalls = (int) aL;
						if(nCalls <0)
						{
							answer = false;
						}
						printf("Number of calls is %d\n",nCalls);fflush(stdout);
						break;

					default:
						puts("Unexpected argument count."); fflush(stdout);
						answer = false;
						break;
					}//end of switch
				}//end of for loop on argument count
				puts("after reading arguments"); fflush(stdout);
			}
			Space** bingoBoard = (Space**) malloc(5*5*sizeof(Space*));
		    init(5, bingoBoard);
		    LLNode* theRecord = makeEmptyLinkedList();
		    printf("Initial Board:\n");fflush(stdout);
		    displayBoard(bingoBoard, 5, 5);
		    aPlayer* thePlayer = (aPlayer*)malloc(sizeof(aPlayer));
	        //the caller is going call some random values
		    for(int i = 0; i<nCalls; i++)
		    {
		    	aCall* theCall = (aCall*)malloc(sizeof(aCall));
		    	call(theCall, thePlayer);
		    	aCall* checkCall = thePlayer->currCall;
		    	Result* theResultP = (Result*)malloc(sizeof(Result));
		    	theResultP->wasMatch = false;
		    	theResultP->aCallP = checkCall;
		    	if(check(checkCall->letter, checkCall->number, bingoBoard))
		    	{
		    		for(int row = 0; row<5; row++)
		    				{
		    					for(int col = 0; col<5; col++)
		    					{
		    						Space* testSpaceP = *(bingoBoard + row*5 +col);
		    						if(testSpaceP->letter == checkCall->letter && testSpaceP->number == checkCall->number)
		    						{
		    							mark(*(bingoBoard + row*5 +col));
		    							theResultP->wasMatch = true;
		    							theResultP->row = row;
		    							theResultP->col = col;
		    							theResultP->aCallP = checkCall;
		    						}
		    					}
		    				}
		    	}
		    	displayBoard(bingoBoard, 5, 5);
		    	savePayload(theRecord, theResultP);
		    	if(isBingo(bingoBoard))
		    	{
		    		printf("BINGO!\n");fflush(stdout);
		    		displayBoard(bingoBoard, 5, 5);
		    		printHistory(theRecord);
		    		return answer;
		    	}

		    }
		    printHistory(theRecord);
		    return answer;
}

				//caller calls
		    	//is it a match?
		    	//show the board
		    	//save result on linked list
		    	//did we win?
