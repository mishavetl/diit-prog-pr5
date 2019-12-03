#include "employee_methods.h"
#include "catch.hpp"

using namespace lr5;

TEST_CASE("EmployeeList's behaviour is valid", "[employeeList]") {
    SECTION("destruct runs without errors") {
        EmployeeList list;
        employeeList::destruct(list);
        employeeList::destruct(list);

        REQUIRE(list.head == nullptr);

        EmployeeList list1;
        list1.head = new EmployeeNode();
        list1.head->next = new EmployeeNode();
        employeeList::destruct(list1);
        employeeList::destruct(list1);

        REQUIRE(list1.head == nullptr);
    }

    SECTION("get works correctly") {
        EmployeeList list;

        // TODO

        employeeList::destruct(list);
    }

    SECTION("insert works correctly") {
        EmployeeList list;
        Employee john = {"J. Doe", "Google Inc.", {"+380", "675182945"}, 100};
        Employee michael = {"M. Jordan", "Yahoo Inc.", {"+4", "675182945"}, 300};

        employeeList::insert(list, john, 0);
        employeeList::insert(list, michael, 0);

        REQUIRE(list.head->data == john);
        REQUIRE(list.head->next->data == michael);
        REQUIRE(list.head->next->next == nullptr);

        employeeList::destruct(list);
    }
}