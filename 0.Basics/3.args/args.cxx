///
/// args.cxx
///
/// Este ejemplo muestra los argumentos argc y argv pasados a main al ejecutar el programa
///
/// Ejercicio: compilar y correr este programa pasando argumentos
///
/// Ejemplos de como compilar el programa MINGW64:
///
///   g++ args.cxx -o args
///   gcc args.cxx -o args
///
/// Ejemplos de como ejecutar el programa:
///
///   ./args.exe uno dos tres
///   ./args.exe mult 6 7
///   ./args.exe mult 6 7
///
/// Ejercicio: convertir el lazo 'while' a un lazo 'for'
///

#include <stdio.h>

int main(int argc, const char *argv[])
{
  // la variable argc es pasada como parametro al main
  // argc es de tipo int y contiene el numero de argumentos
  // aqui imprimimos el valor de argc
  fprintf(stdout, "argc: %d\n\n", argc);

  int i = 0;
  while (i < argc) {
    // para obtener el i-esimo argumento usamos la expresion argv[i]
    // en la corrida van a notar que argv[0] es el path/nombre del programa
    const char *arg = argv[i];
    fprintf(stdout, "argv[%d]: %s\n", i, arg);
    i = i + 1;
  }
}
