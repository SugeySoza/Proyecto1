
#include "Laboratorio.h"
#include<iostream>
using namespace std;

void Laboratorio:: registrarEquipo(Equipo* equipo) {

    //validamos que el equipo no este nulo
    if (equipo==nullptr) {
        cout<<"Equipo es nulo"<<endl;
        return;
    }

    //validamos que aun haya espacio para equipo nuevo
    if (cantidad>=100) {
        cout<<"No hay espacio para mas equipos"<<endl;
        return;
    }
    //agregamos el equipo
    equipos[cantidad]=equipo;
    cantidad++;

    cout<<"Equipo registrado correctamente"<<endl;


}

//Buscamos un Id en los equipos registrados
Equipo* Laboratorio::buscarEquipoPorId(string id) {
    for (int i=0;i<cantidad;i++) {
        if (equipos[i]->getId()==id) {
            return equipos[i];
            cout<<"El Id buscado es:"<< id << " esta en la posicion:"<<i<<endl;
        }
    }
    //si no se encuentra el Id buscado
    return nullptr;
    cout<<"El equipo buscado con Id:"<< id << "no se encuentra registrado"<<endl;
}

//Registrar mantenimiento recibido en equipo
 void Laboratorio::registrarMantenimientoRealizado(Equipo* eq) {
    if (eq!=nullptr) {
        eq->RecibirMantenimiento();


        cout<< "Mantenimiendo de equipo: " << eq->getId() <<"registrado con exito"<<endl;
    }
    else {
        cout<<"Equipo nulo"<<endl;
    }
}

 //Calcula el riesgo promedio de los equipos
double Laboratorio:: riesgoGlobalPromedio() {

    // hacer validacion con throw (if cantidad==0)

    double suma=0;

    for (int i=0;i<cantidad;i++) {
        if (equipos[i]!=nullptr) {
       suma+= equipos[i]->calcularPrioridad();

        }
    }
     double promedio=suma/cantidad;
    cout<< "El riesgo global promedio es: " << promedio <<endl;

    return promedio;

}
