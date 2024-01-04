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
    List l = newList();
    Iterator it = iter(self);
    for (Objeto o = next(it); o != NULL; o = next(it))
    {
        ((List)This(l))->append(o);
    }
    return l;
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
    ListaEnc *lista1 = ((List)self)->__list__;
    ListaEnc *lista2 = (((List)l)->copy())->__list__;
    if (lista1->inicio == NULL)
    {
        lista1->inicio = lista2->inicio;
        lista1->final = lista2->final;
    }
    else
    {
        Node *q = lista1->final;
        q->prox = lista2->inicio;
        lista2->inicio->ant = q;
        lista1->final = lista2->final;
    }
    lista1->length += lista2->length;
    free(lista2);
}

Objeto pop(long int index)
{
    ListaEnc *lista = ((List)self)->__list__;
    Node *iterator;
    if (lista->inicio == NULL)
    {
        printf("IndexError: pop from empty list\n");
        exit(1);
    }
    if (index < 0)
    {
        iterator = lista->final;
        lista->final = iterator->ant;

        if (lista->final != NULL)
        {
            lista->final->prox = NULL;
        }
        else
        {
            lista->inicio = NULL;
        }
    }
    else
    {
        size_t i = 0;
        for (iterator = lista->inicio; iterator != NULL; iterator = iterator->prox)
        {
            if (index == i)
            {
                if (iterator == lista->inicio)
                {
                    if (iterator->prox != NULL)
                    {
                        lista->inicio = iterator->prox;
                        iterator->prox->ant = iterator->ant;
                    }
                    else
                    {
                        lista->inicio = NULL;
                        lista->final = NULL; // Atualiza também o ponteiro final quando a lista fica vazia
                    }
                }
                else if (iterator->prox != NULL)
                {
                    iterator->prox->ant = iterator->ant;
                    iterator->ant->prox = iterator->prox;
                }
                else
                {
                    iterator->ant->prox = NULL;
                    lista->final = iterator->ant; // Atualiza o ponteiro final quando o último elemento é removido
                }
                break;
            }
            i++;
        }
    }
    Objeto obj = iterator->obj;
    free(iterator);
    lista->length--;

    return obj;
}

int indexOf(Objeto obj, Comparator c)
{
    /* Itera e retorna */
    Iterator it = iter(self);
    size_t i = 0;
    for (Objeto o = next(it); o != NULL; o = next(it))
    {
        if (c(o, obj))
        {
            return i;
        }
        i++;
    }
    printf("ValueError: \'%p\' is not in list\n", obj);
    exit(1);
}

int count(Objeto obj, Comparator c)
{
    /* Itera contando*/
    Iterator it = iter(self);
    size_t i = 0;
    for (Objeto o = next(it); o != NULL; o = next(it))
    {
        if (c(o, obj))
        {
            i++;
        }
    }
    return i;
}

void insert(size_t index, Objeto obj)
{
    /* Itera e insere */
    Node *iterator;
    ListaEnc *lista = ((List)self)->__list__;
    size_t i = 0;
    for (iterator = lista->inicio; iterator != NULL; iterator = iterator->prox)
    {
        if (index == i)
        {
            Node *aux = calloc(1, sizeof(Node));
            aux->obj = obj;
            aux->prox = iterator;
            iterator->ant = aux;
            aux->ant = iterator->ant;
            if (aux->ant != NULL)
            {
                aux->ant->prox = aux;
            }
            else
            {
                lista->inicio = aux;
            }
            lista->length++;
        }
        i++;
    }
}

void removeItem(Objeto obj, Comparator c)
{
    /* Itera e remove */
    Node *iterator;
    ListaEnc *lista = ((List)self)->__list__;
    for (iterator = lista->inicio; iterator != NULL; iterator = iterator->prox)
    {
        if (c(iterator->obj, obj))
        {
            if (iterator == lista->inicio)
            {
                if (iterator->prox != NULL)
                {
                    lista->inicio = iterator->prox;
                    iterator->prox->ant = iterator->ant;
                }
                else
                {
                    lista->inicio = NULL;
                    lista->final = NULL; // Atualiza também o ponteiro final quando a lista fica vazia
                }
            }
            else if (iterator->prox != NULL)
            {
                iterator->prox->ant = iterator->ant;
                iterator->ant->prox = iterator->prox;
            }
            else
            {
                iterator->ant->prox = NULL;
                lista->final = iterator->ant; // Atualiza o ponteiro final quando o último elemento é removido
            }
            lista->length--;
            free(iterator);
        }
    }
}

size_t __len__()
{
    return ((ListaEnc *)(((List)self)->__list__))->length;
}

Iterator __iter__()
{
    Iterator it = newIterator(false);
    return it;
}

Iterator __reversed__()
{
    Iterator it = newIterator(true);
    return it;
}

List newList()
{
    ListaEnc *list = calloc(1, sizeof(ListaEnc));
    List this = calloc(1, sizeof(struct StList));
    this->self = this;
    this->__list__ = list;
    this->copy = copy;
    this->append = append;
    this->extend = extend;
    this->pop = pop;
    this->index = indexOf;
    this->count = count;
    this->insert = insert;
    this->remove = removeItem;
    this->__len__ = __len__;
    this->__iter__ = __iter__;
    this->__reversed__ = __reversed__;
    return this;
}

Enumerate *enumerate(Iterator __iterator)
{
    // Iterator it = iter(self); Já vem como parâmetro
    static Enumerate e;
    Objeto obj = next(__iterator);
    if (obj)
    {
        e.index = __enumer;
        e.obj = obj;
        __enumer++;
        return &e;
    }
    __enumer = 0;
    return NULL;
}

void print_list(List l, Printer p)
{
    Iterator it = iter(l);
    print_generic("[");
    for (Objeto obj = next(it); obj != NULL;)
    {
        p(obj);
        obj = next(it);
        if (obj)
        {
            print_generic(", ");
        }
    }
    print_generic("]\n");
}

void print_enum_list(Iterator __iterator, Printer p)
{
    Enumerate *e = enumerate(__iterator);
    print_generic("[");
    while (e)
    {
        print_generic("(");
        p(e->obj);
        print_generic(", ");
        print_generic(e->index);
        print_generic(")");
        e = enumerate(__iterator);
        if (e)
        {
            print_generic(", ");
        }
    }
    print_generic("]\n");
}
