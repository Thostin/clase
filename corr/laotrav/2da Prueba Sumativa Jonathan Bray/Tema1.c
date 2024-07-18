#include <stdio.h>
#include <stdlib.h>

int ver(int n);
int ver1(int n);
int ver2(int n);
int calpunt(int n);
int comparator(const void* p, const void* q);

int main()
{
  int N;
  N = ver(N);
  int P[N];
  char C[N][25];
  char nombre[25];
  int p;
  int m;
  int puntos = 0;

  for (int i = 0; i < N; ++i) {
    printf("Ingrese el nombre del cliente\n");
    scanf("%s", &nombre);

    for (int j = 0; j < 25; ++j)
      C[i][j] = nombre[j];

    p = ver1(p);

    for (int j = 0; j < p; ++j) {

      m = ver2(m);
      }
      puntos = puntos + calpunt(m);


    P[i] = puntos;
    puntos = 0;
  }

  qsort((void*)P, N, sizeof(int), comparator);

  printf("\n");
  printf("Lista de puntos ordenados:\n");
  for (int i = 0; i<N; ++i){
    printf("%s:    %d\n", C[i], P[i]);
  }

  return 0;
}

int calpunt(int n) {
  switch (n){
  case 0:
    return 0;
    break;
  case 1:
    return 1;
    break;
  case 2:
    return 3;
    break;
  case 3:
    return 6;
    break;
  }
}

int comparator(const void* p, const void* q)
{
  return (*(int*)p - *(int*)q);
}

int ver(int n)
{
  printf("Ingrese la cantidad de clientes que se quiere cargar:\n");
  scanf("%d", &n);
  while (n < 1){
    printf("Ingrese una cantidad mayor que uno\n");
    scanf("%d", &n);
  }
  return n;
}

int ver1(int n)
{
  printf("Ingrese la cantidad de prestamos realizados por el cliente\n");
    scanf("%d", &n);
    while (n != 1 && n !=2) {
      printf("Ingrese 1 o 2 para la cantidad de prestamos\n");
      scanf("%d", &n);
    }
  return n;
}

int ver2(int n)
{
  printf("Ingrese la cantidad de meses de atraso para el prestamo\n");
  scanf("%d", &n);
  while (n < 0 || n > 3) {
    printf("Ingrese una cantidad desde 0 a 3\n");
    scanf("%d", &n);
  return n;
  }
}
