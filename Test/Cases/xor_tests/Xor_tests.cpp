#ifndef XOR_H
#define XOR_H

#include <gtest/gtest.h>
#include <string>

#include "Calculator.h"
// Created by bolo on 18.01.25.
//

class Xor {
public:
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult) {
        Calculator test(expression);
        if (test.result == expectedResult)
            return testing::AssertionSuccess();
        else
            return testing::AssertionFailure() << "Oczekiwany wynik: " << expectedResult << ", ale otrzymano: " << test.result;
    }
};

#define XOR_TEST_TRUE(name, expression, expected) \
TEST(XorTests, name) {                   \
Xor xorTest;                        \
EXPECT_TRUE(xorTest.performTest(expression, expected)); \
}

#define XOR_TEST_FALSE(name, expression, expected) \
TEST(XorTests, name) {                   \
Xor xorTest;                        \
EXPECT_FALSE(xorTest.performTest(expression, expected)); \
}

// True cases
XOR_TEST_TRUE(XorTrueXorFalse_ExpectedTrue, "1^0", "1")
XOR_TEST_TRUE(XorFalseXorTrue_ExpectedTrue, "0^1", "1")
XOR_TEST_TRUE(XorBothTrue_ExpectedFalse, "1^1", "0")
XOR_TEST_TRUE(XorBothFalse_ExpectedFalse, "0^0", "0")
XOR_TEST_TRUE(XorPositiveXorPositive_ExpectedTrue, "5^3", "6")
XOR_TEST_TRUE(XorPositiveXorZero_ExpectedTrue, "5^0", "5")
XOR_TEST_TRUE(XorNegativeXorPositive_ExpectedTrue, "-5^3", "-8")
XOR_TEST_TRUE(XorNegativeXorNegative_ExpectedTrue, "-5^-3", "6")
XOR_TEST_TRUE(XorZeroXorNegative_ExpectedTrue, "0^-5", "-5")


// False cases
XOR_TEST_FALSE(XorTrueXorFalse_ExpectedFalse, "1^0", "0")
XOR_TEST_FALSE(XorFalseXorTrue_ExpectedFalse, "0^1", "0")
XOR_TEST_FALSE(XorBothTrue_ExpectedTrue, "1^1", "1")
XOR_TEST_FALSE(XorBothFalse_ExpectedTrue, "0^0", "1")
XOR_TEST_FALSE(XorPositiveXorPositive_ExpectedFalse, "5^3", "0")
XOR_TEST_FALSE(XorPositiveXorZero_ExpectedFalse, "5^0", "0")
XOR_TEST_FALSE(XorNegativeXorPositive_ExpectedFalse, "-5^3", "0")
XOR_TEST_FALSE(XorNegativeXorNegative_ExpectedFalse, "-5^-3", "0")
XOR_TEST_FALSE(XorZeroXorNegative_ExpectedFalse, "0^-5", "0")
XOR_TEST_FALSE(XorLargeNumbers_ExpectedFalse, "1000000^500000", "0")

#endif // XOR_H