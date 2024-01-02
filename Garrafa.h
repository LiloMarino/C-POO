#ifndef GARRAFA_H
#define GARRAFA_H

#include <stdbool.h>

typedef struct StGarrafa
{
    struct StGarrafa *self;
    bool tampada;
    int litros;
    bool (*isTampada)();
    void (*abrirGarrafa)();
    void (*fecharGarrafa)();
    void (*setLitros)(int);
    int (*getLitros)();

} Garrafa; // Atributos e Métodos públicos

Garrafa newGarrafa(); // Static e Público

Garrafa This(Garrafa g);

#endif
