#ifndef GARRAFA_H
#define GARRAFA_H

#include <stdbool.h>

struct StGarrafa
{
    struct StGarrafa *self;
    bool tampada;
    int litros;
    bool (*isTampada)();
    void (*abrirGarrafa)();
    void (*fecharGarrafa)();
    void (*setLitros)(int);
    int (*getLitros)();

}; // Atributos e Métodos públicos
typedef struct StGarrafa * Garrafa;

Garrafa newGarrafa(); // Static e Público

#endif
