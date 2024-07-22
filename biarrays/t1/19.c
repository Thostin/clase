#include "func.h"
#include <stdio.h>

/*
 * Entiendo que es hallar la separación con el borde
 * izquierdo de q, siendo en la figura igual a dos, e
 * igual a 2 también a la separación que hay con la línea
 * iferior y p.
 * */

/*
 * En el problema asume las coordenadas desde 1,
 * pero yo las asumiré desde 0*/
int suma_especial(int *mat, int f, int c, int p, int q) {
  int s = 0;
  if (f == 2 * p + 1)
    for (int i = q; i < c - q; ++i) {
      s += mat[p * c + i];
    }

  else
    for (int i = q; i < c - q; ++i) {
      s += mat[p * c + i] + mat[(f - p - 1) * c + i];
    }

  if (c == 2 * q + 1)
    for (int i = p + 1; i < f - p - 1; ++i) {
      s += mat[i * c + q];
    }
  else
    for (int i = p + 1; i < f - p - 1; ++i) {
      s += mat[i * c + q] + mat[i * c + c - q - 1];
    }

  return s;
}

int _main(void) {
  printf("Ingrese las dimensiones de la matriz:\n");
  printf("f> ");
  int f, c;
  leer_dimension(&f);
  printf("c> ");
  leer_dimension(&c);

  printf("Ingrese los valores de p y q (van de 0 hasta f - 1 ó c - 1):\np> ");
  int p, q;

  if (1 != scanf(" %d", &p) || p < 0 || p >= f) {
    printf("inválido\n");
    return 1;
  }

  if (1 != scanf(" %d", &q) || q < 0 || p >= c) {
    printf("inválido\n");
    return 1;
  }

  int mat[f * c];
  _rellenar(mat, f * c);

  printf("La matriz:\n");
  mostrar_matriz(mat, f, c);

  printf("La suma de los elementos en cuestión: %d\n",
         suma_especial(mat, f, c, p, q));
  return EXIT_SUCCESS;
}

int main(void) {
  srand(time(NULL));
  return _main();
}
