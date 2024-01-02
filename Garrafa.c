#include "CVM.h"
#include "Garrafa.h"
#include <stdlib.h>

bool isTampada()
{
    return ((Garrafa)self)->tampada;
}

void abrirGarrafa()
{
    ((Garrafa)self)->tampada = true;
}

void fecharGarrafa()
{
    ((Garrafa)self)->tampada = false;
}

void setLitros(int L)
{
    ((Garrafa)self)->litros = L;
}

int getLitros()
{
    return ((Garrafa)self)->litros;
}

Garrafa newGarrafa()
{
    Garrafa self = calloc(1, sizeof(struct StGarrafa));
    self->self = self;
    self->tampada = true;
    self->isTampada = isTampada;
    self->abrirGarrafa = abrirGarrafa;
    self->fecharGarrafa = fecharGarrafa;
    self->setLitros = setLitros;
    self->getLitros = getLitros;
    return self;
}
