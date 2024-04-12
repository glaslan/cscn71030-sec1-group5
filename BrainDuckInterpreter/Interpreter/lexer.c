// implementation for lexer functions 
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void removeNewLine(char* buffer) {
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0';
}
 
// get user input
char* getInput(){
	static char input[100];
	printf("Please enter a string: \n");
	fgets(input, 100, stdin);
	removeNewLine(input);
	return input;

}

// extract the chars 
char extractChar(char input[], int* index) {
	char next = input[*index];
	if (next != '\0') {
		(*index)++;
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
TOKENTYPE getType(char c) {
	TOKENTYPE t = INVALID;
	switch (c)
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
	case EOF:
		t = END_TOKEN;
		break;
	case ' ':
		break;
	case '\n':
		break;
	case '\t':
		break;
	case '\v':
		break;
	case '\f':
		break;
	case '\r':
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

// to get the name of the token instead of number 
const char* TOKENNAME[] = {
	"MOVE LEFT",
	"MOVE RIGHT",
	"INCREMENT",
	"DECREMENT",
	"INPUT",
	"OUTPUT",
	"JUMP PAST",
	"JUMP BACK",
	"DOUBLE",
	"HALF",
	"RANDOM",
	"END TOKEN",
	"INVALID"
};