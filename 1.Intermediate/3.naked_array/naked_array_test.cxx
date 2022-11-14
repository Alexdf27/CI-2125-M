///
/// naked_array_test.cxx
///
/// Ejercicio: extender este programa de prueba
///
/// Besides well written code, a good test suite exhibits these characteristics:
/// (100% Coverage): test all the functions, in common and special situations
/// (Organization): the tests are well organized, in a systemic and modular way
/// (Readable): the output should make easy to identify tests and verify them
///
/// Weight: 20% 
///

#include "naked_array.h"

int main(int argc, const char *argv[]) {

  // This code is NOT a good recipe for extending the test suite
  // Look for better ways to organize the code as it grows

  int tiny[] = { 42 };
  show_int_array(1, tiny);

  double pair[] = { 42.67, 67.42 };
  show_double_array(2, pair);

  const int S = 8;
  int *small = random_int_array(S, -1, 1);
  show_int_array(S, small);

  const int C = 16;
  int *compact = random_int_array(C, -10000, 10000);
  show_int_array(C, compact);

  return 0;
}
