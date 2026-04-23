//
// Created by gabriel on 22/4/26.
//

#ifndef PROYECTO1_PCBASICA_H
#define PROYECTO1_PCBASICA_H

#include "Equipo.h"

class PCBasica : public Equipo {
    public:
    void depreciarporDia(int diaActual) override;
    std::string getId () override;
};


#endif //PROYECTO1_PCBASICA_H