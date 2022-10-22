///
/// basic.cxx
///
/// Compilen y corran este programa, asi como esta
///
/// Este programa les puede servir de referencia
/// Muestra el tamaño de varios tipos basicos
/// Noten que sizeof acepta variables y tambien tipos (!) como argumento
/// de hecho, la funcion 'sizeof' es magica en varios sentidos
///
/// Ejercicio: denle un vistazo a https://cplusplus.com/reference/cstdio/printf/
/// Ejercicio: y busquen "C format specifiers" en la Web
///

#include <stdio.h>

void size_of_basic_types()
{
  fprintf(stdout, "---------------------\n");
  fprintf(stdout, "Type             Size\n");
  fprintf(stdout, "---------------------\n");
  fprintf(stdout, "bool:        %2lu bytes\n", sizeof(bool));
  fprintf(stdout, "char:        %2lu bytes\n", sizeof(char));
  fprintf(stdout, "short int:   %2lu bytes\n", sizeof(short int));
  fprintf(stdout, "int:         %2lu bytes\n", sizeof(int));
  fprintf(stdout, "long int:    %2lu bytes\n", sizeof(long int));
  fprintf(stdout, "float:       %2lu bytes\n", sizeof(float));
  fprintf(stdout, "double:      %2lu bytes\n", sizeof(double));
  fprintf(stdout, "long double: %2lu bytes\n", sizeof(long double));
  fprintf(stdout, "---------------------\n");
}

void size_of_some_variables()
{
  bool ok = true;
  char grade = 'A';
  int answer = 42;
  float e = 2.718281828459;
  double pi = 3.14159265358979323846;
  const char hello[] = "Hello";

  fprintf(stdout, "------------------------------------------\n");
  fprintf(stdout, "Name     Type             Size    Value   \n");
  fprintf(stdout, "------------------------------------------\n");
  fprintf(stdout, "ok       bool:        %2lu bytes => %s\n",  sizeof(ok), ok ? "true" : "false");
  fprintf(stdout, "grade    char:        %2lu bytes => %c\n",  sizeof(char), grade);
  fprintf(stdout, "answer   int:         %2lu bytes => %d\n",  sizeof(int), answer);
  fprintf(stdout, "e        float:       %2lu bytes => %f\n",  sizeof(e), e);
  fprintf(stdout, "pi       double:      %2lu bytes => %lf\n", sizeof(pi), pi);
  fprintf(stdout, "hello    string (*):  %2lu bytes => %s\n",  sizeof(hello), hello);
  fprintf(stdout, "------------------------------------------\n");
}

int main(int argc, const char *argv[])
{
  size_of_basic_types();
  size_of_some_variables();
  return 0;
}
