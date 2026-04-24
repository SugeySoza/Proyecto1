//
// Created by gabriel on 23/4/26.
//

#include "Algoritmos.h"

void Algoritmos::quicksortEquipo(Equipo** equipos, int lo, int high)
{
    if (lo >= high) return;

    double pivot = equipos[high] -> calcularPrioridad();
    int i = lo - 1;

    for (int j = lo; j < high; j++)
    {
        if (equipos[j]->calcularPrioridad() > pivot) // DESCENDENTE
        {
            i++;
            std::swap(equipos[i], equipos[j]);
        }
    }

    std::swap(equipos[i + 1], equipos[high]);
    int pi = i + 1;

    quicksortEquipo(equipos, lo, pi - 1);
    quicksortEquipo(equipos, pi + 1, high);
}

void Algoritmos::ordenarEquiposPorPrioridadDesc(Equipo** equipos)
{
    if (equipos == nullptr) return;

    int n = 0;
    while (equipos[n] != nullptr)
    {
        n++;
    }

    if (n > 1)
    {
        quicksortEquipo(equipos, 0, n - 1);
    }
}

int Algoritmos::busquedaBinariaId(string** id, string idBuscado)
{
    if (id == nullptr) return -1;

    // Calcular tamaño
    int n = 0;
    while (id[n] != nullptr)
    {
        n++;
    }

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (*id[mid] == idBuscado)
        {
            return mid; // encontrado
        }
        else if (*id[mid] < idBuscado)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // no encontrado
}

