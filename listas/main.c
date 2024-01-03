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
    List l1 = newList();
    int v[10] = {1,2,3,4,5,6,7,8,9,10};

    /* Append */
    for (size_t i = 0; i < 10; i++)
    {
        ((List)This(l1))->append(&v[i]);
    }
    print_list(l1,printInt);
    
    /* Copy */
    // List l2 = ((List)This(l1))->copy();
    // print_list(l1,printInt);
    // print_list(l2,printInt);

    // /* Extend */
    // ((List)This(l1))->extend(l2);
    // print_list(l1,printInt);
    // print_list(l2,printInt);
}