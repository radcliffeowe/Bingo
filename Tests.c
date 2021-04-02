/*
 * Tests.c
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#include "Tests.h"
#include "production.h"
#include "Player.h"
#include "production.h"
#include "Board.h"
#include "Space.h"
#include "Caller.h"
#include "LinkedList.h"

bool tests()
{
	bool answer = false;
		bool ok1 = testInit();
		bool ok2 = testCall();
		//bool ok17 = testCallCatchInvalidNumber();
		bool ok4 = testCheck();
		bool ok5 = testCheckWrongLetter();
		bool ok6 = testCheckWrongNumber();
		bool ok7 = testMark();
		bool ok8 = testMaxCalls();
		bool ok9 = testDisplayBoard();
		bool ok16 = testDisplayBoardMarked();
		bool ok10 = testIsBingo();
		bool ok11 = testCallBingo();
		bool ok12 = testIsEmpty();
		bool ok13 = testMakeEmptyLinkedList();
		bool ok14 = testSavePayload();
		bool ok15 = testPrintHistory();
		answer = ok1 && ok2 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12 && ok13 && ok14 && ok15 && ok16;
		return answer;
}

bool testInit()
{
	printf("starting testInitInvalidArg\n");fflush(stdout);
	bool ok = false;
	int totalTrue = 0;
	Space** bingoBoard = (Space**)malloc(25* sizeof(Space*));
	init(5, bingoBoard);
	for(int row = 0; row<5; row++)
		{
			for(int col = 0; col<5; col++)
			{
				Space* testSpaceP = *(bingoBoard + row*5 +col);
				if(65<=(int)testSpaceP->letter && (int)testSpaceP->letter<=90 && 0<=testSpaceP->number && testSpaceP->number<=9 && testSpaceP->row == row && testSpaceP->col == col)
				{
					totalTrue++;
				}
			}
		}

		if(totalTrue == 25)
		{
			ok = true;
			printf("testInit passed \n");fflush(stdout);
		}
		else
		{
			printf("testInit failed\n");fflush(stdout);
		}
	return ok;
}

bool testCall()
{
	printf("starting testCall\n");fflush(stdout);
	bool ok = false;
	aCall testCall = {'A', 1};
	aCall* testCallP = &testCall;
	aPlayer testPlayer;
	aPlayer* testPlayerP = &testPlayer;
	call(testCallP, testPlayerP);
	if(testPlayerP->currCall == testCallP)
	{
		ok = true;
		printf("testCall passed\n");fflush(stdout);
	}
	else
	{
		printf("testCall failed\n");
	}
	return ok;
}

bool testCallCatchInvalidNumber()
{
	printf("starting testCallCatchInvalidNumber\n");fflush(stdout);
	bool ok = false;
	aCall testCall = {'A', 10};
	aCall* testCallP = &testCall;
	aPlayer testPlayer;
	aPlayer* testPlayerP = &testPlayer;
	call(testCallP, testPlayerP);
	printf("Did it display an error message? Enter y if yes.\n");fflush(stdout);
	char a = 'a';
	scanf(" %c", &a);
	if(a == 'y')
	{
		printf("testCallCatchInvalidNumber passed\n");fflush(stdout);
		ok = true;
	}
	else
	{
		printf("testCallCatchInvalidNumber failed\n");fflush(stdout);
	}
	return ok;
}

bool testCheck()
{
	printf("starting testCheck\n");fflush(stdout);
	bool ok = false;
	Space** bingoBoard = (Space**)malloc(25* sizeof(Space*));
	for(int row = 0; row< 5; row++)
			{
				for(int col = 0; col < 5; col++)
				{
					Space* x = (Space*) malloc (sizeof(Space)); //reserve a cardCell on heap
					x->row = row;
					x->col = col;
					x->letter = 'A';
					x->number = 1;
					Space**  thatSpaceP = bingoBoard + row*5 + col; // finds the index for the pointer, nRows is actually nCols
					*thatSpaceP = x; //put its address into bingo card space
				}
			}
	if(check('A', 1, bingoBoard))
	{
		printf("testCheck passed\n");fflush(stdout);
		ok = true;
	}
	else
	{
		printf("testCheck failed\n");fflush(stdout);
	}
	return ok;
}

bool testCheckWrongLetter()
{
	printf("starting testCheckWrongLetter\n");fflush(stdout);
	bool ok = false;
	Space** bingoBoard = (Space**)malloc(25* sizeof(Space*));
	for(int row = 0; row< 5; row++)
			{
				for(int col = 0; col < 5; col++)
				{
					Space* x = (Space*) malloc (sizeof(Space)); //reserve a cardCell on heap
					x->row = row;
					x->col = col;
					x->letter = 'A';
					x->number = 1;
					Space**  thatSpaceP = bingoBoard + row*5 + col; // finds the index for the pointer, nRows is actually nCols
					*thatSpaceP = x; //put its address into bingo card space
				}
			}
	if(check('B', 1, bingoBoard))
	{
		printf("testCheckWrongLetter failed\n");fflush(stdout);
	}
	else
	{
		printf("testCheckWrongLetter passed\n");fflush(stdout);
		ok = true;
	}
	return ok;
}

bool testCheckWrongNumber()
{
	printf("starting testCheckWrongNumber\n");fflush(stdout);
	bool ok = false;
	Space** bingoBoard = (Space**)malloc(25* sizeof(Space*));
	for(int row = 0; row< 5; row++)
			{
				for(int col = 0; col < 5; col++)
				{
					Space* x = (Space*) malloc (sizeof(Space)); //reserve a cardCell on heap
					x->row = row;
					x->col = col;
					x->letter = 'A';
					x->number = 1;
					Space**  thatSpaceP = bingoBoard + row*5 + col; // finds the index for the pointer, nRows is actually nCols
					*thatSpaceP = x; //put its address into bingo card space
				}
			}
	if(check('A', 3, bingoBoard))
	{
		printf("testCheckWrongNumber failed\n");fflush(stdout);
	}
	else
	{
		printf("testCheckWrongNumber passed\n");fflush(stdout);
		ok = true;
	}
	return ok;
}

bool testMark()
{
	bool ok = false;
	printf("starting testMark\n");fflush(stdout);
	Space** bingoBoard = (Space**)malloc(25* sizeof(Space*));
		for(int row = 0; row< 5; row++)
				{
					for(int col = 0; col < 5; col++)
					{
						Space* x = (Space*) malloc (sizeof(Space)); //reserve a cardCell on heap
						x->row = row;
						x->col = col;
						x->letter = 'A';
						x->number = 1;
						Space**  thatSpaceP = bingoBoard + row*5 + col; // finds the index for the pointer, nRows is actually nCols
						*thatSpaceP = x; //put its address into bingo card space
					}
				}
		Space* testSpace = *bingoBoard;
		mark(testSpace);
		if(testSpace->marked == true)
		{
			printf("testMark passed\n");fflush(stdout);
			ok = true;
		}
		else
		{
			printf("testMark failed\n");fflush(stdout);
		}
		return ok;
}

bool testMaxCalls()
{
	printf("starting testMaxCalls\n");fflush(stdout);
	bool ok = false;
	Caller testCaller ={1};
	Caller* testCallerP = &testCaller;
	maxCalls(5, testCallerP);
	if(testCallerP->maxNumOfCalls == 5)
	{
		printf("testMaxCalls passed\n");fflush(stdout);
		ok = true;
	}
	else
	{
		printf("testMaxCalls failed\n");fflush(stdout);
	}
	return ok;
}

bool testDisplayBoard()
{
	printf("starting testDisplayBoard\n");fflush(stdout);
	bool ok = false;
	Space** bingoBoard = (Space**)malloc(25* sizeof(Space*));
	init(5, bingoBoard);
	displayBoard(bingoBoard, 5, 5);
	printf("does it look like a board? Press y if yes\n");fflush(stdout);
	char a = 'a';
	scanf("%c", &a);
	if(a == 'y')
	{
		ok = true;
		printf("testDisplayBoard passed\n");fflush(stdout);
	}
	else
	{
		printf("testDisplayBoard failed\n");fflush(stdout);
	}
	return ok;
}

bool testDisplayBoardMarked()
{
	printf("starting testDisplayBoardMarked\n");fflush(stdout);
		bool ok = false;
		Space** bingoBoard = (Space**)malloc(25* sizeof(Space*));
		init(5, bingoBoard);
		for(int row = 0; row<5; row++)
				{
					for(int col = 0; col<5; col++)
					{
						Space* x = *(bingoBoard + row*5 + col);
						x->marked = true;
					}
				}
		displayBoard(bingoBoard, 5, 5);
		printf("does it look like a fully marked board? Press y if yes\n");fflush(stdout);
		char b = 'a';
		scanf(" %c", &b);
		if(b == 'y')
		{
			ok = true;
			printf("testDisplayBoardMarked passed\n");fflush(stdout);
		}
		else
		{
			printf("testDisplayBoardMarked failed\n");fflush(stdout);
		}
		return ok;
}


bool testIsBingo()
{
	printf("starting testIsBingoNotBingo\n");fflush(stdout);
	bool ok = false;
	Space** bingoBoard = (Space**)malloc(25* sizeof(Space*));
	init(5, bingoBoard);
	Space* v = *(bingoBoard+4);
	v->marked = true;
	Space* w = *(bingoBoard+6);
	w->marked = true;
	Space* x = *(bingoBoard+8);
	x->marked = true;
	Space* y = *(bingoBoard+1);
	y->marked = true;
	Space* z = *(bingoBoard+14);
	z->marked = true;
	displayBoard(bingoBoard, 5, 5);
	if(isBingo(bingoBoard))
	{
		printf("testIsBingoNotBingo failed\n");fflush(stdout);
	}
	else
	{
		ok = true;
		printf("testIsBingoNotBingo passed\n");fflush(stdout);
	}
	return ok;
}

bool testCallBingo()
{
	bool ok = false;
	printf("starting testCallBingo\n");fflush(stdout);
	Caller testCaller = {5, false};
	Caller* testCallerP = &testCaller;
	callBingo(testCallerP);
	if(testCallerP->bingo == true)
	{
		ok = true;
		printf("testCallBingo passed\n");fflush(stdout);
	}
	else
	{
		printf("testCallBingo failed\n");fflush(stdout);
	}
	return ok;
}

bool testIsEmpty()
{
	printf("starting testIsEmpty\n");fflush(stdout);
	bool ok = false;
	LLNode testNode;
	LLNode* testNodeP = &testNode;
	testNodeP->next = (struct LLNode*)0;
	testNodeP->prev = (struct LLNode*)0;
	testNodeP->payP = (Result*)0;
	if(isEmpty(testNodeP))
	{
		ok = true;
		printf("testIsEmpty passed\n");fflush(stdout);
	}
	else
	{
		printf("testIsEmpty failed\n");fflush(stdout);
	}
	return ok;
}

bool testMakeEmptyLinkedList()
{
	printf("starting testMakeEmptyLinkedListOneFieldWithValue\n");fflush(stdout);
	bool ok = false;
	LLNode* testLL = makeEmptyLinkedList();
	LLNode testLLOne;
	LLNode* testLLOneP = &testLLOne;
	testLLOneP->next = (struct LLNode*)0;
	testLLOneP->prev = (struct LLNode*)0;
	testLLOneP->payP = (Result*)1;
	if(testLL->next == testLLOneP->next && testLL->prev == testLLOneP->prev && testLL->payP == testLLOneP->payP)
	{
		printf("testMakeEmptyLinkedListOneFieldWithValue failed\n");fflush(stdout);
	}
	else
	{
		ok = true;
		printf("testMakeEmptyLinkedListOneFieldWithValue passed\n");fflush(stdout);
	}
	return ok;
}

bool testSavePayload()
{
	printf("starting testSavePayloadNonEmptyList\n");fflush(stdout);
	bool ok = false;
	Result* tResultP = (Result*)malloc(sizeof(Result));
	tResultP->wasMatch = false;
	Result tResult2;
	Result* tResult2P = &tResult2;
	tResult2P->wasMatch = true;
	LLNode* tNode = makeEmptyLinkedList();
	savePayload(tNode, tResult2P);
	while(tNode->next)
	{
		tNode = (LLNode*)tNode->next;
	}
	if(tNode->payP == tResult2P)
	{
		ok = true;
		printf("testSavePayloadNonEmptyList passed\n");
	}
	else
	{
		printf("testSavePayloadNonEmptyList failed\n");
	}
	return ok;
}

bool testPrintHistory()
{
	bool ok = false;
	printf("starting testPrintHistoryMultipleItemsList\n");fflush(stdout);
	LLNode* tNode = makeEmptyLinkedList();
	aCall theCall = {'A', 8};
	aCall* theCallP = &theCall;
	Result tResult1 = {true, 1, 1, theCallP};
	Result* tResult1P = &tResult1;
	savePayload(tNode, tResult1P);
	aCall theCall1 = {'C', 6};
	aCall* theCall1P = &theCall1;
	Result tResult2 = {false, -1, -1, theCall1P};
	Result* tResult2P = &tResult2;
	savePayload(tNode, tResult2P);
	aCall theCall3 = {'D', 5};
	aCall* theCall3P = &theCall3;
	Result tResult3 = {true, 4, 2, theCall3P};
	Result* tResult3P = &tResult3;
	savePayload(tNode, tResult3P);
	printHistory(tNode);
	printf("Does it print the right history?\n Press y if yes\n");fflush(stdout);
	char f = 'f';
	scanf(" %c", &f);
	if(f == 'y')
	{
		ok = true;
		printf("testPrintHistoryMultipleItemsList passed\n");fflush(stdout);
	}
	else
	{
		printf("testPrintHistoryMultipleItemsList failed\n");fflush(stdout);
	}
	return ok;
}













