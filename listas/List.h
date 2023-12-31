#ifndef LIST_H
#define LIST_H

#include "../CVM.h"
#include "Iterator.h"

typedef struct StList *List;
typedef List Iterable;

extern size_t __enumer;

struct StList
{
    List self;                            // Ponteiro para ela mesma
    Objeto __list__;                      // Ponteiro para a lista
    List (*copy)();                       // Gera uma cópia rasa da lista
    void (*append)(Objeto);               // Adiciona o objeto no final da lista
    void (*extend)(Iterable);             // Concatena as listas
    Objeto (*pop)(long index);            // Remove o objeto da lista do índice e o retorna, caso o índice seja -1 remove do final da lista
    int (*index)(Objeto, Comparator);     // Retorna o índice do objeto
    int (*count)(Objeto, Comparator);     // Conta quantas vezes o objeto se repete na lista
    void (*insert)(size_t index, Objeto); // Insere o objeto no índice e "empurra" os outros elementos para frente
    void (*remove)(Objeto, Comparator);   // Remove o objeto da lsita
    size_t (*__len__)();                  // Retorna o tamanho da lista
    Iterator (*__iter__)();               // Retorna o iterador da lista
    Iterator (*__reversed__)();           // Retorna o iterador reverso da lista
};

List newList();

/*
Exemplo de uso:
Iterator it = iter(Iterable i);
for (Enumerate* e = enumerate(it); e != NULL; e = enumerate(it))
{
    e => (index, obj)
}
 */
Enumerate *enumerate(Iterator __iterator);

void print_list(List l, Printer p);

void print_enum_list(Iterator __iterator, Printer p);

#endif