#include "CVM.h"
#include "Garrafa.h"
#include <stdio.h>

int main()
{
    CVM();
    Garrafa g1 = newGarrafa();
    Garrafa g2 = newGarrafa();
    This(g2).setLitros(50);
    This(g1).abrirGarrafa();
    printf("A garrafa está aberta? %s\n",This(g1).isTampada() == 1 ? "true" : "false");
    This(g1).fecharGarrafa();
    printf("A garrafa está aberta? %s\n",This(g1).isTampada() == 1 ? "true" : "false");
    printf("Quantidade de litros na garrafa 1: %d\n", This(g1).getLitros());
    printf("Quantidade de litros na garrafa 2: %d\n", This(g2).getLitros());
}