/*
 * En cierto juego se lanzan dos dados y se registra la suma de los valores que
 * resultan en cada uno de ellos. Escribir un algoritmo que simule P
 * lanzamientos y elabore una tabla de frecuencias para los valores posibles de
 * la suma (una tabla de frecuencias contiene cada valor posible y la cantidad
 * de veces que el mismo se ha presentado).
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int P;
  printf("Introduzca el límite de lanzamientos: ");

  // Evaluado de izquierda a derecha
  if (!scanf(" %d", &P) || P <= 0) {
    printf("Improper input\n");
    return 1;
  }

  int vec[11];

  srand(time(NULL));
  for (int i = 0; i < P; ++i)
    ++vec[rand() % 6 + rand() % 6];

  printf("TABLA DE FRECUENCIAS: \n");
  for (int i = 0; i < 11; ++i) {
    printf("%2d: ", i + 2);
    for (int j = 0; j < vec[i]; ++j)
      putchar('*');
    putchar('\n');
  }
  putchar(10);
  return EXIT_SUCCESS;
}
