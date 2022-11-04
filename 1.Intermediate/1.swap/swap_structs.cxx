///
/// swap_structs.cxx
///

#include "swap_structs.h"

#include <stdio.h>
#include <string>

using std::string;

// swapping the content of Point variables

class Point {
public:
  Point(double x, double y) :
    x_(x),
    y_(y)
  {}

  string str() const {
    static char buffer[64];
    sprintf(buffer, "Point(%lf, %lf)", x_, y_);
    return string(buffer);
  }

private:
  double x_; // x-coordinate
  double y_; // y-coordinate
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

  Point p1 = Point(409, 427);
  Point p2 = Point(379, 313);

  fprintf(stdout, "initial values: p1: %s, p2: %s\n", p1.str().c_str(), p2.str().c_str());

  swap_points_v(p1, p2);

  fprintf(stdout, "after 'v' swap: p1: %s, p2: %s\n", p1.str().c_str(), p2.str().c_str());

  swap_points_p(&p1, &p2);

  fprintf(stdout, "after 'p' swap: p1: %s, p2: %s\n", p1.str().c_str(), p2.str().c_str());
}
