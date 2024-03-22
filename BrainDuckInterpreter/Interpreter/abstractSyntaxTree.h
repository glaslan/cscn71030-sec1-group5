#pragma once
#include <stdbool.h>
//#include "lexer.h"

typedef enum token {
	INCREMENT,
	DECREMENT
} TOKEN;

typedef struct treeNode {
	TOKEN token;
	int value;
	struct treeNode* right;
	struct treeNode* left;
}TREENODE, *PTREENODE;

PTREENODE createNode(TOKEN);

PTREENODE addNode(PTREENODE, TOKEN);

bool printAST(PTREENODE);

PTREENODE removeNode(PTREENODE);

void destroyAST(PTREENODE);