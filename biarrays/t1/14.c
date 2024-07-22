#include "func.h"
#include <stdio.h>

void mostrar_matriz_alumnos(int *mat, int f, int c) {
  printf("\n            ");
  for (int i = 0; i < 5; ++i)
    printf("Asg_%-2d ", i + 1);
  putchar(10);

  for (int i = 0; i < f; ++i) {
    printf("Alumno  %2d| ", i + 1);
    for (int j = 0; j < c; ++j) {
      if (0 == mat[c * i + j])
        printf("   --  ");
      else
        printf("   %2" TYPE_FORMAT "  ", mat[c * i + j]);
    }
    printf("|");
    putchar(10);
  }
}

#define ALUMNOS 30
#define MATERIAS 5

void rellenar_alumnos(type *matriz, int f, int c) {
  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < c; ++j) {
      matriz[c * i + j] = 1 + rand() % 5;
    }
  }
}

int _main(void) {
  int mat[ALUMNOS * MATERIAS];
  rellenar_alumnos(mat, 30, 5);

  int num;
  for (int i = 0; i < 30; ++i) {
    do {
      num = 3 + rand() % 29;
    } while (num == 4 || num == 8 || num == 16);
    for (int j = 0; j < 5; ++j) {
      if (((1 << j) & num) == 0)
        mat[i * MATERIAS + j] = 0;
    }
  }

  printf("Notas de los alumnos:\n\n");
  mostrar_matriz_alumnos(mat, ALUMNOS, MATERIAS);
  return EXIT_SUCCESS;
}

int main(void) {
  srand(time(NULL));
  return _main();
}
