#include "../CVM.h"
#include "List.h"
#include <stdio.h>

int printInt(Objeto obj)
{
    int i = *((int *)obj);
    print_generic(i);
}

int main()
{
    CVM();
    List l = newList();
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    for (size_t i = 0; i < 10; i++)
    {
        ((List)This(l))->append(&v[i]);
    }
    print_list(l,printInt);
}