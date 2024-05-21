#include "defs.h"

type s_a_b(type *arr, pos_t from, pos_t to) {
  int sum = 0;

  for (int i = from; i <= to; ++i) {
    sum += arr[i];
  }
  return sum;
}
