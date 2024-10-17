// #include <cstdio>
#include "../t1/func.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

char *leer_palabra(void) {
  static int arr[100];
  // scanf(" %99s", (char *)arr);
  int c, i = 0;

  while ((c = getchar()) == '\n' || ' ' == c || '\t' == c)
    ;

  do {
    arr[i] = c;
    ++i;
  } while ((c = getchar()) != '\n' && i < 100);

  printf("i: %d\n", i);
  char *ret = malloc(i);
  if (nullptr == ret) {
    perror("malloc(i)");
    exit(1);
  }

  __builtin_memcpy(ret, arr, 99);
  ret[i - 1] = '\0';
  return ret;
}

void leer_matriz(char ***mat_ptr, int *_N) {
  int N;
  leer_dimension(&N);

  *mat_ptr = malloc(N * N * sizeof(char *));
  for (int i = 0; i < N * N; ++i) {
    (*mat_ptr)[i] = leer_palabra();
  }
}

void encontrar_palabra(char **mat, int N, char *pal) {
  for (int i = 0; i < N * N; ++i) {
    if (0 == strcmp(mat[i], pal)) {
      printf("Se ha encontrado la palabra en (%d, %d)\nIngrese la palabra que "
             "la reemplace: ",
             i / N, i % N);
      free(mat[i]);
      mat[i] = leer_palabra();
    }
  }
}

int main(void) {
  char **mat;
  int N;
  leer_matriz(&mat, &N);

  printf("Ingrese la palabra a buscar: ");
  char pal[100] = {0};
  scanf(" %99s", pal);

  encontrar_palabra(mat, N, pal);
  return EXIT_SUCCESS;
}
