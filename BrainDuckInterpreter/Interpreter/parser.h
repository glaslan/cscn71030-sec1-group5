#pragma once
#include <stdbool.h>
#include "programQueue.h"
#include "charQueue.h"


char* parseArguments(char* argVal, int argNum);
PTREENODE parseProgram(CHARQUEUE*);

bool parseShiftRight(PTREENODE, QNODE*);
bool parseShiftLeft(PTREENODE, QNODE*);
bool parseIncrement(PTREENODE, QNODE*);
bool parseDecrement(PTREENODE, QNODE*);
bool parseOutput(PTREENODE, QNODE*);
bool parseInput(PTREENODE, QNODE*);
bool parseJumpForward(PTREENODE, QNODE*);
bool parseJumpBack(PTREENODE, QNODE*);
bool parseDouble(PTREENODE, QNODE*);
bool parseHalve(PTREENODE, QNODE*);
bool parseRandom(PTREENODE, QNODE*);
void parseEnd(CHARQUEUE*);

void errorTooManyArgs();
void errorInvalidToken(char, int);
void errorNullTokenList();
void errorNoEOFToken();