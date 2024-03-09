#pragma once
#include"const.h"

#define NULL_OBJ "NULL"
#define ERROR_OBJ "ERROR"

typedef  char* ObjectType;

typedef struct Object
{
	ObjectType type;
	char* inspect;
}OBJ,*POBJ;

typedef struct Environment
{
	POBJ pObject;
	PENV environment;
}ENV,*PENV;
