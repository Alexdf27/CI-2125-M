///
/// sort.cxx
///

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

///
/// Record type - tipo del registro para ejemplificar
///

struct Record {
  int key;
  double number;
};

// constructor de un registro aleatorio
Record random_record()
{
  Record record;
  record.key = rand() % 10000;
  record.number = (100.0 * rand()) / RAND_MAX;
  return record;
}

// constructor alterno de un registro aleatorio
Record alt_random_record_1()
{
  int key = rand() % 10000;
  double number = (100.0 * rand()) / RAND_MAX;
  return { key, number };
}

// otro constructor alterno de un registro aleatorio
Record alt_random_record_2()
{
  return Record({ rand() % 10000, (100.0 * rand()) / RAND_MAX });
}

///
/// naked C array - arreglo "desnudo" en C
///

// constructs an array of 'n' random records
Record *random_naked_array(int n)
{
  // dynamically allocate memory
  Record *rec = (Record *) calloc(n , sizeof(Record));
  // initialize array with random records
  for (int i = 0; i < n; ++i) {
    rec[i] = random_record();
  } 
  return rec;
}

// deallocates (destroys) a dynamically allocated array of records
void destroy_naked_array(Record *rec)
{
  free(rec);
}

// shows a naked C array of records
void show_naked_array(int n, Record *rec)
{
  for (int i = 0; i < n; ++i) {
    fprintf(stdout, "  { %4d, %12.4lf }\n", rec[i].key, rec[i].number);
  }
}

// sorts a naked C array of Record elements by key
// @param 'n': number of Record elements
// @param 'rec': array
// ordena un arreglo de registros por clave
void sort_naked_array(int n, Record rec[])
{
  for (int i = 0; i < n; ++i) {
    int minidx = i;
    int minkey = rec[minidx].key;
    for (int j = i + 1; j < n; ++j) {
      if (rec[j].key < minkey) {
        minidx = j;
        minkey = rec[minidx].key;
      }
    }
    Record tmp = rec[i];
    rec[i] = rec[minidx];
    rec[minidx] = tmp;
  }
}

// alternative syntax - same definition
void alt_sort_naked_array(int n, Record *rec)
{
  // same function body as above: feel free to copy and paste and try it
  // copien y peguen
  for (int i = 0; i < n; ++i) {
    int minidx = i;
    int minkey = rec[minidx].key;
    for (int j = i + 1; j < n; ++j) {
      if (rec[j].key < minkey) {
        minidx = j;
        minkey = rec[minidx].key;
      }
    }
    Record tmp = rec[i];
    rec[i] = rec[minidx];
    rec[minidx] = tmp;
  }
}

///
/// C++ vector of Record elements
///

typedef std::vector<Record> RecordDB;

// returns a pointer to a RecordDB: a C++ vector of 'n' random records
RecordDB *random_vector(int n)
{
  RecordDB *db = new RecordDB();

  // initialize array with random records
  for (int i = 0; i < n; ++i) {
    db->push_back(random_record());
  } 
  return db;
}

// deallocates (destroys) a dynamically allocated RecordDB
void destroy_vector(RecordDB *db)
{
  delete db;
}

// shows a C++ vector of records
void show_vector(RecordDB *db)
{
  const int n = db->size();
  for (int i = 0; i < n; ++i) {
    fprintf(stdout, "  { %4d, %12.4lf }\n", (*db)[i].key, (*db)[i].number);
  }
}

// sorts a C++ vector of Record elements by key
// @param 'n': number of Record elements
// @param 'db': vector of records (database)
// ordena un arreglo de registros por clave
void sort_vector(RecordDB *db)
{
  // note how we need to dereference db to use the [] notation
  const int n = db->size();
  for (int i = 0; i < n; ++i) {
    int minidx = i;
    int minkey = (*db)[minidx].key;
    for (int j = i + 1; j < n; ++j) {
      if ((*db)[j].key < minkey) {
        minidx = j;
        minkey = (*db)[minidx].key;
      }
    }
    Record tmp = (*db)[i];
    (*db)[i] = (*db)[minidx];
    (*db)[minidx] = tmp;
  }
}

const int NR = 7;

int main()
{
  // timestamp used as seed for the random number generator
  time_t timestamp = time(0);

  // Naked array test
  {
    srand(timestamp);
    fprintf(stdout, "NAKED C ARRAY\n");
    Record *rec = random_naked_array(NR);
    show_naked_array(NR, rec);
    sort_naked_array(NR, rec);
    fprintf(stdout, "sorted:\n");
    show_naked_array(NR, rec);
    destroy_naked_array(rec);
  }

  // C++ vector test
  {
    srand(timestamp); // to (re)produce the same random data
    fprintf(stdout, "C++ VECTOR\n");
    RecordDB *db = random_vector(NR);
    show_vector(db);
    sort_vector(db);
    fprintf(stdout, "sorted:\n");
    show_vector(db);
    destroy_vector(db);
  }

  fprintf(stdout, "Hasta la vista ...\n");
  return 0;
}
