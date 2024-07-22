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

int _main(void) {
  srand(time(NULL));
  printf("Ingrese las dimensiones de las matrices:\n");
  int f_1, c_1, f_2, c_2;

  printf("f_a: ");
  leer_dimension(&f_1);

  printf("f_b: ");
  leer_dimension(&f_2);

  printf("c_a: ");
  leer_dimension(&c_1);

  printf("c_b: ");
  leer_dimension(&c_2);

  int *mat_1 = malloc(f_1 * c_1 * sizeof(int));
  int *mat_2 = malloc(f_2 * c_2 * sizeof(int));

  rellenar(mat_1, f_1, c_1);
  rellenar(mat_2, f_2, c_2);

  printf("Matrices en cuestión:\n");

  mostrar_matriz(mat_1, f_1, c_1);

  putchar(10);
  putchar(10);

  mostrar_matriz(mat_2, f_2, c_2);

  printf("\nEl producto de las matrices es: \n");

  int *res = multiplicar_matrices(mat_1, mat_2, f_1, c_1, f_2, c_2);
  mostrar_matriz(res, f_1, c_2);
  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
