/*
 * Space.h
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#ifndef SPACE_H_
#define SPACE_H_

#include <stdbool.h>

typedef struct
{
	int row;
	int col;
	char letter;
	int number;
	bool marked;
}Space;

void mark(Space*);

char* printSpace(Space);

bool isMatch(char letter, int number);

#endif /* SPACE_H_ */
