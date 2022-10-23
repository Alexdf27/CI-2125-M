///
/// swap.cxx
///
/// Esta simple tarea (6 lineas) consiste en intercambiar el valor de variables numericas
/// de tipo int asi como de tipo double. Es un buen ejemplo de como manejar
/// argumentos pasados al programa desde la linea de comandos cuando hay varios
/// casos que manejar de manera distinta. Notar el uso de strcmp, atoi, y atof.
///
/// Ejemplo de compilación y corrida (intenten violar el uso adecuado para aprender):
///
/// g++ swap.cxx -o swap
/// ./swap int 42 67
/// ./swap double 3.14159 2.71828
///

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void usage(const char *program) {
  fprintf(stderr, "usos posibles:\n");
  fprintf(stderr, "%s int <valor entero> <valor entero>\n", program);
  fprintf(stderr, "%s double <valor double> <valor double>\n", program);
}

int main(int argc, const char *argv[]) {
  if (argc != 4) {
    usage(argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "int") == 0) {
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    fprintf(stdout, "x:%d, y:%d\n", x, y);
    // ... intercambiar el valor de las variables aqui
    fprintf(stdout, "x:%d, y:%d\n", x, y);
    return 0;
  }

  if (strcmp(argv[1], "double") == 0) {
    double x = atof(argv[2]);
    double y = atof(argv[3]);
    fprintf(stdout, "x:%lf, y:%lf\n", x, y);
    // ... intercambiar el valor de las variables aqui
    fprintf(stdout, "x:%lf, y:%lf\n", x, y);
    return 0;
  }

  // si llegamos aqui el usuario no especifico un tipo soportado
  usage(argv[0]);
  return 1;
}
