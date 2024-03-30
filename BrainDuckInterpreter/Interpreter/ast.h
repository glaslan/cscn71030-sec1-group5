#pragma once
#include"const.h"

typedef struct node {
	char* data;
	struct node* left;
	struct node* right;
}NODE, * PNODE;

typedef struct treeNode {
	TOKEN token;
	int value;
	struct treeNode* right;
	struct treeNode* left;
}TREENODE, * PTREENODE;

typedef struct program
{
	PNODE root;
}PROG,*PPROG;

typedef enum token 
{
	MOVE_LEFT,		// <
	MOVE_RIGHT,		// >
	INCREMENT,		// +
	DECREMENT,		// -
	INPUT,			// ,
	OUTPUT,			// .
	JUMP_PAST,		// ]
	JUMP_BACK,		// [
	DOUBLE,			// *
	HALF,			// /
	RANDOM,			// ?
	END_TOKEN,		// reached end of file 
	INVALID
} TOKEN;
//PAST createAST();

//PNODE createNode(char*);

//bool addNode(PAST, PNODE);

//PNODE removeNode(PAST);

//void destroyAST(PAST);