#include "CVM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct StSystem System;
Collector collector = {0};
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

void linkToGarbage(Free f, Objeto obj)
{
    struct StFree *temp = realloc(collector.collector, (collector.size + 1) * sizeof(struct StFree));
    if (temp != NULL) {
        collector.collector = temp;
        collector.collector[collector.size].f = f;
        collector.collector[collector.size].obj = obj;
        collector.size++;
    } else {
        // Tratar falha na alocação de memória
        printf("Erro ao alocar memória.\n");
    }
}


void GarbageCollector()
{
    for (size_t i = 0; i < collector.size; i++)
    {
        collector.collector[i].f(collector.collector[i].obj);
    }
    free(collector.collector);
}
