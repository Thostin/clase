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
