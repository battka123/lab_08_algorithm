// Copyright 2022 Sushin Ivan <i.suschin@yandex.ru>
#include "header.hpp"

std::vector<Group> Groups(const std::vector<Student>& students) {
  std::vector<Group> groups;
  std::vector<std::string> unic_groups = GroupsId(students);

  for (const auto& group : unic_groups) {
    std::vector<Student> buf_group;
    for (const auto& student : students) {
      if (group == student.GroupId) {
        buf_group.push_back(student);
      }
    }
    Group group1;
    group1.Id = group;
    group1.Students = buf_group;
    groups.push_back(group1);
  }
  return groups;
}
