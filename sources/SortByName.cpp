// Copyright 2022 Sushin Ivan <i.suschin@yandex.ru>
#include "header.hpp"

bool pred(const Student& student1, const Student& student2) {
  return student1.Name < student2.Name;
}
void SortByName(std::vector<Student>& students) {
  std::sort(students.begin(), students.end(), pred);
}
