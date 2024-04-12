#pragma once
#include"abstractSyntaxTree.h"
#include "const.h"

int Eval(PTREENODE tnode, FILE*);

bool rakeTree(PTREENODE);


void ini();

void inc(char tape[], int* idx, int value);

void dec(char tape[], int* idx, int value);

void x2(char tape[], int* idx);

void div2(char tape[], int* idx);

void jumpPast(char[], int);
void jumpBack(char[], int);

int bound(int up, int low);
void randNum(char tape[], int* idx);

//statement
void incdex(int* idx);

void decdex(int* idx);

void sendOut(char tape[], int* idx, FILE*);

void in(char tape[], int* idx);