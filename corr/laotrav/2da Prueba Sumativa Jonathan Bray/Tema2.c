#include <stdio.h>
#include <stdlib.h>

#define ALEATORIO 534
int cMismo(int *a);

int main()
{
  int max = 777;
  int cond = 0;
  int arr[300];
  int b[100];
  int c[19] = {0};
  for (int i = 0; i < 300; ++i){    //generacion de numeros aleatorios
    arr[i] = 0;
    for (int j = 1; j <= i; ++j){
      if ((i+ALEATORIO) % j == 0)
        arr[i] = arr[i] + j;
    }
  arr[i] = arr[i]%6 + 1;
  printf("%d\n", arr[i]);
  if (i % 3 == 2){
    printf("\n");
  }
  }//generacion de numeros aleatorios


  printf("\n\n\n");
  for (int i = 0; i < 100; ++i) {
    b[i] = arr[3*i] + arr[3*i+1] + arr[3*i+2];
    printf("%d\n", b[i]);
  }

  for (int i = 0; i < 100; ++i) {
    switch (b[i]) {
    case 0:
      c[0] = c[0] + 1;
      break;
    case 1:
      c[1] = c[1] + 1;
      break;
    case 2:
      c[2] = c[2] + 1;
      break;
    case 3:
      c[3] = c[3] + 1;
      break;
    case 4:
      c[4] = c[4] + 1;
      break;
    case 5:
      c[5] = c[5] + 1;
      break;
    case 6:
      c[6] = c[6] + 1;
      break;
    case 7:
      c[7] = c[7] + 1;
      break;
    case 8:
      c[8] = c[8] + 1;
      break;
    case 9:
      c[9] = c[9] + 1;
      break;
    case 10:
      c[10] = c[10] + 1;
      break;
    case 11:
      c[11] = c[11] + 1;
      break;
    case 12:
      c[12] = c[12] + 1;
      break;
    case 13:
      c[13] = c[13] + 1;
      break;
    case 14:
      c[14] = c[14] + 1;
      break;
    case 15:
      c[15] = c[15] + 1;
      break;
    case 16:
      c[16] = c[16] + 1;
      break;
    case 17:
      c[17] = c[17] + 1;
      break;
    case 18:
      c[18] = c[18] + 1;
      break;

    }
  }

  printf("\n\n\n");

  for (int i = 0; i< 19; ++i){
    printf("%d\n", c[i]);
  }

  for (int i = 0; i < 19; ++i){
    for (int j = 0; j < 19; ++j){
      cond = 1;
      if (c[j] > c[i]){
        cond = 0;
        break;
      }
    }
    if (cond == 1){
      max = i;
      break;
    }
  }

  printf("\n\n\n");
  printf("El numero que mas veces se presenta como suma total es: %d\n", max);
  printf("\n\n\n");
  printf("En %d jugadas los tres dieron el mismo numero\n", cMismo(arr));
  printf("\n\n\n");
  printf("En %d jugadas se formo una escalera\n", cEscalera(arr));


  return 0;
}

int cMismo(int *a)
{
  int c = 0;
  for (int i = 0; i < 100; ++i) {
    if (a[3*i] == a[3*i+1] && a[3*i+1] == a[3*i+2])
      c = c + 1;
  }
  return c;
}

int cEscalera(int *a)
{
  int c = 0;
  for (int i = 0; i < 100; ++i) {
    if ((a[3*i] + 1) == a[3*i+1] && (a[3*i+1] + 1) == a[3*i+2])
      c = c + 1;
  }
  return c;
}
