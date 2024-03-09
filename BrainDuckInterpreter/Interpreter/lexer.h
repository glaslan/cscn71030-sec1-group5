#pragma once
// Destiny - Lexer pls

// types of tokens 
typedef enum {
	MOVE_LEFT,		// <
	MOVE_RIGHT,		// >
	INCREMENT,		// +
	DECREMENT,		// -
	INPUT,			// ,
	OUTPUT,			// .
	JUMP_PAST,		// ]
	JUMP_BACK,		// [
	END_TOKEN		// reached end of file 
}tokenType;

// actual token struct
typedef struct token {
	tokenType t;
}TOKEN;

// lexer thingy struct
typedef struct lexer {
	char* input;
	int position;
	char current;
}LEXER;

// initialize the lexer (i.e. set the starting point)
void initLexer();

// advance to the next char 
void goToNext();

// turn the char into a token 
TOKEN getToken(LEXER* l);