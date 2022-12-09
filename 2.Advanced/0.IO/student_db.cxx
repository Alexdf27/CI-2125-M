///
/// student_db.cxx
///
/// Base de datos en memoria
///

#include "student_db.h"

#include <cstdio>
#include <cstdlib>

// Error codes
const int SUCCESS = 0x00;
const int ERROR_FILE_NOT_FOUND = 0x02;
const int ERROR_ACCESS_DENIED = 0x05;
const int ERROR_WRITE_FAULT = 0x1D;
const int ERROR_READ_FAULT = 0x1E;

StudentDB *create_student_db() {
  return new StudentDB();
}

// Carga la base de datos en memoria con los datos del archivo 'filename'
int load_student_db(StudentDB *db, const char *filename) {
  // mosca esto NO es lo que se quiere: solo muestra como leer el archivo
  fprintf(stdout, "INCOMPLETO\n");

  // solo para propositos de debugging: eviten entregas "sucias"
  // esto vale para todas las funciones; no vamos a repetirlo
  const bool debug = true;
  if (debug) {
    fprintf(stdout, "load_student_db(%p, \"%s\")\n", db, filename);
  }

  FILE *fp = fopen(filename, "r");
  if (fp == nullptr) {
    fprintf(stderr, "el archivo %s no pudo abrirse\n", filename);
    fflush(stderr); // hacer flush de stderr despues imprimir un error
    return ERROR_FILE_NOT_FOUND;
  }

  const int BUFSIZE = 512;
  char buffer[BUFSIZE];
  for (;;) {
    const char *status = fgets(buffer, BUFSIZE, fp);
    if (status == nullptr) {
      if (ferror(fp)) {
        fprintf(stderr, "error leyendo el archivo %s\n", filename);
        fflush(stderr); // hacer flush de stderr despues imprimir un error
        return ERROR_READ_FAULT;
      }
      break;
    }
    if (debug) {
      // para demostrar que estamos leyendo el archivo bien
      fprintf(stdout, "%s", buffer);
    }
    //
    // completar ...
    //
  }

  fclose(fp);
  return SUCCESS;
}

// Obtiene el estudiante en la posicion i del vector
// i.e. retorna (una copia de) la i-esima fila de la tabla
Student get(StudentDB *db, int i) {
  fprintf(stdout, "INCOMPLETO\n");
  // deben chequear que i esta en rango
  return (*db)[i];
}

// Busca estudiante por clave
// retorna el indice del estudiante en el vector o -1 si no lo consigue
int find_student(StudentDB *db, uint32_t key) {
  fprintf(stdout, "INCOMPLETO\n");
  return -1; // not found
}

// Busca estudiante por identificador
// retorna el indice del estudiante en el vector o -1 si no lo consigue
int find_student_by_id(StudentDB *db, const char *id) {
  fprintf(stdout, "INCOMPLETO\n");
  return -1; // not found
}

// Busca estudiante por su nombre
// retorna el indice del estudiante en el vector o -1 si no lo consigue
int find_student_by_name(StudentDB *db, const char *name) {
  fprintf(stdout, "INCOMPLETO\n");
  return -1; // not found
}

// Agrega un estudiante a la base de datos
// retorna el indice del estudiante en el vector
int add_student(StudentDB *db, Student student) {
  db->push_back(student);
  return db->size() - 1;
}

// Actualiza los datos del i-esimo estudiante en la base de datos
void update_student(StudentDB *db, int i, Student student) {
  // mosca con modificar una copia, dejando la db igual
  fprintf(stdout, "INCOMPLETO\n");
}

// Borra el i-esimo estudiante de la base de datos
void remove_student(StudentDB *db, int i, Student student) {
  // advertencia: este metodo tiene sus detalles
  // deben averiguar como eliminar un elemento arbitrario de un std::vector
  fprintf(stdout, "INCOMPLETO\n");
}

// ordena el arreglo por clave (ascendiente)
void sort_student_db(StudentDB *db) {
  fprintf(stdout, "INCOMPLETO\n");
}

// ordena el arreglo por identificador (ascendiente)
void sort_student_db_by_id(StudentDB *db) {
  fprintf(stdout, "INCOMPLETO\n");
}

// ordena el arreglo por nombre (ascendiente)
void sort_student_db_by_name(StudentDB *db) {
  fprintf(stdout, "INCOMPLETO\n");
}

int save_student_db(StudentDB *db, const char *filename) {
  fprintf(stdout, "INCOMPLETO\n");
  FILE *fp = fopen(filename, "w");
  if (fp == nullptr) {
    fprintf(stderr, "el archivo %s no pudo abrirse\n", filename);
    fflush(stderr); // hacer flush de stderr despues imprimir un error
    return ERROR_ACCESS_DENIED;
  }
  ///
  /// completar
  ///
  fclose(fp);
  return SUCCESS;
}

// elimina la base de datos, rescatando la memoria ocupada
void delete_student_db(StudentDB *db) {
  if (db != nullptr) {
    delete db;
  }
}
