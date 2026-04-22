#include<iostream>

#include "Equipo.h"
#ifndef PROYECTO1_LABORATORIO_H
#define PROYECTO1_LABORATORIO_H


class Laboratorio {

private:
    Equipo* equipos[100];
    string idsOrdenados[100];
    int cantidad;

public:
    void registrarEquipo(Equipo* equipo);
    Equipo* buscarEquipoPorId(string id);
    void registrarMantenimientoRealizado(Equipo* eq);
    double riesgoGlobalPromedio();


};


#endif //PROYECTO1_LABORATORIO_H