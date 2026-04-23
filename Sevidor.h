//
// Created by gabriel on 22/4/26.
//

#ifndef PROYECTO1_SEVIDOR_H
#define PROYECTO1_SEVIDOR_H

#include "Equipo.h"

class Sevidor : public Equipo {
public:
    void depreciarporDia(int diaActual) override;
    std::string getId();
    void optimizarRecursos();
};


#endif //PROYECTO1_SEVIDOR_H