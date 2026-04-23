#include <iostream>
#include "Laboratorio.h"
#include "Simulador.h"
#include "PCBasica.h"
#include "Servidor.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    // 1. Crear laboratorio
    Laboratorio* lab = new Laboratorio();

    // 2. Crear equipos
    Equipo* e1 = new PCBasica("PC1", 8, 0, 2, 10.0);
    Equipo* e2 = new PCBasica("PC2", 5, 0, 1, 5.0);
    Equipo* e3 = new Servidor("SV1", 9, 0, 3, 20.0);
    Equipo* e4 = new Servidor("SV2", 7, 0, 2, 15.0);

    // 3. Registrar equipos en laboratorio
    lab->registrarEquipo(e1);
    lab->registrarEquipo(e2);
    lab->registrarEquipo(e3);
    lab->registrarEquipo(e4);

    // 4. Crear simulador
    Simulador sim(lab);

    // 5. Ejecutar simulación
    sim.ejecutar30Dias("./");

    // 6. Liberar memoria
    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete lab;

    return 0;
}