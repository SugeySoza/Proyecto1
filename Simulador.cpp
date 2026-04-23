#include "Simulador.h"
#include "Equipo.h"
#include "MantenimientoCorrectivo.h"
#include "Incidencia.h"
#include "Severidad.h"
#include <iostream>
#include <fstream>

using namespace std;

Simulador::Simulador(Laboratorio *lab) {
    this->laboratorio = lab;
}

/*void Simulador::ejecutar30Dias(string directorioSalida) {
    ofstream archivo(directorioSalida + "reporte.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    archivo << "=== SIMULACION DE 30 DIAS ===\n";

    EstrategiaMantenimiento* estrategia = new MantenimientoCorrectivo();

    for (int dia = 1; dia <= 30; dia++) {

        archivo << "\n===== DIA " << dia << " =====\n";

        int cantidad = laboratorio->getCantidad();

        // 1. Degradación de equipos
        for (int i = 0; i < cantidad; i++) {

            Equipo* eq = laboratorio->getEquipo(i);

            if (eq != nullptr) {
                eq->depreciarporDia(dia);
            }
        }

        // 2. Generación de incidencias
        for (int i = 0; i < cantidad; i++) {

            Equipo* eq = laboratorio->getEquipo(i);

            /*if (eq != nullptr && eq->getEstado() < 0.7) {

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

            if (eq != nullptr && eq->getEstado() == 2) {

                Severidad sev = Severidad::ALTA;

                Incidencia* inc = new Incidencia(eq->getId(), sev, dia, true);

                laboratorio->agregarIncidencia(inc);
                eq->agregarIncidencia(inc);
            }
        }

            for (int i = 0; i < cantidad; i++) {

                Equipo* eq = laboratorio->getEquipo(i);

                if (eq != nullptr) {

                    // 1 de cada 5 días genera incidencia
                    if (rand() % 5 == 0) {

                        Severidad sev = Severidad::MEDIA;

                        Incidencia* inc = new Incidencia(eq->getId(), sev, dia, true);

                        laboratorio->agregarIncidencia(inc);
                        eq->agregarIncidencia(inc);

                        cout << "Incidencia generada para equipo: " << eq->getId() << endl;
                    }
                }
            }

            // 3. Cálculo de prioridades
            for (int i = 0; i < laboratorio->getCantidad(); i++) {

                Equipo* eq = laboratorio->getEquipo(i);

                if (eq != nullptr) {

                    double prioridad = eq->calcularPrioridad();

                    cout << "Prioridad " << prioridad <<" del equipo # "<<eq->getId()<< endl;
                }
            }

            // 4. Orden + 5. selección + 6. mantenimiento
            laboratorio->atenderTop3(estrategia);

            archivo << "Mantenimiento aplicado a top 3 equipos\n";

            // 7. actualización global
            laboratorio->actualizarMetricas();

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
}
*/
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
        cout << "\n===== DIA " << dia << " =====" << endl;

        int cantidad = laboratorio->getCantidad();

        // 1. Degradar todos los equipos.
        // Esto aumenta desgaste e inactividad.
        for (int i = 0; i < cantidad; i++) {
            Equipo* eq = laboratorio->getEquipo(i);

            if (eq != nullptr) {
                eq->depreciarporDia(dia);
            }
        }

        // 2. Generar incidencias aleatorias.
        // Esto hace que la simulacion no sea igual todos los dias.
        for (int i = 0; i < cantidad; i++) {
            Equipo* eq = laboratorio->getEquipo(i);

            if (eq != nullptr) {

                // Probabilidad simple: 1 de cada 5
                if (rand() % 5 == 0) {

                    Severidad sev;

                    int r = rand() % 4;

                    if (r == 0)
                        sev = Severidad::BAJA;
                    else if (r == 1)
                        sev = Severidad::MEDIA;
                    else if (r == 2)
                        sev = Severidad::ALTA;
                    else
                        sev = Severidad::CRITICA;

                    Incidencia* inc = new Incidencia(eq->getId(), sev, dia, true);

                    // Se guarda en el laboratorio
                    laboratorio->agregarIncidencia(inc);

                    // Tambien se guarda en el equipo para que suba su prioridad
                    eq->agregarIncidencia(inc);

                    cout << "Incidencia generada para equipo: "
                         << eq->getId() << endl;

                    archivo << "Incidencia generada para equipo: "
                            << eq->getId() << "\n";
                }
            }
        }

        // 3. Calcular prioridades antes de ordenar.
        archivo << "\nPrioridades calculadas:\n";

        for (int i = 0; i < cantidad; i++) {
            Equipo* eq = laboratorio->getEquipo(i);

            if (eq != nullptr) {
                double prioridad = eq->calcularPrioridad();

                cout << "Prioridad " << prioridad
                     << " del equipo # " << eq->getId() << endl;

                archivo << eq->getId()
                        << " prioridad: " << prioridad << "\n";
            }
        }

        // 4, 5 y 6.
        // Ordena por prioridad, selecciona los 3 mayores
        // y les aplica mantenimiento usando Strategy.
        laboratorio->atenderTop3(estrategia);

        archivo << "\nSe aplico mantenimiento a los 3 equipos con mayor prioridad.\n";

        // 7. Actualizar metricas globales del laboratorio.
        laboratorio->actualizarMetricas();

        // 8. Registrar riesgo global del dia.
        double riesgo = laboratorio->riesgoGlobalPromedio();

        archivo << "Riesgo global promedio: " << riesgo << "\n";

        cout << "Riesgo global promedio: " << riesgo << endl;
    }

    delete estrategia;
    archivo.close();

    cout << "\nSimulacion completada correctamente" << endl;
}