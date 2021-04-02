/*
 * Board.c
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#include "Board.h"
#include <stdio.h>
#include <time.h>



void init(int nRows, Space** bingoBoard)
{
	if(nRows>0)
	{
	srand(time(0));
	for(int row = 0; row< nRows; row++)
		{
			for(int col = 0; col < nRows; col++)
			{
				Space* x = (Space*) malloc (sizeof(Space)); //reserve a cardCell on heap
				x->row = row;
				x->col = col;
				x->letter = 'A' + (rand()%26);
				x->number = (rand()%10);
				x->marked = false;
				Space**  thatSpaceP = bingoBoard + row*nRows + col; // finds the index for the pointer, nRows is actually nCols
				*thatSpaceP = x; //put its address into bingo card space
			}
		}
	}
	else
	{
		printf("Invalid number of rows, you tried to print %d rows, please have at least 1\n", nRows);fflush(stdout);
	}
}


bool check(char callLetter, int callNumber, Space** bingoBoard)
{
	bool match = false;
	for(int row = 0; row<5; row++)
		{
			for(int col = 0; col<5; col++)
			{
				Space* testSpaceP = *(bingoBoard + row*5 +col);
				if(testSpaceP->letter == callLetter && testSpaceP->number == callNumber)
				{
					match = true;
					return match;
				}
			}
		}
	return match;
}

void displayBoard(Space** bingoBoard, int nRows, int nCols)
{
	for(int row = 0; row<nRows; row++)
	{
		printf("|");fflush(stdout);
		for(int col = 0; col<nCols; col++)
		{
			Space* x = *(bingoBoard + row*nCols +col);
			if(x->marked == true)
			{
				printf("## ");fflush(stdout);
			}
			else
			{
				printf("%c%d ", x->letter, x->number);fflush(stdout);
			}
		}
		printf("|\n");fflush(stdout);
	}
}

bool isBingo(Space** bingoBoard)
{
	bool win = false;
	bool hWinH = false;
	bool hWinV = false;
	bool hWinLR = false;
	bool hWinRL = false;
	for(int row = 0; row<5; row++)
	{
		Space* y = *(bingoBoard +row*5);
		if(y->marked == true)
		{
			int totalMarkedH = 1;
			for(int col = 1; col<5; col++)
			{
				Space* x = *(bingoBoard +row*5 +col);
				if(x->marked == true)
				{
					totalMarkedH++;
				}
			}
			if(totalMarkedH==5)
			{
				hWinH = true;
			}
		}
	}
	for(int col = 0; col<5; col++)
	{
		Space* z = *(bingoBoard + col);
		if(z->marked == true)
		{
			int totalMarkedV = 1;
			for(int row = 1; row<5; row++)
			{
				Space* a = *(bingoBoard + row*5 +col);
				if(a->marked == true)
				{
					totalMarkedV++;
				}
			}
			if(totalMarkedV == 5)
			{
				hWinV = true;
			}
		}
	}
	Space* b = *(bingoBoard);
	if(b->marked ==true)
	{
		int totalMarkedLR = 1;
		for(int i = 1; i<5; i++)
		{
			Space* c = *(bingoBoard+i*5+i);
			if(c->marked == true)
			{
				totalMarkedLR++;
			}
		}
		if(totalMarkedLR == 5)
		{
			hWinLR = true;
		}
	}
	Space* d = *(bingoBoard+4);
	if(d->marked == true)
	{
		int totalMarkedRL =1;
		for(int i = 1; i<5; i++)
		{
			Space* e = *((bingoBoard+4)+i*5-i);
			if(e->marked == true)
			{
				totalMarkedRL++;
			}
		}
		if(totalMarkedRL == 5)
		{
			hWinRL = true;
		}
	}
	if(hWinH||hWinV||hWinLR||hWinRL)
	{
		win = true;
	}
	return win;
}

































