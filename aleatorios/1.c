#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  const unsigned lim = 1000;

  printf("SIMULANDO 1000 LANZAMIENTOS DE MONEDA\n");
  int cara = 0;
  int cruz = 0;
  for (unsigned i = 0; i < lim; ++i) {
    switch (rand() & 1) {
    case 1:
      ++cara;
      break;
    default:
      ++cruz;
    }
  }

  printf("CANTIDAD DE:\n");
  printf("CARAS: %u\n", cara);
  printf("CRUZ: %u\n", cruz);
  return EXIT_SUCCESS;
}
