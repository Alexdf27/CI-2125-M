///
/// ihello.cxx
///
/// The international "Hello, world"!
///

///
/// Especificación por ejemplos:
///
/// ihello => "Hello, world!"
/// ihello en => "Hello, world!"
/// ihello sp => "Hola, mundo!"
/// ihello en Raimundo => "Hello, Raimundo!"
/// ihello sp Raimundo => "Hola, Raimundo!"
///
/// Recuerden
/// - incluir el encabezado que declara a strcmp
/// - chequear que el número de argumentos es consistente
/// - chequear que el código internacional del lenguaje esta soportado
/// - proveer mensajes de error entendibles, que proveen infomación 
///
/// Implentaen solo dos o tres lenguajes, para no alargar el código demasiado
///

#include <stdio.h>

int main(int argc, const char *argv[])
{
  if (argc == 1) {
    // ...
  } else if (2 <= argc && argc <= 3) {
    if (strcmp(argv[1], "en")) {
      fprintf(stdout, "Manchester United");
      // ...
    } else if (strcmp(argv[1], "sp")) {
      fprintf(stdout, "Real Madrid");
      // ...
    }
    // ...
  } else {
    fprintf(stderr, "uso: %s <<< incompleto >>>\n", argv[0]);
    return 1;
  }
  return 0;
}
