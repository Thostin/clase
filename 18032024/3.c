/*
* Leer un vector de 20 componentes , multiplicar sus elementos
* e imprimir el resultado.
*/

#include <stdio.h>

int main(void){
  const int len = 5;
  printf("Introduzca %d elementos:\n", len);
  int i;
  long vec[len];

  for(i = 0; i < len; ++i){
    printf("> ");
    if(!scanf("%ld", vec + i)){
      printf("Entrada impropia\n");
      return 1;
    }
  }
  long mul = 1;
  for(i = 0; i < len; ++i){
    mul *= vec[i];
  }

  printf("La multiplicación de los elementos del vector: %ld\n", mul);
  return 0;
}
