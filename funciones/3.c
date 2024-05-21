#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 0.00001L
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

void imp(int *arr, const size_t len) {
  qsort(arr, len, sizeof(int), comp);

  const long cte = 8783465892;
  long min = cte;
  int pos;
  for (int i = 0; i < len - 1; ++i) {
    if (arr[i + 1] - arr[i] < min) {
      min = arr[i + 1] - arr[i];
      pos = i;
    }
  }

  if (min == cte) {
    return;
  }

  int raza = arr[pos + 1] / arr[pos];

  if (arr[pos + 1] > raza * arr[pos]) {
    printf("Falló la condición\n");
    return;
  }

  min = raza;

  int pod;
  double podl;
  int primer;

  for (double i = 1; i < 10000; i += 1.0L) {

    podl = pow((double)min, 1 / i);
    pod = podl;
    printf("podl - pod = %lf - %d = %lf\n", podl, pod, podl - pod);
    if (podl - pod > EPSILON)
      continue;

    if (verif(arr, len, pod)) {
      primer = arr[0];

      printf("RATIO: %d\n"
             "%d",
             pod, primer);
      while ((primer *= pod) <= arr[len - 1]) {
        printf(", %d", primer);
      }
      putchar(10);
      break;
    }
  }
}

int main(void) {
  int arr[] = {5, 1080, 30};
  // printf("verif: %d\n", verif(arr, 4, 2));
  imp(arr, sizeof(arr) / sizeof(int));

  return 0;
}
