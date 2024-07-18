#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sim(int l[], int c[]) { // simular los lanzameintos
  int d1, d2, d3, sum;
  for (int i = 0; i < 100; i++) {
    d1 = rand() % 6 + 1; // primer dado
    d2 = rand() % 6 + 1; // segundo dado
    d3 = rand() % 6 + 1; // tercer dado
    sum = d1 + d2 + d3;
    l[i] = sum;

    // Can buffer overflow, off-by-one
    c[sum]++;
  }
}

int a(int c[]) { // primer punto
  int fm = 0;
  for (int i = 0; i < 18; i++) {
    if (c[i] > c[fm]) {
      fm = i;
    }
  }
  return fm;
}

// Al sumar no tiene por qué: tres iguales si y solo si los tres son iguales.
int b(int l[], int n) { // segundo punto
  int c = 0;
  for (int i = 0; i < n; i++) {
    int d1 = l[i] / 3;
    if (l[i] % 3 == 0 && (d1 >= 1 && d1 <= 6)) {
      c++;
    }
  }
  return c;
}

// No funciona, creo..., no, no anda
int cc(int l[], int n) {
  int c = 0;
  for (int i = 0; i < n; i++) {
    // obtener los digitos de la suma (1-6)
    int d1 = l[i] % 10;
    int d2 = (l[i] / 10) % 10;
    int d3 = l[i] / 100;
    // verifica si los dados estan en orden ascendente o descendente
    if ((d1 == d2 + 1 && d2 == d3 + 1) || (d1 == d2 - 1 && d2 == d3 - 1)) {
      c++;
    }
  }
  return c;
}

int main() {
  int l[100], c[18] = {0}; // declarar los variables
  srand(time(NULL));
  sim(l, c);     // simulacion de lanzamientos
  int ar = a(c); // respuesta del primer punto, la suma que más veces sale.
  int br = b(l, 100);  // respuesta del segundo punto
  int cr = cc(l, 100); // respuesta del tercer punto
  // imprimir los resultados
  printf("simulando 100 lanzamientos de 3 dados se obtiene\n");
  printf("el numero que mas veces se presenta como suma total es %d\n", ar);
  printf("en %d tiradas los dados dieron el mismo numero\n",
         br); // MAL, da casi siempre más de lo que debe
  printf("en %d tiradas los dados formaron una escalera\n", cr);
  return 0;
}
