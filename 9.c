/*
* Leer un vector de N componentes. Hallar e imprimir 
* el promedio de todas sus posiciones impares.
*/
#include <stdio.h>

int main(void){
  unsigned _len;
  printf("Introduzca la cantidad de elementos del vector: ");

  if(!scanf("%d", &_len) || _len < 1){
    printf("Chaoooo\n");
    return 1;
  }

  const unsigned long len = (unsigned long)_len;
  int i;
  long vec[len];

  for(i = 0; i < len; ++i){
    printf("> ");
    if(!scanf("%ld", vec + i)){
      printf("AAAAA\n");
      return 1;
    }
  }

  long sum = 0;
  for(i = -1; (i += 2) < len; ){
    sum += (long)vec[i];
  }

  printf("La suma de los elementos de las posiciones impares: %ld\n", sum);
  return 0;
}
