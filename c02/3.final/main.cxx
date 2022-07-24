///
/// main.cxx
///
/// Tarea Final: programa principal
///

#include "dynarray.h"
#include "stochastic.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Este codigo se provee como esqueleto. Respeten el esqueleto, pero ...
/// ... debe ser extendido: los subprogramas de prueba son minimales
/// No prueban todas las funciones, combinaciones tipicas y atipicas ...
/// ... casos de borde, casos perversos, etc.
///
/// Apliquen su intuicion de ingenieria, para desarrollarla
/// 
/// 20% de la evaluacion de esta tarea (10 puntos) se basa en:
/// - buena cobertura: completitud y probabilidad de pillar errores
/// - calidad del codigo de prueba: modularidad, claridad, limpieza, etc.
/// - eficiencia: esencialmente evitar pruebas que no mejoran la cobertura
///
/// Son ingenieros: investiguen!
/// https://en.wikipedia.org/wiki/Code_coverage
/// https://en.wikipedia.org/wiki/Software_testing
/// https://en.wikipedia.org/wiki/Edge_case

//////////////////////////////////////////
/// Seccion: tablas + entrada y salida ///
//////////////////////////////////////////

int test_table(int argc, const char *argv[]) {
  return 0;
}

//////////////////////////////////////////////////
/// Seccion: matrices y pruebas de rendimiento ///
//////////////////////////////////////////////////

int test_matrix_performance(int argc, const char *argv[]) {
  return 0;
}

///////////////////////////////////
/// Seccion: arreglos dinamicos ///
///////////////////////////////////

///
/// show_dynarray: imprime un arreglo dinamico
///
/// const Dynarray *dyna: apuntador a un arreglo dinamico
///
void show_dynarray(const Dynarray *dyna) {
  
  // no podemos accesar directamente los campos de la estructura Dynarray ...
  // ... ya que son partes privadas de la implementacion.
  // pero podemos obtener sus valores usando las funciones de acceso
  const double *data = dyna_data(dyna);
  size_t size = dyna_size(dyna);
  size_t capacity = dyna_capacity(dyna);

  fprintf(stdout, "numero de elementos / capacidad: %u/%u\n", size, capacity);
  fprintf(stdout, "[\n");
  for (size_t i = 0; i < size; ++i) {
    fprintf(stdout, "  %6d: %12.6f\n", i, data[i]);
  }
  fprintf(stdout, "]\n\n");
}

///
/// Funciones inicializadoras
///

double zero(int) {
  return 0.0;
}

double fortytwo(int) {
  return 42.0;
}

double index(int i) {
  return double(i);
}

double u(int) {
  return uniform();
}

double z(int) {
  return normal();
}

double fancy(int i) {
  return i + uniform();
}

// return array initializer function given the user choice
// valid initializer choices are: "0", "42", "u", and "f"
Initializer get_initializer(const char *choice) {
  if (strcmp(choice, "0") == 0) {
    return zero;
  }
  if (strcmp(choice, "42") == 0) {
    return fortytwo;
  }
  if (strcmp(choice, "i") == 0) {
    return index;
  }
  if (strcmp(choice, "u") == 0) {
    return u;
  }
  if (strcmp(choice, "z") == 0) {
    return z;
  }
  if (strcmp(choice, "f") == 0) {
    return fancy;
  }
  // reportar error y seguir
  fprintf(stderr, "warning: invalid initializer selection - using 0 as default\n");
  return zero;
}

///
/// Prueba de arreglos dinamicos (debe ser extendida)
///

int test_dynamic_arrays(int argc, const char *argv[]) {
  // si argc es mayor o igual a 3, usar el parametro provisto, si no 8
  size_t NX = (3 <= argc ? atoi(argv[2]) : 8);

  Initializer init_x = get_initializer("z");

  Dynarray *x = dynarray(NX, init_x);
  show_dynarray(x);

  // si argc es mayor o igual a 4, usar el parametro provisto, si no 16
  size_t NY = (4 <= argc ? atoi(argv[3]) : 16);
  Initializer init_y = get_initializer("f");

  Dynarray *y = dynarray(NY, init_y);
  show_dynarray(y);

  Dynarray *result = dyna_concatenate(x, y);
  show_dynarray(result);
  return 0;    
}

int dispatch(int argc, const char *argv[]) {
  if (strcmp(argv[1], "dyna") == 0) {
    return test_dynamic_arrays(argc, argv);
  }
  if (strcmp(argv[1], "matrix") == 0) {
    return test_matrix_performance(argc, argv);
  }
  if (strcmp(argv[1], "table") == 0) {
    return test_table(argc, argv);
  }
}

///
/// Main: punto de entrada
///
int main(int argc, const char *argv[]) {
  // accept no less than one argument
  assert(2 <= argc);
  int status = dispatch(argc, argv);
  if (status != 0) {
    fprintf(stderr, "completed with errors: status %d\n", status);
  }
  return status;
}
