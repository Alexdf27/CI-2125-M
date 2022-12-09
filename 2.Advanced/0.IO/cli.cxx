///
/// I/O example: menu based CLI
///

#include "student.h"
#include "student_db.h"

#include <cstdio>
#include <cstring>
#include <string>

using std::string;

///
/// Longitud de los buffers para nombres de archivo
///
const size_t FILENAME_SIZE = 64;

///
/// El apuntador a la base de datos en memoria principal!
///
static StudentDB *db = nullptr;

///
/// El nombre del archivo que corresponde al cargado en memoria
///
static char current[FILENAME_SIZE] = "\000";

///
/// Indica si la base de datos en memoria principal es consistente ...
/// ... con el archivo current: la base de datos en memoria secundaria
///
static bool consistent = false;

/// Menu

struct Option {
  string description;
  void (*function)();
};

void help();

// Funcion de prueba
void test() {
  test_student_module();
}

// funcion para cargar la base de datos
void load() {
  fprintf(stdout, "INCOMPLETO\n");
  //
  // OJO: si la base de datos ya esta en memoria no debemos volvera a cargar
  // si no esta en memoria, adivinen cual es un buen sitio para crearla
  //
  char filename[FILENAME_SIZE];
  fprintf(stdout, "nombre del archivo: ");
  fflush(stdout); // hacer flush de stdout despues de un prompt sin fin de linea
  fscanf(stdin, "%s", filename);
  fflush(stdin); // hacer flush de stdin despues de fscanf o fgets

  // load student DB
  int status = load_student_db(db, filename);

  strncpy(current, filename, FILENAME_SIZE);
}

// Funcion para buscar un estudiante
void find() {
  // deben preguntarle al usuario que campo desea usar para la busqueda
  // (NO alteren el menu principal con mas opciones)
  // el usuario solo tiene que teclear "key", "id", o "name"
  // ... y luego proveer el valor adecuado
  //
  // si no consigue el estudiante indica que no existe
  // si lo consigue, pide al usuario que actualice los campos
  fprintf(stdout, "INCOMPLETO\n");
}

// Funcion para agregar un estudiante
void add() {
  fprintf(stdout, "INCOMPLETO\n");
}

// Funcion para actualizar los datos de un estudiante
// deben preguntarle al usuario que campo desea usar para la busqueda
// (NO alteren el menu principal con mas opciones)
// el usuario solo tiene que teclear "key", "id", o "name"
// ... y luego proveer el valor adecuado
//
// si no consigue el estudiante indica que no existe
// si lo consigue, pide al usuario que actualice los campos
// para todo campo muestra un prompt con un valor por defecto
// por ejemplo, para actualizar el nombre, el prompt seria algo asi:
//    nombre (Gina Luckenkemper): 
// noten que deben dejar un espacio en blanco despues del dos puntos
// el usuario puede dar un nuevo valor o darle a 'Enter' para dejarlo igual
// NOTA: lo anterior se realiza para todos los campos excepto la clave 'key'
// el campo clave 'key' JAMAS debe ser actualizada
void update() {
  fprintf(stdout, "INCOMPLETO\n");
}

// Funcion para remover un estudiante de la base de datos
// deben preguntarle al usuario que campo desea usar para la busqueda
// (NO alteren el menu principal con mas opciones)
// el usuario solo tiene que teclear "key", "id", o "name"
// ... y luego proveer el valor adecuado
//
// si no consigue el estudiante indica que no existe
// si lo consigue, lo elimina de la base de datos
void remove() {
  fprintf(stdout, "INCOMPLETO\n");
}

// Funcion para ordenar la base de datos
void sort() {
  // deben preguntarle al usuario que campo desea usar
  // el usuario solo tiene que teclear "key", "id", o "name"
  // NO alteren el menu principal con mas opciones
  fprintf(stdout, "INCOMPLETO\n");
  //
  // Completar ...
  //
}

// Funcion para salvar la base de datos en un archivo
void save() {
  fprintf(stdout, "INCOMPLETO\n");
  char filename[FILENAME_SIZE];
  fprintf(stdout, "nombre del archivo: ");
  fflush(stdout); // hacer flush de stdout despues de un prompt sin fin de linea
  fscanf(stdin, "%s", filename);
  fflush(stdin); // hacer flush de stdin despues de fscanf o fgets
  fprintf(stdout, "salvando %s ...\n", filename);
  //
  // Completar ...
  //
}

// Completar a su juicio para proteger el usuario contra "poner la torta"
void erase() {
  fprintf(stdout, "INCOMPLETO\n");
  if (db != nullptr) {
    delete_student_db(db);
  }
  db = nullptr;
}

// Completar a su juicio para proteger el usuario contra "poner la torta"
void leave() {
  fprintf(stdout, "INCOMPLETO\n");
  exit(0);
}

//
// Menu de opciones
//

Option options[] = {
  { "ayuda!", help    },
  { "prueba", test    },
  { "cargar", load    },
  { "buscar", find    },
  { "agregar", add    },
  { "cambiar", update },
  { "remover", remove },
  { "ordenar", sort   },
  { "salvar", save    },
  { "borrar", erase   },
  { "terminar", leave }
};

void help() {
  int NO = sizeof(options) / sizeof(options[0]);
  fprintf(stdout, "-------------\n");
  for (int i = 0; i < NO; ++i) {
    fprintf(stdout, "(%2d) %s\n", i, options[i].description.c_str());
  }
  fprintf(stdout, "-------------\n");
  fflush(stdout);
}

void menu() {
  int BUFSIZE = 128;
  char buffer[BUFSIZE];

  fprintf(stdout, "Current DB: %s (%c)\n", current, consistent ? 'C' : 'M');

  for (;;) {
    fprintf(stdout, "> ");
    fflush(stdout);
    const char *status = fgets(buffer, BUFSIZE, stdin);
    fflush(stdin); // hacer flush de stdin despues de fscanf o fgets
    if (status != buffer) {
      fprintf(stderr, "error al leer la consola\n");
      continue;
    }
    int opt = atoi(buffer);
    // INCOMPLETO: deben validar que opt esta en rango!
    options[opt].function();
  }
}

int main() {
  help();
  menu();
  return 0;
}
