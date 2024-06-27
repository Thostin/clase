#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mensaje() {
  printf("El total de alumnos en el aula es de xxx, de ellos estan afectados "
         "yyy por la enfermedad, y la temperatura que estan sufriendo es de "
         "zzzz grados centigrados");
}

int main() {
  int alumnos, afectada, temperatura;
  srand(time(NULL));
  alumnos = rand() % 20 + 30;
  printf("/n%d", alumnos);

  mensaje();
  return 0;
}
