#include "config.h"
#include "employee_methods.h"
#include "phone_number_methods.h"
#include "list_index_out_of_bounds_exception.h"

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

 	if (index > list.length || index < 0) {
		throw ListIndexOutOfBoundsException();
	}

	EmployeeNode *node = new EmployeeNode{employee};
	EmployeeNode *prev = list.head;

	if (index == 0) {
		list.head = node;
		if (prev) {
			list.head->next = prev;
		}
	} else {
		for (int i = 1; i < index; ++i) {
			prev = prev->next;
		}
		if (prev->next) {
			node->next = prev->next;
		}
		prev->next = node;
	}

	++list.length;

	return node;
}

bool operator<(const lr5::Employee &left, const lr5::Employee &right) {
	return left.phone < right.phone;
}

bool operator==(const lr5::Employee &left, const lr5::Employee &right) {
	return left.name == right.name && left.companyName == right.companyName
		&& left.phone == right.phone && left.salary == right.salary;
}

std::istream &operator>>(std::istream &stream, lr5::Employee &employee) {
	getline(stream, employee.name); 
	getline(stream, employee.companyName);
	stream >> employee.salary;
	stream >> employee.phone;
	return stream;
}

std::ostream &operator<<(std::ostream &stream, const lr5::Employee &employee) {
	using namespace lr5;
	stream.width(NAME_COLUMN_WIDTH);
	stream << std::left << employee.name;
	stream.width(COMPANY_NAME_COLUMN_WIDTH);
	stream << std::left << employee.companyName;
	stream.width(SALARY_COLUMN_WIDTH);
	stream << std::left << employee.salary;
	stream.width(PHONE_NUMBER_COLUMN_WIDTH);
	stream << std::left << employee.phone;
	return stream;
}

std::ostream &operator<<(std::ostream &stream, const lr5::EmployeeList &employeeList) {
	using namespace lr5;
	stream.width(NAME_COLUMN_WIDTH);
	stream << std::left << "Name";
	stream.width(COMPANY_NAME_COLUMN_WIDTH);
	stream << std::left << "Company Name";
	stream.width(SALARY_COLUMN_WIDTH);
	stream << std::left << "Salary";
	stream.width(PHONE_NUMBER_COLUMN_WIDTH);
	stream << std::left << "Phone number";
	stream << std::endl;

	EmployeeNode *cur = employeeList.head;

	while (cur) {
		stream << cur->data << std::endl;
		cur = cur->next;
	}

	return stream;
}
