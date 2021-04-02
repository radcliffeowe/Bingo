/*
 * Production.h
 *
 *  Created on: Feb 9, 2021
 *      Author: radcl
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "Space.h"


#define FILENAMELENGTHALLOWANCE 50

bool production(int argc, char* argv[]);

void showBoard();

#endif /* PRODUCTION_H_ */
