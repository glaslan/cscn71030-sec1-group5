// implementation for lexer functions 
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// get user input
char* getInput(){
	char* input[100];
	printf("Please enter a string: \n");
	fgets(input, sizeof(input), stdin);
	return input;

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
TOKENTYPE getType(ITEM i) {
	char input = i.data;
	TOKENTYPE t;
	switch (input)
	{
	case '<':
		t = MOVE_LEFT;
		break;
	case '>':
		t = MOVE_RIGHT;
		break;
	case '+':
		t = INCREMENT;
		break;
	case '-':
		t = DECREMENT;
		break;
	case ',':
		t = INPUT;
		break;
	case '.':
		t = OUTPUT;
		break;
	case ']':
		t = JUMP_PAST;
		break;
	case '[':
		t = JUMP_BACK;
		break;
	case '*':
		t = DOUBLE;
		break;
	case '/':
		t = HALF;
		break;
	case '?':
		t = RANDOM;
		break;
	case '\0':
		t = DOUBLE;
		break;
	default:
		t = INVALID;
		break;
	}
	return t;
}

// create a token 
TOKEN createToken(ITEM item, TOKENTYPE type) {
	TOKEN token = { 0 };
	token.i = item;
	token.t = type;
	return token;
}
