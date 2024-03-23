#include "charQueue.h"
#include <stdio.h>
#include <stdlib.h>

static QNODE *pHead, *pTail;

void initQueue() {
	pHead = pTail = NULL;
}

QNODE createNode(TOKEN t) {
	QNODE* newNode = (link)malloc(sizeof(QNODE));
	newNode->token = t;
	newNode->next = NULL;
	return *newNode;
}

link newLink(link h, QNODE n) {
	link new = (link)malloc(sizeof(QNODE));
	if (new == NULL) {

		exit(EXIT_FAILURE);
	}
	*new = n;
	new->next = h;
	return new;
}

int isEmpty(link h) {
	return h == NULL;
}

void addToQueue(link* h, QNODE n) {
	*h = newLink(*h, n);
}

void printQueue(link h) {
	while (h != NULL) {
		printf("Character = %c, Type = %d \n", h->token.i, h->token.t);
		h = h->next;
	}
}



