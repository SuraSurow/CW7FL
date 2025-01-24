#ifndef MODULO_H
#define MODULO_H

#include <gtest/gtest.h>
#include <string>

#include "Calculator.h"
// Created by bolo on 18.01.25.
//

class Modulo {
public:
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult) {
        Calculator test(expression);
        if (test.result == expectedResult)
            return testing::AssertionSuccess();
        else
            return testing::AssertionFailure() << "Oczekiwany wynik: " << expectedResult << ", ale otrzymano: " << test.result;
    }
};

#define MODULO_TEST_TRUE(name, expression, expected) \
TEST(ModuloTests_True, name) {                   \
Modulo modulo;                        \
EXPECT_TRUE(modulo.performTest(expression, expected)); \
}

#define MODULO_TEST_FALSE(name, expression, expected) \
TEST(ModuloTests_False, name) {                   \
Modulo modulo;                        \
EXPECT_FALSE(modulo.performTest(expression, expected)); \
}

MODULO_TEST_TRUE(PositiveByPositive, "10%3", "1")
MODULO_TEST_TRUE(PositiveByNegative, "10%(-3)", "1")
MODULO_TEST_TRUE(NegativeByPositive, "(-10)%3", "-1")
MODULO_TEST_TRUE(NegativeByNegative, "(-10)%(-3)", "-1")
MODULO_TEST_TRUE(PositiveByOne, "10%1", "0")
MODULO_TEST_TRUE(NegativeByOne, "(-10)%1", "0")
MODULO_TEST_TRUE(ZeroByPositive, "0%3", "0")
MODULO_TEST_TRUE(ZeroByNegative, "0%(-3)", "0")
MODULO_TEST_TRUE(LargeNumbers, "1000000007%100", "7")

MODULO_TEST_FALSE(PositiveByPositive, "10%3", "2")
MODULO_TEST_FALSE(PositiveByNegative, "10%(-3)", "2")
MODULO_TEST_FALSE(NegativeByPositive, "(-10)%3", "1")
MODULO_TEST_FALSE(NegativeByNegative, "(-10)%(-3)", "1")
MODULO_TEST_FALSE(PositiveByOne, "10%1", "1")
MODULO_TEST_FALSE(NegativeByOne, "(-10)%1", "1")
MODULO_TEST_FALSE(ZeroByPositive, "0%3", "3")
MODULO_TEST_FALSE(ZeroByNegative, "0%(-3)", "-3")
MODULO_TEST_FALSE(LargeNumbers, "1000000007%100", "6")

#endif // MODULO_H

