/*
 * Realice un algoritmo que lea un arreglo de N datos y asigmed a sus elementos
 * los valores {1, 4, 9, ...};
 *
 * Yo: Cómo, sobreescribo todo otra vez o cómo, no voy a hacer eso
 */

#include <stdio.h>
#include <stdlib.h>

void mostrar_arreglo(size_t *src, long nmemb);

int main(void) {
  printf("Introduzca un N: ");

  long tam;
  if (!scanf(" %ld", &tam) || tam <= 0) {
    printf("Improper input\n");
    return EXIT_FAILURE;
  }

  size_t arr[tam];
  for (size_t i = 0; i < tam; ++i)
    arr[i] = (i + 1) * (i + 1);

  mostrar_arreglo(arr, tam);
  putchar(10);
  putchar(10);
  return 0;
}

void mostrar_arreglo(size_t *src, long nmemb) {
  printf("{%ld", *src);
  for (int i = 1; i < nmemb; ++i) {
    printf(", %ld", src[i]);
  }
  putchar('}');
}
