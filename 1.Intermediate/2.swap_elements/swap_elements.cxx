///
/// swap.cxx
///
/// This project contrasts the function call semantic used for structs and arrays
/// struct and arrays have one thing in common: they are container types
///
/// A container contains multiple independent variables
/// e.g. each instance of the type Pair, in previous examples, contains two coordinates
/// moreover, each coordinate is an independent variable in its own right
/// e.g. assume that pair is an instance of Pair, with coordinates (0,0)
/// it is possible to change the entire pair (both coordinates) doing this:
/// pair = Pair(42, 67);
/// however, it is also possible to change one coordinate independently from the other
/// pair.y = 21.9;
/// Finally, the component variables of a struct can be of different type:
/// struct { int key, const char *value; } record = { 42, "forty two" };
///
/// In the case of arrays, all the elements must have the same type
/// char grades[] = { 'A', 'C', 'C', 'B', 'C', 'A' };
/// As is the case for structs, each element is an independent variable in itself
/// grades[1] = 'B'; // <== changes the 'C' grade to 'B'
/// Elements in an array are selected using 0-based indexes
/// 
/// To compare function call semantics, we will swap elements in different containers
/// ... but that is very imprecise language, to be pedantically precise:
/// we will swap the *content* of two elements in different kinds of containers
/// we will do so for struct containers and array containers
///

#include "swap_struct_elements.h"
#include "swap_array_elements.h"

int main() {
  swap_struct_elements_example();
  swap_array_elements_example();
  return 0;
}
