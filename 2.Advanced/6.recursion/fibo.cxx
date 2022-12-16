///
/// fibo.cxx
///

#include "fibo.h"

int fibonacci_i(int n) {
  if (n < 2) {
    return n;
  }

  int pen = 0; // fibo(0)
  int ult = 1; // fibo(1)

  int sig = pen + ult;
  for (int i = 2; i < n; ++i) {
    pen = ult;
    ult = sig;
    sig = pen + ult;
  }

  return sig;
}

int fibonacci_r(int n) {
  return n < 2 ? n : fibonacci_r(n - 1) + fibonacci_r(n - 2); 
}
