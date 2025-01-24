#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include <gtest/gtest.h>
#include <string>

#include "Calculator.h"
// Created by bolo on 18.01.25.
//

class Subtraction {
public:
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult) {
        Calculator test(expression);
        if (test.result == expectedResult)
            return testing::AssertionSuccess();
        else
            return testing::AssertionFailure() << "Oczekiwany wynik: " << expectedResult << ", ale otrzymano: " << test.result;
    }
};

#define SUBTRACTION_TEST_TRUE(name, expression, expected) \
TEST(SubtractionTests, name) {                   \
Subtraction subtraction;                        \
EXPECT_TRUE(subtraction.performTest(expression, expected)); \
}

#define SUBTRACTION_TEST_FALSE(name, expression, expected) \
TEST(SubtractionTests, name) {                   \
Subtraction subtraction;                        \
EXPECT_FALSE(subtraction.performTest(expression, expected)); \
}

SUBTRACTION_TEST_TRUE(SubtractionPositiveFromPositive_ExpectedTrue, "5-3", "2")
SUBTRACTION_TEST_TRUE(SubtractionNegativeFromPositive_ExpectedTrue, "5-(-3)", "8")
SUBTRACTION_TEST_TRUE(SubtractionPositiveFromNegative_ExpectedTrue, "(-5)-3", "-8")
SUBTRACTION_TEST_TRUE(SubtractionNegativeFromNegative_ExpectedTrue, "(-5)-(-3)", "-2")
SUBTRACTION_TEST_TRUE(SubtractionZeroFromPositive_ExpectedTrue, "5-0", "5")
SUBTRACTION_TEST_TRUE(SubtractionZeroFromNegative_ExpectedTrue, "(-5)-0", "-5")
SUBTRACTION_TEST_TRUE(SubtractionPositiveFromZero_ExpectedTrue, "0-5", "-5")
SUBTRACTION_TEST_TRUE(SubtractionNegativeFromZero_ExpectedTrue, "0-(-5)", "5")
SUBTRACTION_TEST_TRUE(SubtractionZeroFromZero_ExpectedTrue, "0-0", "0")

SUBTRACTION_TEST_FALSE(SubtractionPositiveFromPositive_ExpectedFalse, "5-3", "1")
SUBTRACTION_TEST_FALSE(SubtractionNegativeFromPositive_ExpectedFalse, "5-(-3)", "7")
SUBTRACTION_TEST_FALSE(SubtractionPositiveFromNegative_ExpectedFalse, "(-5)-3", "-7")
SUBTRACTION_TEST_FALSE(SubtractionNegativeFromNegative_ExpectedFalse, "(-5)-(-3)", "-3")
SUBTRACTION_TEST_FALSE(SubtractionZeroFromPositive_ExpectedFalse, "5-0", "4")
SUBTRACTION_TEST_FALSE(SubtractionZeroFromNegative_ExpectedFalse, "(-5)-0", "-4")
SUBTRACTION_TEST_FALSE(SubtractionPositiveFromZero_ExpectedFalse, "0-5", "-4")
SUBTRACTION_TEST_FALSE(SubtractionNegativeFromZero_ExpectedFalse, "0-(-5)", "4")
SUBTRACTION_TEST_FALSE(SubtractionZeroFromZero_ExpectedFalse, "0-0", "1")

#endif // SUBTRACTION_H