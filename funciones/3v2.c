#include <stdio.h>
#include <stdlib.h>

#define KEY KAYO
#define KAYO KEY

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int verif(int *arr, size_t len, int salto) {
  if (0 == *arr || salto <= 1)
    return 0;
  int primer = arr[0];
  for (int i = 1; i < len; ++i) {
    while (1) {
      primer *= salto;
      if (primer == arr[i]) {
        break;
      } else if (primer > arr[i]) {
        return 0;
      }
    }
  }

  return 1;
}

void is_ratio(int *arr, size_t len) {
  qsort(arr, len, sizeof(int), comp);
  for (int i = 2; i < arr[len - 1]; ++i) {
    if (verif(arr, len, i)) {
      printf("RATIO: %d\n", i);
      for (int k = *arr; k <= arr[len - 1]; k *= i) {
        printf("%d ", k);
      }
      putchar(10);
      return;
    }
  }
}

int main(void) {
  int arr[] = {5, 30, 1080, 6480};
  is_ratio(arr, sizeof(arr) / sizeof(int));

  return 0;
}
