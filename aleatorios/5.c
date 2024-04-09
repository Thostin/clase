#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT 5

typedef int type;

int cmp(const void *a, const void *b) { return (*(type *)a - *(type *)b); }

int main(void) {
  type arr[CANT];
  int lim;

  if (!scanf(" %d", &lim) || lim <= 0) {
    printf("Improper input\n");
    return 1;
  }

  int gen, poker, foul, escalera;
  gen = poker = foul = escalera = 0;
  int cont;

  srand(time(NULL));
  for (int i = 0; i < lim; ++i) {
    for (int j = 0; j < 5; ++j) {
      arr[j] = rand() % 6;
    }
    qsort(arr, CANT, sizeof(int), cmp);
    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] &&
        arr[3] == arr[4]) {
      ++gen;
    } else {
      printf("NO GENERALA\n");
      printf("a");

      if ((arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) ||
          (arr[1] == arr[2] && arr[2] == arr[3] && arr[3] == arr[4])) {
        ++poker;
      } else {
        printf("NO POKER\n");
        if ((arr[0] == arr[1] && arr[1] == arr[2] && arr[3] == arr[4]) ||
            (arr[0] == arr[1] && arr[2] == arr[3] && arr[3] == arr[4])) {
          ++foul;
        } else {
          printf("NO FAUL\n");
          cont = 0;
          for (int aux = 0; aux < CANT - 1; ++aux) {
            if (arr[aux] + 1 != arr[aux + 1]) {
              cont = 1;
              goto pop;
            }
          }
        pop:
          if (0 == cont)
            ++escalera;
        }
      }
    }
    putchar(10);
  }

  printf("GENERALA: %d\n", gen);
  printf("POKER: %d\n", poker);
  printf("FOUL: %d\n", foul);
  printf("ESCALERA: %d\n\n", escalera);
  return EXIT_SUCCESS;
}
