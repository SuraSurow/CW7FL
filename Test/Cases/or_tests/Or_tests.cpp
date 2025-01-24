#ifndef OR_H
#define OR_H

#include <gtest/gtest.h>
#include <string>

#include "Calculator.h"
// Created by bolo on 18.01.25.
//

class Or {
public:
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult) {
        Calculator test(expression);
        if (test.result == expectedResult)
            return testing::AssertionSuccess();
        else
            return testing::AssertionFailure() << "Oczekiwany wynik: " << expectedResult << ", ale otrzymano: " << test.result;
    }
};

#define OR_TEST_TRUE(name, expression, expected) \
TEST(OrTests, name) {                   \
Or orTest;                        \
EXPECT_TRUE(orTest.performTest(expression, expected)); \
}

#define OR_TEST_FALSE(name, expression, expected) \
TEST(OrTests, name) {                   \
Or orTest;                        \
EXPECT_FALSE(orTest.performTest(expression, expected)); \
}

// True cases
OR_TEST_TRUE(OrBothTrue_ExpectedTrue, "1||1", "1")
OR_TEST_TRUE(OrTrueOrFalse_ExpectedTrue, "1||0", "1")
OR_TEST_TRUE(OrFalseOrTrue_ExpectedTrue, "0||1", "1")
OR_TEST_TRUE(OrBothFalse_ExpectedTrue, "0||0", "0")
OR_TEST_TRUE(OrPositiveOrPositive_ExpectedTrue, "5||3", "1")
OR_TEST_TRUE(OrPositiveOrZero_ExpectedTrue, "5||0", "1")
OR_TEST_TRUE(OrNegativeOrPositive_ExpectedTrue, "-5||3", "1")
OR_TEST_TRUE(OrNegativeOrNegative_ExpectedTrue, "-5||-3", "1")
OR_TEST_TRUE(OrZeroOrNegative_ExpectedTrue, "0||-5", "1")
OR_TEST_TRUE(OrLargeNumbers_ExpectedTrue, "1000000||500000", "1")

// False cases
OR_TEST_FALSE(OrBothTrue_ExpectedFalse, "1||1", "0")
OR_TEST_FALSE(OrTrueOrFalse_ExpectedFalse, "1||0", "0")
OR_TEST_FALSE(OrFalseOrTrue_ExpectedFalse, "0||1", "0")
OR_TEST_FALSE(OrBothFalse_ExpectedFalse, "0||0", "1")
OR_TEST_FALSE(OrPositiveOrPositive_ExpectedFalse, "5||3", "0")
OR_TEST_FALSE(OrPositiveOrZero_ExpectedFalse, "5||0", "0")
OR_TEST_FALSE(OrNegativeOrPositive_ExpectedFalse, "-5||3", "0")
OR_TEST_FALSE(OrNegativeOrNegative_ExpectedFalse, "-5||-3", "0")
OR_TEST_FALSE(OrZeroOrNegative_ExpectedFalse, "0||-5", "0")
OR_TEST_FALSE(OrLargeNumbers_ExpectedFalse, "1000000||500000", "0")

#endif // OR_H