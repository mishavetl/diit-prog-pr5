#pragma once

#include "phone_number.h"

namespace lr5 {
	namespace phoneNumber {
		std::string getNumber(const PhoneNumber &phone);
	}
}

bool operator<(const lr5::PhoneNumber &left, const lr5::PhoneNumber &right);
bool operator==(const lr5::PhoneNumber &left, const lr5::PhoneNumber &right);

// std::istream &operator>>(std::istream &stream, lr5::PhoneNumber &employee);
// std::ostream &operator<<(std::ostream &stream, const lr5::PhoneNumber &employee);