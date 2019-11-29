#include <sstream>

#include "double.h"

using namespace lr5;

bool Double::operator==(const Double &other) const {
    return abs(*this - other).value < EPSILON;
}

Double Double::operator-(const Double &other) const {
    return {value - other.value};
}

Double Double::operator-() const {
    return {-this->value};
}

Double Double::operator+(const Double &other) const {
    return {value + other.value};
}

Double Double::operator*(const Double &other) const {
    return {value * other.value};
}

Double Double::operator^(const Double &exponent) const {
    return {pow(value, exponent.value)};
}

Double Double::operator/(const Double &other) const {
    return {value / other.value};
}

Double lr5::abs(const Double &num) {
    return {fabs(num.value)};
}

std::istream &lr5::operator>>(std::istream &stream, Double &num) {
    stream >> num.value;
    return stream;
}

std::ostream &lr5::operator<<(std::ostream &stream, const Double &num) {
    stream << num.value;
    return stream;
}
