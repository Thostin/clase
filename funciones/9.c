#include <stdio.h>

void serie_a(void);
void serie_b(void);
void serie_c(void);
void serie_d(int n);
void serie_e(void);

int main(void) {
  serie_a();
  serie_b();
  serie_c();
  serie_d(5);
  serie_e();
  return 0;
}

void serie_a(void) {
  int s = 1;
  for (int i = 2; i < 10; ++i) {
    printf("%d\n", s);
    s = 10 * s + i;
  }
  putchar(10);
}

void serie_b(void) {
  int s = 1;
  for (int i = 1; i < 9; ++i) {
    printf("%d\n", s * i);
    s = 10 * s + 1;
  }
  putchar(10);
}

#define XD 8

void sum1(int *m) {
  for (int i = 0; i < 4; ++i) {
    ++*m;
    ++m;
  }
}

void serie_c(void) {
  int s[] = {1, 2, 3, 4};
  for (int i = 0; i < 13; ++i) {
    for (int j = 0; j < 4; ++j) {
      printf("%d", s[j]);
    }
    putchar(10);
    sum1(s);
  }
  putchar(10);
}

void serie_d(int n) {
  int s = 1;
  for (int i = 0; i < n; ++i) {
    printf("%d\n", s * s);
    s = 10 * s + 1;
  }
  putchar(10);
}

void serie_e(void) {
  int s = 1234;
  for (int i = 1; i <= 4; ++i) {
    printf("%d\n", s);
    s = 10 * (s % 1000) + i;
  }
  putchar(10);
}
