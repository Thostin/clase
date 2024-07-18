#include <stdio.h>
#include <stdlib.h>

int main()
{
  char N[40][40];
  char p[40];
  printf("Ingrese el nombre del cliente\n");
  scanf("%s", &p);

  for (int i = 0; i<40; ++i){
    N[1][i] = p[i];
  }


  printf("%s", N[1]);
    return 0;
}
