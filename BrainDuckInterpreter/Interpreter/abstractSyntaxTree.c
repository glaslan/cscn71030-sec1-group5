#include "abstractSyntaxTree.h"
#include <stdlib.h>
#include <stdio.h>


PTREENODE createNode(TOKEN t) {
	PTREENODE newNode = (PTREENODE)malloc(sizeof(TREENODE));
	newNode->token = t;
	newNode->value = 1;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

PTREENODE addNode(PTREENODE n, TOKEN t) {
	if (n == NULL) {
		return createNode(t);
	}
	if (t < 2)
		n->left = addNode(n->left, t);
	if (t) // if t is an item that goes on the right
		n->right = addNode(n->right, t);
	if (n->left == NULL && n->right == NULL && n->token == t)
		++(n->value); // if t is the same as the final item add one to the final node's value
	return n;
}

bool printAST(PTREENODE n) {
	if (n == NULL)
		return false;
	printAST(n->left);
	printf("Current token is: %d\n", n->token);
	printAST(n->right);
}

PTREENODE removeNode(PTREENODE n) {
	return NULL;
}

void destroyAST(PTREENODE n) {
	if (n == NULL)
		return;
	destroyAST(n->left);
	destroyAST(n->right);
	free(n);
}