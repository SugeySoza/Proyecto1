//
// Created by gabriel on 22/4/26.
//

#ifndef PROYECTO1_PCBASICA_H
#define PROYECTO1_PCBASICA_H

#include "Equipo.h"

class PCBasica : public Equipo {
    public:
    PCBasica();
    PCBasica(string id, int criticidad, int estado, int inactividad, double desgaste);
    void depreciarporDia(int diaActual) override;
    std::string getId () override;
};


#endif //PROYECTO1_PCBASICA_H