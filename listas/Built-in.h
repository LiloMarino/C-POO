#ifndef BUILTIN_LIST_H
#define BUILTIN_LIST_H

#include "List.h"
#include "Iterator.h"

typedef Objeto (*Mapper)(Objeto o);
typedef bool (*Filter)(Objeto o);
typedef Objeto (*Reduce)(Objeto acumulador, Objeto o);

/**
 * @brief Retorna o próxmo objeto do iterador chamando a função __next__()
 * @param i Objeto iterável
 * @return Retorna o próximo objeto do iterável
 */
Objeto next(Iterator i);

/**
 * @brief Retorna o tamanho do Iterable i chamando a função __len__()
 * @param i Objeto iterável
 * @return Retorna o tamanho do iterável
 */
size_t len(Iterable i);

/**
 * @brief Retorna o iterador do Iterable i chamando a função __iter__()
 * @param i Objeto iterável
 * @return Retorna o iterador
 */
Iterator iter(Iterable i);

// A função "map" recebe um Iterable "i" e um ponteiro para uma função "f" que será aplicada em cada elemento da lista.
// Ela retorna uma nova lista com os elementos transformados pela função "f".
Iterable map(Mapper f, Iterable i);

// A função "filter" é similar à função "map", porém seleciona apenas os elementos que satisfazem a condição imposta por "f".
// Ela recebe um Iterable "i" e um ponteiro para uma função "f" que retorna true ou false.
// A função retorna uma nova lista contendo apenas os itens que satisfazem a condição.
Iterable filter(Filter f, Iterable i);

// A função "reduce" é usada para reduzir o Iterable "i" a um único valor, aplicando a função "f" sucessivamente em cada item da lista.
// Ela recebe Iterable "i" e um ponteiro para uma função "f"
Objeto reduce(Reduce f, Iterable i);

#endif