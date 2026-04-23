#include<iostream>

#ifndef PROYECTO1_LABORATORIO_H
#define PROYECTO1_LABORATORIO_H

#include <string>
#include "Equipo.h"

class Laboratorio {

private:
    Equipo* equipos[100];
    std::string idsOrdenados[100];
    int cantidad;

public:
    // Constructor
    Laboratorio();

    // Métodos principales
    void registrarEquipo(Equipo* equipo);
    Equipo* buscarEquipoPorId(std::string id);
    void registrarMantenimientoRealizado(Equipo* eq);
    double riesgoGlobalPromedio();
    void atenderTop3(EstrategiaMantenimiento* estrategia);

    // Métodos necesarios para Simulador
    int getCantidad();
    Equipo* getEquipo(int i);
};

#endif