#include "charQueue.h"
#include <stdio.h>
#include <stdlib.h>


CHARQUEUE* initQueue() {
	CHARQUEUE* newQueue = (CHARQUEUE*)malloc(sizeof(CHARQUEUE));
	newQueue->head = NULL;
	newQueue->tail = NULL;
	return newQueue;
}

QNODE* createNode(TOKEN t) {
	QNODE* newNode = (QNODE*)malloc(sizeof(QNODE));
	newNode->token = t;
	newNode->next = NULL;
	return newNode;
}

// for adding nodes to the queue
void enqueue(CHARQUEUE* cq, QNODE* n) {
	if (cq == NULL) {
		printf("Error allocating node memory.\n");
		exit(EXIT_FAILURE);
	}
	if (cq->head == NULL) {
		cq->head = cq->tail = n;
	 }
	else {
		cq->tail->next = n;
		cq->tail = n;
	}
}

bool isEmpty(CHARQUEUE cq) {
	return cq.head == NULL;
}

// used for unit testing
QNODE dequeue(CHARQUEUE* cq) {
	if (isEmpty(*cq)) {
		printf("Queue is empty!\n");
		exit(EXIT_FAILURE);
	}
	QNODE removed = *cq->head;
	QNODE* temp = cq->head;
	cq->head = cq->head->next;
	free(temp);
	if (cq->head == NULL) {
		cq->tail = NULL;
	}
	return removed;
}

void printQueue(CHARQUEUE cq) {
	QNODE* current = cq.head;
	printf("This is the queue: \n");
	printf("-----------------------\n");

	while (current != NULL) {
		printf("Token Data: %c\nTokenType: %s\n\n", current->token.i.data, TOKENNAME[current->token.t]);
		current = current->next;
	}
}




