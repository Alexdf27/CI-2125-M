///
/// hola.cxx
///
/// Ejercicio: completar el programa y correrlo con y sin argumento
///
///   ./hola
///   ./hola Marina
///   ./hola Pepe y Paco
///

#include <stdio.h>

int main(int argc, const char *argv[])
{
  if (argc == 1) {
    // ... imprimir "Hola!"
  } else if (argc == 2) {
    // ... imprimir "Hola <nombre>!"
  } else {
    // ... imprimir un error
    fprintf(stderr, "uso: %s [<nombre>]\n", argv[0]);
    return 1;
  }
  return 0;
}
