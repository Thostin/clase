/*
 * Sabiendo que se tiene en memoria un vector de tamaño N (N es par),
 * hacer un algoritmo que permita intercambiar los elementos de la
 * primera mitad con los elementos de la segunda mitad.
 */

#include <stdio.h>
#include <stdlib.h>

typedef long type;

void intercambiar(type *src, size_t nmemb, size_t size_memb);
void mostrar_arreglo(type *src, size_t nmemb);

int main(void) {
  printf("Introduzca un tamaño par de arreglo: ");
  size_t tam;
  if (!scanf(" %zu", &tam) || 0 == tam || tam & 1) {
    printf("Improper input\n");
    return 1;
  }

  type arr[tam];
  for (int i = 0; i < tam; ++i) {
    arr[i] = rand() % 100;
  }
  printf("Antes del intercambio: \n");
  mostrar_arreglo(arr, tam);
  putchar(10);

  intercambiar(arr, tam, sizeof(type));

  printf("Despues del arreglo:\n");
  mostrar_arreglo(arr, tam);
  putchar(10);

  return EXIT_SUCCESS;
}

void mostrar_arreglo(type *src, size_t nmemb) {
  printf("{%ld", *src);
  for (int i = 1; i < nmemb; ++i) {
    printf(", %ld", src[i]);
  }
  putchar('}');
}

void intercambiar(type *src, size_t nmemb, size_t size_memb) {
  for (size_t i = 0; i < nmemb / 2; ++i) {
    src[i] ^= src[i + nmemb / 2];
    src[i + nmemb / 2] ^= src[i];
    src[i] ^= src[i + nmemb / 2];
  }
}
