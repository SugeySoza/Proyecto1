//
// Created by gabriel on 23/4/26.
//

#include "Algoritmos.h"

void Algoritmos::quicksortEquipo(Equipo** equipos, double lo, double high)
{
   if (lo >= high) return;

   double pivot = equipos[high] -> calcularPrioridad();
   int i = lo - 1;

   for (int j = lo, j < high; j++)
   {
      if (equipos[j] -> calcularPrioridad() < pivot)
      {
         i++;
         swap(equipos[i], equipos[high]);
      }
   }

   swap (equipos[i + 1], equipos[high] );
   int pi = i + 1;

   quicksortEquipo(equipos, lo, pi -1);
   quicksortEquipo(equipos, pi +1 , high);
}
