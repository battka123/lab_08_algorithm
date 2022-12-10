// Copyright 2022 Sushin Ivan <i.suschin@yandex.ru>
#include "header.hpp"

std::vector<std::string> GroupsId(const std::vector<Student>& students) {
  std::vector<std::string> unic_group;
  for (const auto& student : students) {
    if (!unic_group.empty()) {
      if (std::find(unic_group.begin(), unic_group.end(), student.GroupId) ==
          unic_group.end()) {
        unic_group.push_back(student.GroupId);
      }
    } else {
      unic_group.push_back(student.GroupId);
    }
  }
  return unic_group;
}
