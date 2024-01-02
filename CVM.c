#include "CVM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct StSystem System;
Objeto self;

int println(const char *String)
{
    char variavel[strlen(String) + 2];
    strcpy(variavel, String);
    strcat(variavel, "\n");
    return printf(variavel);
}

void CVM()
{
    System.out.print = printf;
    System.out.println = println;
}

Objeto This(Objeto o)
{
    self = o;
    return o;
}