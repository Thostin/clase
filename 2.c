/*
* Leer un vector de 30 componentes. Sumar sus componentes, 
* hallar el promedio e imprimir el resultado.
*/

#include <stdio.h>

int main(void){
  const int len = 5;
  printf("Introduzca %d enteros:\n", len);
  int vec[len];

  int i;
  for(i = 0; i < len; ++i){
    printf("> ");
    if(!scanf("%d", vec + i)){
      printf("Improper input\n");
      return 0;
    }
  }

  int sum = 0;
  for(i = 0; i < len; ++i){
    sum += vec[i];
  }

  printf("Promedio: %lf\n", (double)sum / (double)len);
  return 0;
}
