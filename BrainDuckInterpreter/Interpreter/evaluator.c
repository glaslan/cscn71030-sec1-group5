#include "evaluator.h"
int idx = 0;
PTREENODE jumpStart = NULL;

int Eval(PTREENODE tnode)
{
	if (tnode == NULL || tnode->token==END_TOKEN)
		return;
	Eval(tnode->left);
	if (tnode->token == JUMP_BACK)
	{
		jumpStart = tnode;
		if (tape[idx] == 0)Eval(tnode->right);
	}

	if (tnode->token == JUMP_PAST)
	{
		if (tape[idx] == 0)
			Eval(tnode->right);
		else
			Eval(jumpStart);
	}
	else
	{
		//statements
		if (tnode->token == MOVE_RIGHT)
			incdex(&idx);
		if (tnode->token == MOVE_LEFT)
			decdex(&idx);
		//expression
		if (tnode->token == INCREMENT)
			inc(tape, &idx, tnode->value);
		if (tnode->token == DECREMENT)
			inc(tape, &idx, tnode->value);
		if (tnode->token == DOUBLE)
			x2(tape, &idx);
		if (tnode->token == HALF)
			div2(tape, &idx);
		if (tnode->token == INPUT)
			in(tape, &idx);
		if (tnode->token == OUTPUT)
			out(tape, &idx);
		if (tnode->token == RANDOM)
			randNum(tape, &idx);
		Eval(tnode->right);
	}

	
    //return;
}

//expressions
void inc(char tape[],int* idx,int value)
{
	tape[*idx] += value;
}

void dec(char tape[], int* idx, int value)
{
	tape[*idx] -= value;
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
void randNum(unsigned char tape[], int* idx)
{
	//srand(time(NULL));
	tape[*idx] = bound(255,0);
}

//statement
void incdex(int* idx)
{
	*idx++;
	if (*idx == MAX_TAPE)
		*idx = 0;
}

void decdex(int* idx)
{
	*idx--;
	if (*idx <0)
		*idx = MAX_TAPE-1;
}

void jump1(int* idx)
{}

void jump2(int* idx)
{}

void out(unsigned char tape[], int* idx)
{
	printf("%d", tape[*idx]);
}

void in(unsigned char tape[], int* idx)
{
	int inp;
	printf("\nPlease enter a character: ");
	fscanf("%d", &inp);
	tape[*idx] = inp;
}
