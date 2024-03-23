// implementation for lexer functions 
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// get user input
char* getInput(char* input[]){
	char input[100];
	printf("Please enter a string: \n");
	fgets(input, sizeof(input), stdin);

}

// extract the chars 
char extractChar(char input[], int* index) {
	char next = input[*index];
	if (next != '\0') {
		(*index++);
	}
	return next;
}


// create an item from a char 
ITEM createItem(char a) {
	ITEM iNew = { 0 };
	iNew.data = a;
	return iNew;
}

// get the token type 
TOKENTYPE getType(ITEM i);

// create a token 
TOKEN createToken(ITEM i, TOKENTYPE t);
