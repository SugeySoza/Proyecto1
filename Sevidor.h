//
// Created by gabriel on 22/4/26.
//

#ifndef PROYECTO1_SEVIDOR_H
#define PROYECTO1_SEVIDOR_H

#include "Equipo.h"

class Sevidor : public Equipo {
public:
    void degradarPorDia( int diaActual );
    std::string getTipo();
    void optimizarRecursos();
};


#endif //PROYECTO1_SEVIDOR_H