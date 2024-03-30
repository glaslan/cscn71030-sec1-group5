#include <stdlib.h>
#include "programQueue.h"


PPROGRAMNODE createProgramNode(PTREENODE root) {
	PPROGRAMNODE newNode = (PPROGRAMNODE)malloc(sizeof(PROGRAMNODE));
	newNode->root = root;
	newNode->next = NULL;
	return newNode;
}
PPROGRAMQUEUE createProgramQueue() {
	PPROGRAMQUEUE newQueue = (PPROGRAMQUEUE)malloc(sizeof(PPROGRAMQUEUE));
	newQueue->head = NULL;
	newQueue->tail = NULL;
	return newQueue;
}
bool enQueue(PPROGRAMQUEUE pq, PTREENODE tn) {
	if (pq == NULL)
		return false;
	PPROGRAMNODE newNode = createProgramNode(tn);
	if (pq->tail == NULL) {
		pq->tail = newNode;
		pq->head = newNode;
		return true;
	}
	pq->tail->next = newNode;
	pq->tail = newNode;
}
PTREENODE deQueue(PPROGRAMQUEUE pq) {
	if (pq->head == NULL)
		return;
	PPROGRAMNODE temp = pq->head;
	PTREENODE root = temp->root;
	pq->head = pq->head->next;
	if (pq->head == NULL)
		pq->tail = NULL;
	free(temp);
	return root;
}