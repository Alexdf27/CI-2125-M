///
/// fact.cxx
///

#include "fact.h"

#include <cassert>
#include <cstdio>
#include <cstdlib>

int64_t factorial_i(int n) {
  int64_t fact = 1;
  for (int i = 1; i <= n; ++i) {
    fact *= i;
  }
  return fact;
}

int64_t factorial_rx(int n) {
  if (n == 0) return 1;
  return n * factorial_rx(n - 1); 
}

int64_t factorial_r(int n) {
  if (n < 0) {
    fprintf(stderr, "error: llamada a factorial_r con r = %d (negativo)\n", n);
    exit(2);
  }

  assert(n >= 0);

  return factorial_rx(n);
}
