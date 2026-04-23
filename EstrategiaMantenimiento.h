#include<iostream>
using namespace std;
#ifndef PROYECTO1_ESTRATEGIAMANTENIMIENTO_H
#define PROYECTO1_ESTRATEGIAMANTENIMIENTO_H


class EstrategiaMantenimiento {

   //Clase funciona como interfaz para implementar el didiseño Strategy
public:
   virtual void aplicar(Equipo* equipo)=0;
   virtual string descripcion(Equipo* e)=0;
   virtual ~EstrategiaMantenimiento(){}



};


#endif //PROYECTO1_ESTRATEGIAMANTENIMIENTO_H