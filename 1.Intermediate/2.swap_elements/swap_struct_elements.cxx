///
/// swap_struct_elements.cxx
///
/// Exercise: answer questions at the end
///
/// Weight: 10%
///

#include "swap_struct_elements.h"

#include <stdio.h>
#include <string>

using std::string;

// swapping the content of struct variables

struct Point {

  Point(double x, double y) :
    x_(x),
    y_(y)
  {}

  string str() const {
    static char buffer[64];
    sprintf(buffer, "Point(%lf, %lf)", x_, y_);
    return string(buffer);
  }

  double x_; // x-coordinate
  double y_; // y-coordinate
};

// swap Point coordinates taking a Point as a parameter
void swap_coordinates_v(Point a) {
  double t = a.x_;
  a.x_ = a.y_;
  a.y_ = t;
}

// swap Point coordinates taking a pointer to a Point as a parameter
// desagured syntax - sintaxis no azucarada (estilo cerrero)
void swap_coordinates_d(Point *pa) {
  double t = (*pa).x_;
  (*pa).x_ = (*pa).y_;
  (*pa).y_ = t;
}

// swap Point coordinates taking a pointer to a Point as a parameter
// sugared syntax - sintaxis azucarada: esta es la que deben usar
void swap_coordinates_p(Point *pa) {
  double t = pa->x_;
  pa->x_ = pa->y_;
  pa->y_ = t;
}

void swap_struct_elements_example() {

  fprintf(stdout, "\nPoint (pair of coordinates) example:\n");

  Point point = Point(409, 427);

  fprintf(stdout, "initial coordinates: point: %s\n", point.str().c_str());

  swap_coordinates_v(point);

  fprintf(stdout, "after 'v' coordinates swap: %s\n", point.str().c_str());

  swap_coordinates_d(&point);

  fprintf(stdout, "after 'd' coordinates swap: %s\n", point.str().c_str());

  swap_coordinates_p(&point);

  fprintf(stdout, "after 'p' coordinates swap: %s\n", point.str().c_str());
}

//
// Answer the following questions here (Spanish or English OK, as always):
//
// a) Was swap_coordinates_v able to swap the coordinates of variable point?
//
// b) Was swap_coordinates_d able to swap the coordinates of variable point?
//
// c) Was swap_coordinates_p able to swap the coordinates of variable point?
//
// d) In swap_coordinates_d, why do we write (*pa).x_ instead if *pa._x?
//
