//
// Created by gabriel on 22/4/26.
//

#include "Servidor.h"

Servidor::Servidor() {
}

Servidor::Servidor(string id, int criticidad, int estado, int inactividad, double desgaste):Equipo(id, criticidad, estado, inactividad, desgaste) {//Constructor para crear un objeto de esta clase
}

void Servidor::depreciarporDia( int diaActual) {
    cout<<"Dia:"<< diaActual <<" depreciando equipo "<<id<<endl;

    //Desgaste diario
    double desgasteDiario=0.5;
    //Desgaste por criticidad
    desgasteDiario+=criticidad*0.02;
    //Desgaste por incidencias
    desgasteDiario+=cantidadIncidencias *0.3;
    //Desgaste por inactividad
    desgasteDiario+=inactividad * 0.2;
    // Sumamos el desgaste acumulado
    desgaste+=desgasteDiario;

    //Desgaste total del equipo(equipo obsoleto)

    if (desgaste>=100) {
        estado=0;
        cout<<"El equipo "<< id <<"ha fallado por desgaste"<<endl;

    }
}

string Servidor::getId() { return id;}

void Servidor::optimizarRecursos(){
    cout << "Se ha optimizado los recursos del servidor." << endl;
}
//