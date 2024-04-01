/*
El problema pide calcular 10 + 20 + 40 + ... + 10 * 2^19
Eso es igual a 10 * (1 + 2 + 4 + 8 + ... + 2^19),
que es lo mismo que:
10 * (2^20 - 1)

Sabemos que 2^10 = 1024,
por lo que dejamos al compilador calcular 10 * (1024*1024 - 1)
*/

#include <stdio.h>

int main(void){
  printf("**LA CUENTA**\n");
  int aux = 10;

  for(int i = 1; i < 21; ++i){
    printf("Mes %d: %d€\n", i, aux);
    aux *= 2;
  }
  printf("________________\n");
  printf("TOTAL: %d€\n", 10*(1024 * 1024 - 1));
  return 0;
}
