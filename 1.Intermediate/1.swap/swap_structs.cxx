///
/// swap_structs.cxx
///
/// This compilation unit uses C++ instead of pure C for three reasons:
/// 1. Elegance: the use of constructors eliminates messy initialization code
/// 2. Legibility: as a result of the above, the example is easoer to read
/// 3. Learning: this serves as a basic introduction to C++ concepts
///
/// Exercise: first read and understand the code
/// Run the program at least twice, as instructed
/// Then answer the questions at the end
///
/// Weight 10%
///

#include "swap_structs.h"

#include <stdio.h>
#include <string>

using std::string;

// Swapping the content of Point variables

class Point {
public:
  /// Class constructor: a class constructor creates instances of the class
  /// In this case, the instances are (as you should guess) Points
  /// An instance of type Point is a pair of coordinates
  Point(double x, double y) :
    x_(x),
    y_(y)
  {}

  /// class method: returns a string (instance)
  string str() const {
    static char buffer[64];
    sprintf(buffer, "Point(%lf, %lf)", x_, y_); // <<= the string mirrors
    return string(buffer);
  }

private:
  double x_; // instance variable: this one represents the x-coordinate
  double y_; // instance variable: this one represents the y-coordinate
};

// swap function taking Point values as parameters
void swap_points_v(Point a, Point b) {
  Point t = a;
  a = b;
  b = t;
}

// swap function taking pointers to int variables as parameters
void swap_points_p(Point *a, Point *b) {
  Point t = *a;
  *a = *b;
  *b = t;
}

void swap_struct_variables_example() {

  // Note the elegance of the following initializations
  // Made possible by the use of the name of the type (Point) as a constructor function
  Point p1 = Point(409, 427);
  Point p2 = Point(379, 313);

  // We have to apply the method c_str to the string value returned by the str method
  // The str method returns an instance of the C++ string class
  // But the %s format specifiers in *printf functions need a 'const char *'
  fprintf(stdout, "initial values: p1: %s, p2: %s\n", p1.str().c_str(), p2.str().c_str());

  swap_points_v(p1, p2);

  fprintf(stdout, "after 'v' swap: p1: %s, p2: %s\n", p1.str().c_str(), p2.str().c_str());

  swap_points_p(&p1, &p2);

  fprintf(stdout, "after 'p' swap: p1: %s, p2: %s\n", p1.str().c_str(), p2.str().c_str());
}

// Exercise:
//
// Run the program and compare the output to that observed for scalar variables
//
// Also, change the word 'class' in the definition of Point with the word 'struct'
// Compile and run the program both ways and observe the behavior
//
// Finally check this link: https://www.geeksforgeeks.org/structure-vs-class-in-cpp/
// 
// Answer the following questions (Spanish or English OK) right in this comment:
//
// a) Was swap_points_v able to swap the content of the variables p1 and p2?
//
// b) Was swap_points_p able to swap the content of the variables p1 and p2?
//
// c) Is the behavior of struct variables consistent with that of scalar variables?
//
// d) What's the main difference between struct class in C++? Is it observable here?
//
//
