#include<iostream>
#include"Incidencia.h"

#ifndef PROYECTO1_LABORATORIO_H
#define PROYECTO1_LABORATORIO_H

#include <string>
#include "Equipo.h"
#include "Algoritmos.h"

class Laboratorio {

private:
    Equipo* equipos[100];
    string idsOrdenados[100];
    int cantidad;
    Incidencia* incidencias[300];
    int cantidadIncidencias;
    int equiposActivos;
    int equiposCriticos;


public:
    // Constructor
    Laboratorio();

    // Métodos principales
    void registrarEquipo(Equipo* equipo);
    Equipo* buscarEquipoPorId(string id);
    void registrarMantenimientoRealizado(Equipo* eq);
    double riesgoGlobalPromedio();
    void atenderTop3(EstrategiaMantenimiento* estrategia);
    void agregarIncidencia(Incidencia* inc);
    void actualizarMetricas();


    // Métodos necesarios para Simulador
    int getCantidad();
    Equipo* getEquipo(int i);
};

#endif