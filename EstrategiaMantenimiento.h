//
// Created by gabriel on 22/4/26.
//

#ifndef PROYECTO1_ESTRATEGIAMANTENIMIENTO_H
#define PROYECTO1_ESTRATEGIAMANTENIMIENTO_H

#include "Equipo.h"

class EstrategiaMantenimiento {
public:
    virtual void aplicar(Equipo* equipo) = 0;
    virtual std::string descripcion() = 0;
};


#endif //PROYECTO1_ESTRATEGIAMANTENIMIENTO_H