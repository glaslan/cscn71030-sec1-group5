#pragma once
#include <stdbool.h>
#include "programQueue.h"
#include "charQueue.h"


char* parseArguments(char* argVal, int argNum);
PTREENODE parseProgram(QNODE*);

void parseShiftRight(PTREENODE, QNODE*);
void parseShiftLeft(PTREENODE, QNODE*);
void parseIncrement(PTREENODE, QNODE*);
void parseDecrement(PTREENODE, QNODE*);
void parseOutput(PTREENODE, QNODE*);
void parseInput(PTREENODE, QNODE*);
void parseJumpForward(PTREENODE, QNODE*);
void parseJumpBack(PTREENODE, QNODE*);
void parseDouble(PTREENODE, QNODE*);
void parseHalve(PTREENODE, QNODE*);
void parseRandom(PTREENODE, QNODE*);
void parseEnd(QNODE*);

void errorTooManyArgs();
void errorInvalidToken(char, int);
void errorNullTokenList();
void errorNoEOFToken();