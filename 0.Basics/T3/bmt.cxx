///
/// bmt.cxx
///
/// La transformada Box-Mueller esta descrita en esta página:
/// https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform
///
/// Pero (don't panic!) lo único que necesitan es la imagen con las
/// fórmulas mágicas Box-Mueller.png y leer lo que está explicado aquí.
///
/// Para hacer esta tarea van a tener que buscar en la Web varias
/// funciones de libreria e incluir (#include) el encabezado correspondiente.
/// Tambien van a tener que buscar como generar numeros aleatorios (random)
/// entre 0 y 1, that is, how to generate random numbers between 0 and 1. :-)
/// Hay varias formas de hacerlo. No se preocupen si la que usan no es portable
/// entre C y C++ ... con tan solo ver el código yo voy a saber como compilarlo.
///
/// El programa ya esta preparado para imprimir doce pares de (Z0, Z1)
/// Literalmente, aparte de buscar y ver como (por ejemplo) calcular un coseno,
/// lo unico que tienen que hacer es definir las funciones Z0 y Z1 de manera
/// adecuada y llamarlas desde el main, igualmente de manera adecuada.
///
/// Es importante destacar que, en cada iteración, los valores de U1 y U2
/// utilizados por Z0 y Z1 deben ser consistentes, como indica la imagen.

#include <stdio.h>

// number of Box-Mueller pair samples
const int NS = 16;

double Z0( /* definir parametros */ ) {
  // implementar la fórmula para Z0
  return -1.42; // regresar el resultado de la formula y no esto, obviamente
}

double Z1( /* definir parametros */ ) {
  // implementar la fórmula para Z1
  return 1.67; // regresar el resultado de la formula y no esto, obviamente
}

int main() {
  for (int i = 0; i < NS; ++i) {
    // ... hacer cálculos preliminares de ser necesarios
    double z0 = Z0(/* pasar parametros */);
    double z1 = Z1(/* pasar parametros */);
    fprintf(stdout, "(Z0, Z1) => (%9.6lf, %9.6lf)\n", z0, z1);
  }
  return 0;
}
