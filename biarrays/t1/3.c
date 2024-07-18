#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef MAXLINE
#define MAXLINE 100
#endif /* ifndef MAXLINE */

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */

typedef int type;
#define FORMAT "d"

void iguales(type *matriz, int f, int c) {
  int ig;
  for (int i = 0; i < f; ++i) {
    for (int j = i + 1; j < f; ++j) {
      ig = 1;
      for (int k = 0; k < c; ++k) {
        if (matriz[i * f + k] != matriz[j * f + k]) {
          ig = 0;
          break;
        }
      }
      if (1 == ig) {
        printf("Las filas %d y %d son iguales:\n", i + 1, j + 1);
        printf("m[%d]: ", i);
        for (int k = 0; k < c; ++k) {
          printf("%2" FORMAT " ", matriz[i * f + k]);
        }
        putchar(10);

        printf("m[%d]: ", j);
        for (int k = 0; k < c; ++k) {
          printf("%2" FORMAT " ", matriz[j * f + k]);
        }
        putchar(10);
      }
    }
  }

  if (0 == ig)
    printf("No hay dos filas iguales\n");
}

/* Números enteros no negativos entre 0 y 19 */
void rellenar(type *matriz, int f, int c) {
  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < c; ++j) {
      matriz[f * i + j] = rand() % 20;
    }
  }
}

int main(void) {
  srand(time(NULL));
  printf("Ingrese las dimensiones de la matriz:\n");
  int f;
  if (1 != scanf(" %d", &f) || f <= 0 || f >= 100) {
    printf("Inválido, los límites (excluyentes) son (0, 100)\n");
    return 1;
  }

  int c;
  if (1 != scanf(" %d", &c) || c <= 0 || c >= 100) {
    printf("Inválido, los límites (excluyentes) son (0, 100)\n");
    return 1;
  }

  int *matriz = malloc(f * c * sizeof(int));

  rellenar(matriz, f, c);

  iguales(matriz, f, c);
  return EXIT_SUCCESS;
}
