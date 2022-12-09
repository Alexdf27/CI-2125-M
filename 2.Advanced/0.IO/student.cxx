///
/// Student.cxx
///

#include "student.h"
#include "prng32.h"

#include <cstdio>
#include <cstring>
#include <vector>

using std::string;

#define OLD_WAY false

#if OLD_WAY
Student students[] = {
  { 0x000040FA, "16-28376", "Athina Markopoulou", 3.69 },
  { 0x000020AF, "17-29114", "Barbara Carminati", 4.07 },
  { 0x0000608A, "18-29887", "Kaoutar El Maghraoui", 3.88 },
  { 0x00006196, "18-29891", "Panagiotis Papadimitratos", 4.24 },
  { 0x000020AF, "18-29929", "Ke Yi", 4.28 },
  { 0x000010CC, "19-33836", "Margaret Hamilton", 4.16 }
};
#else
Student students[] = {
  Student(0x000040FA, "16-28376", "Athina Markopoulou", 3.69),
  Student(0x000020AF, "17-29114", "Barbara Carminati", 4.07),
  Student(0x0000608A, "18-29887", "Kaoutar El Maghraoui", 3.88),
  Student(0x00006196, "18-29891", "Panagiotis Papadimitratos", 4.24),
  Student(0x000020AF, "18-29929", "Ke Yi", 4.28),
  Student(0x000010CC, "19-33836", "Margaret Hamilton", 4.16)
};
#endif

static PRNG32 prng32;

Student::Student(const char *identifier, string name, float gpa) {
  this->key = prng32.next();
  strncpy(this->identifier, identifier, sizeof(this->identifier));
  this->name = name;
  this->gpa = gpa;
}

Student::Student(uint32_t key, const char *identifier, string name, float gpa) {
  this->key = key;
  strncpy(this->identifier, identifier, sizeof(this->identifier));
  this->name = name;
  this->gpa = gpa;
}

Student::Student(const Student& other) {
  *this = other;
}

const Student& Student::operator=(const Student& rhs) {
  this->key = rhs.key;
  strncpy(identifier, rhs.identifier, sizeof(this->identifier));
  this->name = rhs.name;
  this->gpa = rhs.gpa;
  return *this;
}

//
// Pruebas Internas!
//

static void direct_test() {
  const int NS = sizeof(students) / sizeof(Student);

  fprintf(stdout, "--------------------------------\n");
  fprintf(stdout, "Generating keys implicitly:\n");
  fprintf(stdout, "--------------------------------\n");

  for (int i = 0; i < NS; ++i) {
    Student *data = &students[i];
    Student s = Student(data->identifier, data->name, data->gpa);
    fprintf(stdout, student_desc_format, s.key, s.identifier, s.name.c_str(), s.gpa);
    fprintf(stdout, "--------------------------------\n");
  }

  fprintf(stdout, "--------------------------------\n");
  fprintf(stdout, "Generating keys explicitly:\n");
  fprintf(stdout, "--------------------------------\n");

  for (int i = 0; i < NS; ++i) {
    uint32_t key = prng32.next();
    Student *data = &students[i];
    Student s = Student(key, data->identifier, data->name, data->gpa);
    fprintf(stdout, student_desc_format, s.key, s.identifier, s.name.c_str(), s.gpa);
    fprintf(stdout, "--------------------------------\n");
  }

  fprintf(stdout, "--------------------------------\n");
  fprintf(stdout, "Copying keys:\n");
  fprintf(stdout, "--------------------------------\n");

  for (int i = 0; i < NS; ++i) {
    Student *data = &students[i];
    Student s = Student(data->key, data->identifier, data->name, data->gpa);
    fprintf(stdout, student_desc_format, s.key, s.identifier, s.name.c_str(), s.gpa);
    fprintf(stdout, "--------------------------------\n");
  }
}

static void file_test() {
  const int NS = sizeof(students) / sizeof(Student);
  
  fprintf(stdout, "\nSHORT FORMAT:\n");
  for (int i = 0; i < NS; ++i) {
    Student *s = &students[i];
    fprintf(stdout, student_short_format, s->identifier, s->name.c_str());
  }

  fprintf(stdout, "================================\n");
  fprintf(stdout, "\nLONG FORMAT:\n");
  for (int i = 0; i < NS; ++i) {
    Student *s = &students[i];
    fprintf(stdout, student_long_format, s->key, s->identifier, s->name.c_str(), s->gpa);
  }

  fprintf(stdout, "================================\n");
  fprintf(stdout, "\nDESCRIPTIVE FORMAT:\n");
  for (int i = 0; i < NS; ++i) {
    Student *s = &students[i];
    fprintf(stdout, student_desc_format, s->key, s->identifier, s->name.c_str(), s->gpa);
    fprintf(stdout, "--------------------------------\n");
  }

  FILE *db = fopen("small.db", "w");
  for (int i = 0; i < NS; ++i) {
    Student *s = &students[i];
    fprintf(db, student_long_format, s->key, s->identifier, s->name.c_str(), s->gpa);
  }
  fclose(db);
}

void test_student_module() {
  direct_test();
  file_test();
}
