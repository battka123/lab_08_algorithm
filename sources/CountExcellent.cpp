// Copyright 2022 Sushin Ivan <i.suschin@yandex.ru>
#include "header.hpp"
bool pred(Student student) {
  if (student.Ratings.empty()) {
    return false;
  }
  return std::equal(student.Ratings.begin() + 1, student.Ratings.end(),
                    student.Ratings.begin());
}
size_t CountExcellent(const std::vector<Student>& students) {
  return std::count_if(students.begin(), students.end(), pred);
}
