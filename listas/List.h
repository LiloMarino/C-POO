#ifndef LIST_H
#define LIST_H

#include "../CVM.h"
#include "Iterator.h"

typedef List Iterable;
typedef struct StList List;

struct StList
{
    List *self;                        // Ponteiro para ela mesma
    Objeto *__list__;                 // Ponteiro para a lista
    List (*copy)();                    // Gera uma cópia rasa da lista
    void (*append)(Objeto);            // Adiciona o objeto no final da lista
    void (*extend)(Iterable);          // Concatena as listas
    Objeto (*pop)(int index);          // Remove o objeto da lista do índice e o retorna, caso o índice seja -1 remove do final da lista
    int (*index)(Objeto);              // Retorna o índice do objeto
    int (*count)(Objeto);              // Conta quantas vezes o objeto se repete na lista
    void (*insert)(int index, Objeto); // Insere o objeto no índice e "empurra" os outros elementos para frente
    void (*remove)(Objeto);            // Remove o objeto da lsita
    int (*__len__)();                  // Retorna o tamanho da lista
    Iterator (*__iter__)();            // Retorna o iterador da lista
    Iterator (*__reversed__)();        // Retorna o iterador reverso da lista
};

List newList();

List This(List l);

#endif