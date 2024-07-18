// Escriba un algoritmo que simule 100 lanzamientos de tres dados. Generar
// procedimientos que permitan realizar lo siguiebte: calcular cuál es el número
// que más veces se presenta como suma total de los tres dados, en cuántas
// tiradas los tres dados dieron el mismo número en cuántas tiradas los números
// formaron una escalera.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Sumatoria(int Vector[100]);
void Igual(int Vector[100]);
void Escalera(int Vector[100]);
int Mayor(int Vector[100]);

int i, j, Contador, escalera, igual;

int main() {
  int Vector[2];
  Contador = 0;
  srand(time(NULL));
  printf("Se simulan 100 lanzamientos de tres dados\n");
  while (Contador < 100) {
    Sumatoria(Vector);
    Igual(Vector);
    Contador++;
  }
  printf("Salieron %d veces escalera\n", escalera);
  return 0;
}

void Sumatoria(int Vector[100]) {
  int Suma, Total[100];
  Suma = Contador = 0;
  while (Contador < 100) {
    for (i = 0; i < 3; i++) {
      Suma = Suma + Vector[i];
    }

    Total[Contador] = Suma;
    Contador++;
  }
  Mayor(Total);
  // return 0;
}

// MACANADA
int Mayor(int Vector[100]) {
  Contador = 0;
  // La mayor suma posible puede ser 18, si es que salen tres dados con la cara
  // igual a seis
  while (Contador < 100) {

    Contador++;
  }
  return 0;
}

// MAAAAALLL
void Igual(int Vector[100]) {
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (Vector[i] == Vector[j]) {
        igual++;
      }
    }
  }
  printf("Salieron %d veces el mismo número\n", igual);
}

// Esta función tiene sentido
void Escalera(int Vector[100]) {
  escalera = 0;
  if ((Vector[0] == 1 && (Vector[1] == 2 && Vector[2] == 3))) {
    escalera++;
  }
  if (Vector[0] == 2 && Vector[1] == 3 && Vector[2] == 4) {
    escalera++;
  }
  if (Vector[0] == 3 && Vector[1] == 4 && Vector[2] == 5) {
    escalera++;
  }
  if (Vector[0] == 4 && Vector[1] == 5 && Vector[2] == 6) {
    escalera++;
  }
}
