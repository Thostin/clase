#include <stdio.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */

void zero(void){
  int lim;
  printf("Digite la cantidad de números que va a introducir: \n> ");
  scanf("%d", &lim);
  if(lim <= 0){
    printf("No pue seeee\n");
    return;
  }
  printf("Digite los enteros por favor:\n");


  const int val = 1 << 31;
  int menor_0 = 0, igual_0 = 0, mayor_0 = 0;
  int aux;
  while(lim--){
    printf("> ");
    scanf("%d", &aux);
    switch(aux){
      case 0: ++igual_0; break;
      default:
      switch (aux & val) {
          case 0: ++mayor_0; break;
          default: ++menor_0;
      }
    }
  }

  printf("Se ingresaron %d enteros menores que 0, %d ceros, y %d enteros mayores que 0\n", menor_0, igual_0, mayor_0);
}

int main(void){
  zero();
  return EXIT_SUCCESS;
}
