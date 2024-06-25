#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int alumnos=20, n1, afectados=5, n2, temperatura=37, n3;
    srand(time(NULL));
    n1 = (rand() % 20) + 10;
    if (n1 >= 20 && n1 <= 30)
    {
        alumnos = n1;
    }
    
    n2 = (rand() % 5) + 7;
      if (n2 >= 5 && n2 <= 12)
    {
        afectados = n2;
    }
    n3 = (rand() % 37) + 3;
      if (n3 >= 37 && n3 <= 40)
    {
        temperatura = n3;
    }
    printf("El total de alumnos en el aula es de %d, de ellos estan afectados %d por la enfermedad, y la temperatura que estan sufriendo es de %d", alumnos, afectados, temperatura);
}