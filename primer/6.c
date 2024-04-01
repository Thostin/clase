#include <stdio.h>
#include <stdlib.h>

void num(int a, int b){
  if(a > b){
    a ^= b;
    b ^= a;
    a ^= b;
  }
  printf("Números en el intervalo (%d, %d): \n{", a, b);

  a += 2 - (a&1);
  b += b&1;

  if(a < b)
    printf("%d", a);
  else
    goto final;
  a += 2;
  while(a < b){
    printf(", %d", a);
    a += 2;
  }

final:
  putchar('}');
  putchar(10);
}

int main(int argc, char *argv[]){
  num(atoi(argv[1]), atoi(argv[2]));
  return 0;
}
