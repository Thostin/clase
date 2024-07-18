#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef MAXLINE
#define MAXLINE 100
#endif /* ifndef MAXLINE */

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */

typedef size_t type;
#define TYPE_FORMAT "zu"

void rellenar(type *matriz, int n_n) {
  for (int i = 0; i < n_n; ++i) {
    for (int j = 0; j < n_n; ++j) {
      matriz[n_n * i + j] = rand() % 100;
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

type s2(type *matriz, int n_n) {
  type s = 0;
  for (int i = 0; i < n_n; ++i) {
    s += matriz[n_n * i + n_n - i - 1];
  }
  return s;
}

int main(void) {
  srand(time(NULL));
  type *matriz;
  printf("Inserte el tamaño del lado de la matriz: ");

  int n;
  if (1 != scanf(" %d", &n) || n <= 0) {
    printf("Inválido\n");
    return 1;
  }

  if (n >= 100) {
    printf("El límite superior es 100\n");
    return 1;
  }

  matriz = malloc(n * n * sizeof(type));
  rellenar(matriz, n);

  printf("Matriz en cuestión:\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%2" TYPE_FORMAT " ", matriz[n * i + j]);
    }
    putchar(10);
  }

  if (s1(matriz, n) > s2(matriz, n)) {
    printf("La diagonal con mayor suma es la principal\n");
  } else {
    printf("La diagonal con mayor suma es la secundaria\n");
  }
  return EXIT_SUCCESS;
}
