#pragma once
#include <stdbool.h>
#include "lexer.h"

typedef struct qnode {
	TOKEN token;
	struct qnode* next;
} QNODE;

typedef struct charQueue {
	QNODE* head;
	QNODE* tail;
}CHARQUEUE;

CHARQUEUE* initQueue();
QNODE* createNode(TOKEN t);
void enqueue(CHARQUEUE*, QNODE* n);
bool isEmpty(CHARQUEUE cq);
QNODE dequeue(CHARQUEUE* cq);
void printQueue(CHARQUEUE cq);



