#pragma once

#include "employee.h"

namespace lr5 {
	namespace employeeList {
        void destruct(EmployeeList &list);
        EmployeeNode *insert(EmployeeList &list, Employee &employee, int index = 0);
        void sortByPhone(lr5::EmployeeList &list);
    }
}

bool operator<(const lr5::Employee &left, const lr5::Employee &right);
bool operator==(const lr5::Employee &left, const lr5::Employee &right);

std::istream &operator>>(std::istream &stream, lr5::Employee &employee);
std::ostream &operator<<(std::ostream &stream, const lr5::Employee &employee);

std::ostream &operator<<(std::ostream &stream, const lr5::EmployeeList &employee);