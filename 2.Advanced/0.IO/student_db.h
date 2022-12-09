///
/// student_db.h
///
/// Base de datos en memoria
///

#pragma once

#include "student.h"
#include <vector>

typedef std::vector<Student> StudentDB;

StudentDB *create_student_db();

int load_student_db(StudentDB *db, const char *filename);

Student get(StudentDB *db, int i);

int find_student(StudentDB *db, uint32_t key);

int find_student_by_id(StudentDB *db, const char *id);

int find_student_by_name(StudentDB *db, const char *id);

int add_student(StudentDB *db, Student student);

void update_student(StudentDB *db, int i, Student student);

void remove_student(StudentDB *db, int i);

void sort_student_db(StudentDB *db);

void sort_student_db_by_id(StudentDB *db);

void sort_student_db_by_name(StudentDB *db);

int save_student_db(StudentDB *db, const char *filename);

void delete_student_db(StudentDB *db);
