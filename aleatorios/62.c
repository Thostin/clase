#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int type;

int main(void) {
  srand(time(NULL));
  const type primos[] = {1, 2, 3, 5, 7, 11};

  unsigned res[4] = {0};

  int lim;
  printf("Ingrese el límite de la prueba: ");
  if (!scanf("%d", &lim) || lim < 1) {
    printf("Improper input\n");
    return 1;
  }

  for (int i = 0; i < lim; ++i) {
    switch (primos[rand() % 6] * primos[rand() % 6] * primos[rand() % 6] *
            primos[rand() % 6] * primos[rand() % 6]) {

      // generala
    case 1:
    case 32:
    case 243:
    case 3125:
    case 16807:
    case 161051:
      ++*res;
      break;

    // Poker
    case 16:
    case 81:
    case 625:
    case 2401:
    case 14641:
    case 162:
    case 1250:
    case 4802:
    case 29282:
    case 1875:
    case 7203:
    case 43923:
    case 12005:
    case 73205:
    case 102487:
    case 2:
    case 3:
    case 5:
    case 7:
    case 11:
      ++res[1];
      break;
      // Faul

    case 8:
    case 27:
    case 125:
    case 343:
    case 1331:
    case 108:
    case 500:
    case 1372:
    case 5324:
    case 1125:
    case 3087:
    case 11979:
    case 8575:
    case 33275:
    case 65219:
    case 4:
    case 9:
    case 25:
    case 49:
    case 121:
      ++res[2];
      break;
    // Escalera
    case 210:
    case 2310:
      ++res[3];
      break;
    }
  }

  printf("GENERALA: %u\n", res[0]);
  printf("POKER: %u\n", res[1]);
  printf("FAUL: %u\n", res[2]);
  printf("ESCALERA: %u\n\n", res[3]);
  return EXIT_SUCCESS;
}
