#pragma once

#include <string>

#include "phone_number.h"
#include "double.h"

namespace lr5 {
    struct Employee {
        std::string name;
        std::string companyName;
        PhoneNumber phone;

        Double salary;
    };

    struct EmployeeList {
        Employee *next = nullptr;
        int length = 0;
    };
}
