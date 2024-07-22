#include "func.h"

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int _main(void) {
  printf("Ingrese las dimensiones de la matriz:\n");
  printf("f> ");
  int f, c;
  leer_dimension(&f);
  printf("c> ");
  leer_dimension(&c);

  int mat[f * c];
  _rellenar(mat, f * c);

  printf("Antes:\n");
  mostrar_matriz(mat, f, c);

  qsort(mat, f * c, sizeof(int), comp);
  int mat_order[f * c];

  for (int j = 0, I = 0; j < c; ++j)
    for (int i = 0; i < f; ++i) {
      mat_order[i * c + j] = mat[I++];
    }

  printf("\nMatriz con la regla de orden:\n");
  mostrar_matriz(mat_order, f, c);
  return EXIT_SUCCESS;
}

int main(void) {
  srand(time(NULL));
  return _main();
}
