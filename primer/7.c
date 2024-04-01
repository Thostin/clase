#include <stdio.h>
#include <stdlib.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */


void tabla_de_multiplicar(char *str, int n){

  if(0 == n){
    printf("Che te dije bien\n");
    printf("Chau\n");
    int len = strlen(str);
    char comando[9 + len];
    long *aux = (long *)comando;
    *aux =     *(long *)"killall ";

    memcpy(comando + 8, str + 2, len);
    system(comando);
  }
  printf("Tabla de multiplicar del %d:\n", n);
  printf("________________________\n");
  for(int i = 1; i < 11; ++i){
    printf("|%d * %d = %d\n", n, i, n * i);
  }
  printf("________________________\n");
}

int main(int argc, char *argv[]){
  int n;
  printf("Introduzca un entero entre -2147483648 y 2147483147 pero distinto de 0:\n> ");
  scanf("%d", &n);
  tabla_de_multiplicar(*argv, n);
  return EXIT_SUCCESS;
}
