#define _CRT_SECURE_NO_WARNINGS
#include "evaluator.h"
#define PROGRAM_LENGTH 5000

PTREENODE jumpStart = NULL;
TOKENTYPE program[PROGRAM_LENGTH];
int programPtr = 0;
char tape[MAX_TAPE];
int idx = 0;

void ini()
{
	for (int i = 0; i < MAX_TAPE; i++)
		tape[i] = 0;
}

bool rakeTree(PTREENODE p)
{
	if (p == NULL) {
		return false;
	}
	TREENODE t;
	// in order traversal
	rakeTree(p->left);
	t = *p;
	program[programPtr] = t.token.t;
	programPtr++;
	rakeTree(p->right);
}

int Eval(PTREENODE p, FILE* out)
{
    //traverseTree(p);
    rakeTree(p);
    program[programPtr] = END_TOKEN;
    /*for (int k = 0; k < programPtr; k++) {
        printf("%d", program[k]);
    }*/
    programPtr = 0;

    bool getOut = false;
    while (!getOut)
    {
        switch (program[programPtr])
        {
        case 0:
            decdex(&idx);
            break;
        case 1:
            incdex(&idx);
            break;
        case 2:
            inc(tape, idx, p->value);
            break;
        case 3:
            dec(tape, idx, p->value);
            break;
        case 4:
            in(tape, &idx);
            break;
        case 5:
            sendOut(tape, &idx, out);
            break;
        case 6:
            jumpPast(tape, idx);
            break;
        case 7:
            jumpBack(tape, idx);
            break;
        case 8:
            x2(tape, &idx);
            break;
        case 9:
            div2(tape, &idx);
            break;
        case 10:
            randNum(tape, &idx);
            break;
        case 11:
            getOut = true;
            break;
        default:
            break;
        }
        if (programPtr < PROGRAM_LENGTH)
            programPtr++;
    }
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

int bound(int up, int low)
{
	return rand() % (up - low + 1) + low;
}
void randNum(char tape[], int* idx)
{
	srand(time(0));
	tape[*idx] = bound(126,33);
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

void jumpPast(char tape[], int i)
{
    //printf("Jump End\n");
    if (tape[i] != 0)
    {
        while (program[programPtr] != JUMP_BACK)
        {
            programPtr--;
        }
    }
}

void jumpBack(char tape[], int i)
{
    //printf("Jump back\n");
    if (tape[i] == 0)
    {
        while (program[programPtr] != JUMP_PAST)
        {
            programPtr++;
        }
        //printf("Jumped\n");
    }
}

void sendOut(char tape[], int* idx, FILE* out)
{
	fputc(tape[*idx], stdout);
    fputc(tape[*idx], out);
}

void in(char tape[], int* idx)
{
	char inp;
	printf("\nPlease enter a character: ");
	scanf("%c", &inp);
	tape[*idx] = inp;
}
