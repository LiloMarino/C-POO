#include "../CVM.h"
#include "Built-in.h"
#include "Iterator.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct StNode
{
    Objeto obj;
    struct StNode *prox;
    struct StNode *ant;
} Node;

typedef struct StListaEnc
{
    Node *inicio;
    Node *final;
    size_t length;
} ListaEnc;

size_t __enumer = 0;

List copy()
{
    /* Itera copiando */
    Iterator it = iter(self);
    for (Objeto o = next(it); o != NULL; next(it))
    {
    }
}

void append(Objeto obj)
{
    ListaEnc *lista = ((List)self)->__list__;
    Node *aux = calloc(1, sizeof(Node));
    aux->obj = obj;

    if (lista->inicio == NULL)
    {
        lista->inicio = aux; // Lista vazia, insere como o primeiro elemento
    }
    else
    {
        Node *p = lista->final;
        aux->ant = p;
        p->prox = aux;
    }

    lista->final = aux;
    lista->length++;
}

void extend(List l)
{
    /* Copia a lista e concatena as listas fazendo jogo de ponteiro */
    Iterator it = iter(self);
    for (Objeto o = next(it); o != NULL; next(it))
    {
    }
}

Objeto pop(int index)
{
    ListaEnc *lista = ((List)self)->__list__;
    if (lista->inicio == NULL)
    {
        printf("IndexError: pop from empty list\n");
        exit(1);
    }

    Node *aux = lista->final;
    lista->final = aux->ant;

    if (lista->final != NULL)
    {
        lista->final->prox = NULL;
    }
    else
    {
        lista->inicio = NULL;
    }

    Objeto obj = aux->obj;
    free(aux);
    lista->length--;

    return obj;
}

int index(Objeto obj, Comparator c)
{
    /* Itera e retorna */
    Iterator it = iter(self);
    size_t i = 0;
    for (Objeto o = next(it); o != NULL; next(it))
    {
        if (c(o))
        {
            return i;
        }
        i++;
    }
}

int count(Objeto obj, Comparator c)
{
    /* Itera contando*/
    Iterator it = iter(self);
    size_t i = 0;
    for (Objeto o = next(it); o != NULL; next(it))
    {
        if (c(o))
        {
            i++;
        }
    }
    return i;
}

void insert(int index, Objeto obj)
{
    /* Itera e insere */
    Node* iterator;
    size_t i = 0;
    for (iterator = ((ListaEnc*)((List)self)->__list__)->inicio;iterator != NULL; iterator = iterator->prox)
    {
        if (index == i)
        {
            Node *aux = calloc(1, sizeof(Node));
            aux->obj = obj;
            if (iterator->ant != NULL)
            {
                iterator->ant->prox = aux;
            }
            if (iterator->prox != NULL)
            {
                iterator->prox->ant = aux;
            }
            iterator->ant = aux;
            aux->prox = iterator;            
        }
        i++
    }
    
}

void removeitem(Objeto obj)
{
    /* Itera e remove */
    Node* iterator;
}

size_t __len__()
{
    return ((ListaEnc *)(((List)self)->__list__))->length;
}

Iterator __iter__()
{
    Iterator it = newIterator(true);
    return it;
}

Iterator __reversed__()
{
    Iterator it = newIterator(false);
    return it;
}

List newList()
{
    List this = calloc(1, sizeof(struct StList));
    this->self = this;
    return this;
}

Enumerate *enumerate(Iterable __iterable, Iterator __iterator)
{
    // Iterator it = iter(self); Já vem como parâmetro
    Enumerate temp;
    Enumerate *e = &temp;
    Objeto obj = next(__iterator);
    if (obj)
    {
        e->index = __enumer;
        e->obj = obj;
        return e;
    }
    __enumer = 0;
    return NULL;
}
