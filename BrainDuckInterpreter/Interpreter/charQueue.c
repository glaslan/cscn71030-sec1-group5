#include "charQueue.h"
#include <stdio.h>
#include <stdlib.h>

static QNODE *pHead, *pTail;

void initQueue() {
	pHead = pTail = NULL;
}

QNODE* createNode(TOKEN t) {
	QNODE* newNode = (QNODE*)malloc(sizeof(QNODE));
	newNode->token = t;
	newNode->next = NULL;
	return newNode;
}

// for adding nodes to the queue
void enqueue(TOKEN t) {
	QNODE* new = createNode(t);
	if (new == NULL) {
		printf("Error allocating node memory.\n");
		exit(EXIT_FAILURE);
	}
	if (pHead == NULL) {
		pHead = pTail = new;
	}
	else {
		pTail->next = new;
		pTail = new;
	}
}

int isEmpty() {
	return pHead == NULL;
}

// used for unit testing
QNODE dequeue() {
	if (isEmpty()) {
		printf("Queue is empty!\n");
		exit(EXIT_FAILURE);
	}
	QNODE removed = *pHead;
	QNODE* temp = pHead;
	pHead = pHead->next;
	free(temp);
	if (pHead == NULL) {
		pTail = NULL;
	}
	return removed;
}

void printQueue() {
	QNODE* current = pHead;
	printf("This is the queue: \n");
	printf("-----------------------\n");

	while (current != NULL) {
		printf("Token Data: %c\nTokenType: %s\n\n", current->token.i.data, TOKENNAME[current->token.t]);
		current = current->next;
	}
}




