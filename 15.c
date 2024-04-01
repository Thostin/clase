#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long type;

void mostrar_arreglo(type *src, size_t nmemb);

int main(void) {
  srand(time(NULL));
  size_t tA, tB, tC;

  printf("Introduzca tres tamaños de arreglos separados por espacios: ");
  if (3 != scanf(" %zu %zu %zu", &tA, &tB, &tC) || !(tA * tB * tC)) {
    printf("Improper input\n");
    return 1;
  }

  type A[tA];
  type B[tB];
  type C[tC];

  for (size_t i = 0; i < tA; ++i) {
    A[i] = rand() % 100;
  }

  for (size_t i = 0; i < tB; ++i) {
    B[i] = rand() % 100;
  }

  for (size_t i = 0; i < tC; ++i) {
    C[i] = rand() % 100;
  }

  type Z[tA + tB + tC];
  size_t i;
  for (i = 0; i < tA; ++i) {
    Z[i] = A[i];
  }

  for (i = 0; i < tB; ++i) {
    Z[i + tA] = B[i];
  }

  for (i = 0; i < tC; ++i) {
    Z[i + tA + tB] = C[i];
  }

  printf("A := ");
  mostrar_arreglo(A, tA);
  putchar(10);

  printf("B := ");
  mostrar_arreglo(B, tB);
  putchar(10);

  printf("C := ");
  mostrar_arreglo(C, tC);
  putchar(10);

  printf("Z := ");
  mostrar_arreglo(Z, tA + tB + tC);
  putchar(10);
  putchar(10);

  return 0;
}

void mostrar_arreglo(type *src, size_t nmemb) {
  printf("{%ld", *src);
  for (int i = 1; i < nmemb; ++i) {
    printf(", %ld", src[i]);
  }
  putchar('}');
}
