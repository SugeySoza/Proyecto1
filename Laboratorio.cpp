
#include "Laboratorio.h"
#include <iostream>
#include"EstrategiaMantenimiento.h"

using namespace std;

// Constructor
Laboratorio::Laboratorio() {
    cantidad = 0;
    cantidadIncidencias=0;
    equiposActivos=0;
    equiposCriticos=0;


    for (int i = 0; i < 100; i++) {
        equipos[i] = nullptr;
        idsOrdenados[i] = "";
    }
    for (int i=0;i<300;i++) {
        incidencias[i]=nullptr;


    }
}

// Registrar equipo
void Laboratorio::registrarEquipo(Equipo* equipo) {
    if (cantidad < 100 && equipo != nullptr) {
        equipos[cantidad] = equipo;
        idsOrdenados[cantidad] = equipo->getId();
        cantidad++;
    }
}

// Buscar equipo por ID
Equipo* Laboratorio::buscarEquipoPorId(string id) {
    for (int i = 0; i < cantidad; i++) {
        if (equipos[i] != nullptr && equipos[i]->getId() == id) {
            return equipos[i];
        }
    }
    return nullptr;
}

// Registrar mantenimiento (ejemplo básico)
void Laboratorio::registrarMantenimientoRealizado(Equipo* eq) {
    if (eq != nullptr) {
        cout << "Mantenimiento registrado para equipo: "
             << eq->getId() << endl;
    }
}

// Calcular riesgo promedio
double Laboratorio::riesgoGlobalPromedio() {

    if (cantidad == 0) {
        throw runtime_error("No hay equipos registrados");
    }

    double suma = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {
        if (equipos[i] != nullptr) {
            suma += equipos[i]->calcularPrioridad();
            contador++;
        }
    }

    if (contador == 0) return 0;

    return suma / contador;
}

// Obtener cantidad de equipos
int Laboratorio::getCantidad() {
    return cantidad;
}

// Obtener equipo por índice
Equipo* Laboratorio::getEquipo(int i) {
    if (i >= 0 && i < cantidad) {
        return equipos[i];
    }
    return nullptr;
}
// Escoge los 3 equipos que se van atender

void Laboratorio:: atenderTop3(EstrategiaMantenimiento* estrategia) {

    /*int n = cantidad;

    Equipo* lista[100];
    double prioridades[100];

    // copiar datos
    for (int i = 0; i < n; i++) {
        lista[i] = equipos[i];
        if (equipos[i] != nullptr) {
            prioridades[i] = equipos[i]->calcularPrioridad();
        }
    }

    // ordenar (burbuja)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (prioridades[j] < prioridades[j + 1]) {

                // swap prioridades
                double tempP = prioridades[j];
                prioridades[j] = prioridades[j + 1];
                prioridades[j + 1] = tempP;

                // swap equipos
                Equipo* tempE = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tempE;
            }
        }
    }

    // aplicar a top 3
    int limite = (n < 3) ? n : 3;

    for (int i = 0; i < limite; i++) {

        if (lista[i] != nullptr) {

            estrategia->aplicar(lista[i]);

            registrarMantenimientoRealizado(lista[i]);
        }
    }
    */
    Equipo* lista[100];

    // Copiar equipos a una lista auxiliar
    for (int i = 0; i < cantidad; i++) {
        lista[i] = equipos[i];
        if (lista[i] != nullptr) {
            lista[i]->calcularPrioridad();
        }
    }
    // Ordenar usando QuickSort propio
    Algoritmos::ordenarEquiposPorPrioridadDesc(lista, cantidad);
    // Atender solo los 3 más prioritarios
    int limite = 3;

    if (cantidad < 3) {
        limite = cantidad;
    }

    for (int i = 0; i < limite; i++) {
        if (lista[i] != nullptr) {
            estrategia->aplicar(lista[i]);
            registrarMantenimientoRealizado(lista[i]);
        }
    }
}

void Laboratorio::agregarIncidencia(Incidencia *inc) {
    if (inc!= nullptr&&cantidadIncidencias<300) {
        incidencias[cantidadIncidencias]=inc;
        cantidadIncidencias++;

        cout<<"Incidencia agregada con exito"<<endl;
    }
}
void Laboratorio::actualizarMetricas() {

    int activos = 0;
    int criticos = 0;

    for (int i = 0; i < cantidad; i++) {

        Equipo* eq = equipos[i];

        if (eq != nullptr) {

            if (eq->getEstado() == 0)
                activos++;

            if (eq->getEstado() == 2)
                criticos++;
        }
    }

    this->equiposActivos = activos;
    this->equiposCriticos = criticos;
}

