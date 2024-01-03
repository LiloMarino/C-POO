#ifndef LIST_H
#define LIST_H

#include "../CVM.h"
#include "Iterator.h"

typedef struct StList *List;
typedef List Iterable;

extern size_t __enumer;

struct StList
{
    List self;                         // Ponteiro para ela mesma
    Objeto __list__;                   // Ponteiro para a lista
    List (*copy)();                    // Gera uma cópia rasa da lista
    void (*append)(Objeto);            // Adiciona o objeto no final da lista
    void (*extend)(Iterable);          // Concatena as listas
    Objeto (*pop)(int index);          // Remove o objeto da lista do índice e o retorna, caso o índice seja -1 remove do final da lista
    int (*index)(Objeto, Comparator);  // Retorna o índice do objeto
    int (*count)(Objeto, Comparator);  // Conta quantas vezes o objeto se repete na lista
    void (*insert)(int index, Objeto); // Insere o objeto no índice e "empurra" os outros elementos para frente
    void (*remove)(Objeto);            // Remove o objeto da lsita
    size_t (*__len__)();               // Retorna o tamanho da lista
    Iterator (*__iter__)();            // Retorna o iterador da lista
    Iterator (*__reversed__)();        // Retorna o iterador reverso da lista
};

List newList();

/*
Exemplo de uso:
for (size_t i = 0; i < len(Iterable __iterable); Enumerate e = enumerate(Iterable __iterable, Iterator __iterator))
{
    e => (index, objeto)
}
 */
Enumerate *enumerate(Iterable __iterable, Iterator __iterator);

#endif