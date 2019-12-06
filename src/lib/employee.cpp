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
			prev->prev = list.head;
		}
	} else {
		for (int i = 1; i < index; ++i) {
			prev = prev->next;
		}
		if (prev->next) {
			node->next = prev->next;
			node->next->prev = node;
		}
		prev->next = node;
		node->prev = prev;
	}

	++list.length;

	return node;
}

void lr5::employeeList::sortByPhone(lr5::EmployeeList &list) {
	using namespace lr5;
	EmployeeNode *node1 = list.head;
    while (node1) {
        EmployeeNode *node2 = node1->next;
        while (node2) {
            if (node2->data.phone < node1->data.phone) {
                EmployeeNode *t = node1->next;
                node1->next = node2->next;
                node2->next = t;

                t = node1->prev;
                node1->prev = node2->prev;
                node2->prev = t;

                if (node1->prev == node1) {
                    node1->prev = node2;
                }

                if (node2->next == node2) {
                    node2->next = node1;
                }

                if (node2->next) {
                    node2->next->prev = node2;
                }

                if (node1->next) {
                    node1->next->prev = node1;
                }

                if (node2->prev) {
                    node2->prev->next = node2;
                }

                if (node1->prev) {
                    node1->prev->next = node1;
                }

                if (node1 == list.head) {
                	list.head = node2;
                }

                t = node1;
                node1 = node2;
                node2 = t;
            }
            node2 = node2->next;
        }
        node1 = node1->next;
    }
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
