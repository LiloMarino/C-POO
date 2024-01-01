#ifndef BUILTIN_LIST_H
#define BUILTIN_LIST_H

#include "List.h"
#include "Iterator.h"

Objeto next(Iterator i);

int len(Iterable i);

Iterator iter(Iterable i);

Iterable map(Function f, Iterable i);

Iterable filter(Function f, Iterable i);

Iterable reduce(Function f, Iterable i);

#endif