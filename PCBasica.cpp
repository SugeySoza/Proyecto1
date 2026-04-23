//
// Created by gabriel on 22/4/26.
//

#include "PCBasica.h"

PCBasica::PCBasica() {
}

PCBasica::PCBasica(string id, int criticidad, int estado, int inactividad, double desgaste):Equipo(id,criticidad,estado,inactividad,desgaste) {//Constructor para crear un objeto de esta clase
}

void PCBasica::depreciarporDia(int diaActual) {
    cout<<"Dia:"<< diaActual <<" depreciando equipo "<<id<<endl;

    inactividad++; //cada dia que pasa aumenta la inactividad

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

string PCBasica::getId() { return id; }
