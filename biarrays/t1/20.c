#include "func.h"
#include <unistd.h>

int aux_swap;
#define swap(a, b)                                                             \
  aux_swap = *(a);                                                             \
  *(a) = *(b);                                                                 \
  *(b) = aux_swap;

int final_pos_x;
int final_pos_y;

void rand_move(int *arr, int pos_x, int pos_y, int f, int c, int lim_gen) {
  // El objetivo de esta variable es hacer que se mezcle un poco más
  int last = -1;
  for (int i = 0; i < lim_gen; ++i) {
    switch (rand() % 4) {
    case 0:
      if (pos_y - 1 >= 0 && 2 != last) {
        swap(arr + c * pos_y + pos_x, arr + c * (pos_y - 1) + pos_x);
        --pos_y;
        last = 0;
      } else {
        --i;
        continue;
      }
      break;
    case 2:
      if (pos_y + 1 < f && 0 != last) {
        swap(arr + c * pos_y + pos_x, arr + c * (pos_y + 1) + pos_x);
        ++pos_y;
        last = 2;
      } else {
        --i;
        continue;
      }
      break;

    case 3:
      if (pos_x - 1 >= 0 && 1 != last) {
        swap(arr + c * pos_y + pos_x, arr + c * pos_y + pos_x - 1);
        --pos_x;
        last = 3;
      } else {
        --i;
        continue;
      }
      break;

    case 1:
      if (pos_x + 1 < c && 3 != last) {
        swap(arr + c * pos_y + pos_x, arr + c * pos_y + pos_x + 1);
        ++pos_x;
        last = 1;
      } else {
        --i;
        continue;
      }
    }

    system("clear");
    printf("Mezclando...\n________________\n");
    mostrar_matriz(arr, f, c);
    printf("________________\n");

#define TIME_SPAN 41900
    usleep(TIME_SPAN);
  }
  final_pos_x = pos_x;
  final_pos_y = pos_y;
}

void play(int *sample, int *arr, int pos_x, int pos_y, int f, int c,
          int lim_play) {
  system("clear");
  printf("Movimientos restantes: %d\n________________\n", lim_play);
  mostrar_matriz(arr, f, c);
  printf("________________\n");

  if (0 == __builtin_memcmp(sample, arr, f * c * sizeof(int))) {
    printf("\nError, la matriz ya está resuelta\n");
    return;
  }

  printf("\nIntenta ordenarla con movimientos hacia arriba(1) y abajo(3), "
         "izquierda(4) "
         "y derecha(2):\n");
  int op;
  for (int i = 0; i < lim_play; ++i) {
    printf("> ");
    if (1 != scanf(" %d", &op) || op <= 0 || op >= 5) {
      printf("Inválido\n");
      return;
    }

    switch (op - 1) {
    case 0:
      if (pos_y - 1 >= 0) {
        swap(arr + c * pos_y + pos_x, arr + c * (pos_y - 1) + pos_x);
        --pos_y;
      } else
        printf("Inválido\n"), --i;
      break;
    case 2:
      if (pos_y + 1 < f) {
        swap(arr + c * pos_y + pos_x, arr + c * (pos_y + 1) + pos_x);
        ++pos_y;
      } else
        printf("Inválido\n"), --i;
      break;

    case 3:
      if (pos_x - 1 >= 0) {
        swap(arr + c * pos_y + pos_x, arr + c * pos_y + pos_x - 1);
        --pos_x;
      } else
        printf("Inválido\n"), --i;
      break;

    case 1:
      if (pos_x + 1 < c) {
        swap(arr + c * pos_y + pos_x, arr + c * pos_y + pos_x + 1);
        ++pos_x;
      } else
        printf("Inválido\n"), --i;
    }
    system("clear");
    printf("Movimientos restantes: %d\n________________\n", lim_play - i - 1);
    mostrar_matriz(arr, f, c);
    printf("________________\n");

    if (0 == __builtin_memcmp(sample, arr, f * c * sizeof(int))) {
      printf("Lo has resuelto!\nMovimientos: %d\n", i + 1);
      return;
    }
  }

  printf("No has podido resolverlo en %d movimientos\n", lim_play);
}

int _main(void) {
  srand(time(nullptr));

  const int f = 5, c = 4;
  int arr[f * c];
  int sample[f * c];

  for (int i = 0; i < f * c - 1; ++i) {
    arr[i] = sample[i] = i + 1;
  }

// Es el valor que servirá como pivote
#define VAL_MOV 0
  arr[f * c - 1] = VAL_MOV;
  sample[f * c - 1] = VAL_MOV;
  const int pos_x = c - 1, pos_y = f - 1;
  const int lim_gen = 120;
  const int lim_play = 3000;

  rand_move(arr, pos_x, pos_y, f, c, lim_gen);
  play(sample, arr, final_pos_x, final_pos_y, f, c, lim_play);

  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
