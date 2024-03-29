#include "phone_number_methods.h"

std::string lr5::phoneNumber::getNumber(const PhoneNumber &phone) {
	return phone.code + phone.number;
}

bool operator<(const lr5::PhoneNumber &left, const lr5::PhoneNumber &right) {
	using namespace lr5::phoneNumber;
	return getNumber(left) < getNumber(right);
}

bool operator==(const lr5::PhoneNumber &left, const lr5::PhoneNumber &right) {
	using namespace lr5::phoneNumber;
	return getNumber(left) == getNumber(right);
}

std::istream &operator>>(std::istream &stream, lr5::PhoneNumber &phoneNumber) {
	stream >> phoneNumber.code >> phoneNumber.number;
	return stream;
}

std::ostream &operator<<(std::ostream &stream, const lr5::PhoneNumber &phoneNumber) {
	stream << lr5::phoneNumber::getNumber(phoneNumber);
	return stream;
}