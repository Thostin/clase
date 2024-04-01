#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main(void) {
  srand(time(NULL));
  int A[N];
  int B[N];
  int L[N];
  int M[N];

  for (int i = 0; i < N; ++i) {
    B[i] = rand() & 1;
    L[i] = rand();
    M[i] = rand();
  }

  for (int i = 0; i < N; ++i) {
    A[i] = B[i] ? M[i] : L[i];
  }

  printf("A:\n%d", *A);
  for (int i = 1; i < N; ++i) {
    printf(", %d", A[i]);
  }
  return EXIT_SUCCESS;
}
