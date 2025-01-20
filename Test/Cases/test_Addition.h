#ifndef ADDITION_H
#define ADDITION_H

#include <gtest/gtest.h>
#include <string>


#include "CW7FL/Calculator.h"
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


#define ADDITION_TEST(name, expression, expected) \
TEST(AdditionTests, name) {                   \
Addition addition;                        \
EXPECT_TRUE(addition.performTest(expression, expected)); \
}

ADDITION_TEST(AdditionMinusNumberToMinusNumber, "(-23)+(-5)", "-28")
ADDITION_TEST(AdditionMinusNumberToPlusNumber, "23+(-5)", "18")
ADDITION_TEST(AdditionPlusNumberToPlusNumber, "23+5", "28")
ADDITION_TEST(AdditionZeroToMinusNumber, "0+(-5)", "-5")
ADDITION_TEST(AdditionZeroToPlusNumber, "0+5", "5")
ADDITION_TEST(AdditionZeroToZero, "0+0", "0")


#endif // ADDITION_H

