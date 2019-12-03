#include "employee_methods.h"
#include "phone_number_methods.h"

void lr5::employeeList::destruct(lr5::EmployeeList &list) {
	EmployeeNode *node = list.head;
	EmployeeNode *prev = nullptr;

	if (node == nullptr) {
		return;
	}

	do {
		if (prev) {
			delete prev;
		}
		prev = node;
	} while (node = node->next);

	delete prev;

	list.head = nullptr;
	list.length = 0;
}

lr5::EmployeeNode *lr5::employeeList::insert(lr5::EmployeeList &list, lr5::Employee &employee, int index) {
	using namespace lr5::employeeList;

	EmployeeNode *node = new EmployeeNode{employee};

	// TODO

	return node;
}

bool operator<(const lr5::Employee &left, const lr5::Employee &right) {
	return left.phone < right.phone;
}

bool operator==(const lr5::Employee &left, const lr5::Employee &right) {
	return left.name == right.name && left.companyName == right.companyName
		&& left.phone == right.phone && left.salary == right.salary;
}