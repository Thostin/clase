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

static struct Alumno **a, **b;
int comp_alumnos(const void *_a, const void *_b) {
  a = (struct Alumno **)_a;
  b = (struct Alumno **)_b;
  return (*a)->matricula - (*b)->matricula;
}

// Aquí se asume que *alumnos es un arreglo de estructuras, y n la cantidad de
// alumnos La función retorna el promedio más alto
void ordenar_alumnos_por_matricula(struct Alumno *alumnos, int n) {
  struct Alumno **ptr_alumnos = malloc(n << 3);
  *ptr_alumnos = alumnos;

  for (int i = 1; i < n; ++i)
    ptr_alumnos[i] = alumnos + i * sizeof(struct Alumno);

  qsort(ptr_alumnos, 8, n, comp_alumnos);
  printf("Alumnos ordenados por matrícula:\n");

  for (int i = 0; i < n; ++i) {
    printf("%10d | %s\n", ptr_alumnos[i]->matricula, ptr_alumnos[i]->nombre);
  }
}

// int main(void) { return 0; }
