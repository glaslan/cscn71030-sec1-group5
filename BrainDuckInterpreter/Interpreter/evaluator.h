#pragma once

#include"abstractSyntaxTree.h"
#include "const.h"

int Eval(PTREENODE tnode);




void ini();

void inc(char tape[], int* idx, int value);

void dec(char tape[], int* idx, int value);

void x2(char tape[], int* idx);

void div2(char tape[], int* idx);

int bound(char up, char low);
void randNum(char tape[], int* idx);

//statement
void incdex(int* idx);

void decdex(int* idx);

void out(char tape[], int* idx);

void in(char tape[], int* idx);