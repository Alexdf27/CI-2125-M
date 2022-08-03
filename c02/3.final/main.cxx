///
/// main.cxx
///
/// Tarea Final: programa principal
///

#include "test_dyna.h"
#include "test_matrix.h"
#include "test_table.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Este codigo, y el de todos los archivos test_*, se provee como esqueleto
/// Deben seguir el esqueleto y extenderlo: estas prueba no son suficientes
/// - no prueban todas las funciones, mucho menos combinaciones de las mismas
/// - no cubren usos tipicas y atipicos de las funciones
/// - no consideran casos de borde, casos perversos, etc.
///
/// 20% de la evaluacion de esta tarea (10 puntos) se basa en:
/// - buena cobertura: completitud y probabilidad de pillar errores
/// - calidad del codigo de prueba: modularidad, claridad, limpieza, etc.
/// - eficiencia: esencialmente evitar pruebas que no mejoran la cobertura
///
/// Son buenos ingenieros: investiguen!
/// https://en.wikipedia.org/wiki/Code_coverage
/// https://en.wikipedia.org/wiki/Software_testing
/// https://en.wikipedia.org/wiki/Edge_case

//
// ayuda para reconocimiento de datos usando *scanf
//

// usamos este tipo de estructura como ejemplo
struct Record {
  const char *sval;
  double dval;
  float fval;
  int ival;
};

// funcion que muestra un Record, para verificar que el reconocimiento funciona
static void show_record(const char *label, Record r) {
  fprintf(stdout, "%s: { %s, %lf, %f, %d }\n", label, r.sval, r.dval, r.fval, r.ival);
}

// funcion equivalente, pero pasando un apuntador a el Record
static void show_record_lean(const char *label, Record *r) {
  fprintf(stdout, "%s: { %s, %lf, %f, %d }\n", label, r->sval, r->dval, r->fval, r->ival);
}

static int load_record_short(Record *record, char *input) {
  // traza para ver la entrada
  // fprintf(stdout, "input: %s\n", input);
  // el input buffer corresponde a una linea del archivo, terminada con ASCII NUL

  char sval[128]; // buffer para almacenar el string a ser leido

  sscanf(input, "%[^,], %lf, %f, %d", &sval, &record->dval, &record->fval, &record->ival);
  record->sval = strdup(sval);
}

static int load_record_long(Record *record, char *input) {
  // traza para ver la entrada
  // fprintf(stdout, "input: %s\n", input);
  // el input buffer corresponde a una linea del archivo, terminada con ASCII NUL

  char separator = ','; // separador de campos
  const int NF = 4; // numero de campos
  const char *field[NF]; // arreglo de campos no convertidos (aun en formato de strings)

  // cada elementos de 'field' va a apuntar al campo correspondiente en 'input'!
  // de esa manera no tenemos que reservar memoria separada, pero ...
  // ... como evitamos que el campo i quede concatenado con el i+1 etc.?
  // simplemente reemplazamos los separadores por ASCII NUL (0) !!

  int f = 0; // indice de campo
  for (int i = 0; input[i] != 0 && f < NF; ++i) {
    // comerse los caracteres blancos (superfluos) al comienzo de un campo
    while (input[i] == ' ' || input[i] == '\t') {
      ++i;
    }
    // habemus field (tenemos el comienzo de un campo)
    field[f++] = &input[i];
    // encontrar el separador ...
    while (input[i] != separator && input[i] != 0) {
      ++i;
    }
    // ... para convertirlo en ASCII NUL
    if (input[i] == separator) {
      input[i++] = 0;
    }
  }

  if (f != NF) {
    fprintf(stderr, "input: %s\nEl reconocimiento de los datos fallo\n");
    return 1;
  }

  char sval[128];
  double dval;
  float fval;
  int ival;

  sscanf(field[0], "%[^\0]", &sval); // aqui NO podemos usar directamente &record->sval
  sscanf(field[1], "%lf", &dval); // aqui podriamos usar directamente &record->dval
  sscanf(field[2], "%f", &fval); // aqui podriamos usar directamente &record->dval
  sscanf(field[3], "%d", &ival); // aqui podriamos usar directamente &record->dval

  // ... traza para verificar la lectura de scanf
  // fprintf(stdout, "%s, %lf, %f, %d\n", sval, dval, fval, ival);

  // es absolutamente necesario duplicar (clonar) el string en la memoria dinamica
  record->sval = strdup(sval);
  record->dval = dval;
  record->fval = fval;
  record->ival = ival;

  return 0;
}

static int test_io(int argc, const char *argv[]) {
  // Comenzamos con un registro (record) para ver como lo reconstruimos a partir de una linea
  Record rx = { "This is how we do it!", 42.42 * 67.67, 42.42 * 67.67, 6 * 7 };

  // cargamos los datos de rx en el input buffer
  char input[256];
  sprintf(input, "%s, %lf, %f, %d", rx.sval, rx.dval, rx.fval, rx.ival);

  Record ry; // inicializado con "basura" ... y no importa si no usamos la basura!

  // ahora extraemos los datos del input buffer, cargandolos en ry
  load_record_long(&ry, input);

  // noten que el input buffer fue alterado por load_record_long
  // aqui lo volvemos a asignar con los datos de rx
  sprintf(input, "%s, %lf, %f, %d", rx.sval, rx.dval, rx.fval, rx.ival);

  Record rz; // tambien inicializado con "basura" ... y no importa!

  // ahora extraemos los datos del input buffer, cargandolos en ry
  load_record_short(&rz, input);

  // ver para creer, desconfiados!
  show_record("rx", rx);
  show_record("ry", ry);
  show_record("rz", rz);

  return 0;
}

static int dispatch(int argc, const char *argv[]) {
  if (strcmp(argv[1], "dyna") == 0) {
    return test_dynamic_arrays(argc, argv);
  }
  if (strcmp(argv[1], "matrix") == 0) {
    return test_matrix(argc, argv);
  }
  if (strcmp(argv[1], "table") == 0) {
    return test_table(argc, argv);
  }
  if (strcmp(argv[1], "io") == 0) {
    return test_io(argc, argv);
  }
  fprintf(stderr, "usage: %s (dyna | matrix | table | io) <args>\n", argv[0]);
  return 1;
}

///
/// Main: punto de entrada
///
int main(int argc, const char *argv[]) {
  // acceptar no menos de un argumento para despachar
  assert(2 <= argc);
  int status = dispatch(argc, argv);
  if (status != 0) {
    fprintf(stderr, "se completo con errores: status %d\n", status);
  }
  return status;
}
