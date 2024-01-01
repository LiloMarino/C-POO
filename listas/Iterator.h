#ifndef ITERATOR_H
#define ITERATOR_H

typedef struct Iterator
{
    Iterator *__iter__;           // Ponteiro para ele mesmo
    Objeto (*__next__)();         // Retorna o elemento da lista e avança
};

#endif