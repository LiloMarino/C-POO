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
    if (iter->__current__ == NULL)
    {
        /* StopIteration */
        return NULL;
    }
    
    Objeto obj = iter->__current__->obj;
    if (iter->__reversed__)
    {
        iter->__current__ = iter->__current__->ant;
    }
    else
    {
        iter->__current__ = iter->__current__->prox;
    }
    return obj;
}

Iterator newIterator(bool __reversed__)
{
    Iter *iter = malloc(sizeof(Iter));
    linkToGarbage(free,iter);
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
    linkToGarbage(free,it);
    it->__iter__ = it;
    it->__iterator__ = iter;
    it->__next__ = __next__;
    return it;
}
