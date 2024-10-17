// #include <cstdio>
#include "../t1/func.c"
#include <stdio.h>
#include <string.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

int equal_fila(char *palabra, char *mat, int pos_init, int len) {
  for (int i = pos_init, j = 0; j < len; ++i, ++j) {
    if (palabra[j] != mat[i])
      return 0;
  }
  return 1;
}

int equal_columna(char *palabra, char *mat, int pos_init, int N, int len) {
  for (int i = pos_init, j = 0; j < len; i += N, ++j) {
    if (palabra[j] != mat[i])
      return 0;
  }
  return 1;
}

int encontrar_palabra(char *mat, int N, char *palabra) {
  const int len = strlen(palabra);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - len + 1; ++j) {
      if (equal_fila(palabra, mat, i * N + j, len)) {
        printf("Encontrada en la posición (%d, %d)\n", i, j);
        return 1;
      }
    }
  }

  for (int i = 0; i < N - len + 1; ++i) {
    for (int j = 0; j < N; ++j) {
      if (equal_columna(palabra, mat, i * N + j, N, len)) {
        printf("Encontrada en la posición (%d, %d)\n", i, j);
        return 1;
      }
    }
  }
  return 0;
}

void leer_matriz(char **mat_ptr, int *_N) {
  int N;
  leer_dimension(&N);

  *mat_ptr = malloc(N * N);
  int c, i = 0;
  while ((c = getchar()) != EOF && i < N * N) {
    if (('\n' == c) || (' ' == c) || ('\t' == c))
      continue;
    (*mat_ptr)[i] = c;
    ++i;
  }

  if (i < N * N) {
    if (c != EOF) {
      printf("What happened?\n");
      exit(1);
    }
    printf("Cantidad insuficiente de argumentos\n");
  }
  *_N = N;
}

int main(void) {
  char *mat;
  int N;
  leer_matriz(&mat, &N);

  printf("Ingrese la palabra a buscar: ");
  char pal[100] = {0};
  scanf(" %s", pal);

  encontrar_palabra(mat, N, pal);
  return EXIT_SUCCESS;
}
