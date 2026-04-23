#include "Simulador.h"
#include "Equipo.h"
#include "MantenimientoCorrectivo.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Simulador::ejecutar30Dias(string directorioSalida) {

    ofstream archivo(directorioSalida + "reporte.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    archivo << "=== SIMULACION DE 30 DIAS ===\n";

    // Estrategia de mantenimiento
    EstrategiaMantenimiento* estrategia = new MantenimientoCorrectivo();

    for (int dia = 1; dia <= 30; dia++) {

        archivo << "\n===== DIA " << dia << " =====\n";

        //  Desgaste diario de todos los equipos
        for (int i = 0; i < laboratorio.getCantidad(); i++) {

            Equipo* eq = laboratorio.getEquipo(i);

            if (eq != nullptr) {
                eq->depreciarporDia(dia);
            }
        }

        // Aplicar mantenimiento a los 3 equipos de prioridad diaria
        laboratorio.atenderTop3(estrategia);

        archivo << "Mantenimiento aplicado a los 3 equipos de mayor prioridad\n";
    }

    delete estrategia;
    archivo.close();

    cout << "Simulacion completada correctamente" << endl;
}



void Simulador::aplicarRevisionEspecial(Equipo* equipo) {
    if (equipo != nullptr) {

        EstrategiaMantenimiento* estrategia = new MantenimientoCorrectivo();

        estrategia->aplicar(equipo);

        laboratorio.registrarMantenimientoRealizado(equipo);

        delete estrategia;
    }
}