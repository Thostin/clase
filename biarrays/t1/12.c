/*
 * NOTA: No tengo ni idea de cómo hice para que funcione a la primera
 * */
#include "func.h"

#define check(n) (n) <= 7 && n >= 0

void ajedrez(void) {
  const int arr_1[] = {2, 1, -1, -2};
  const int arr_2[] = {1, -1, 2, -2};

  int f, c;
  printf("Ingrese la posición de su caballo en el tablero:\nf > ");
  if (1 != scanf(" %d", &f) || f >= 8 || f < 0) {
    printf("No tiene sentido\n");
    exit(1);
  }
  printf("c > ");
  if (1 != scanf(" %d", &c) || c >= 8 || c < 0) {
    printf("No tiene sentido\n");
    exit(1);
  }

  int chess[64] = {0};
  signed j = 0, i, k;
  for (i = 0; i < 2; ++i) {
    if (check(f + arr_1[i]))
      for (k = 0; k < 2; ++k) {
        if (check(c + arr_2[j]))
          chess[8 * (f + arr_1[i]) + c + arr_2[j]] = 1;
        ++j;
      }
  }

  for (; i < 4; ++i) {
    k = 0;
    if (check(f + arr_1[i])) {
      do {
        --j;
        ++k;
        if (check(c + arr_2[j]))
          chess[8 * (f + arr_1[i]) + c + arr_2[j]] = 1;
      } while (k < 2);
    }
  }
  mostrar_matriz(chess, 8, 8);
}

int main(void) {
  ajedrez();
  return EXIT_SUCCESS;
}
