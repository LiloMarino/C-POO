#ifndef BUILTIN_LIST_H
#define BUILTIN_LIST_H

#include "List.h"
#include "Iterator.h"

typedef Objeto (*Mapper)(Objeto o);
typedef bool (*Filter)(Objeto o);
typedef Objeto (*Reduce)(Objeto acumulador, Objeto o);

Objeto next(Iterator i);

size_t len(Iterable i);

Iterator iter(Iterable i);

Iterable map(Mapper f, Iterable i);

Iterable filter(Filter f, Iterable i);

Objeto reduce(Reduce f, Iterable i);

#endif