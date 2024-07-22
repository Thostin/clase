#include "func.h"

int _main(void) {
  printf("Ingrese las dimensiones de la matriz:\nf> ");
  int f, c;
  leer_dimension(&f);

  printf("c> ");
  leer_dimension(&c);

  int mat[f * c * sizeof(int)];
  int j;
  for (int i = 0; i < f; ++i) {
    for (j = i; j < c; ++j) {
      mat[i * c + j] = j + 1 - i;
    }
    for (j = 0; j < i; ++j) {
      mat[i * c + j] = c - j;
    }
  }

  printf("El cuadro latino:\n");
  mostrar_matriz(mat, f, c);
  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
