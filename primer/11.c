#include <stdio.h>
#include <math.h>

int is_prime(size_t n){
  switch(n){
    case 1: return 0;
    case 2: return 1;
  }
  size_t range = sqrt(n);
  range -= !(range&1);

  if(n & 1)
  while(range - 1){
    if(n % range)
      range -= 2;
    else
      return 0;
  }
  else 
    return 0;

  return 1;
}

int main(int argc, char *argv[]){
  size_t n;
  if(argc == 2 && sscanf(argv[1], "%zu", &n))
    printf("%zu: %srime\n", n, is_prime(n) ? "P" : "Not p");
  else 
    printf("Improper input\n");
  return 0;
}
