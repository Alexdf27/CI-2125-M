///
/// hello.cxx
///
/// <<< históricamente importante y útil >>>
///
/// Este es el primer ejemplo de un programa en C en el libro de Kernighan & Ritchie
/// Pueden apreciar la importancia histórica de este libro en Wikipedia:
/// https://en.wikipedia.org/wiki/The_C_Programming_Language
///
/// Lo pueden ver en el primer capitulo del libro, en la seccion "1.1 Getting Started"
/// https://docs.google.com/viewer?a=v&pid=sites&srcid=ZGVmYXVsdGRvbWFpbnxnanVoYWN8Z3g6NTFiY2ExMDdkYTI5YmRmZA
///
/// Noten que el ejemplo en este archivo es levemente distinto al del libro:
/// - La función main es explicitamente declarada de tipo int: el caso por defecto si se omite la declaración
/// - De manera correspondiente, explícitamente retornamos 0 al final para indicar que todo está bien
/// - Usamos la función fprintf para imprimir, indicando explícitamente la salida estándar: stdout
///
/// Las diferencias reflejan: 
/// 1. razones de enseñanza: en particular el deseo de evitar casos especiales
/// 2. convenciones generalmente aceptadas de "mejores practicas" de programación
/// 
///

#include <stdio.h>

int main()
{
  fprintf(stdout, "Hello, world!\n");
  return 0;
}
