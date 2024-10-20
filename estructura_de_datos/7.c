#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Existe un desperdicio de espacio sin sentido
struct Alumno {
  uint32_t CI;
  uint32_t matricula;
  char nombre[100];
  int examen[2];
  int tp[2]; // trabajo práctico
  float promedio;
};

struct Alumno *alumnos = NULL;

#define LIM_SUP_ALUMNOS 56
#define LIM_SUP_HABITANTES 10000000

#define BAD_ALLOC 5774

void prom(struct Alumno *alumnos, int n) {
  for (int i = 0; i < n; ++i) {
    alumnos[i].promedio =
        ((float)alumnos[i].examen[0] + (float)alumnos[i].examen[1] +
         (float)alumnos[i].tp[0] + (float)alumnos[i].tp[1]) /
        4.0f;
  }
}

static struct Alumno **a, **b;
int comp_alumnos_prom(const void *_a, const void *_b) {
  a = (struct Alumno **)_a;
  b = (struct Alumno **)_b;
  return (*a)->promedio - (*b)->promedio;
}

// Aquí se asume que *alumnos es un arreglo de estructuras, y n la cantidad de
// alumnos La función retorna el promedio más alto
void ordenar_alumnos_por_matricula(struct Alumno *alumnos, int n) {
  prom(alumnos, n);
  struct Alumno **ptr_alumnos = malloc(n << 3);
  *ptr_alumnos = alumnos;

  for (int i = 1; i < n; ++i)
    ptr_alumnos[i] = alumnos + i * sizeof(struct Alumno);

  qsort(ptr_alumnos, 8, n, comp_alumnos_prom);
  printf("Alumnos ordenados por promedio:\n");

  for (int i = 0; i < n; ++i) {
    printf("%3.2f | %s\n", ptr_alumnos[i]->promedio, ptr_alumnos[i]->nombre);
  }
}

// int main(void) { return 0; }
