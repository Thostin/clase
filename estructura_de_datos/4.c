#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Alumno {
  uint32_t CI;
  char nombre[100];
  int nota[3];
};

struct Alumno *alumnos = NULL;

#define LIM_SUP_ALUMNOS 56
#define LIM_SUP_HABITANTES 10000000

void leer_alumnos(void) {
  struct Alumno aux;
  int n;

  printf("Ingrese la cantidad de alumnos: ");

  if (!scanf(" %d", &n) || n <= 0 || n >= LIM_SUP_ALUMNOS) {
    printf("Inválido\n");
    exit(1);
  }

  alumnos = malloc(sizeof(struct Alumno) * n);

  for (int i = 0; i < n; ++i) {
    printf("Ingrese la cédula del alumno %d: ", i + 1);
    if (!scanf(" %d", &alumnos[i].CI) || alumnos[i].CI <= 0 ||
        alumnos[i].CI >= LIM_SUP_HABITANTES) {
      printf("Inválido\n");
      exit(1);
    }

    printf("Ingrese el nombre completo del alumno: ");
    fgets(alumnos[i].nombre, 100, stdin);

    printf("Ingrese sus notas en cada examen:\n");

    int _aux;
    for (int j = 1; j <= 3; ++j) {
      printf("Examen %d: ", i);
      if (!scanf(" %d", &_aux) || _aux < 0) {
        printf("Inválido\n");
        exit(1);
      }

      alumnos[i].nota[j] = _aux;
    }
  }
}

int main(void) { return 0; }
