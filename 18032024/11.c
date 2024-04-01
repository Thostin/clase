#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int *ptr, int size);

int main(void){
  const int len = 100;
  int B[len];

  srand(time(NULL));
  for(int i = 0; i < len; ++i){
    B[i] = 1 + rand()%100;
  }

  int elem_max = max((int *)B, len);
  
  int A[len];
  for(int i = 0; i < len; ++i){
    A[i] = B[i] - elem_max;
  }
  printf("%d", A[0]);
  for(int i = 1; i < len; ++i)
    printf(", %d", A[i]);
  
  putchar(10);
  return 0;
}

int max(int *ptr, int size){
  if(size <= 0)
    return 73;

  int p_max = *ptr;
  for(int i = 1; i < size; ++i){
    if(ptr[i] > p_max)
      p_max = ptr[i];
  }

  return p_max;
}

