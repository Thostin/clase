#include <stdio.h>

void min_max(long *src, size_t tam, long band);

int main(int argc, char *argv[]) {
  printf("Introduzca el tamaño del vector: ");
  long _tam;

  if (!scanf(" %zu", &_tam) || _tam <= 0) {
    printf("Improper input\n");
    return 1;
  }

  size_t tam = _tam;
  long vec[tam];

  printf("A continuación, introduzca los elementos del vector:\n");
  for (size_t i = 0; i < tam; ++i) {
    printf("vec[%ld] = ", i);
    if (!scanf(" %ld", vec + i)) {
      printf("Improper input\n");
      return 1;
    }
  }

  long band;
  printf("Introduzca otro entero: ");
  if (!scanf(" %ld", &band)) {
    printf("Improper input\n");
    return 1;
  }

  min_max(vec, tam, band);
  return 0;
}

void min_max(long *src, size_t tam, long band) {
  char existe = 0;
  long val = 9223372036854775807;

  for (size_t i = 0; i < tam; ++i) {
    if ((src[i] > band && src[i] <= val))
      (val = src[i]), existe = 1;
  }

  switch (existe) {
  case 0:
    printf("No existe un número en el vector que sea mayor que %ld\n", band);
    break;
  default:
    printf("El menor elemento del vector que es mayor que %ld es %ld\n", band,
           val);
  }
}
