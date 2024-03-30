#include "abstractSyntaxTree.h"
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"


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
	if (getType(t.i) == JUMP_BACK) {
		n->left = addNode(n->left, t);
	}
	else {// if t is an item that goes on the right
		n->right = addNode(n->right, t);
	}
	if (n->left == NULL && n->right == NULL && n->token.t == t.t)
		++(n->value); // if t is the same as the final item add one to the final node's value
	return n;
}

PTREENODE getLeftTreeNodePtr(PTREENODE pt) {
	if (pt == NULL) {
		fprintf(stderr, "PTREENODE was NULL in getLeftTreeNodePtr(PTREENODE pt)");
		return NULL;
	}
	return pt->left;
}

PTREENODE getRightTreeNodePtr(PTREENODE pt) {
	if (pt == NULL) {
		fprintf(stderr, "PTREENODE was NULL in getRightTreeNodePtr(PTREENODE pt)");
		return NULL;
	}
	return pt->right;
}

bool printAST(PTREENODE n) {
	if (n == NULL)
		return false;
	printAST(n->left);
	printf("Current token is: %d\n", n->token);
	printAST(n->right);
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

void destroyAST(PTREENODE n) {
	if (n == NULL)
		return;
	destroyAST(n->left);
	destroyAST(n->right);
	free(n);
}