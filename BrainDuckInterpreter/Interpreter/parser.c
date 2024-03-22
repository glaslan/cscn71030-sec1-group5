#include "parser.h"
//#include "lexer.h"
#include "abstractSyntaxTree.h"
#include <stdlib.h>
#include <stdio.h>

// 1. Lexer passes a list of tokens to parser
// 2. Parser reads a token
// 3. Parser determines the token type and executes the corresponding function
// 4. The function turns the token into a char and passes it to the ast
// 5. The ast 

bool parseArguments(char* argVal, int argNum) {
	const int MAX_ARGUMENTS = 2;
	const int MIN_ARGUMENTS = 1;
	// Accept args and loop through them.
	// Get location of file
	for (int i = 0; i < argNum; i++) {
		if (argNum > MAX_ARGUMENTS || argNum < MIN_ARGUMENTS)
			errorTooManyArgs();

	}
	return true;
}

PPROGRAMQUEUE parseProgram() {
	
}

void parseShiftRight() {
}

void parseShiftLeft() {
}

void parseIncrement() {
}

void parseDecrement() {
}

void parseOutput() {
}

void parseInput() {
}

void parseJumpForward() {
}

void parseJumpBack() {
}

void parseDouble() {
}

void parseHalve() {
}

void parseRandom() {
	
}


// Error handling

void errorTooManyArgs() {
	fprintf(stderr, "Too many arguments.\n");
	exit(EXIT_FAILURE);
}
void errorInvalidToken(char symbol, int num) {
	fprintf(stderr, "Invalid token \'%c\' at position %d\n", symbol, num);
	exit(EXIT_FAILURE);
}
void errorNullTokenList() {
	fprintf(stderr, "Token list is NULL\n");
	exit(EXIT_FAILURE);
}
void errorNoEOFToken() {
	fprintf(stderr, "No EOF token found\n");
	exit(EXIT_FAILURE);
}