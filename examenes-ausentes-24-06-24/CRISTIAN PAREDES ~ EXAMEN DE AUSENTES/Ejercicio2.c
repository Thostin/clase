#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int alumnos, afectada, temperatura;

  alumnos = rand();
  while (alumnos > 30 || alumnos < 20) {
    alumnos = rand();
  }

  afectada = rand();
  while (afectada > 5 || afectada < 12) {
    afectada = rand();
  }

  temperatura = rand();
  while (temperatura > 40 || temperatura < 37) {
    temperatura = rand();
  }

  printf("El total de alummnos en el aula es %d, de ellos estan afectados %d "
         "por la enfermedad, y la temperatura que estan sufriendo es %d grados "
         "centigrados",
         alumnos, afectada, temperatura);

  return 0;
}
