#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void temperatura() {
  int alumnos = rand() % (30 - 20 + 1) - 20;
  int afectada = rand() % (11 - 5 + 1) - 5;
  int temperatura = rand() % (40 - 37 + 1) - 37;
  printf("EL total de alumnos es %d, de ellos estan afectados %d, y la "
         "temperatura que estan sufriendo es %d",
         alumnos, afectada, temperatura);
}

int main() {
  srand(time(NULL));
  temperatura();
}
