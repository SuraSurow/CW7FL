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
TEST(ModuloTests, name) {                   \
Modulo modulo;                        \
EXPECT_TRUE(modulo.performTest(expression, expected)); \
}

#define MODULO_TEST_FALSE(name, expression, expected) \
TEST(ModuloTests, name) {                   \
Modulo modulo;                        \
EXPECT_FALSE(modulo.performTest(expression, expected)); \
}

MODULO_TEST_TRUE(ModuloPositiveByPositive_ExpectedTrue, "10%3", "1")
MODULO_TEST_TRUE(ModuloPositiveByNegative_ExpectedTrue, "10%(-3)", "1")
MODULO_TEST_TRUE(ModuloNegativeByPositive_ExpectedTrue, "(-10)%3", "-1")
MODULO_TEST_TRUE(ModuloNegativeByNegative_ExpectedTrue, "(-10)%(-3)", "-1")
MODULO_TEST_TRUE(ModuloPositiveByOne_ExpectedTrue, "10%1", "0")
MODULO_TEST_TRUE(ModuloNegativeByOne_ExpectedTrue, "(-10)%1", "0")
MODULO_TEST_TRUE(ModuloZeroByPositive_ExpectedTrue, "0%3", "0")
MODULO_TEST_TRUE(ModuloZeroByNegative_ExpectedTrue, "0%(-3)", "0")
MODULO_TEST_TRUE(ModuloLargeNumbers_ExpectedTrue, "1000000007%100", "7")
MODULO_TEST_TRUE(ModuloByItself_ExpectedTrue, "15%15", "0")
MODULO_TEST_TRUE(ModuloByZero_ExpectedTrue, "10%10", "0")

MODULO_TEST_FALSE(ModuloPositiveByPositive_ExpectedFalse, "10%3", "2")
MODULO_TEST_FALSE(ModuloPositiveByNegative_ExpectedFalse, "10%(-3)", "2")
MODULO_TEST_FALSE(ModuloNegativeByPositive_ExpectedFalse, "(-10)%3", "1")
MODULO_TEST_FALSE(ModuloNegativeByNegative_ExpectedFalse, "(-10)%(-3)", "1")
MODULO_TEST_FALSE(ModuloPositiveByOne_ExpectedFalse, "10%1", "1")
MODULO_TEST_FALSE(ModuloNegativeByOne_ExpectedFalse, "(-10)%1", "1")
MODULO_TEST_FALSE(ModuloZeroByPositive_ExpectedFalse, "0%3", "3")
MODULO_TEST_FALSE(ModuloZeroByNegative_ExpectedFalse, "0%(-3)", "-3")
MODULO_TEST_FALSE(ModuloLargeNumbers_ExpectedFalse, "1000000007%100", "6")
MODULO_TEST_FALSE(ModuloByItself_ExpectedFalse, "15%15", "1")

#endif // MODULO_H
