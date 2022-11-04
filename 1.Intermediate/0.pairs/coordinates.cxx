///
/// coordinates.cxx
///

#include <math.h>
#include <stdio.h>

//
// The ancient way (FORTRAN): no product-type abstraction
// Estilo antiguo (FORTRAN): sin soporte a abstracciones para tipos compuestos
//

double distance_ancient(double ax, double ay, double bx, double by) {
  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

void main_ancient() {
  // Point p1
  double p1_x = 4.0;
  double p1_y = 2.0;

  // Point p2
  double p2_x = 7.0;
  double p2_y = 6.0;

  double result = distance_ancient(p1_x, p1_y, p2_x, p2_y);

  fprintf(stdout, "ancient: %lf\n", result);
}

//
// A more evolved way: the early years of C and Disco
// Estilo más evolucionado: los primeros años de C y musica Disco
//

// Alternative A: straight to typedef
// naive syntax (simple but deceptive): typedef <type> <name>
// actual syntax (the true story): <type> <expression using the defined name>
//
// /*
typedef struct {
  double x; // x-coordinate
  double y; // y-coordinate
} C_Point;
// */

// Alternative B: required when the type is recursive
/*
struct point {
  double x; // x-coordinate
  double y; // y-coordinate
  // here you could do something like struct point *next;
};

typedef struct point C_Point;

*/

double distance_evolved(C_Point a, C_Point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void main_evolved() {
  C_Point p1;
  p1.x = 4.0;
  p1.y = 2.0;

  C_Point p2 = { 7.0, 6.0 };

  double result = distance_evolved(p1, p2);
  fprintf(stdout, "evolved: %lf\n", result);

  // result = distance_evolved({ 4.0, 2.0 }, { 7.0, 6.0 }); // legal en C++ mas no en C
  // fprintf(stdout, "evolved: %lf\n", result);
}

/*

//
// A more elegant way: the advent of constructors in C++
// Estilo más elegante: la llegada de constructores en C++
//

struct Point {
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
  double x; // x-coordinate
  double y; // y-coordinate
};

double distance_elegant(Point a, Point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void main_elegant() {
  Point p1 = Point(4, 2);
  Point p2 = Point(7, 6);

  double result = distance_elegant(p1, p2);
  fprintf(stdout, "elegant: %lf\n", result);

  result = distance_elegant(Point(4, 2), Point(7, 6));
  fprintf(stdout, "elegant: %lf\n", result);
}

*/

int main() {
  main_ancient();
  main_evolved();
  // main_elegant();
  return 0;
}
