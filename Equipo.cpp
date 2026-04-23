#include <iostream>
#include "Equipo.h"
using namespace std;


Equipo::Equipo() {
    id="";
    criticidad=0;
    estado=0;
    inactividad=0;
    cantidadIncidencias=0;
    estrategia=nullptr;
    desgaste=0.0;

    //Inicializamos el array donde se van a guardar las incidencias
    for (int i=0;i<50;i++) {
        incidencias[i]=nullptr;
    }
}
Equipo::Equipo(string ide, int c, int e, int in, int ci, double d)
    : id(ide),
      criticidad(c),
      estado(e),
      inactividad(in),
      cantidadIncidencias(ci),
      desgaste(d),
      estrategia(nullptr)
{



    for (int i=0;i<50;i++) {
        incidencias[i]=nullptr;
    }
}

    //Recibimos una incidencia y la agregamos a un equipo

    void Equipo::agregarIncidencia(Incidencia* inc) {
    // aqui hay que hacer excepciones
        if (cantidadIncidencias<50) {
            incidencias[cantidadIncidencias]=inc;
            cantidadIncidencias++;

            cout<<"Se registro la incidencia del equipo: "<<id<<endl;

        }


    }

    // Es el proceso de realizacion del mantenimiento

    void Equipo::RecibirMantenimiento() {

    if (estado==1) {
        cout<<"El equipo ya esta en mantenimiento"<<endl;
    }
    cout<<"Iniciando mantenimiento del equipo"<<id<<endl;

    estado=1;  //1="en mantenimiento"

    //Mientras el equipo esta en mantenimiento, la inactividad del equipo aumenta
    inactividad++;


}
    double Equipo::calcularPrioridad() {

    double prioridad=0;
    cout<<"Calculando prioridad del equipo: "<<id<<endl;

    // Se calcula mediante formula

    prioridad = ( criticidad * 0.5) +(cantidadIncidencias*0.3)+(inactividad*0.2);

    return prioridad;
    cout<<"Prioridad del equipo: "<< id << "calculada:"<< prioridad <<endl;


}

//Con este metodo podemos asignarle un tipo de mantenimiento, en este caso si recibe o no mantenimiento, e sun tipo de constructor
void Equipo:: setEstrategia(EstrategiaMantenimiento* e) {
    estrategia=e;

}


