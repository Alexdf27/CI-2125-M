///
/// student.h
///

#pragma once

#include <string>

struct Student {
  Student(const char *identifier, std::string name, float gpa);
  Student(uint32_t key, const char *identifier, std::string name, float gpa);
  Student(const Student& other);
  const Student& operator=(const Student& rhs);

  uint32_t key;
  char identifier[9];
  std::string name;
  float gpa;
};

// short format: student identifier and name
static const char *student_short_format = "%s %s %f\n";

// long format: all fields, one line
static const char *student_long_format = "0x%08x|%s|%s|%f\n";

// descriptive format: all fields, one field per line
static const char *student_desc_format = "key:\t0x%08x\nid:\t%s\nname:\t%s\ngpa:\t%4.2f\n";

void test_student_module();
