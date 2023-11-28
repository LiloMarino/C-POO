#include "CVM.h"
#include "Garrafa.h"
#include <stdlib.h>


Garrafa self;

bool isTampada()
{
    return self.this->tampada;
}

bool polimorfismo()
{
    return false;
}

void abrirGarrafa()
{
    self.this->tampada = true;
}

void fecharGarrafa()
{
    self.this->tampada = false;
}

void setLitros(int L)
{

    self.this->litros = L;
}

int getLitros()
{
    return self.this->litros;
}

Garrafa newGarrafa()
{
    Garrafa *this = calloc(1, sizeof(Garrafa));
    this->this = this;
    this->tampada = true;
    this->isTampada = isTampada;
    this->abrirGarrafa = abrirGarrafa;
    this->fecharGarrafa = fecharGarrafa;
    this->setLitros = setLitros;
    this->getLitros = getLitros;
    return *this;
}


Garrafa This(Garrafa g)
{
    self = g;
    return self;
}
