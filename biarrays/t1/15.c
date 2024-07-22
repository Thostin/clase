#include "func.h"
#include <stdio.h>

int _main(void) {
  int arr[12];
  printf("Ingrese los elementos del arreglo:\n");

  int num;
  for (int i = 0; i < 12; ++i) {
    printf("> ");
    if (1 != scanf(" %d", &num)) {
      printf("Algo salió mal\n");
      return 1;
    }
    arr[i] = num % 100;
  }

  printf("La matriz resultante con sus elementos vistos módulo 100:\n");
  mostrar_matriz(arr, 4, 3);
  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
