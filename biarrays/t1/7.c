#include <limits.h>
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

#define nullptr NULL

/* Números enteros no negativos entre 0 y 19 */
void rellenar(type *matriz, int f, int c) {
  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < c; ++j) {
      matriz[c * i + j] = rand() % 20;
    }
  }
}

/*
 * f_a: cantidad de filas
 * c_a: cantidad de columnas
 * */
int *multiplicar_matrices(int *mat_a, int *mat_b, int f_a, int c_a, int f_b,
                          int c_b) {
  if (c_a != f_b) {
    printf("Error, no se pueden multiplicar las matrices\n");
    return nullptr;
  }

  int *res = malloc(f_a * c_b * sizeof(int));

  if (nullptr == res) {
    perror("malloc");
    exit(1);
  }

  int s;
  for (int f = 0; f < f_a; ++f) {
    for (int c = 0; c < c_b; ++c) {
      s = 0;

      // En lugar de c_a puede haber f_b
      for (int m_x = 0; m_x < c_a; ++m_x) {
        s += mat_a[f * c_a + m_x] * mat_b[m_x * c_b + c];
      }

      res[c_b * f + c] = s;
    }
  }

  return res;
}

void mostrar_matriz(int *mat, int f, int c) {
  for (int i = 0; i < f; ++i) {
    printf("| ");
    for (int j = 0; j < c; ++j) {
      printf("%2" TYPE_FORMAT " ", mat[c * i + j]);
    }
    printf(" |");
    putchar(10);
  }
}

void leer_dimension(int *n) {
  if (1 != scanf(" %d", n) || *n <= 0 || *n >= 100) {
    printf("Inválido, los límites (excluyentes) son (0, 100)\n");
    exit(1);
  }
}

int minimax(int *mat, int f, int c) {
  // int mimax = (1 << 31) | 1;
  int mimax = INT_MAX;
  int max;
  for (int j = 0; j < c; ++j) {
    max = mat[j];
    for (int i = 1; i < f; ++i) {
      if (max < mat[i * c + j])
        max = mat[i * c + j];
    }
    if (max < mimax) {
      mimax = max;
    }
  }
  return mimax;
}

int _main(void) {
  srand(time(NULL));
  printf("Ingrese las dimensiones de la matriz:\n");
  int f, c;

  printf("f: ");
  leer_dimension(&f);

  printf("c: ");
  leer_dimension(&c);

  int *mat = malloc(f * c * sizeof(int));

  rellenar(mat, f, c);

  printf("Matriz en cuestión:\n");

  mostrar_matriz(mat, f, c);

  putchar(10);
  putchar(10);

  printf("\nminimax(mat) = %d\n", minimax(mat, f, c));

  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
