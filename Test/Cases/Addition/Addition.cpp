#ifndef ADDITION_H
#define ADDITION_H

#include <gtest/gtest.h>
#include <string>


#include "Calculator.h"
// Created by bolo on 18.01.25.
//


class Addition {
public:
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult)  {
        Calculator test(expression);
        if (test.result == expectedResult)
            return testing::AssertionSuccess();
        else
            return testing::AssertionFailure() << "Oczekiwany wynik: " << expectedResult << ", ale otrzymano: " << test.result;
    }
};


#define ADDITION_TEST_TRUE(name, expression, expected) \
TEST(AdditionTests, name) {                   \
Addition addition;                        \
EXPECT_TRUE(addition.performTest(expression, expected)); \
}


#define ADDITION_TEST_FALSE(name, expression, expected) \
TEST(AdditionTests, name) {                   \
Addition addition;                        \
EXPECT_FALSE(addition.performTest(expression, expected)); \
}


ADDITION_TEST_TRUE(AdditionMinusNumberToMinusNumber_ExpectedTrue, "(-23)+(-5)", "-28")
ADDITION_TEST_TRUE(AdditionMinusNumberToPlusNumber_ExpectedTrue, "23+(-5)", "18")
ADDITION_TEST_TRUE(AdditionPlusNumberToPlusNumber_ExpectedTrue, "23+5", "28")
ADDITION_TEST_TRUE(AdditionZeroToMinusNumber_ExpectedTrue, "0+(-5)", "-5")
ADDITION_TEST_TRUE(AdditionZeroToPlusNumber_ExpectedTrue, "0+5", "5")
ADDITION_TEST_TRUE(AdditionZeroToZero_ExpectedTrue, "0+0", "0")


ADDITION_TEST_FALSE(AdditionMinusNumberToMinusNumber_ExpectedFalse, "(-23)+(-5)", "-27")
ADDITION_TEST_FALSE(AdditionMinusNumberToPlusNumber_ExpectedFalse, "23+(-5)", "17")
ADDITION_TEST_FALSE(AdditionPlusNumberToPlusNumber_ExpectedFalse, "23+5", "27")
ADDITION_TEST_FALSE(AdditionZeroToMinusNumber_ExpectedFalse, "0+(-5)", "5")
ADDITION_TEST_FALSE(AdditionZeroToPlusNumber_ExpectedFalse, "0+5", "-5")
ADDITION_TEST_FALSE(AdditionZeroToZero_ExpectedFalse, "0+0", "1")


# endif ADDITION_H

