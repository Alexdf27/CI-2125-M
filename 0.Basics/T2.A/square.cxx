///
/// square.cxx
///
/// Esta tarea se deriva de la tarea 0 parte A. Es la tarea 2 llevada a código real.
/// Si corren el siguiente fragmento en frío se pueden notar algo interesante ...
/// ... z toma estos valores, en secuencia: 0, 1, 4, 9, 16 (looks familiar?)
///
///  int x = 1;
///  int z = 0;
///  z = z + x;
///  x = x + 2;
///  z = z + x;
///  x = x + 2;
///  z = z + x;
///  x = x + 2;
///  z = z + x;
///  x = x + 2;
///
/// Como ven, las últimas dos instrucciones se vienen repitiendo en el programa.
/// De hecho pueden demostrar por inducción (si quieren, no tienen que hacerlo)
/// que la secuencia de valores de z, sin importar que tanto extendemos la parte
/// repetitiva, es de la forma i^2 para los enteros i desde 0 en adelante.
/// Lógicamente, extender código a fuerza bruta (copy & paste) es ridículo.
/// Para eso existen los lazos en los lenguajes imperativos.
///
/// Tarea: completar la función square (abajo) para calcular n^2 (n al cuadrado) 
/// para un n arbitrario (pasado como argumento) usando solamente operaciones de suma.
/// Pueden usar un lazo 'while' o (más elegante en este caso) un lazo 'for'
///
/// Compilar: g++ square.cxx -o square
/// Correr: ./square.exe 20

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int square(int n) {
  // NOTA: quitar este comentario y este (horrible) fprintf en la entrega
  // Están para convencer a los incrédulos que el párametro n es correcto
  // Quiten esto tan pronto como esten convencidos que asi es
  fprintf(stderr, "CHECK: computing square(%d)\n", n);

  // El uso de este condicional nos permite simplificar el programa.
  // Claramente estamos explotando que (-n)^2 es igual a n^2
  if (n < 0) {
    n = -n;
  }

  assert(0 <= n); // podemos afirmar con certeza que esto se cumple

  int resultado = 0;
  // ...
  // ... hagan su "magia" aqui
  // ...
  // esta función (square) debe retornar (return) el resultado
  // y, como pueden ver, la instrucción al final hace precisamente eso.
  // Pueden cambiar el nombre de la variable, pero sean consistentes
  return resultado;
}

// Leer y entender, pero NO cambiar, el código que sigue
int main(int argc, const char *argv[]) {
  // aqui chequeamos el número de argumentos
  if (argc != 2) {
    // si es distinto de 2, imprimimos un mensaje ...
    fprintf(stderr, "uso: %s <int N>\n", argv[0]);
    // ... y retornamos un código de error
    return 1;
  }

  // obtener y chequear el valor del argumento (viene de la línea de comando)
  // usamos la función atoi (stdlib) para convertir el string argv[1] a entero
  int n = atoi(argv[1]);

  // aqui invocamos la función square y asignamos el resultado
  int result = square(n);

  // aqui imprimimos el resultado
  fprintf(stdout, "square(%d) => %d\n", n, result);

  return 0;
}
