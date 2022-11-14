///
/// swap_array_elements.cxx
///
/// Exercise: carefully observe the behavior of this program
/// understand the code in light of the lectures or your own research
/// note the different swapping routines AND the arguments used to call them
/// note the output of the program and draw your own conclusion
///
/// Tip: uncommenting the fprintf statements inside swap routines can help
///
/// Finally, extend this comment pretending to explain to future students:
/// - how is passing arrays as arguments different from passing structs?
/// - why is the sugared a[i] syntax preferable to *(a + i)?
/// - is there a situation where desugaring pointer arithmetic is useful?
/// - explain why pointer arithmetic requires all array elements being of the same type
///
/// Bonus question:
/// - state one or more reasons for defining a different behavior for structs and arrays
///
/// By extending *this* comment, I mean right here, in English or Spanish. 10 lines max. 
///
/// Weight: 15%
///

#include "swap_array_elements.h"

#include <stdio.h>
#include <string>

using std::string;

// swapping the content of struct variables

// case 1: swap array elements taking the array (is it?) as a parameter
void swap_elements_fv(int a[]) {
  // fprintf(stdout, "swap_elements_fv: a = %p | ", a);
  int t = a[0];
  a[0] = a[1];
  a[1] = t;
}

// case 2: swap array elements taking an explicit pointer to the array as parameter
void swap_elements_pa(int (*a)[2]) {
  // fprintf(stdout, "swap_elements_pa: a = %p | ", a);
  int t = (*a)[0];
  (*a)[0] = (*a)[1];
  (*a)[1] = t;
}

// case 3: swap elements taking the address of the first element as a parameter 
// effectively this is a partially desugared version of case 1 above
void swap_elements_a0(int *a) {
  // fprintf(stdout, "swap_elements_a0: a = %p | ", a);
  int t = a[0];
  a[0] = a[1];
  a[1] = t;
}

// case 4: case 3 fully desugared to show pointer arithmetic
//
// Pointer arithmetic explained:
// Let p be a pointer to variables of type T; i.e.: T *p;
// Then, the expression (p + i) where i is an integer, is a pointer to T
// And the address computed by the expression is p + i * sizeof(T)
void swap_elements_aa(int *a) {
  // fprintf(stdout, "swap_elements_aa: a = %p | ", a);
  int t = *(a + 0);
  *(a + 0) = *(a + 1);
  *(a + 1) = t;
}

// case 5: case 2 fully desugared to show pointer arithmetic
void swap_elements_pd(int (*a)[2]) {
  // fprintf(stdout, "swap_elements_pa: a = %p | ", a);
  int t = *(*a + 0);
  *(*a + 0) = *(*a + 1);
  *(*a + 1) = t;
}

void separator() {
  fprintf(stdout, "----------------------------------------------------------------------\n");
}

void swap_array_elements_example() {

  fprintf(stdout, "\nArray (pair of coordinates) example:\n");

  int array[] = { 409, 427 };

  // uncomment to observe the address of the array
  // fprintf(stdout, "address of the array: %p | ", &array);

  fprintf(stdout, "initial element values:  [ %d, %d ]\n", array[0], array[1]);

  separator();

  // call to fv, passing array as parameter ... whatever that means ;-)
  swap_elements_fv(array);
  fprintf(stdout, "after 'fv' element swap: [ %d, %d ]\n", array[0], array[1]);

  // call to fv, but passing the address of element 0 as parameter ... huh? :O
  swap_elements_fv(&array[0]);
  fprintf(stdout, "after 'fv' element swap: [ %d, %d ]\n", array[0], array[1]);

  separator();

  // call to pa, passing the address of array as parameter
  swap_elements_pa(&array);
  fprintf(stdout, "after 'pa' element swap: [ %d, %d ]\n", array[0], array[1]);

  // same call to pa, just to revert to initial state :-)
  swap_elements_pa(&array);
  fprintf(stdout, "after 'pa' element swap: [ %d, %d ]\n", array[0], array[1]);

  separator();

  // call to a0, passing the address of element 0 as parameter
  swap_elements_a0(&array[0]);
  fprintf(stdout, "after 'a0' element swap: [ %d, %d ]\n", array[0], array[1]);

  // call to a0, passing array as parameter ... whatever that means ;-)
  swap_elements_a0(array);
  fprintf(stdout, "after 'a0' element swap: [ %d, %d ]\n", array[0], array[1]);

  separator();

  // call to aa, passing the address of element 0 as parameter
  swap_elements_aa(&array[0]);
  fprintf(stdout, "after 'aa' element swap: [ %d, %d ]\n", array[0], array[1]);

  // call to aa, passing array as parameter ... whatever that means ;-)
  swap_elements_aa(array);
  fprintf(stdout, "after 'aa' element swap: [ %d, %d ]\n", array[0], array[1]);

  separator();

  // call to pd, passing the address of array as parameter
  swap_elements_pd(&array);
  fprintf(stdout, "after 'pd' element swap: [ %d, %d ]\n", array[0], array[1]);

  // same call to pd, just to revert to initial state :-)
  swap_elements_pd(&array);
  fprintf(stdout, "after 'pd' element swap: [ %d, %d ]\n", array[0], array[1]);
}
