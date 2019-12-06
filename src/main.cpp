#include <iostream>

#include "employee_methods.h"
#include "phone_number_methods.h"

using namespace lr5;

int main() {
    std::string command, buffer;
    EmployeeList list;

    while (true) {
        std::cout << "? for help> ";
        getline(std::cin, command);

        std::cout << std::endl;

        if (command == "?") {
            std::cout << "1 | add employee (<employee name><Enter><company name><Enter><salary><Enter><phone number><Enter>) - add new employee to the list" << std::endl
                 << "2 | list employees - output the employee list;" << std::endl
                 << "3 | list employees with salary (<your salary><Enter>) - output the employees with specified salary" << std::endl
                 << "4 | list employees with max salary - output the employees with specified salary" << std::endl
                 << "5 | find employee (<employee name><Enter><company name><Enter><salary><Enter><phone number><Enter>) - output the employees with specified salary" << std::endl
                 << "6 | list employees sorted by phone number" << std::endl
                 << "7 | exit" << std::endl;
        } else if (command == "add employee" || command == "1") {
            Employee employee;
            std::cin >> employee;
            getline(std::cin, buffer);
            employeeList::insert(list, employee, list.length);
        } else if (command == "list employees" || command == "2") {
            std::cout << list;
        } else if (command == "list employees with salary" || command == "3") {
            Double salary = 0;
            std::cin >> salary;
            getline(std::cin, buffer);
            EmployeeList newList;
            EmployeeNode *cur = list.head;
            while (cur) {
                if (cur->data.salary == salary) {
                    employeeList::insert(newList, cur->data, newList.length);
                }
                cur = cur->next;
            }
            std::cout << newList;
            employeeList::destruct(newList);
        } else if (command == "list employees with max salary" || command == "4") {
            Double maxSalary = -1;
            EmployeeNode *cur = list.head;
            while (cur) {
                if (cur->data.salary.value > maxSalary.value) {
                    maxSalary = cur->data.salary;
                }
                cur = cur->next;
            }
            EmployeeList newList;
            cur = list.head;
            while (cur) {
                if (cur->data.salary == maxSalary) {
                    employeeList::insert(newList, cur->data, newList.length);
                }
                cur = cur->next;
            }
            std::cout << newList;
            employeeList::destruct(newList);
        } else if (command == "find employee" || command == "5") {
            Employee employee;
            std::cin >> employee;
            getline(std::cin, buffer);

            EmployeeList newList;
            EmployeeNode *cur = list.head;
            while (cur) {
                if (cur->data == employee) {
                    employeeList::insert(newList, cur->data, newList.length);
                }
                cur = cur->next;
            }
            std::cout << newList;
            employeeList::destruct(newList);
        } else if (command == "list employees sorted by phone number" || command == "6") {
            EmployeeList newList;
            EmployeeNode *cur = list.head;
            while (cur) {
                employeeList::insert(newList, cur->data, newList.length);
                cur = cur->next;
            }
            employeeList::sortByPhone(newList);
            std::cout << newList;
            employeeList::destruct(newList);
        } else if (command == "exit" || command == "7") {
            break;
        } else {
            std::cout << "Unknown command: " << command;
        }

        std::cout << std::endl;
    }

    employeeList::destruct(list);
}
