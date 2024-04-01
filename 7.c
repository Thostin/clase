#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
 *
 * Se tiene un vector de longitud n y hallar los ebd f fjsbs
 *
 * */

int main(void){
  srand(time(NULL));
  const unsigned k = 100;
  int A[k];

  for(int i = 0; i < k; ++i){
    A[i] = 1 + rand()%9;
  }

  printf("Introduzca un número entre 1 y 9: ");
  int x;
  if(!scanf(" %d", &x) || x < 1 || x > 9){
    printf("Improper input\n");
    return 1;
  }

  int hay = 0;
  for(int i = 0; i < k; ++i){
    if(A[i] == x){
      printf("vec[%d] = %d\n", i, A[i]);
      hay = 1;
    }
  }
  if(hay == 0){
    printf("Ningún elemento coincide con la búsqueda\n");
  }
  return 0;
}
