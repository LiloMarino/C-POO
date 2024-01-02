#ifndef ITERATOR_H
#define ITERATOR_H

#include "../CVM.h"

typedef struct StIterator
{
    Iterator *__iter__;           // Ponteiro para ele mesmo
    Objeto *__iterator__;       // Ponteiro para ele mesmo
    Objeto (*__next__)();         // Retorna o elemento da lista e avança
}Iterator;

#endif