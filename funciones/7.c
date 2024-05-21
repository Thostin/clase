#include <stdio.h>
// a ^ b
int pod(int a, int b) {
  int pot = a;
  while (--b)
    pot *= a;
  return pot;
}

void verif_fermat(void) {
  char *arr[] = {"True", "False"};
  char *arg;
  int sum, pot;
  int a, b, c, gap;
  int diff_min = 9857689;
  for (int i = 5; i <= 20; ++i) {
    for (int j = 5; j <= 20; ++j) {
      for (int k = 5; k <= 20; ++k) {
        for (int gop = 3; gop <= 5; ++gop) {
          sum = pod(i, gop) + pod(j, gop);

          arg = (sum == pod(k, gop)) ? arr[0] : arr[1];
          pot = pod(k, gop);
#define absl(x) ((x) < 0 ? -(x) : (x))
          if (sum == pot) {
            printf("EXISTEN!!!, EXISTEN!!!\n\n");
            return;
          } else if (absl(pot - sum) <= diff_min) {
            a = i;
            b = j;
            c = k;
            gap = gop;
            diff_min = absl(pot - sum);
          }
          /*
          printf("%d^%d + %d^%d = %d^%d = %d: %s\n", i, gop, j, gop, k, gop,
                 sum, arg);
          */
        }
      }
    }
  }
  printf("No existen :(\n\n");
  printf("Mínima diferencia: %d\n"
         "%d^%d + %d^%d casi igual a %d^%d",
         diff_min, a, gap, b, gap, c, gap);
}

int main(void) {
  verif_fermat();

  return 0;
}
