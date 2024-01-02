#ifndef BUILTIN_LIST_H
#define BUILTIN_LIST_H

#include "List.h"
#include "Iterator.h"

typedef Objeto (*Function)(Objeto o);
typedef Objeto (*Reduce)(Objeto acumulador, Objeto o);

Objeto next(Iterator i);

int len(Iterable i);

Iterator iter(Iterable i);

Iterable map(Function f, Iterable i);

Iterable filter(Function f, Iterable i);

Objeto reduce(Reduce f, Iterable i);

#endif