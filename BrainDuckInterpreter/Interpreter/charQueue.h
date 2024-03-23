#pragma once
#include "lexer.h"

typedef struct charQueue* link;

typedef struct charQueue {
	TOKEN token;
	link next;
}QNODE;

QNODE createNode(TOKEN token);

link newLink(link h, QNODE n);

void initQueue();

int isEmpty(link h);

void addToQueue(link* h, QNODE n);

void printQueue(link h);

// might not need this 
link deQueue();

