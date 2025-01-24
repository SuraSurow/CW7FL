#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <gtest/gtest.h>
#include <string>

#include "Calculator.h"
// Created by bolo on 18.01.25.
//

class Multiplication {
public:
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult) {
        Calculator test(expression);
        if (test.result == expectedResult)
            return testing::AssertionSuccess();
        else
            return testing::AssertionFailure() << "Oczekiwany wynik: " << expectedResult << ", ale otrzymano: " << test.result;
    }
};

#define MULTIPLICATION_TEST_TRUE(name, expression, expected) \
TEST(MultiplicationTests, name) {                   \
Multiplication multiplication;                        \
EXPECT_TRUE(multiplication.performTest(expression, expected)); \
}

#define MULTIPLICATION_TEST_FALSE(name, expression, expected) \
TEST(MultiplicationTests, name) {                   \
Multiplication multiplication;                        \
EXPECT_FALSE(multiplication.performTest(expression, expected)); \
}

MULTIPLICATION_TEST_TRUE(MultiplicationPositiveWithPositive_ExpectedTrue, "5*3", "15")
MULTIPLICATION_TEST_TRUE(MultiplicationPositiveWithNegative_ExpectedTrue, "5*(-3)", "-15")
MULTIPLICATION_TEST_TRUE(MultiplicationNegativeWithPositive_ExpectedTrue, "(-5)*3", "-15")
MULTIPLICATION_TEST_TRUE(MultiplicationNegativeWithNegative_ExpectedTrue, "(-5)*(-3)", "15")
MULTIPLICATION_TEST_TRUE(MultiplicationZeroWithPositive_ExpectedTrue, "0*5", "0")
MULTIPLICATION_TEST_TRUE(MultiplicationZeroWithNegative_ExpectedTrue, "0*(-5)", "0")
MULTIPLICATION_TEST_TRUE(MultiplicationPositiveWithZero_ExpectedTrue, "5*0", "0")
MULTIPLICATION_TEST_TRUE(MultiplicationNegativeWithZero_ExpectedTrue, "(-5)*0", "0")
MULTIPLICATION_TEST_TRUE(MultiplicationZeroWithZero_ExpectedTrue, "0*0", "0")
MULTIPLICATION_TEST_TRUE(MultiplicationOneWithPositive_ExpectedTrue, "1*5", "5")
MULTIPLICATION_TEST_TRUE(MultiplicationPositiveWithOne_ExpectedTrue, "5*1", "5")
MULTIPLICATION_TEST_TRUE(MultiplicationNegativeWithOne_ExpectedTrue, "(-5)*1", "-5")
MULTIPLICATION_TEST_TRUE(MultiplicationOneWithNegative_ExpectedTrue, "1*(-5)", "-5")
MULTIPLICATION_TEST_TRUE(MultiplicationLargeNumbers_ExpectedTrue, "1000*1000", "1000000")
MULTIPLICATION_TEST_TRUE(MultiplicationDecimalWithInteger_ExpectedTrue, "25*4", "100")
MULTIPLICATION_TEST_TRUE(MultiplicationIntegerWithDecimal_ExpectedTrue, "4*25", "100")


MULTIPLICATION_TEST_FALSE(MultiplicationPositiveWithPositive_ExpectedFalse, "5*3", "14")
MULTIPLICATION_TEST_FALSE(MultiplicationPositiveWithNegative_ExpectedFalse, "5*(-3)", "-14")
MULTIPLICATION_TEST_FALSE(MultiplicationNegativeWithPositive_ExpectedFalse, "(-5)*3", "-14")
MULTIPLICATION_TEST_FALSE(MultiplicationNegativeWithNegative_ExpectedFalse, "(-5)*(-3)", "14")
MULTIPLICATION_TEST_FALSE(MultiplicationZeroWithPositive_ExpectedFalse, "0*5", "5")
MULTIPLICATION_TEST_FALSE(MultiplicationZeroWithNegative_ExpectedFalse, "0*(-5)", "-5")
MULTIPLICATION_TEST_FALSE(MultiplicationPositiveWithZero_ExpectedFalse, "5*0", "5")
MULTIPLICATION_TEST_FALSE(MultiplicationNegativeWithZero_ExpectedFalse, "(-5)*0", "-5")
MULTIPLICATION_TEST_FALSE(MultiplicationZeroWithZero_ExpectedFalse, "0*0", "1")
MULTIPLICATION_TEST_FALSE(MultiplicationOneWithPositive_ExpectedFalse, "1*5", "6")
MULTIPLICATION_TEST_FALSE(MultiplicationPositiveWithOne_ExpectedFalse, "5*1", "6")
MULTIPLICATION_TEST_FALSE(MultiplicationNegativeWithOne_ExpectedFalse, "(-5)*1", "-6")
MULTIPLICATION_TEST_FALSE(MultiplicationOneWithNegative_ExpectedFalse, "1*(-5)", "-6")
MULTIPLICATION_TEST_FALSE(MultiplicationLargeNumbers_ExpectedFalse, "1000*1000", "999999")


#endif // MULTIPLICATION_H