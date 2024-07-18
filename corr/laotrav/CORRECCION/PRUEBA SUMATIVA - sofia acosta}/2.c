
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void orden(int vector[], int cant) {
  for (int i = 0; i < cant; i++) {
    for (int j = i + 1; j < cant; j++) {
      if (vector[i] < vector[j]) {
        int aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }
}

int main(void) {
  srand(time(NULL));
  int dados[3], suma = 0, sumando[18], veces_igual = 0, escalera = 0, mayor;
  for (int i = 0; i < 18; i++) {
    sumando[i] = 0; // contador para el total de las sumas
  }

  for (int a = 0; a < 100; a++) {
    suma = 0;

    for (int i = 0; i < 3; i++) {
      dados[i] = rand() % 6 + 1;
      suma += dados[i];
    }
    sumando[suma - 1]++;

    if (dados[0] == dados[1] && dados[1] == dados[2]) {
      veces_igual++;
    }

    orden(dados, 3);
    if (dados[0] > dados[1] && dados[1] > dados[2]) {
      escalera++;
    }
  }

  for (int a = 0; a < 18; a++) {
    if (a == 0) {
      mayor = a;
    } else if (a != 0 && sumando[a - 1] > sumando[a]) {
      mayor = a - 1;
    }
  }

  /*
  mayor = 0;
  for(int a = 1; a < 18; a++)
    if(sumando[a] > sumando[mayor])
      mayor = a;
*/

  printf("\n El numero que mas aparece como suma total de los datos es %d ",
         mayor + 1);
  printf("\n Los dados coincidieron en valor %d veces ", veces_igual);
  printf("\n Los numeros formaron escalera %d veces ", escalera);
  return 0;
}
