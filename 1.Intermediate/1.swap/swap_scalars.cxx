///
/// swap_scalars.cxx
///

#include "swap_scalars.h"

#include <stdio.h>

// swapping the content of int variables

// swap function taking int values as parameters
void swap_ints_v(int x, int y) {
  int t = x;
  x = y;
  y = t;
}

// swap function taking pointers to int variables as parameters
void swap_ints_p(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

// swapping the content of double precision floating point variables
// Exercise: complete the example following the int case mutatis mutandis

// swap function taking double values as parameters
void swap_doubles_v(/* ... */) {
  // complete ...
}

// swap function taking pointers to double variables as parameters
void swap_doubles_p(/* ... */) {
  // complete ...
}

void swap_scalar_variables_example() {

  // Swapping the content of int variables

  int m = 101;
  int n = 137;

  fprintf(stdout, "initial values: m: %d, n: %d\n", m, n);

  swap_ints_v(m, n);

  fprintf(stdout, "after 'v' swap: m: %d, n: %d\n", m, n);

  swap_ints_p(&m, &n);

  fprintf(stdout, "after 'p' swap: m: %d, n: %d\n", m, n);

  // swapping content of double precision floating point variables
  // ...
  // Exercise: complete the example following the int case mutatis mutandis
  // ...

}
