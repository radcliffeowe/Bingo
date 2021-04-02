/*
 * Board.h
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <stdbool.h>
#include <stdlib.h>
#include "Space.h"



void displayBoard(Space** bingoBoard, int nRows, int nCols);

bool check(char letter, int number, Space** bingoBoard);

void init(int nRows, Space** bingoBoard);

bool isBingo(Space**);


#endif /* BOARD_H_ */
