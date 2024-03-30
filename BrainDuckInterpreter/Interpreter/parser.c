#include "parser.h"
#include "lexer.h"
#include "abstractSyntaxTree.h"
#include <stdlib.h>
#include <stdio.h>

// 1. Lexer passes a list of tokens to parser
// 2. Parser reads a token
// 3. Parser determines the token type and executes the corresponding function
// 4. The function turns the token into a char and passes it to the ast
// 5. The ast 

char* parseArguments(char* argVal, int argNum) {
	const int MAX_ARGUMENTS = 2;
	const int MIN_ARGUMENTS = 1;
	// Accept args and loop through them.
	// Get location of file
	for (int i = 0; i < argNum; i++) {
		if (argNum > MAX_ARGUMENTS || argNum < MIN_ARGUMENTS)
			errorTooManyArgs();

	}
	return argVal + 1;
}

PTREENODE parseProgram(QNODE* qn) {
	if (qn == NULL) {
		errorNullTokenList();
	}
	PTREENODE root;
	int count = 0;
	do {
		switch (qn->token.t) {
		case 0: 
			parseShiftLeft(root, qn);
			break;
		case 1:
			parseShiftRight(root, qn);
			break;
		case 2:
			parseIncrement(root, qn);
			break;
		case 3:
			parseDecrement(root, qn);
			break;
		case 4:
			parseInput(root, qn);
			break;
		case 5:
			parseOutput(root, qn);
			break;
		case 6:
			parseJumpForward(root, qn);
			break;
		case 7:
			parseJumpBack(root, qn);
			break;
		case 8:
			parseDouble(root, qn);
			break;
		case 9:
			parseHalve(root, qn);
			break;
		case 10:
			parseRandom(root, qn);
			break;
		case 11:
			// End token received
			parseEnd(qn);
			return root;
		case 12:
			errorInvalidToken(qn->token.i.data, count);
		}
		count++;
	} while (qn->next != NULL);
	errorNoEOFToken();
}

void parseShiftRight(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseShiftLeft(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseIncrement(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseDecrement(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseOutput(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseInput(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseJumpForward(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseJumpBack(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseDouble(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseHalve(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseRandom(PTREENODE tn, QNODE* qn) {
	if (tn == NULL)
		return;
	tn = addNode(tn, qn->token);
}

void parseEnd(QNODE* qn) {
	while (qn != NULL) {
		dequeue();
	}
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