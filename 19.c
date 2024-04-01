#include "list/list.h"

#include <stdio.h>
#include <stdlib.h>

typedef long type;

void mostrar_arreglo(type *src, size_t nmemb, int lado);

int main(void) {
  printf("Introduzca los elementos del vector (introduzca algo inválido para "
         "finalizar):\n");
  listptr_t root = nullptr;
  type aux;

  printf("> ");
  if (!scanf(" %ld", &aux)) {
    printf("Improper input\n");
    return EXIT_FAILURE;
  }

  if (initl(&root, &aux, sizeof(type))) {
    printf("initl <<< main: ERROR\n");
    return EXIT_FAILURE;
  }

  listptr_t ptr = root;
  size_t count = 1;
  while (printf("> "), scanf(" %ld", &aux)) {
    if (pushl(ptr, &aux, sizeof(type))) {
      printf("init <<< main: ERROR");
      return EXIT_FAILURE;
    }
    ptr = ptr->next;
    ++count;
  }

  type arr[count];
  if (compactl(root, arr, sizeof(type))) {
    printf("compactl <<< main: ERROR\n");
    return EXIT_FAILURE;
  }

  freel(&root);

  putchar(10);
  printf("Arreglo normal y corriente: \n");
  mostrar_arreglo(arr, count, 0);
  putchar(10);
  putchar(10);

  printf("Arreglo alrevés: \n");
  mostrar_arreglo(arr, count, 1);
  putchar(10);
  putchar(10);

  printf("Tamaño del arreglo: %zu elementos.\n", count);
  return EXIT_SUCCESS;
}

void mostrar_arreglo(type *src, size_t nmemb, int lado) {
  if (lado) {
    printf("{%ld", src[nmemb - 1]);
    for (int i = nmemb - 2; i >= 0; --i) {
      printf(", %ld", src[i]);
    }
    putchar('}');
    return;
  }

  printf("{%ld", *src);
  for (int i = 1; i < nmemb; ++i) {
    printf(", %ld", src[i]);
  }
  putchar('}');
}
