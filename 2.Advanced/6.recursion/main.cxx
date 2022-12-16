///
/// main.cxx
///

#include "fact.h"
#include "fibo.h"
#include "timer.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

int test_factorial() {
  int n;
  fprintf(stdout, "N: ");
  fflush(stdout);
  fscanf(stdin, "%d", &n);

  Timer timer;
  int64_t fact_i = factorial_i(n);
  double elapsed_factorial_i = timer.restart();
  int64_t fact_r = factorial_r(n);
  double elapsed_factorial_r = timer.elapsed();

  fprintf(stdout, "fact_i == %lld\n", fact_i);
  fprintf(stdout, "fact_r == %lld\n", fact_r);

  fprintf(stdout, "fact_i: %lf s\n", elapsed_factorial_i);
  fprintf(stdout, "fact_r: %lf s\n", elapsed_factorial_r);

  if (fact_i != fact_r) {
      fprintf(stderr, "HORROR: factorial mismatch!\n");
      return 4;
  }

  return 0;
}

int test_fibonacci() {
  int n;
  fprintf(stdout, "N: ");
  fflush(stdout);
  fscanf(stdin, "%d", &n);

  Timer timer;
  int fibo_i = fibonacci_i(n);
  double elapsed_fibonacci_i = timer.restart();
  int fibo_r = fibonacci_r(n);
  double elapsed_fibonacci_r = timer.elapsed();

  fprintf(stdout, "fibo_i == %d\n", fibo_i);
  fprintf(stdout, "fibo_r == %d\n", fibo_r);

  fprintf(stdout, "fibo_i: %lf s\n", elapsed_fibonacci_i);
  fprintf(stdout, "fibo_r: %lf s\n", elapsed_fibonacci_r);

  if (fibo_i != fibo_r) {
      fprintf(stderr, "HORROR: fibonacci mismatch!\n");
      return 4;
  }

  return 0;
}

void usage(const char *program) {
  fprintf(stderr, "Usage %s (fact | fibo)\n", program);
}

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    usage(argv[0]);
    return 2;
  }

  int status = 4;
  if (strcmp(argv[1], "fact") == 0) {
    status = test_factorial();
  } else if (strcmp(argv[1], "fibo") == 0) {
    status = test_fibonacci();
  } else {
    usage(argv[0]);
  }

  return 0;
}
