#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Existe un desperdicio de espacio sin sentido
struct Alumno {
  uint32_t CI;
  uint32_t matricula;
  char nombre[100];
  int examen[2];
  int tp[2];
};

struct Alumno *alumnos = NULL;

#define LIM_SUP_ALUMNOS 56
#define LIM_SUP_HABITANTES 10000000

#define BAD_ALLOC 5774

void leer_alumnos(void) {
  struct Alumno aux;
  int n;

  printf("Ingrese la cantidad de alumnos: ");

  if (!scanf(" %d", &n) || n <= 0 || n >= LIM_SUP_ALUMNOS) {
    printf("Inválido\n");
    exit(1);
  }

  alumnos = malloc(sizeof(struct Alumno) * n);
  if (NULL == alumnos) {
    perror("malloc");
    exit(BAD_ALLOC);
  }

  for (int i = 0; i < n; ++i) {
    printf("Ingrese la cédula del alumno %d: ", i + 1);
    if (!scanf(" %d", &alumnos[i].CI) || alumnos[i].CI <= 0 ||
        alumnos[i].CI >= LIM_SUP_HABITANTES) {
      printf("Inválido\n");
      exit(1);
    }

    printf("Ingrese el nombre completo del alumno: ");
    fgets(alumnos[i].nombre, 100, stdin);

    printf("Ingrese su número de matrícula: ");
    int _aux;

    if (1 != scanf(" %d", &_aux) || _aux <= 0 || _aux > LIM_SUP_ALUMNOS) {
      printf("Inválido\n");
      exit(1);
    }
    alumnos[i].matricula = _aux;

    printf("Ingrese sus notas en cada examen:\n");

    for (int j = 0; j < 2; ++j) {
      printf("Examen %d: ", j + 1);
      if (!scanf(" %d", &_aux) || _aux < 0) {
        printf("Inválido\n");
        exit(1);
      }

      alumnos[i].examen[j] = _aux;
    }

    printf("Ingrese sus notas en cada trabajo práctico:\n");

    for (int j = 0; j < 2; ++j) {
      printf("TP %d: ", j + 1);
      if (!scanf(" %d", &_aux) || _aux < 0) {
        printf("Inválido\n");
        exit(1);
      }

      alumnos[i].tp[j] = _aux;
    }
  }
}

float promedio_total_alumno(struct Alumno *alumno) {
  return ((float)alumno->examen[0] + (float)alumno->examen[1] +
          (float)alumno->tp[0] + (float)alumno->tp[1]) /
         4.0f;
}

// int main(void) { return 0; }
