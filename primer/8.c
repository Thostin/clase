#include <stdlib.h>
#include <stdio.h>

#define abs(x) (x) < 0 ? -(x) : (x)

void open_interval(void){
  printf("Introduzca dos números: \n> ");
  double a, b;

intento:
  if(scanf("%lf%lf", &a, &b) != 2)
    goto err;

  if(a > b){
    printf("El primer valor no puede ser mayor al segundo, vuelva a intentarlo\n> ");
    goto intento;
  }

  printf("Ahora digite una serie de números, para terminar introduza un 0:\n");
  double aux;

  int c_dentro_intervalo = 0;
  int c_fuera_intervalo = 0;
  int c_al_limite = 0;

  printf("> ");
  while(scanf("%lf", &aux)){
    while(getchar() != '\n');
    if(0 == aux){
      printf("***Resultados***\n");
      printf("Cantidad de números dentro del intervalo abierto (%lf, %lf): %d\n", a, b, c_dentro_intervalo);
      printf("Cantidad de números en los límites del intervalo (%lf, %lf): %d\n", a, b, c_al_limite);
      printf("Cantidad fuera del intervalo: %d\n", c_fuera_intervalo);
      return;
    }
    if(aux == a || aux == b)
      ++c_al_limite;
    else if(aux < a || aux > b)
      ++c_fuera_intervalo;
    else 
      ++c_dentro_intervalo;
    printf("> ");
  }

err:
  printf("Ha ingresado algo inválido, chau\n");
  exit(73);
}

int main(void){
  open_interval();
  return 0;
}
