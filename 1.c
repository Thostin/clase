/*
* Leer un vector de 50 elementos y un escalar X y calcule imprimir la suma de la multiplicación de los elementos del vecto por el escalar.
* Ejemplo: A(1, 2, 4)
* Producto escalar: (1 * X) + (2 * X) + (4 * X)
*/

#include <stdio.h>

int main(void){
  printf("Introduzca un escalar: ");
  int X;
  if(!scanf("%d", &X)){
    printf("Che aaaa\n");
    return 1;
  }

  const int size = 5;

  printf("A continuación, introduzca %d enteros:\n", size);
  int vec[size];
  int sum = 0;

  int i;
  for(i = 0; i < size; ++i){
    printf("> ");
    if(!scanf("%d", vec + i)){
      printf("Improper input\n");
    }
  }
  for(i = 0; i < size; ++i)
    sum += vec[i];

  printf("suma * escalar = %d\n", sum * X);
  return 0;
}
