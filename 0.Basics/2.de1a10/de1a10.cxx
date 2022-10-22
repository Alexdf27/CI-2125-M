///
/// de1a10.cxx
///
/// Programa de ejemplo que cuenta 1 a 10
/// Muestra el uso de la instrucción while para iterar
///
/// Ejercicio: compilar y ejecutar el programa
///
/// Ejemplos de como compilar el programa en MINGW64:
///
///   g++ de1a10.cxx -o de1a10
///   gcc de1a10.cxx -o de1a10
///
/// Ejemplo de como ejecutar el programa:
///
///   ./de1a10
///   ./de1a10.exe
///
/// Ejercicio: convertir el lazo 'while' a un lazo 'for'
/// Ejercicio: definir una constante entera N para el numero 10
/// Ejercicio: alinear los numeros en la salida (use  %4d en vez de %d)
///

#include <stdio.h>

int main()
{
  int i = 1;
  while (i <= 10) {
    fprintf(stdout, "Numero: %d\n", i);
    i = i + 1;
  }
}
