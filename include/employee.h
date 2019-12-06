#pragma once

#include <string>

#include "phone_number.h"
#include "double.h"

namespace lr5 {
    struct Employee {
        std::string name = "";
        std::string companyName = "";
        PhoneNumber phone;

        Double salary = 0;
    };

    struct EmployeeNode {
        Employee data;
        EmployeeNode *prev = nullptr;
        EmployeeNode *next = nullptr;
    };

    struct EmployeeList {
        EmployeeNode *head = nullptr;
        int length = 0;
    };
}
