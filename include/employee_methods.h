#pragma once

#include "employee.h"

namespace lr5 {
	namespace employeeList {
        void destruct(EmployeeList &list);
    }
}

bool operator<(const lr5::Employee &left, const lr5::Employee &right);

std::istream &operator>>(std::istream &stream, lr5::Employee &employee);
std::ostream &operator<<(std::ostream &stream, const lr5::Employee &employee);

std::istream &operator>>(std::istream &stream, lr5::EmployeeList &employee);
std::ostream &operator<<(std::ostream &stream, const lr5::EmployeeList &employee);