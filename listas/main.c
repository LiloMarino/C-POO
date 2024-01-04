#include "../CVM.h"
#include "Built-in.h"
#include "List.h"
#include <stdio.h>

void divideTela(const char *msg)
{
    printf("--------------------%s--------------------\n",msg);
}

int printInt(Objeto obj)
{
    int i = *((int *)obj);
    return print_generic(i);
}

int main()
{
    CVM();
    List l1 = newList();
    int v[10] = {1,2,3,4,5,6,7,8,9,10};

    /* Append */
    divideTela("APPEND");
    for (size_t i = 0; i < 10; i++)
    {
        ((List)This(l1))->append(&v[i]);
    }
    print_list(l1,printInt);
    
    /* Copy */
    divideTela("COPY");
    List l2 = ((List)This(l1))->copy();
    print_list(l1,printInt);
    print_list(l2,printInt);

    /* Extend */
    divideTela("EXTEND");
    ((List)This(l1))->extend(l2);
    print_list(l1,printInt);
    print_list(l2,printInt);
    
    /* Enumerate */
    divideTela("ENUMERATE");
    print_enum_list(iter(l1),printInt);
    Iterator it = iter(l1);
    for (Enumerate* e = enumerate(it); e != NULL; e = enumerate(it))
    {
        printf("V[%ld] = %d\n", e->index, *((int*)e->obj));
    }

    GarbageCollector();
}