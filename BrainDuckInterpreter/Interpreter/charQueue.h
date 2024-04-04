#pragma once
#include "lexer.h"

typedef struct qnode {
	TOKEN token;
	struct qnode* next;
} QNODE;

typedef struct charQueue {
	QNODE* head;
	QNODE* tail
}CHARQUEUE;

void initQueue(CHARQUEUE cq);
QNODE createNode(TOKEN t);
void enqueue(QNODE n, CHARQUEUE cq);
int isEmpty(CHARQUEUE cq);
QNODE dequeue(CHARQUEUE cq);
void printQueue(CHARQUEUE cq);



