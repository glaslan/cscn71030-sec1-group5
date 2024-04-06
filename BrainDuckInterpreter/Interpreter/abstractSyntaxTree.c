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
	// Traverse right
	// if the last node is a [ and the adding node is a ] then add it to the right. If it's anything else then traverse left then right and add the node


	if (getType(p->token.i) == JUMP_BACK && p->right == NULL && getType(t.i) != JUMP_PAST) {
		p->left = addNode(p->left, t);
		p->right = addNode(p->right, t);
	}
	else {
		p->right = addNode(p->right, t);
	}
	return p;
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