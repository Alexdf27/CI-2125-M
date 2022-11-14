///
/// swap.cxx
///
/// This project demonstrates the function call semantic in the C language: pass-by-value
///
/// Pass-by-value-semantic:
/// - arguments are evaluated before calling the function
/// - the resulting values initialize the corresponding function parameters
///
/// This project only covers scalars and structs. Arrays will be covered later.
///
/// Swapping the value of two variables is a great way to demonstrate pass-by-value
/// Because, by the definition, it is impossible to abstract the exchange in a function!
/// Exercise: reflect on the implications of pass-by-value and justify the sentence above
///
/// The way around the problem is to pass (by value, as always) pointers to the variables
/// The pointers allow the swap functions to change the variables, using indirection
/// Passing pointers to variables is an explicit way to implement pass-by-reference
///

#include "swap_scalars.h"
#include "swap_structs.h"

int main() {
  swap_scalar_variables_example();
  swap_struct_variables_example();
  return 0;
}
