#include "abstractSyntaxTree.h"
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"


PTREENODE createTreeNode(TOKEN t) {
	PTREENODE newNode = (PTREENODE)malloc(sizeof(TREENODE));
	newNode->token = t;
	newNode->value = 1;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

PTREENODE addNode(PTREENODE p, TOKEN t) {
	if (p == NULL) {
		return createTreeNode(t);
	}

	p->right = addNode(p->right, t);
	return p;
}

bool printAST(PTREENODE n) {
	if (n == NULL)
		return false;
	printAST(n->left);
	printf("Current token is: %d\n", n->token.t);
	printAST(n->right);
	return true;
}

PTREENODE removeNode(PTREENODE tn) {
	if (tn == NULL)
		return;
	removeNode(tn->left);
	// Need escape statement here
	return tn;
	removeNode(tn->right);
}

int getTreeSize(PTREENODE tn) {
	if (tn == NULL)
		return -1;
	int count = 0;
	count += getTreeSize(tn->left);
	count += getTreeSize(tn->right);
	return count + 1;
}

bool destroyAST(PTREENODE n) {
	if (n == NULL)
		return false;
	destroyAST(n->left);
	destroyAST(n->right);
	free(n);
	return true;
}