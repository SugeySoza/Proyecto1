//
// Created by gabriel on 23/4/26.
//

#ifndef PROYECTO1_ALGORITMOS_H
#define PROYECTO1_ALGORITMOS_H

#include <iostream>
#include <algorithm>

using namespace std;

#include "Equipo.h"

class Algoritmos
{
public:
    static void quicksortEquipo (Equipo** equipos, double lo, double high ); // equipos apuntaria a un vector de puntesros
    static void ordenarEquiposPorPrioridadDesc(Equipo** equipo); // Equipo apuntaria a un vector de punteros
    static int busquedaBinariaId(string** id, string idBuscado); // id apunta a un vector de punteros
};


#endif //PROYECTO1_ALGORITMOS_H