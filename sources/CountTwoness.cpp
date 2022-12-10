// Copyright 2022 Sushin Ivan <i.suschin@yandex.ru>
#include "header.hpp"

bool pred(const Student& students) {
  return std::find(students.Ratings.begin(), students.Ratings.end(), 2) !=
         students.Ratings.end();
}

size_t CountTwoness(const std::vector<Student>& students) {
  return std::count_if(students.begin(), students.end(), pred);
}
