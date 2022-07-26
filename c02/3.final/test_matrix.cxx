///
/// Pruebas de matrices: funcionales y de rendimiento
///
/// deben ser extendidas
///

#include "test_matrix.h"
#include "init.h"

#include <assert.h>
#include <stdio.h>


//////////////////////////////////////////////////
/// Seccion:  ///
//////////////////////////////////////////////////

///
/// show_matrix: imprime una matrix
///
/// const char *name: nombre o etiqueta para identificar la matriz
/// const Matrix *: apuntador a la matriz
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
  
  Initializer fortytwo = get_initializer("42");
  Initializer uniform =  get_initializer("u");

  Matrix *lhs = matrix(6, 8, fortytwo);
  show_matrix("lhs", lhs);

  Matrix *rhs = matrix(6, 8, uniform);
  show_matrix("rhs", rhs);

  Matrix *sum1 = matrix_sum(lhs, rhs);
  assert(sum1 != nullptr); // siempre es una buena idea chequear que no hubo error
  show_matrix("sum1", sum1);

  matrix_destroy(&sum1); // "probar" (parcialmente) la liberacion de memoria
  assert(sum1 == nullptr); // verificar matrix_destroy

  Matrix *m66 = matrix(6, 6, uniform);
  Matrix *sum2 = matrix_sum(lhs, m66); // ¿podriamos volver a usar sum1 aqui?
  assert(sum2 == nullptr); // aqui *experamos* que hubo un error
  // show_matrix("sum2", sum2); // ¿que pasa si tratan de ver la matriz?

  // ...
  return 0;
}

int test_matrix(int argc, const char *argv[]) {
  /// pueden utilizar argv para configurar algunos tests a su manera
  /// pero tienen que documentar como usarlo
  int status = 0;
  status += test_matrix_small(/*...*/);  
  return status;
}
