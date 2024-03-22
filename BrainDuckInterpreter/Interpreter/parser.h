#pragma once
#include <stdbool.h>
#include "programQueue.h"


bool parseArguments(char* argVal, int argNum);
PPROGRAMQUEUE parseProgram();
void handleError();

void parseShiftRight();
void parseShiftLeft();

void parseIncrement();
void parseDecrement();

void parseOutput();
void parseInput();

void parseJumpForward();
void parseJumpBack();

void parseDouble();
void parseHalve();

void parseRandom();

void errorTooManyArgs();
