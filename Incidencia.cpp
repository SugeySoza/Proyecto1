
#include "Incidencia.h"
#include<iostream>
#include"Severidad.h"
using namespace std;


Incidencia::Incidencia(string eqi,int d,bool a) {
    equipoId=eqi;
    diaOrigen=d;
    activa=a;


}
bool Incidencia:: estaActiva() {
  return activa;
}
void Incidencia:: cerrar() {
    if (activa) {
        activa=false;
        cout<<"Incidencia del equipo:"<< equipoId <<"se ha cerrado"<<endl;
    }
    else {
        cout<<"Incidencia del equipo:"<< equipoId <<"ya estaba resuelta"<<endl;
    }
}