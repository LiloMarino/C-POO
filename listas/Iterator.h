#ifndef ITERATOR_H
#define ITERATOR_H

#include "../CVM.h"
#include <stdbool.h>

struct StIterator
{
    struct StIterator *__iter__;           // Ponteiro para ele mesmo
    Objeto __iterator__;       // Ponteiro para ele mesmo
    Objeto (*__next__)();         // Retorna o elemento da lista e avança
};

typedef struct StIterator* Iterator;

Iterator newIterator(bool __reversed__);

#endif