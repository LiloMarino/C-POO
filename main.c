#include "CVM.h"
#include "Garrafa.h"
#include <stdio.h>

int main()
{
    CVM();
    Garrafa g1 = newGarrafa();
    Garrafa g2 = newGarrafa();
    ((Garrafa)This(g2))->setLitros(50);
    ((Garrafa)This(g1))->abrirGarrafa();
    printf("A garrafa está aberta? %s\n", ((Garrafa)This(g1))->isTampada() == 1 ? "true" : "false");
    ((Garrafa)This(g1))->fecharGarrafa();
    printf("A garrafa está aberta? %s\n",((Garrafa)This(g1))->isTampada() == 1 ? "true" : "false");
    printf("Quantidade de litros na garrafa 1: %d\n", ((Garrafa)This(g1))->getLitros());
    printf("Quantidade de litros na garrafa 2: %d\n", ((Garrafa)This(g2))->getLitros());
}