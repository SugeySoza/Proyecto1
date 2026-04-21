#include<iostream>
using namespace std;


#ifndef PROYECTO1_EQUIPO_H
#define PROYECTO1_EQUIPO_H

class Incidencia;

class Equipo {
private:
    string id;
    int criticidad;
    int estado;
    int inactividad;
    Incidencia* incidencias[50];
    int cantidadIncidencias;


public:
    Equipo();
    Equipo(string,int ,int ,int ,int );
    void agregarIncidencia(Incidencia* inc);
    void RecibirMantenimiento();
    void calcularPrioridad();
    void depreciar();


};


#endif //PROYECTO1_EQUIPO_H