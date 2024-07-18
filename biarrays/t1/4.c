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
#define TYPE_FORMAT "d"

/* Números enteros no negativos entre 0 y 19 */
void rellenar(type *matriz, int f, int c) {
  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < c; ++j) {
      matriz[f * i + j] = rand() % 20;
    }
  }
}

type s1(type *matriz, int n_n) {
  type s = 0;
  for (int i = 0; i < n_n; ++i) {
    s += matriz[n_n * i + i];
  }
  return s;
}

int main(void) {
  srand(time(NULL));
  printf("Ingrese las dimensiones de la matriz:\n");
  int f;
  if (1 != scanf(" %d", &f) || f <= 0 || f >= 100) {
    printf("Inválido, los límites (excluyentes) son (0, 100)\n");
    return 1;
  }
  int *matriz = malloc(f * f * sizeof(int));

  rellenar(matriz, f, f);

  printf("Matriz en cuestión:\n");
  printf("--\n");
  for (int i = 0; i < f; ++i) {
    printf("| ");
    for (int j = 0; j < f; ++j) {
      printf("%2" TYPE_FORMAT " ", matriz[f * i + j]);
    }
    printf(" |");
    putchar(10);
  }
  printf("--\n");

  printf("\nLa suma de la diagonal principal es: %" TYPE_FORMAT "\n",
         s1(matriz, f));
  return EXIT_SUCCESS;
}
