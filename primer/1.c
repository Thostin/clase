#include <stdio.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

uint64_t fac(int x)
{
  if(x < 0)
    return -1;
  if(0 == x)
    return 1;

  uint64_t ret = x;
  uint64_t _x = ret;

  while(--_x != 1)
    ret *= _x;

  return ret;
}

int main(int argc, char *argv[])
{
  if(argc != 2){
    printf("Argumento impropio\n");
    return 1;
  }
  int n = atoi(1 [argv]);
  printf("Factorial de %d: %zu\n", n, fac(n));
  return EXIT_SUCCESS;
}
