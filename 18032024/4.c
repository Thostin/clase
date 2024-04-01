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
  for(i = -2; (i += 2) < len; ){
    sum += (long)vec[i];
  }

  const long p_len = (len + 1) / 2;
  printf("El promedio de las posiciones impares: %lf\n", (double)sum / (double)p_len);
  return 0;
}
