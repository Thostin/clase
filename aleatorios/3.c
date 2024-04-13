/*
 * Si se lanzan 3 monedas al mismo tiempo, estimar la probabilidad de que las
 * tres resulten "caras" o "cruces"
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int lim;
  printf("Introduzca un límite positivo: ");
  if (!scanf(" %u", &lim)) {
    printf("SOS UN PELOTUDO\n");
    return 1;
  }

  if (lim <= 0) {
    printf("Improper input\n");
    return 1;
  }
  int tot = 0;
  int aux;
  srand(time(NULL));
  for (int i = 0; i < lim; ++i) {
    if (rand() % 3 == (aux = rand() % 3) && aux == rand() % 3)
      ++tot;
  }

  printf("LANZAMIENTOS TOTALES: %d\n", lim);
  printf("TOTAL DE TRES MONEDAS IGUALES: %d\n", tot);
  printf("PROBABILIDAD: %lf\n\n", (double)100.0 * tot / lim);
  return EXIT_SUCCESS;
}
