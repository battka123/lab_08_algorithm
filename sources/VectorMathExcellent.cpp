// Copyright 2022 Sushin Ivan <i.suschin@yandex.ru>
#include "header.hpp"
std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
  std::vector<Student> students_exellent;
  for (const auto& student : students) {
    for (size_t i = 0; i < student.Subjects.size(); ++i) {
      if (student.Subjects[i] == "Math") {
        if (student.Ratings[i] == 5) {
          students_exellent.push_back(student);
        }
        break;
      }
    }
  }
  return students_exellent;
}
