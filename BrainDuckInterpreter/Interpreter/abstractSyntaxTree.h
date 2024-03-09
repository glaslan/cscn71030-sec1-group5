#pragma once
#include <stdbool.h>

typedef struct node {
	int token;
	struct node* left;
	struct node* right;
}NODE, *PNODE;

typedef struct program {
	struct node* root;
}PROGRAM, *PPROGRAM;

PPROGRAM createAST();

PNODE createNode(char*);

bool addNode(PPROGRAM, PNODE);

bool astHasNodes(PPROGRAM);

PNODE removeNode(PPROGRAM);

void destroyAST(PPROGRAM);