///
/// fibo.cxx
///
/// Esta tarea viene de la tarea 0 parte C. Vamos a generalizarla en código.
/// Recomendamos fuertemente hacer la tarea anterior (T0.A) antes de esta
///
/// Si corren el siguiente fragmento en frío pueden notar que la variable s
/// toma estos valores, en secuencia: 1, 2, 3, 5
///
///  int p = 0;
///  int u = 1;
///  int s = u + p;
///  p = u;
///  u = s;
///  s = u + p;
///  p = u;
///  u = s;
///  s = u + p;
///  p = u;
///  u = s;
///  s = u + p;
///
/// Como ven, las últimas tres instrucciones se vienen repitiendo en el programa.
/// De hecho pueden demostrar por inducción (si quieren, no tienen que hacerlo)
/// que la secuencia de valores de s son los números de fibonacci, excluyendo los
/// dos primeros que corresponden a los casos base (0 y 1), definidos asi:
///
/// fibonacci(0) => 0
/// fibonacci(1) => 1
/// fibonacci(n) => fibonacci(n-1) + fibonacci(n-2), para todo n >= 2
///
/// Siguiendo el espíritu de la tarea anterior (T0.A) deben implementar una
/// función (fibo) que calcula fibonacci(n), para todo n >=0, usando un lazo.
/// Pueden usar un lazo 'while' o (más elegante en este caso) un lazo 'for'
///
/// Compilar: g++ fibo.cxx -o fibo
/// Correr: ./fibo.exe 20
///
/// Warning: do not compute fibonacci(n) for n greater than 30, 40, or 42

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// version recursiva correspondiente a la definición ... do not touch!
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// version recursiva en una linea ... do not touch!
int fibo_recursive(int n) {
  return n < 2 ? n : fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

// version rápida ... this is where you do your magic
int fibo(int n) {
  assert(n >= 0); // precondición: aborta si no se cumple

  int resultado = fibonacci(n);

  // ...
  // ... hagan su "magia" aqui
  // ...

  assert(resultado == fibo_recursive(n));
  return resultado;
}

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "uso: %s <int N>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (n < 0) {
    fprintf(stderr, "el argumento N debe ser mayor o igual a cero\n");
    return 2;
  }

  int result = fibo(n);

  fprintf(stdout, "fibo(%d) => %d\n", n, result);

  return 0;
}
