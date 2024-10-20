#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Existe un desperdicio de espacio sin sentido
struct Alumno {
  uint32_t CI;
  char nombre[100];
  int examen[2];
  int tp[2];
};

struct Alumno *alumnos = NULL;

#define LIM_SUP_ALUMNOS 56
#define LIM_SUP_HABITANTES 10000000

#define BAD_ALLOC 5774

// Aquí se asume que *alumnos es un arreglo de estructuras, y n la cantidad de
// alumnos La función retorna el promedio más alto
float promedio_total_alumnos_examen(struct Alumno *alumnos, int n) {
  printf("Se calculará el promedio de cada alumno en cada examen y el alumno "
         "con promedio más alto\n");
  float sup_prom = -2.0f, aux;
  char *nom_sup_pro = NULL;

  for (int i = 0; i < n; ++i) {
    aux = (alumnos[i].examen[0] + alumnos[i].examen[1]) / 2.0f;
    printf("El alumno %30s tiene promedio %f\n", alumnos[i].nombre, aux);
    if (aux > sup_prom) {
      sup_prom = aux;
      nom_sup_pro = alumnos[i].nombre;
    }
  }

  printf("\n | El alumno %s obtuvo el promedio más alto, con promedio igual a "
         "%f!\n",
         nom_sup_pro, sup_prom);

  return sup_prom;
}

// int main(void) { return 0; }
