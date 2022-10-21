///
/// de1aN.cxx
///
/// programa que cuenta de 1 a N
///
/// Ejercicio 1: corregir y completar el programa para hacerlo robusto (Windows y Linux)
/// Ejercicio 2: convertir el lazo 'while' a un lazo 'for'
///

#include <stdio.h>

int main(int argc, const char *argv[])
{
  // obtener el valor de N a partir del argumento
  int N = argv[1];

  // contar de 1 a N
  int i = 1;
  while (i <= N) {
    fprintf(stdout, "%d\n", i);
    i = i + 1;
  }

  return 0;
}
