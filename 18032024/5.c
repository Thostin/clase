/*
 * Escriba un algoritmo que permita
 * encontrar el maximo elemento del vector
 * */

#include <stdio.h>

int max(int *, int size);

int main(void){
  printf("Introduzca el tamaño del vector: ");
  int n;
  if(!scanf(" %d", &n) || n <= 0){
    printf("Improper input\n");
    return 1;
  }

  int vec[n];
  printf("Introduzca los elementos:\n");
  for(int i = 0; i < n; ++i){
    printf("vec[%d]: ", i);
    if(!scanf(" %d", vec + i)){
      printf("Improper input\n");
      return 1;
    }
  }

  int elem_maximo = max((int *)vec, n);

  printf("El elemento maximo es: %d\n", elem_maximo);
  return 0;
}

int max(int *ptr, int size){
  if(size <= 0)
    return 73;

  int p_max = *ptr;
  for(int i = 1; i < size; ++i){
    if(ptr[i] > p_max)
      p_max = ptr[i];
  }

  return p_max;
}
