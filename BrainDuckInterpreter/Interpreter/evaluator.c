#define _CRT_SECURE_NO_WARNINGS
#include "evaluator.h"
PTREENODE jumpStart = NULL;

char tape[MAX_TAPE];
int idx = 0;

void ini()
{
	for (int i = 0; i < MAX_TAPE; i++)
		tape[i] = 0;
}

int Eval(PTREENODE tnode)
{
	if (tnode == NULL || tnode->token.t==END_TOKEN)
		return;
	Eval(tnode->left);
	if (tnode->token.t == JUMP_BACK)
	{
		jumpStart = tnode;
		if (tape[idx] == 0)Eval(tnode->right);
	}

	if (tnode->token.t == JUMP_PAST)
	{
		if (tape[idx] == 0)
			Eval(tnode->right);
		else
			Eval(jumpStart);
	}
	else
	{
		//statements
		if (tnode->token.t == MOVE_RIGHT)
			incdex(&idx);
		if (tnode->token.t == MOVE_LEFT)
			decdex(&idx);
		//expression
		if (tnode->token.t == INCREMENT)
			inc(tape, &idx, tnode->value);
		if (tnode->token.t == DECREMENT)
			inc(tape, &idx, tnode->value);
		if (tnode->token.t == DOUBLE)
			x2(tape, &idx);
		if (tnode->token.t == HALF)
			div2(tape, &idx);
		if (tnode->token.t == INPUT)
			in(tape, &idx);
		if (tnode->token.t == OUTPUT)
			out(tape, &idx);
		if (tnode->token.t == RANDOM)
			randNum(tape, &idx);
		Eval(tnode->right);
	}

	
    //return;
}

//expressions
void inc(char tape[],int* idx,int value)
{
	tape[*idx]++;
}

void dec(char tape[], int* idx, int value)
{
	tape[*idx]--;
}

void x2(char tape[], int* idx)
{
	tape[*idx] *= 2;
}

void div2(char tape[], int* idx)
{
	tape[*idx] /= 2;
}

int bound(char up, char low)
{
	return rand() % (up - low + 1) + low;
}
void randNum(char tape[], int* idx)
{
	//srand(time(NULL));
	tape[*idx] = bound(255,0);
}

//statement
void incdex(int* idx)
{
	*idx=*idx+1;
	if (*idx == MAX_TAPE)
		*idx = 0;
}

void decdex(int* idx)
{
	*idx=*idx-1;
	if (*idx <0)
		*idx = MAX_TAPE-1;
}

void out(char tape[], int* idx)
{
	printf("%d", tape[*idx]);
}

void in(char tape[], int* idx)
{
	char inp;
	printf("\nPlease enter a character: ");
	scanf("%c", &inp);
	tape[*idx] = inp;
}
