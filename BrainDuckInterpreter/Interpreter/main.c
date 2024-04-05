#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "abstractSyntaxTree.h"
#include "programQueue.h"
#include<stdlib.h>
#include<stdio.h>
#include "charQueue.h"


// Order of operations:
// 1. Parse arguments
// 2. Open file
// 3. Call lexer on file
// 4. Move the charQueue to the parser.
// 5. Run parser on the charQueue
// 6. Move programQueue to the evaluator
// 7. Run evaluator on the programQueue

int main(int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Provide a path to the file\n");
		exit(EXIT_FAILURE);
	}
	FILE* fp = fopen(parseArguments(argv, 1), 'r');
	if (fp == NULL) {
		fprintf(stderr, "Provide a valid file path\n");
		exit(EXIT_FAILURE);
	}
	CHARQUEUE* cq = initQueue();
	int i = 0;
	while ((i = fgetc(fp)) != EOF) {
		ITEM item = createItem(i);
		TOKEN token = createToken(item, getType(item));
		enqueue(cq, createNode(token));
	}
	fclose(fp);
	PTREENODE astRoot = parseProgram(&cq);
	ini();
	Eval(astRoot);
	return 0;
}