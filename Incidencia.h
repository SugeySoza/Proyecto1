#include<iostream>
#include"Severidad.h"
using namespace std;

#ifndef PROYECTO1_INCIDENCIA_H
#define PROYECTO1_INCIDENCIA_H

class Incidencia {
private:
    string equipoId;
    Severidad severidad;
    int diaOrigen;
    bool activa;

public:
    Incidencia(string,int,bool);
    bool estaActiva();
    void cerrar ();

};


#endif //PROYECTO1_INCIDENCIA_H