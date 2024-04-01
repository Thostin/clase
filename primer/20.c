#include <stdio.h>
#include <math.h>

uint64_t atoulong(char *str){
  int len = strlen(str);
  int mul = 1;
  time_t ret = 0;
  while(--len >= 0){
    ret += (str[len] - '0') * mul;
    mul *= 10;
  }

  return ret;
}

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
  uint64_t n;
  if(argc != 2 || sscanf(argv[1], "%zu", &n) != 1){
    printf("Improper input\n");
    return 1;
  }
  switch(n){
    case 0:
    case 1: printf("No primes up to %lu\n", n);
    return 0;
  }
  uint64_t prime = 1;
  int count = 1;
  putchar('2');
  while(count < n){
    if(is_prime(prime)){
      printf(", %lu", prime);
      ++count;
    }
    prime += 2;
  }
  putchar(10);
  return 0;
}
