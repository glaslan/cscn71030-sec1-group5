#pragma once
#include <stdbool.h>
#include "abstractSyntaxTree.h"

typedef struct programNode {
	PTREENODE root;
	struct programNode* next;
} PROGRAMNODE, *PPROGRAMNODE;

typedef struct programQueue {
	PPROGRAMNODE head;
	PPROGRAMNODE tail;
} PROGRAMQUEUE, *PPROGRAMQUEUE;

PPROGRAMNODE createProgramNode(PTREENODE root);
PPROGRAMQUEUE createProgramQueue();
bool enQueue(PPROGRAMQUEUE, PTREENODE);
PTREENODE deQueue(PPROGRAMQUEUE);
