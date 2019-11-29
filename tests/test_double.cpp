#include "double.h"
#include "catch.hpp"

using namespace lr5;

TEST_CASE("Double wrapper's behaviour is valid", "[double]") {
    SECTION("constructor works correctly") {
        Double num = 15.283;
        REQUIRE(num.value == Approx(15.283));
    }

    SECTION("'==' operator works correctly") {
        REQUIRE(Double(0) == Double(0));
        REQUIRE(Double(0.0) == Double(0));
        REQUIRE_FALSE(Double(0.01) == Double(0));
        REQUIRE_FALSE(Double(1) == Double(0));
        REQUIRE(Double(18732.1) == Double(18732.1));
        REQUIRE(Double(18732) == Double(18732));
    }

    SECTION("subtraction works correctly") {
        Double num1 = 123.3;
        Double num2 = 51.51;
        REQUIRE(num1 - num2 == Double(71.79));
    }

    SECTION("unary '-' operator works correctly") {
        Double num1 = 123.3;
        REQUIRE(-num1 == Double(-123.3));
    }

    SECTION("addition works correctly") {
        Double num1 = 123.3;
        Double num2 = 51.51;
        REQUIRE(num1 + num2 == Double(174.81));
    }

    SECTION("abs works correctly") {
        Double num1 = -892.1;
        REQUIRE(abs(num1) == Double(892.1));
    }

    SECTION("multiplication works correctly") {
        Double num1 = 12.3;
        Double num2 = 2;
        REQUIRE(num1 * num2 == Double(24.6));
    }

    SECTION("division works correctly") {
        Double num1 = 12.3;
        Double num2 = 2;
        REQUIRE(num1 / num2 == Double(6.15));
    }

    SECTION("double exponentiation works correctly") {
        Double num1 = 16;
        Double num2 = 0.5;
        REQUIRE((num1 ^ num2) == Double(4));
    }

    SECTION("integer exponentiation works correctly") {
        Double num1 = 12.3;
        Double num2 = 2;
        REQUIRE((num1 ^ num2) == Double(151.29));
    }
}