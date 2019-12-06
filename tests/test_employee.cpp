#include "employee_methods.h"
#include "list_index_out_of_bounds_exception.h"

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

    SECTION("insert works correctly") {
        EmployeeList list;
        Employee john = {"J. Doe", "Google Inc.", {"+380", "675182945"}, 100};
        Employee michael = {"M. Jordan", "Yahoo Inc.", {"+4", "675182945"}, 300};
        Employee michael1 = {"M. Jordan1", "Yahoo Inc.", {"+4", "675182945"}, 300};
        Employee michael2 = {"M. Jordan2", "Yahoo Inc.", {"+4", "675182945"}, 300};

        employeeList::insert(list, john, 0);
        employeeList::insert(list, michael, 1);
        employeeList::insert(list, michael1, 1);
        employeeList::insert(list, michael2, 0);

        REQUIRE(list.head->prev == nullptr);
        REQUIRE(list.head->data == michael2);
        REQUIRE(list.head->next->data == john);
        REQUIRE(list.head->next->prev->data == michael2);
        REQUIRE(list.head->next->next->data == michael1);
        REQUIRE(list.head->next->next->prev->data == john);
        REQUIRE(list.head->next->next->next->data == michael);
        REQUIRE(list.head->next->next->next->prev->data == michael1);
        REQUIRE(list.head->next->next->next->next == nullptr);

        employeeList::destruct(list);
    }

    SECTION("sortByPhone works correctly") {
        EmployeeList list;
        Employee john = {"J. Doe", "Google Inc.", {"+380", "675182945"}, 100};
        Employee michael = {"M. Jordan", "Yahoo Inc.", {"+4", "675182945"}, 300};
        Employee michael1 = {"M. Jordan1", "Yahoo Inc.", {"+4", "875182945"}, 300};
        Employee michael2 = {"M. Jordan2", "Yahoo Inc.", {"+4", "775182945"}, 300};

        employeeList::insert(list, john, 0);
        employeeList::insert(list, michael, 1);
        employeeList::insert(list, michael1, 1);
        employeeList::insert(list, michael2, 0);

        employeeList::sortByPhone(list);

        REQUIRE(list.head->prev == nullptr);
        REQUIRE(list.head->data == john);
        REQUIRE(list.head->next->data == michael);
        REQUIRE(list.head->next->prev->data == john);
        REQUIRE(list.head->next->next->data == michael2);
        REQUIRE(list.head->next->next->prev->data == michael);
        REQUIRE(list.head->next->next->next->data == michael1);
        REQUIRE(list.head->next->next->next->prev->data == michael2);
        REQUIRE(list.head->next->next->next->next == nullptr);

        employeeList::destruct(list);
    }

    SECTION("insert throws error on invalid data") {
        EmployeeList list;
        Employee john = {"J. Doe", "Google Inc.", {"+380", "675182945"}, 100};
        Employee michael = {"M. Jordan", "Yahoo Inc.", {"+4", "675182945"}, 300};
        Employee michael1 = {"M. Jordan1", "Yahoo Inc.", {"+4", "675182945"}, 300};
        Employee michael2 = {"M. Jordan2", "Yahoo Inc.", {"+4", "675182945"}, 300};

        REQUIRE_THROWS_AS(employeeList::insert(list, michael1, 1), ListIndexOutOfBoundsException);

        employeeList::insert(list, john, 0);
        employeeList::insert(list, michael, 1);
        employeeList::insert(list, michael1, 1);

        REQUIRE_THROWS_AS(employeeList::insert(list, michael1, 4), ListIndexOutOfBoundsException);

        employeeList::insert(list, michael2, 0);

        REQUIRE_THROWS_AS(employeeList::insert(list, michael1, -1), ListIndexOutOfBoundsException);     

        REQUIRE(list.head->data == michael2);
        REQUIRE(list.head->next->data == john);
        REQUIRE(list.head->next->next->data == michael1);
        REQUIRE(list.head->next->next->next->data == michael);
        REQUIRE(list.head->next->next->next->next == nullptr);

        employeeList::destruct(list);
    }
}