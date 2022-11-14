///
/// main.cxx
///

#include "dynamic_array.h"

#include <math.h>
#include <stdio.h>

//
// section: Dynarray<double>
//

typedef Dynarray<double> Dynad;

double seed = 0.18937173377;

double frac(double r) {
  return r - floor(r);
}

double uniform() {
  seed = frac(997 * seed);
  return seed;
}

double weird(int i) {
  return i + uniform();
}

void show_as_row(const Dynad& dynad) {
  const int n = dynad.size();
  fprintf(stdout, "[ ");
  for (int i = 0; i < n; ++i) {
    const char *sep = (i == 0 ? "" : ", ");
    fprintf(stdout, "%s%10.6lf", sep, dynad[i]);
  }
  fprintf(stdout, " ]\n");
}

void show_as_col(const Dynad& dynad) {
  const int n = dynad.size();
  fprintf(stdout, "[\n");
  for (int i = 0; i < n; ++i) {
    fprintf(stdout, "\t%10.6lf\n", dynad[i]);
  }
  fprintf(stdout, "]\n");
}

void show(const Dynad& dynad) {
  if (dynad.size() < 10) {
    show_as_row(dynad);
  } else {
    show_as_col(dynad);
  }
}

dynad_test() {
  Dynad d0 = Dynad(8);
  Dynad d1 = Dynad(8, uniform);
  Dynad d2 = Dynad(8, weird);
  show(d0);
  show(d1);
  show(d2);
}

//
// section: Matrix
//

typedef Dynarray<Dynad> Matrix;

Dynad dynad8() {
  return Dynad(8, uniform);
}

void show_matrix(const Matrix& matrix) {
  const int n = matrix.size();
  fprintf(stdout, "[\n");
  for (int i = 0; i < n; ++i) {
    fprintf(stdout, "\t");
    show(matrix[i]);
  }
  fprintf(stdout, "]\n");
}

matrix_test() {
  Matrix m0 = Matrix(8);
  Matrix m1 = Matrix(8, dynad8);
  show_matrix(m0);
  show_matrix(m1);
}

int main(int argc, const char *argv[]) {
  dynad_test();
  matrix_test();
  return 0;
}
