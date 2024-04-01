#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sum(long *dst, long *a, long *b, size_t size);
void mostrar_arreglo(long *src, size_t nmemb);

int main(void) {
  srand(time(NULL));
  printf("Introduzca el tamaño de los vectores: ");
  long _tam;

  if (!scanf(" %ld", &_tam) || _tam <= 0) {
    printf("Improper input\n");
    return 1;
  }

  size_t tam = _tam;
  long A[tam], B[tam], C[tam];
  for (size_t i = 0; i < tam; ++i) {
    A[i] = rand();
    B[i] = rand();
  }

  printf("A := ");
  mostrar_arreglo(A, tam);

  putchar(10);
  putchar(10);

  printf("B := ");
  mostrar_arreglo(B, tam);
  putchar(10);
  putchar(10);

  sum(C, A, B, tam);
  printf("C := A + B = ");
  mostrar_arreglo(C, tam);

  putchar(10);
  putchar(10);
  return 0;
}

void mostrar_arreglo(long *src, size_t nmemb) {
  printf("{%ld", *src);
  for (int i = 1; i < nmemb; ++i) {
    printf(", %ld", src[i]);
  }
  putchar('}');
}

void sum(long *dst, long *a, long *b, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    dst[i] = a[i] + b[i];
  }
}
