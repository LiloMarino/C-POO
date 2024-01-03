#include "../CVM.h"
#include "Iterator.h"
#include "List.h"
#include <stdlib.h>
#include <stdbool.h>

/* Mantendo "privado" as declarações */
typedef struct StNode
{
    Objeto obj;
    struct StNode *prox;
    struct StNode *ant;
} Node;

/* Mantendo "privado" as declarações */
typedef struct StListaEnc
{
    Node *inicio;
    Node *final;
    int length;
} ListaEnc;

typedef struct StIter
{
    Node *__current__;
    bool __reversed__;
} Iter;


Objeto __next__()
{
    Iter *iter = ((Iterator)self)->__iterator__;
    Objeto obj = ((Node *)iter->__current__)->obj;
    if (iter->__reversed__)
    {
        iter->__current__ = ((Node *)iter->__current__)->ant;
    }
    else
    {
        iter->__current__ = ((Node *)iter->__current__)->prox;
    }
    return obj;
}

Iterator newIterator(bool __reversed__)
{
    Iter *iter = malloc(sizeof(Iter));
    iter->__reversed__ = __reversed__;
    if (__reversed__)
    {
        iter->__current__ = ((ListaEnc *)((List)self)->__list__)->final;
    }
    else
    {
        iter->__current__ = ((ListaEnc *)((List)self)->__list__)->inicio;
    }
    Iterator it = malloc(sizeof(struct StIterator));
    it->__iter__ = it;
    it->__iterator__ = iter;
    it->__next__ = __next__;

    return it;
}
