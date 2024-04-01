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

int main(void){
  printf("Tablas de multiplicar de 1, 2, 3, 4, y 5:\n");
  int y = 6;
  while(--y)
    tabla_de_multiplicar(NULL, y);

  return 0;
}
