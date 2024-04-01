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

  int cont = 0;
  for(int i = 0; i < len; ++i){
    if(vec[i] % 15 == 0){
      ++cont;
    }
  }

  switch(cont){
    case 0 : printf("No hay elemento multiplos de 3 y 5\n"); break;
    case 1 : printf("Hay un elemento multiplo de 3 y 5\n"); break;
    default: printf("Hay %d elementos multiplos de 3 y 5\n", cont);
  }
  const long p_len = (len ) / 2;
  printf("El promedio de las posiciones impares: %lf\n", (double)sum / (double)p_len);
  return 0;
}
