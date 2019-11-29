#include "employee_methods.h"
#include "phone_number_methods.h"

bool operator<(const lr5::Employee &left, const lr5::Employee &right) {
	return left.phone < right.phone;
}
