#ifndef CVM_H
#define CVM_H
#include <stdlib.h>
#include <stdbool.h>
typedef void *Objeto;
typedef int (*Print)(const char *String, ...);
typedef int (*PrintLn)(const char *String);
typedef bool (*Comparator)(Objeto obj);

struct Stout
{
    Print print;
    PrintLn println;
};

struct StSystem
{
    struct Stout out;
};

typedef struct StEnumerate
{
    Objeto obj;
    size_t index;
}Enumerate;

extern Objeto self;
extern struct StSystem System;

void CVM();

Objeto This(Objeto o);

#endif
