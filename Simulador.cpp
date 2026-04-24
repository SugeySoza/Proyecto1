#include "Simulador.h"
#include "Equipo.h"
#include "MantenimientoCorrectivo.h"
#include "Incidencia.h"
#include "Severidad.h"
#include <iostream>
#include <fstream>

using namespace std;

void Simulador::ejecutar30Dias(string directorioSalida) {

    ofstream archivo(directorioSalida + "reporte.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    archivo << "=== SIMULACION DE 30 DIAS ===\n";

    EstrategiaMantenimiento* estrategia = new MantenimientoCorrectivo();

    for (int dia = 1; dia <= 30; dia++) {

        archivo << "\n===== DIA " << dia << " =====\n";

        int cantidad = laboratorio.getCantidad();

        // 1. Degradación de equipos
        for (int i = 0; i < cantidad; i++) {

            Equipo* eq = laboratorio.getEquipo(i);

            if (eq != nullptr) {
                eq->depreciarporDia(dia);
            }
        }

        // 2. Generación de incidencias
        for (int i = 0; i < cantidad; i++) {

            Equipo* eq = laboratorio.getEquipo(i);

            if (eq != nullptr && eq->getEstado() < 0.7) {

                Severidad sev;

                if (eq->getEstado() < 0.3)
                    sev = Severidad::CRITICA;
                else if (eq->getEstado() < 0.5)
                    sev = Severidad::ALTA;
                else if (eq->getEstado() < 0.7)
                    sev = Severidad::MEDIA;
                else
                    sev = Severidad::BAJA;

                Incidencia* inc = new Incidencia(eq->getId(),sev,dia,true);


                laboratorio.agregarIncidencia(inc);
            }
        }

        // 3. Cálculo de prioridades
        for (int i = 0; i < laboratorio.getCantidad(); i++) {

            Equipo* eq = laboratorio.getEquipo(i);

            if (eq != nullptr) {

                double prioridad = eq->calcularPrioridad();

                cout << "Prioridad " << prioridad <<" del equipo # "<<eq->getId()<< endl;
            }
        }

        // 4. Orden + 5. selección + 6. mantenimiento
        laboratorio.atenderTop3(estrategia);

        archivo << "Mantenimiento aplicado a top 3 equipos\n";

        // 7. actualización global
        laboratorio.actualizarMetricas();

        // 8. registro diario
        archivo << "Degradacion aplicada\n";
        archivo << "Incidencias generadas\n";
        archivo << "Prioridades actualizadas\n";
        archivo << "Metricas actualizadas\n";
    }

    delete estrategia;
    archivo.close();

    cout << "Simulacion completada correctamente" << endl;
}