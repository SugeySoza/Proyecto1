
#include "Incidencia.h"

using namespace std;

// Constructor
Incidencia::Incidencia(string eqi, Severidad s, int d, bool a) {
    equipoId = eqi;
    severidad = s;
    diaOrigen = d;
    activa = a;
}

// Saber si está activa
bool Incidencia::estaActiva() {
    return activa;
}

// Cerrar incidencia
void Incidencia::cerrar() {
    if (activa) {
        activa = false;
        cout << "Incidencia del equipo " << equipoId << " cerrada" << endl;
    } else {
        cout << "La incidencia ya estaba cerrada" << endl;
    }
}

// Getters
string Incidencia::getEquipoId() {
    return equipoId;
}

Severidad Incidencia::getSeveridad() {
    return severidad;
}

int Incidencia::getDiaOrigen() {
    return diaOrigen;
}