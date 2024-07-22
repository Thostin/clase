#include "func.h"

void gen(int *mat, int *arr, int n) {
  int i = 0;
  int suma_resta = 1;
  int init_f = 0;
  int c_xd;
  int f;
  for (int c = n - 1; c >= 0; --c) {
    f = (init_f * ((suma_resta *= -1) - 1)) / -2;
    c_xd = (n - 1) * (suma_resta - 1) / -2 + c * (suma_resta + 1) / 2;
    while (f * suma_resta <= init_f * (suma_resta + 1) / 2) {
      arr[i] = mat[f * n + c_xd];
      ++i;
      f += suma_resta;
      c_xd += suma_resta;
    }
    ++init_f;
  }
  int init_c = 1;
  for (int c = n - 2; c >= 0; --c) {
    suma_resta *= -1;
    f = ((n - 1) * (suma_resta - 1)) / -2 + (suma_resta + 1) * init_c / 2;
    c_xd = (n - init_c - 1) * (suma_resta - 1) / -2;
    while (c_xd * suma_resta <= (n - init_c - 1) * (suma_resta + 1) / 2) {
      arr[i] = mat[f * n + c_xd];
      ++i;
      f += suma_resta;
      c_xd += suma_resta;
    }
    ++init_c;
  }
}

int _main(void) {
  printf("Ingrese las dimensiones de la matriz n * n: ");
  int n;
  leer_dimension(&n);

  int mat[n * n];
  int arr[n * n];

  rellenar(mat, n, n);
  printf("La matriz:\n");
  mostrar_matriz(mat, n, n);
  gen(mat, arr, n);
  printf("\nEl vector asociado mediante el proceso:\n");

  for (int i = 0; i < n * n; ++i) {
    printf(" %d", arr[i]);
  }
  putchar(10);
  return EXIT_SUCCESS;
}

int main(void) {
  srand(time(nullptr));
  return _main();
}
