#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

void lanzar_dado(int valor) {
  srand(valor + 1);
  printf("%d", valor); // Me olvidé como hacer. 1 punto meno
}

void suma_dados(int dado1, int dado2, int dado3, int suma_dado[]) {
  int suma = dado1 + dado2 + dado3; // Suma los dados.
  suma_dado[(suma - 3)]++;
}

void triple(int dado1, int dado2, int dado3, int triples) {
  if (dado1 == dado2 && dado2 == dado3) {
    triples++; // Suma triples.
  }
}

void escalera(int dado1, int dado2, int dado3, int escaleras) {
  if ((dado1 + 1) == dado2 && (dado2 + 1) == dado3) {
    escaleras++; // Suma escaleras.
  }
}

int main() {

  int dado1, dado2, dado3, suma_dado[16], triples = 0, escaleras = 0;

  for (int i = 0; i < 18; i++) {
    suma_dado[i] = 0; // Inicializa el contador de sumas en 0.
  }

  for (int i = 0; i < 100; i++) {
    lanzar_dado(dado1);
    lanzar_dado(dado2);
    lanzar_dado(dado3); // Lanza dados.

    suma_dados(dado1, dado2, dado3, suma_dado);
    triple(dado1, dado2, dado3, triples);
    escalera(dado1, dado2, dado3, escaleras);
  }

  printf("Veces que se presento cada suma: /n");
  for (int i = 0; i < 18; i++) {
    printf("Suma = %d --> %d. /n", i + 3,
           suma_dado[i]); // Imprime todos los numeros.
  }

  printf("Se dieron el mismo numero en %d tiradas. /n",
         triples); // Imprime triples.
  printf("Se formo una escalera en %d tiradas. /n",
         escaleras); // Imprime escaleras.

  return 0;
}
