///
/// test.cxx
///

#include <vector>

#include <math.h>
#include <stdio.h>

//
// section: std::vector<double>
//

typedef std::vector<double> Dynad;

double seed = 0.18937173377;

double frac(double r) {
  return r - floor(r);
}

double uniform() {
  seed = frac(997 * seed);
  return seed;
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

Dynad dynad(int n, double (*f)()) {
  Dynad d = Dynad(n);
  for (int i = 0; i < n; ++i) {
    d[i] = (*f)();
  }
  return d;
}

void dynad_test() {
  Dynad d0 = Dynad(4);
  Dynad d1 = dynad(8, uniform);
  Dynad d2 = dynad(4, []() -> double {return 42;});
  show(d0);
  show(d1);
  show(d2);
}

//
// section: Matrix
//

typedef std::vector<Dynad> Matrix;

void show_matrix(const Matrix& matrix) {
  const int n = matrix.size();
  fprintf(stdout, "[\n");
  for (int i = 0; i < n; ++i) {
    fprintf(stdout, "\t");
    show(matrix[i]);
  }
  fprintf(stdout, "]\n");
}

Matrix matrix(int M, int N) {
  Matrix m = Matrix(M);
  for (int i = 0; i < M; ++i) {
    m[i] = Dynad(N);
  }
  return m;
}

Matrix matrix(int M, int N, double (*f)()) {
  Matrix m = Matrix(M);
  for (int i = 0; i < M; ++i) {
    m[i] = dynad(N, f);
  }
  return m;
}

Matrix matrix(int M, Dynad (*f)()) {
  Matrix m = Matrix(M);
  for (int i = 0; i < M; ++i) {
    m[i] = (*f)();
  }
  return m;
}

void matrix_test_1() {
  Matrix m0 = matrix(4, []() { return Dynad(6); });
  Matrix m1 = matrix(6, []() { return dynad(8, uniform); });
  Matrix m2 = matrix(2, []() { return dynad(2, []() -> double { return 42; }); });
  show_matrix(m0);
  show_matrix(m1);
  show_matrix(m2);
}

void matrix_test_2() {
  Matrix m0 = matrix(4, 6);
  Matrix m1 = matrix(6, 8, uniform);
  Matrix m2 = matrix(2, 2, []() -> double { return 42; });
  show_matrix(m0);
  show_matrix(m1);
  show_matrix(m2);
}

int main(int argc, const char *argv[]) {
  fprintf(stdout, "\nsizeof(Dynad) = %zu\n", sizeof(Dynad));
  dynad_test();
  
  fprintf(stdout, "\nsizeof(Matrix) = %zu\n", sizeof(Matrix));
  matrix_test_1();
  matrix_test_2();
  return 0;
}
