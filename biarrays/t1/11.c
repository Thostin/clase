#include "func.h"

void swap_diagonales(int *mat, int n) {
  int var;
  int ca = 0;
  int cb = n - 1;

  for (int f = 0; f < n; ++f) {
    var = mat[f * n + ca];
    mat[f * n + ca] = mat[f * n + cb];
    mat[f * n + cb] = var;
    ++ca;
    --cb;
  }
}

int _main(void) {
  srand(time(nullptr));
  printf("Ingrese las dimensiones de la matriz (n * n): ");
  int n;
  leer_dimension(&n);

  int *mat = malloc(n * n * sizeof(int));
  if (nullptr == mat) {
    perror("malloc");
    exit(1);
  }

  rellenar(mat, n, n);
  printf("La matriz en cuestiíon:\n");
  mostrar_matriz(mat, n, n);

  swap_diagonales(mat, n);
  printf("\nLa matriz con las diagonales intercambiadas:\n");
  mostrar_matriz(mat, n, n);
  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
