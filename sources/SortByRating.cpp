// Copyright 2022 Sushin Ivan <i.suschin@yandex.ru>
#include "header.hpp"
double average(const Student& student) {
  double average = 0;
  for (auto mark : student.Ratings) {
    average += mark;
  }
  average /= int(student.Ratings.size());
  return average;
}

bool pred(Student& student1, Student& student2) {
  return average(student1) > average(student2);
}

void SortByRating(std::vector<Student>& students) {
  std::sort(students.begin(), students.end(), pred);
}
