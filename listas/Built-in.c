#include "Built-in.h"
// // A função "map" recebe uma lista "L" e um ponteiro para uma função "f" que será aplicada em cada elemento da lista.
// // Ela retorna uma nova lista com os elementos transformados pela função "f".
// Lista map(Lista L, Apply f, void *aux)
// {
//     Lista novaLista = createLst(((ListaInfo *)L)->capac);
//     Iterador it = createIterador(L, false);
//     while (!isIteratorEmpty(L, it))
//     {
//         Item item = getIteratorNext(L, it);
//         insertLst(novaLista, f(item, aux));
//     }
//     killIterator(it);
//     return novaLista;
// }

// // A função "filter" é similar à função "map", porém seleciona apenas os elementos que satisfazem a condição imposta por "f".
// // Ela recebe uma Lista "L" e um ponteiro para uma função "f" que retorna true ou false.
// // A função retorna uma nova lista contendo apenas os itens que satisfazem a condição.
// Lista filter(Lista L, Check f, void *aux)
// {
//     Lista novaLista = createLst(((ListaInfo *)L)->capac);
//     Iterador it = createIterador(L, false);
//     while (!isIteratorEmpty(L, it))
//     {
//         Item item = getIteratorNext(L, it);
//         if (f(item, aux))
//         {
//             insertLst(novaLista, item);
//         }
//     }
//     killIterator(it);
//     return novaLista;
// }

// // A função "fold" é usada para reduzir a lista L a um único valor, aplicando a função "f" sucessivamente em cada item da lista.
// // Ela recebe uma lista "L", um ponteiro para uma função "f" e uma Clausura "c".
// void fold(Lista L, ApplyClosure f, Clausura c)
// {
//     Iterador it = createIterador(L, false);
//     while (!isIteratorEmpty(L, it))
//     {
//         Item item = getIteratorNext(L, it);
//         f(item, c);
//     }
//     killIterator(it);

Objeto next(Iterator i)
{
    return i->__next__();
}

size_t len(Iterable i)
{
    return ((List)i)->__len__();
}

Iterator iter(Iterable i)
{
    return ((List)i)->__iter__();
}
