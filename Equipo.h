#include<iostream>
using namespace std;


#ifndef PROYECTO1_EQUIPO_H
#define PROYECTO1_EQUIPO_H

class Incidencia;
class EstrategiaMantenimiento;

class Equipo {
protected:
    string id;
    int criticidad;
    int estado;
    int inactividad;
    Incidencia* incidencias[50];
    int cantidadIncidencias;
    EstrategiaMantenimiento* estrategia;
    double desgaste;
public:
    Equipo();
        Equipo(string,int ,int ,int,double);
    void agregarIncidencia(Incidencia* inc);
    void RecibirMantenimiento();
    double calcularPrioridad();
    void setEstrategia(EstrategiaMantenimiento* e);
    virtual void depreciarporDia(int diaActual)=0;
    virtual string getId()=0;
    int getEstado();
    double getDesgaste();
    void setDesgaste(double d);
    void bajarDesgaste(double cantidad);
    void setEstado(int e);
    void setInactividad(int i);
    virtual~Equipo();
};


#endif //PROYECTO1_EQUIPO_H