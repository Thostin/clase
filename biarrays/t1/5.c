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

int max_elem_triangular_superior(int *mat, int n) {
  int max = *mat;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (mat[i * n + j] > max) {
        max = mat[i * n + j];
      }
    }
  }
  return max;
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

  printf("EL mayor elemento de la triangular superior es %d\n",
         max_elem_triangular_superior(matriz, f));
  return EXIT_SUCCESS;
}
