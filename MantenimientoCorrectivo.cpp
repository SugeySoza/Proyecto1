
#include "MantenimientoCorrectivo.h"
#include<iostream>
using namespace std;

// Se va a implementar solo esta clase hija de la interfaz ya que por la naturaleza del programa, solo se pide mantenimiento correctivo, quedando abierto el patron de diseño para agregar nuevos tipos de mantenimientos

 void MantenimientoCorrectivo:: aplicar(Equipo* equipo) {
  if (equipo!=nullptr) {
   cout<<"Recibiendo mantenimiento a equipo:"<< equipo->getId()<<endl;
  }
 }
 string MantenimientoCorrectivo::descripcion(Equipo* equipo) {
  if (equipo!=nullptr) {
   return"Mantenimiento correctivo a equipo #: " + equipo->getId();
  }
  return "Equipo no valido";
 }



MantenimientoCorrectivo:: ~MantenimientoCorrectivo(){}