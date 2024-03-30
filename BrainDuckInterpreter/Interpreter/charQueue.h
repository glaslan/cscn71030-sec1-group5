#pragma once
#include "lexer.h"

typedef struct qnode {
	TOKEN token;
	struct qnode* next;
} QNODE;

void initQueue();
QNODE* createNode(TOKEN t);
void enqueue(TOKEN);
int isEmpty();
QNODE dequeue();
void printQueue();


