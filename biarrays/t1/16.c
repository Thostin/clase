#include "func.h"
#include <stdio.h>

int _main(void) {
  int mat[15];
  printf("Ingrese los elementos de la matriz de 5 * 3:\n");

  int num;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
      printf("[%d][%d]: ", i, j);
      if (1 != scanf(" %d", &num)) {
        printf("Algo bastante extraño acaba de suceder\n");
        return EXIT_FAILURE;
      }
      mat[3 * i + j] = num % 100;
    }
  }

  int mat_tras[15];

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
      mat_tras[j * 5 + i] = mat[i * 3 + j];
    }
  }
  printf("***NOTA: Los elementos están módulo 100***\n");
  printf("La matriz original:\n");
  mostrar_matriz(mat, 5, 3);
  printf("\nLa transpuesta:\n");
  mostrar_matriz(mat_tras, 3, 5);

  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
