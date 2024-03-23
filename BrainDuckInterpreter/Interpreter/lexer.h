#pragma once
// Destiny - Lexer pls

typedef struct item {
	char data;
} ITEM;

// types of tokens 
typedef enum tokenType{
	MOVE_LEFT,		// <
	MOVE_RIGHT,		// >
	INCREMENT,		// +
	DECREMENT,		// -
	INPUT,			// ,
	OUTPUT,			// .
	JUMP_PAST,		// ]
	JUMP_BACK,		// [
	DOUBLE,			// *
	HALF,			// /
	RANDOM,			// ?
	END_TOKEN,		// reached end of file 
	INVALID
} TOKENTYPE;

// actual token struct
typedef struct token {
	ITEM i;
	TOKENTYPE t;
}TOKEN;

// get user input 
char* getInput();

// extract the chars 
char extractChar(char input[], int* index);

// create an item from a char 
ITEM createItem(char a);

// get the token type 
TOKENTYPE getType(ITEM i);

// create a token 
TOKEN createToken(ITEM i, TOKENTYPE t);







