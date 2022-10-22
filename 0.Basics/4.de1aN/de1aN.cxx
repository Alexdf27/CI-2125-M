///
/// de1aN.cxx
///
/// programa que cuenta de 1 a N
///
/// Ejercicio 1: corregir y completar el programa para hacerlo robusto (*)
/// Ejercicio 2: cambiar el especificador '%d' en el fprintf a '%6d'
/// Ejercicio 3: convertir el lazo 'while' a un lazo 'for'
///
/// (*) en particular, vean que pasa si corren el programa sin parametros
///

#include <stdio.h>
// #include <stdlib.h>

int main(int argc, const char *argv[])
{
  // aqui obtenemos el valor de N a partir del argumento
  // pero, la instruccion deliberadamente contiene un error
  // compilen el programa asi como es, para ver el error
  // cada elemento de argv (argv[i]) es de tipo string (const char *)
  // tenemos que convertir el string a un entero para contar
  // la funcion 'atoi' (parte de stdlib) permite hacer eso
  // .:. en vez de argv[1] deben usar atoi(argv[1])
  // es asi de sencillo!

  int N = argv[1];

  // contar de 1 a N
  int i = 1;
  while (i <= N) {
    fprintf(stdout, "%d\n", i);
    i = i + 1;
  }

  return 0;
}
