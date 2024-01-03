#ifndef CVM_H
#define CVM_H
#include <stdlib.h>
#include <stdbool.h>
typedef void *Objeto;
typedef int (*Print)(const char *String, ...);
typedef int (*PrintLn)(const char *String);
typedef bool (*Comparator)(Objeto obj1, Objeto obj2); // A função Comparator deve retornar True caso os objetos sejam iguais
typedef void (*Free)(Objeto obj);                     // A função Free deve realizar a desalocação de memória do objeto

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
} Enumerate;

struct StFree
{
    Free f;
    Objeto obj;
};

typedef struct StCollector
{
    struct StFree *collector;
    size_t size;
} Collector;

extern Objeto self;
extern struct StSystem System;
extern Collector collector;

void CVM();

Objeto This(Objeto o);

void GarbageCollector();

#endif
