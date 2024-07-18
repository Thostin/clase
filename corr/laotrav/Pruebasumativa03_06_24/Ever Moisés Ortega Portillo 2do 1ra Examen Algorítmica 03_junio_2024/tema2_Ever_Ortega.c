/*
 * NOTA: La generación de aleatorios no es muy aleatoria, pero lo intenté
 * */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#define LANZAMIENTOS 100
#define SUMAS_POSIBLES 16

int sum_max(void);
int tres_iguales(void);
int cant_escalera(void);

int main(void) {
  srand(time(NULL));
  printf("La suma de los tres números en los dados que más aparece es: %d\n",
         sum_max());
  printf("En %d ocasiones salieron los tres números iguales\n", tres_iguales());
  printf("En %d ocasiones los números formaron una escalera\n",
         cant_escalera());
  return EXIT_SUCCESS;
}

// Retorna la posición en que se encuentra el mayor elemento
int max_arr(uint8_t *arr, int len) {
  int max = *arr, max_pos = 0;
  for (int i = 1; i < len; ++i) {
    if (max < arr[i]) {
      max = arr[i];
      max_pos = i;
    }
  }
  return max_pos;
}

int sum_max(void) {
  uint8_t arr[SUMAS_POSIBLES] = {0};
  // Hay 16 posibles sumas
  for (int i = 0; i < LANZAMIENTOS; ++i) {
    ++arr[rand() % 6 + rand() % 6 + rand() % 6];
  }

  return max_arr(arr, SUMAS_POSIBLES) + 3;
}

int tres_iguales(void) {
  int num = rand();
  int iguales = 0;
  int aux[3];
  for (int i = 0; i < LANZAMIENTOS; ++i) {
    num *= rand();
    srand(num);
    aux[0] = rand();

    num *= rand();
    srand(num);
    aux[1] = rand();

    num *= rand();
    srand(num);
    aux[2] = rand();
    if (aux[0] % 6 == aux[1] % 6 == aux[2] % 6)
      ++iguales;
  }
  return iguales;
}

int cant_escalera(void) {
  uint8_t primos[] = {1, 2, 3, 5, 7, 11};
  int cantidad_escaleras = 0;
  for (int i = 0; i < LANZAMIENTOS; ++i) {
    switch (primos[rand() % 6] * primos[rand() % 6] * primos[rand() % 6]) {
    case 6:
    case 30:
    case 105:
    case 385:
      ++cantidad_escaleras;
    }
  }
  return cantidad_escaleras;
}
