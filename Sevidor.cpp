//
// Created by gabriel on 22/4/26.
//

#include "Sevidor.h"

void Sevidor::depreciarporDia( int diaActual) {
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
        cout<<"El equipo "<<id<<"ha fallado por desgaste"<<endl;

    }
}

std::string Sevidor::getId() { return "Sevidor"; }

void Sevidor::optimizarRecursos(){
    cout << "Se ha optimizado los recursos del servidor." << endl;
}
//