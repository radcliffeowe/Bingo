/*
 ============================================================================
 Name        : Bingo.c
 Author      : Owen Radcliffe
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "OwenRadcliffe.h"

int main(int argc, char* argv[]) {
	puts("!!!Hello World, let's do HW2!!!"); /* prints !!!Hello World!!! */
	if(tests())
	{
		puts("The tests all passed.");
		production(argc, argv);
	}
	else
	{
		puts("Not all tests passed; better luck next time");
	}

	return EXIT_SUCCESS;
}
