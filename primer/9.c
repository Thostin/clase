#define pow _pow
#include <stdio.h>
#include <stdlib.h>
#undef _pow

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

double pow(double x, size_t y){
  if(0 == y)
    return 1;

  double ret = x;
  while(--y)
    ret *= x;
  return ret;
}

void pot(void){
  printf("Se hará el cálculo de una potencia, introduza los datos por favor:\nBase (puede ser decimal): ");
  double base;
  if(!scanf("%lf", &base)){
    printf("Dato inválido introducido, chau\n");
    exit(26);
  }
  while(getchar() != '\n');

  size_t exp;
  printf("Ahora un numero entero positivo, será la potencia:\n> ");
  if(1 != scanf("%zu", &exp) || !exp){
    printf("Dato invalido, chau\n");
    exit(1729);
  }

  printf("Este es el resultado de la exponenciación:\n%lf^%zu = %lf\n", base, exp, pow(base, exp));
}

int main(int argc, char *argv[])
{
  pot();
  return EXIT_SUCCESS;
}
