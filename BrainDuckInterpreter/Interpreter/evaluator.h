#pragma once

#include"abstractSyntaxTree.h"
#include "const.h"

int Eval(PTREENODE tnode);

char tape[MAX_TAPE];
void ini()
{
	for (int i = 0; i < MAX_TAPE; i++)
		tape[i] = 0x00;
}


void inc(unsigned char tape[], int* idx, int value);

void dec(unsigned char tape[], int* idx, int value);

void x2(unsigned char tape[], int* idx);

void div2(unsigned char tape[], int* idx);

int bound(char up, char low);
void randNum(unsigned char tape[], int* idx);

//statement
void incdex(int* idx);

void decdex(int* idx);

void jump1(int* idx);

void jump2(int* idx);

void out(unsigned char tape[], int* idx);

void in(unsigned char tape[], int* idx, char inp);