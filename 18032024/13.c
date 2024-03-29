/*
 * Se tiene en memoria un vector V de N elementos. Hacer un algoritmo que
 * permita encontrar e imprimir la mediana. La mediana es el elemento del medio
 * o central
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long type;

int comparar(const void *, const void *);

int main(void) {
  srand(time(NULL));

  unsigned int tam;
  printf("Ingrese el tamaño del arreglo: ");
  if (!scanf(" %u", &tam) || 0 == tam) {
    printf("Improper input\n");
    return 1;
  }

  printf("Genereando arreglo aleatorio... ");
  type arr[tam];

  for (int i = 0; i < tam; ++i) {
    arr[i] = rand();
  }
  printf("Hecho\n\n");

  printf("V := {%ld", *arr);
  for (int i = 1; i < tam; ++i) {
    printf(", %ld", arr[i]);
  }
  printf("}\n\n");

  printf("Ordenando elementos... ");
  qsort(arr, tam, sizeof(type), comparar);
  printf("Hecho\n");

  printf("Calculando mediana... ");
  type med;
  switch (tam & 1) {
  case 1:
    med = arr[(tam - 1) >> 1];
    break;
  default:
    med = (arr[tam >> 1] + arr[(tam >> 1) - 1]) >> 1;
  }
  printf("Hecho\n\n");

  printf("med(V) = %ld\n", med);
  return EXIT_SUCCESS;
}

int comparar(const void *a, const void *b) {
  register type *ptr_a = (type *)a;
  register type *ptr_b = (type *)b;

  return *ptr_a - *ptr_b;
}
