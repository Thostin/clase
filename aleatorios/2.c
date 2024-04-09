#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  unsigned lim = 10;

  printf("SIMULANDO 10, 100, 1000, 10000 y 100000 LANZAMIENTOS DE MONEDA\n");
  int cara, cruz;

  for (int j = 0; j < 5; ++j) {
    cara = cruz = 0;
    for (unsigned i = 0; i < lim; ++i) {
      switch (rand() & 1) {
      case 1:
        ++cara;
        break;
      default:
        ++cruz;
      }
    }
    printf("%d Lanzamientos:\n", lim);
    printf("CARAS: %i\n", cara);
    printf("CRUCES: %i\n\n", cruz);
    lim *= 10;
  }

  return EXIT_SUCCESS;
}
