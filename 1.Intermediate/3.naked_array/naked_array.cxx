///
/// naked_array.cxx
///
/// Exercises below: complete code as indicated
///
/// Weight: 40%
///

#include "naked_array.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//
// Quick and simple uniform random generator
//

// global seed
double seed = log(13 * M_PI);

double frac(double r) {
  return r - floor(r);
}

double uniform() {
  seed = frac(997 * seed);
  return seed;
}

//
// array of integer values
//

int *int_array(int n) {
  // A peeled potato
  // Natural precondition: non-negative array size
  assert(0 <= n);
  // calloc allocates a contiguous chunk of memory for the array
  // check the documentation for calloc online
  // 
  // int *pa = (int *) calloc(n, sizeof(int)); // old school C/C++ cast style
  int *pa = static_cast<int *>(calloc(n, sizeof(int))); // only C++ cast style
  // the address of the chunk of memory is all we need to make this work
  // by now you should know why ... see previous project
  return pa;
}

int *random_int_array(int n, int lo, int hi) {
  // Another peeled potato
  // Natural precondition: non-negative array size
  assert(0 <= n);
  // Random numbers precondition 
  assert(lo <= hi);

  // int *pa = (int *) calloc(n, sizeof(int)); // old school C/C++ cast style
  int *pa = static_cast<int *>(calloc(n, sizeof(int))); // only C++ cast style
  for (int i = 0; i < n; ++i) {
    pa[i] = int((hi - lo + 1) * uniform()) + lo;
  }
  return pa;
}

void show_int_array(int n, int a[]) {
  // Another peeled potato
  bool hz = n < 12; // <= fine tune this if you want
  fprintf(stdout, "[%s", hz ? " " : "\n");
  for (int i = 0; i < n; ++i) {
    fprintf(stdout, "%s%6d", hz ? (i == 0 ? "" : ", ") : "\n\t", a[i]);
  }
  fprintf(stdout, "%s]\n", hz ? " " : "\n");
}

int sum_int_array(int n, int a[]) {
  // Exercise: complete
  return 0; // just to make the code compile
}

int min_int_array(int lb, int ub, int a[]) {
  assert(lb < ub);
  // Exercise: complete
  return lb; // just to make the code compile
}

void sort_int_array(int n, int a[]) {
  // Exercise: complete according to the following algorithm
  // find the index of the min value in the [0 - n) range
  // swap the content at index 0 with the content of the index you found above
  // now a[0] has the smallest value in the array, we need to sort the rest
  // ... so, repeat by finding the min value in the [1 - n) range ...
  // ... and so on. You should to this with a for loop, of course!
}

//
// array of double values
//

double *double_array(int n) {
  assert(0 <= n);
  // Exercise: complete
  return nullptr; // just to make the code compile
}

double *random_uniform_array(int n) {
  // Another peeled potato
  double *pa = double_array(n);
  for (int i = 0; i < n; ++i) {
    pa[i] = uniform();
  }
  return pa;
}

double *random_normal_array(int n) {
  // Exercise: complete
  // Tip: you know how to generate normally distributed random numbers
  // It was part of the previous test: remember the Box-Muller transform?
  // Search "Box-Muller transform" on Wikipedia and read "Basic form"
  // You can use either Z[0] or Z[1] to generate the random numbers
  // You know how to generate U[1] and U[2], they are random uniform numbers
  // Breathe deeply: use your head and common sense, this is easy
  return nullptr; // just to make the code compile
}

void show_double_array(int n, double a[]) {
  // Another peeled potato
  bool hz = n < 10; // <= fine tune this if you want
  fprintf(stdout, "[%s", hz ? " " : "\n");
  for (int i = 0; i < n; ++i) {
    fprintf(stdout, "%s%7.4lf", hz ? (i == 0 ? "" : ", ") : "\n\t", a[i]);
  }
  fprintf(stdout, "%s]\n", hz ? " " : "\n");
}

double sum_double_array(int n, double a[]) {
  double sum = 0.0;
  // Exercise: complete
  return sum;
}

double avg_double_array(int n, double a[]) {
  // Exercise: complete
  return 0; // just to make the code compile
}

double var_double_array(int n, double a[]) {
  // Exercise: complete
  return 0; // just to make the code compile
}

int min_double_array(int lb, int ub, double a[]) {
  assert(lb < ub);
  // Exercise: complete
  return lb; // just to make the code compile
}

void sort_double_array(int n, double a[]) {
  // Exercise: complete according to the following algorithm
  // find the index of the min value in the [0 - n) range
  // swap the content at index 0 with the content of the index you found above
  // now a[0] has the smallest value in the array, we need to sort the rest
  // ... so, repeat by finding the min value in the [1 - n) range ...
  // ... and so on. You should to this with a for loop, of course!
}
