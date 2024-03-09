#pragma once
#include"const.h"

typedef struct node {
	char* data;
	struct node* left;
	struct node* right;
}NODE, * PNODE;

typedef struct ast {
	PNODE root;
}AST, * PAST;

PAST createAST();

PNODE createNode(char*);

bool addNode(PAST, PNODE);

PNODE removeNode(PAST);

void destroyAST(PAST);