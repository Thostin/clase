#include <stdio.h>

int ipow(int a, int b) {
  int ret = a;
  for (int i = 1; i < b; ++i)
    ret *= a;
  return ret;
}

int main(void) {
  // Números primos, el 1 no es primo pero es útil que esté
  int arr[] = {1, 2, 3, 5, 7, 11};

  printf("//GENERALA:\n\n");
  printf("case %d: \n", ipow(arr[0], 5));
  printf("case %d: \n", ipow(arr[1], 5));
  printf("case %d: \n", ipow(arr[2], 5));
  printf("case %d: \n", ipow(arr[3], 5));
  printf("case %d: \n", ipow(arr[4], 5));
  printf("case %d: \n", ipow(arr[5], 5));

  printf("\n//POKER:\n\n");
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (i != j)
        printf("case %d: \n", arr[i] * ipow(arr[j], 4));
    }
  }
  /*
  printf("case %d: \n", arr[1] * ipow(arr[0], 4));
  printf("case %d: \n", arr[2] * ipow(arr[0], 4));
  printf("case %d: \n", arr[3] * ipow(arr[0], 4));
  printf("case %d: \n", arr[4] * ipow(arr[0], 4));
  printf("case %d: \n", arr[5] * ipow(arr[0], 4));
  */
  printf("\n//FAUL:\n\n");

  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (i != j)
        printf("case %d:\n", arr[i] * arr[i] * ipow(arr[j], 3));
    }
  }
  /*
  printf("case %d:\n", ipow(arr[0], 3) * ipow(arr[1], 2));
  printf("case %d:\n", ipow(arr[0], 3) * ipow(arr[2], 2));
  printf("case %d:\n", ipow(arr[0], 3) * ipow(arr[3], 2));
  printf("case %d:\n", ipow(arr[0], 3) * ipow(arr[4], 2));
  printf("case %d:\n", ipow(arr[0], 3) * ipow(arr[5], 2));
  */

  printf("\n//ESCALERA:\n\n");
  printf("case %d:\n", arr[0] * arr[1] * arr[2] * arr[3] * arr[4]);
  printf("case %d:\n\n", arr[1] * arr[2] * arr[3] * arr[4] * arr[5]);

  return 0;
}
