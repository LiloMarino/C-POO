#include "CVM.h"
#include "Iterator.h"
#include "List.h"
#include <stdlib.h>

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
    int length;
} ListaEnc;

List *self;

List copy()
{
    /* Itera copiando */
}

void append(Objeto obj)
{
    ListaEnc *lista = self->__list__;
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
}

Objeto pop(int index)
{
    ListaEnc *lista = self->__list__;
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

int index(Objeto obj)
{
    /* Itera e retorna */
}

int count(Objeto obj)
{
    /* Itera contando*/
}

void insert(int index, Objeto obj)
{
    /* Itera e insere */
}

void remove(Objeto obj)
{
    /* Itera e remove */
}

int __len__()
{
    return ((ListaEnc *)(self->__list__))->length;
}

Iterator __iter__()
{
    Iterator it = newIterator();
}

Iterator __reversed__()
{
    Iterator it = newIterator();
}

List newList()
{
    List *this = calloc(1, sizeof(List));
    this->self = this;
    return *this;
}

List This(List l)
{
    self = l.self;
    return *self;
}
