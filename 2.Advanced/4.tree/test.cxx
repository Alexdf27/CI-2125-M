///
/// test.cxx
///
/// Tree ADT test
///

#include "tree.h"

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

const bool predictable = false;

double noise() {
  return predictable ? 0 : double(time(0) % 1000) / 1000.0;
}

double seed = 0.18937173377 + noise();

double frac(double r) {
  return r - floor(r);
}

double uniform() {
  seed = frac(997.0 * seed);
  return seed;
}

int irandom(int n) {
  return int(n * uniform());
}

// sample size (default)
const int S_DEFAULT = 4096;

// range for random numbers (default)
const int R_DEFAULT = 8192;

// test size (default)
const int T_DEFAULT = 1024;

int main(int argc, const char *argv[]) {

  assert(argc <= 4);

  const int S = 1 < argc ? atoi(argv[1]) : S_DEFAULT;
  const int R = 2 < argc ? atoi(argv[2]) : R_DEFAULT;
  const int T = 3 < argc ? atoi(argv[3]) : T_DEFAULT;

  auto tree = Tree<int>();
  for (int i = 0; i < S; ++i) {
    int r = irandom(R);
    if (S < 16) fprintf(stdout, "adding %d\n", r);
    tree.add(r);
  }

  fprintf(stdout, "min tree depth: %d\n", tree.min_depth());
  fprintf(stdout, "max tree depth: %d\n", tree.max_depth());

  int hits = 0;
  for (int i = 0; i < T; ++i) {
    int r = irandom(R);
    if (T < 16) fprintf(stdout, "checking %d\n", r);
    bool in = tree.in(r);
    if (T < 16) fprintf(stdout, "%d is %s\n", r, in ? "in": "not in");
    if (in) ++hits;
  }

  fprintf(stdout, "%d hits out of %d tests\n", hits, T);
  return 0;
}
