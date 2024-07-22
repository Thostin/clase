#include "func.h"

int _main(void) {

  printf("Ingrese dos números positivos menores a 7 (si ingresa uno mayor pues "
         "xd):\nf: ");
  int f, c;
  if (1 != scanf(" %d", &f) || f <= 0 || f >= 7) {
    printf("Inváido\n");
    return EXIT_FAILURE;
  }
  printf("c: ");
  if (1 != scanf(" %d", &c) || c <= 0 || c >= 7) {
    printf("Inváido\n");
    return EXIT_FAILURE;
  }

  --c;
  --f;

  int mat[36];
  rellenar(mat, 6, 6);

  __builtin_memset(mat + 6 * f, 0, 24);

  int *aux = mat;
  for (int f = 0; f < 6; ++f) {
    aux[c] = 0;
    aux += 6;
  }

  printf("La matriz resultante:\n");
  mostrar_matriz(mat, 6, 6);
  return EXIT_SUCCESS;
}

int main(void) {
  srand(time(nullptr));
  return _main();
}
