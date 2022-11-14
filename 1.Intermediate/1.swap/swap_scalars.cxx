///
/// swap_scalars.cxx
///
/// Exercise: read, understand, and complete this file as instructed
///
/// Weight: 5%
///

#include "swap_scalars.h"

#include <stdio.h>

//
// swapping the content of int variables
//

// swap function taking int values as parameters
void swap_ints_v(int x, int y) {
  int t = x;
  x = y;
  y = t;
}

// swap function taking pointers to int variables as parameters
void swap_ints_p(int *x, int *y) {
  // note the use of the (unary prefix) * operator to perform indirection
  int t = *x;
  *x = *y;
  *y = t;
}

//
// swapping the content of double precision floating point variables
//

// Exercise: complete the following functions following the int case mutatis mutandis

// swap function taking double values as parameters
//void swap_doubles_v(double x, double y) {
  // complete ...
//}

// swap function taking pointers to double variables as parameters
//void swap_doubles_p(/* ... */) {
  // complete ...
//}

void swap_scalar_variables_example() {

  // Swapping the content of int variables

  int m = 101;
  int n = 137;

  fprintf(stdout, "initial values: m: %d, n: %d\n", m, n);

  swap_ints_v(m, n);

  fprintf(stdout, "after 'v' swap: m: %d, n: %d\n", m, n);

  swap_ints_p(&m, &n);

  fprintf(stdout, "after 'p' swap: m: %d, n: %d\n", m, n);

  // Swapping the content of double variables

  // ...
  // Exercise: complete this example similarly to the int case, mutatis mutandis
  // ...
}
