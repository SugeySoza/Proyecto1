#ifndef INCIDENCIA_H
#define INCIDENCIA_H

#include <string>
#include <iostream>
#include "Severidad.h"

class Incidencia {
private:
    std::string equipoId;
    Severidad severidad;
    int diaOrigen;
    bool activa;

public:
    // Constructor
    Incidencia(std::string eqi, Severidad s, int d, bool a);

    // Métodos básicos
    bool estaActiva();
    void cerrar();

    // Getters
    std::string getEquipoId();
    Severidad getSeveridad();
    int getDiaOrigen();
};

#endif