#include "Built-in.h"

Objeto next(Iterator i)
{
    return ((Iterator)This(i))->__next__();
}

size_t len(Iterable i)
{
    return ((List)This(i))->__len__();
}

Iterator iter(Iterable i)
{
    return ((List)This(i))->__iter__();
}

// A função "map" recebe um Iterable "i" e um ponteiro para uma função "f" que será aplicada em cada elemento da lista.
// Ela retorna uma nova lista com os elementos transformados pela função "f".
Iterable map(Mapper f, Iterable i)
{
    List l = newList();
    Iterator it = iter(i);
    for (Objeto obj = next(it); it != NULL; obj = next(it))
    {
        ((List)This(l))->append(f(obj));
    }
    return l;
}

// A função "filter" é similar à função "map", porém seleciona apenas os elementos que satisfazem a condição imposta por "f".
// Ela recebe um Iterable "i" e um ponteiro para uma função "f" que retorna true ou false.
// A função retorna uma nova lista contendo apenas os itens que satisfazem a condição.
Iterable filter(Filter f, Iterable i)
{
    List l = newList();
    Iterator it = iter(i);
    for (Objeto obj = next(it); it != NULL; obj = next(it))
    {
        if (f(obj))
        {
            ((List)This(l))->append(obj);
        }
    }
    return l;
}

// A função "reduce" é usada para reduzir o Iterable "i" a um único valor, aplicando a função "f" sucessivamente em cada item da lista.
// Ela recebe Iterable "i" e um ponteiro para uma função "f"
Objeto reduce(Reduce f, Iterable i)
{
    Objeto acumulador;
    Iterator it = iter(i);
    for (Objeto obj = next(it); it != NULL; obj = next(it))
    {
        acumulador = f(acumulador,obj);
    }
    return acumulador;
}
