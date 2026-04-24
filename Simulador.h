#include<iostream>
#include"Laboratorio.h"
#include"Incidencia.h"
#include<string>
using namespace std;

#ifndef PROYECTO1_SIMULADOR_H
#define PROYECTO1_SIMULADOR_H

class Equipo;
class Simulador {
private:
    Laboratorio laboratorio;
public:
    void ejecutar30Dias(string directorioSalida);
    void  aplicarRevisionEspecial(Equipo* equipo);

};


#endif //PROYECTO1_SIMULADOR_H