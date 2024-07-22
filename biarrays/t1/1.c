#include "func.h"

void rellenar_1(type matriz[5][4]) {
  type aux;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      printf("[%d][%d]: ", i, j);
      while (1 != scanf(" %" TYPE_FORMAT, &aux)) {
        printf("Inválido, vuelva a ingresar.\n");
        printf("[%d][%d]: ", i, j);
      }
      matriz[i][j] = aux;
      // matriz[i][j] = rand() % 100;
    }
  }
}

type suma_1(type matriz[5][4]) {
  type sum = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      sum += matriz[i][j];
    }
  }
  return sum;
}

int main(void) {
  srand(time(NULL));
  type matriz[5][4];
  rellenar_1(matriz);

  type sum = suma_1(matriz);
  printf("La suma de los elementos es: %" TYPE_FORMAT, sum);
  printf("EL promedio es: %.2lf\n", (double)sum / 20);
  return EXIT_SUCCESS;
}
