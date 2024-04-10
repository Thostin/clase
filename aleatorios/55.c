#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

typedef int type;

int main(void) {
  // srand(time(NULL));
  const type primos[] = {1, 2, 3, 5, 7, 11};

  unsigned res[4] = {0};

  int lim = 5000000;
  /*
  printf("Ingrese el límite de la prueba: ");
  if (!scanf("%d", &lim) || lim < 1) {
    printf("Improper input\n");
    return 1;
  }*/

  // int mul;
  // int vec[5];

  for (int i = 0; i < lim; ++i) {
    /*mul = 1;
    for (int j = 0; j < 5; ++j) {
      vec[j] = primos[rand() % 6];
      printf("%d ", vec[j]);
      mul *= vec[j];
    }*/

    switch (primos[rand() % 6] * primos[rand() % 6] * primos[rand() % 6] *
            primos[rand() % 6] * primos[rand() % 6]) {
      // GENERALA
    case 1:
    case 32:
    case 243:
    case 3125:
    case 16807:
    case 161051:
      ++*res;
      break;

      // POKER:

    case 16:
    case 81:
    case 625:
    case 2401:
    case 14641:
    case 2:
    case 162:
    case 1250:
    case 4802:
    case 29282:
    case 3:
    case 48:
    case 1875:
    case 7203:
    case 43923:
    case 5:
    case 80:
    case 405:
    case 12005:
    case 73205:
    case 7:
    case 112:
    case 567:
    case 4375:
    case 102487:
    case 11:
    case 176:
    case 891:
    case 6875:
    case 26411:
      ++res[1];
      break;
      // FAUL:

    case 8:
    case 27:
    case 125:
    case 343:
    case 1331:
    case 4:
    case 108:
    case 500:
    case 1372:
    case 5324:
    case 9:
    case 72:
    case 1125:
    case 3087:
    case 11979:
    case 25:
    case 200:
    case 675:
    case 8575:
    case 33275:
    case 49:
    case 392:
    case 1323:
    case 6125:
    case 65219:
    case 121:
    case 968:
    case 3267:
    case 15125:
    case 41503:
      ++res[2];
      break;
      // ESCALERA:

    case 210:
    case 2310:
      ++res[3];
      break;
    }
  }

  printf("\nGENERALA: %u\n", res[0]);
  printf("POKER: %u\n", res[1]);
  printf("FAUL: %u\n", res[2]);
  printf("ESCALERA: %u\n\n", res[3]);

  return EXIT_SUCCESS;
}
