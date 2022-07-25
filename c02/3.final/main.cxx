///
/// main.cxx
///
/// Tarea Final: programa principal
///

#include "dynarray.h"
#include "matrix.h"
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

///////////////////////////////////////////////
/// Seccion: funciones de apoyo compartidas ///
///////////////////////////////////////////////

///
/// Funciones para inicializar elementos
/// Son usadas para probar matrices y arreglos dinamicos
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

//////////////////////////////////////////
/// Seccion: tablas + entrada y salida ///
//////////////////////////////////////////

int test_table(int argc, const char *argv[]) {
  return 0;
}

//////////////////////////////////////////////////
/// Seccion: matrices y pruebas de rendimiento ///
//////////////////////////////////////////////////

///
/// show_dynarray: imprime un arreglo dinamico
///
/// const Dynarray *dyna: apuntador a un arreglo dinamico
///
void show_matrix(const char *name, const Matrix *matrix) {
  // no podemos acceder directamente a los campos de la estructura Matrix ...
  // ... y tampoco cambiarlos, ya que son partes privadas de la implementacion.
  // pero podemos obtener sus valores usando las funciones de acceso
  size_t NR = matrix_nr(matrix);
  size_t NC = matrix_nc(matrix);
  const double **data = matrix_data(matrix);

  fprintf(stdout, "%s: forma: (%zux%zu)\n", name, NR, NC);
  fprintf(stdout, "[\n");
  for (size_t i = 0; i < NR; ++i) {
    fprintf(stdout, "\t[");
    for (size_t j = 0; j < NC; ++j) {
      fprintf(stdout, " %12.6f", data[i][j]);
    }
    fprintf(stdout, " ]\n");
  }
  fprintf(stdout, "]\n\n");
}

int test_matrix_small(/* ...*/) {
  Matrix *lhs = matrix(6, 8, fortytwo);
  show_matrix("lhs", lhs);

  Matrix *rhs = matrix(6, 8, u);
  show_matrix("rhs", rhs);

  Matrix *sum1 = matrix_sum(lhs, rhs);
  assert(sum1 != nullptr); // siempre es una buena idea chequear que no hubo error
  show_matrix("sum1", sum1);

  matrix_destroy(&sum1); // "probar" (parcialmente) la liberacion de memoria
  assert(sum1 == nullptr); // verificar matrix_destroy

  Matrix *m66 = matrix(6, 6, u);
  Matrix *sum2 = matrix_sum(lhs, m66); // ¿podriamos volver a usar sum1 aqui?
  assert(sum2 == nullptr); // aqui *experamos* que hubo un error
  // show_matrix("sum2", sum2); // ¿que pasa si tratan de ver la matriz?

  // ...
  return 0;
}

int test_matrix_performance(int argc, const char *argv[]) {
  /// pueden utilizar argv para configurar algunos tests a su manera
  /// pero tienen que documentar como usarlo
  int status = 0;
  status += test_matrix_small(/*...*/);  
  return status;
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
  // ... y tampoco cambiarlos, ya que son partes privadas de la implementacion.
  // pero podemos obtener sus valores usando las funciones de acceso
  size_t size = dyna_size(dyna);
  size_t capacity = dyna_capacity(dyna);
  const double *data = dyna_data(dyna);

  fprintf(stdout, "numero de elementos / capacidad: %u/%u\n", size, capacity);
  fprintf(stdout, "[\n");
  for (size_t i = 0; i < size; ++i) {
    fprintf(stdout, "  %6d: %12.6f\n", i, data[i]);
  }
  fprintf(stdout, "]\n\n");
}

///
/// Prueba de arreglos dinamicos (debe ser extendida)
///

int test_dynamic_arrays(int argc, const char *argv[]) {
  // si argc es mayor o igual a 3, usar el parametro provisto
  const size_t NX_DEFAULT = 8;
  const size_t NX = (3 <= argc ? atoi(argv[2]) : NX_DEFAULT);

  Initializer init_x = get_initializer("z");

  Dynarray *x = dynarray(NX, init_x);
  show_dynarray(x);

  // si argc es mayor o igual a 4, usar el parametro provisto
  const size_t NY_DEFAULT = 16;
  const size_t NY = (4 <= argc ? atoi(argv[3]) : NY_DEFAULT);
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
  // acceptar no menos de un argumento para despachar
  assert(2 <= argc);
  int status = dispatch(argc, argv);
  if (status != 0) {
    fprintf(stderr, "se completo con errores: status %d\n", status);
  }
  return status;
}
