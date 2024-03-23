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

}

int isEmpty(link h) {


}

void addToQueue(link h) {
	
}

void printQueue(link h) {

}

link deQueue() {

}

