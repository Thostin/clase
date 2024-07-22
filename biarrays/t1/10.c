#include "func.h"

type *generar(void) {
  int *mat = malloc(64);
  for (int f = 1; f < 4; f += 2) {
    for (int c = 0; c < 4; ++c) {
      mat[4 * f + c] = (rand() % 100) & (~1);
    }
  }
  for (int f = 0; f < 4; f += 2) {
    for (int c = 0; c < 4; ++c) {
      mat[4 * f + c] = (rand() % 34) * 3;
    }
  }
  return mat;
}

int _main(void) {
  srand(time(NULL));
  int *mat = generar();

  printf("Matriz generada:\n");
  mostrar_matriz(mat, 4, 4);

  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
