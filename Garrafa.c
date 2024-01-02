#include "CVM.h"
#include "Garrafa.h"
#include <stdlib.h>


Garrafa *self;

bool isTampada()
{
    return self->tampada;
}

void abrirGarrafa()
{
    self->tampada = true;
}

void fecharGarrafa()
{
    self->tampada = false;
}

void setLitros(int L)
{

    self->litros = L;
}

int getLitros()
{
    return self->litros;
}

Garrafa newGarrafa()
{
    Garrafa *self = calloc(1, sizeof(Garrafa));
    self->self = self;
    self->tampada = true;
    self->isTampada = isTampada;
    self->abrirGarrafa = abrirGarrafa;
    self->fecharGarrafa = fecharGarrafa;
    self->setLitros = setLitros;
    self->getLitros = getLitros;
    return *self;
}


Garrafa This(Garrafa g)
{
    self = g.self;
    return *self;
}
