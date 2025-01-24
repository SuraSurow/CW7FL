#ifndef AND_H
#define AND_H

#include <gtest/gtest.h>
#include <string>

#include "Calculator.h"
// Created by bolo on 18.01.25.
//

class And {
public:
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult) {
        Calculator test(expression);
        if (test.result == expectedResult)
            return testing::AssertionSuccess();
        else
            return testing::AssertionFailure() << "Oczekiwany wynik: " << expectedResult << ", ale otrzymano: " << test.result;
    }
};

#define AND_TEST_TRUE(name, expression, expected) \
TEST(AndTests, name) {                   \
And andTest;                        \
EXPECT_TRUE(andTest.performTest(expression, expected)); \
}

#define AND_TEST_FALSE(name, expression, expected) \
TEST(AndTests, name) {                   \
And andTest;                        \
EXPECT_FALSE(andTest.performTest(expression, expected)); \
}

// True cases
AND_TEST_TRUE(AndBothTrue_ExpectedTrue, "1&&1", "1")
AND_TEST_TRUE(AndTrueAndFalse_ExpectedTrue, "1&&0", "0")
AND_TEST_TRUE(AndFalseAndTrue_ExpectedTrue, "0&&1", "0")
AND_TEST_TRUE(AndBothFalse_ExpectedTrue, "0&&0", "0")
AND_TEST_TRUE(AndPositiveAndPositive_ExpectedTrue, "5&&3", "1")
AND_TEST_TRUE(AndPositiveAndZero_ExpectedTrue, "5&&0", "0")
AND_TEST_TRUE(AndNegativeAndPositive_ExpectedTrue, "-5&&3", "1")
AND_TEST_TRUE(AndNegativeAndNegative_ExpectedTrue, "-5&&-3", "1")
AND_TEST_TRUE(AndZeroAndNegative_ExpectedTrue, "0&&-5", "0")
AND_TEST_TRUE(AndLargeNumbers_ExpectedTrue, "1000000&&500000", "1")

// False cases
AND_TEST_FALSE(AndBothTrue_ExpectedFalse, "1&&1", "0")
AND_TEST_FALSE(AndTrueAndFalse_ExpectedFalse, "1&&0", "1")
AND_TEST_FALSE(AndFalseAndTrue_ExpectedFalse, "0&&1", "1")
AND_TEST_FALSE(AndBothFalse_ExpectedFalse, "0&&0", "1")
AND_TEST_FALSE(AndPositiveAndPositive_ExpectedFalse, "5&&3", "0")
AND_TEST_FALSE(AndPositiveAndZero_ExpectedFalse, "5&&0", "1")
AND_TEST_FALSE(AndNegativeAndPositive_ExpectedFalse, "-5&&3", "0")
AND_TEST_FALSE(AndNegativeAndNegative_ExpectedFalse, "-5&&-3", "0")
AND_TEST_FALSE(AndZeroAndNegative_ExpectedFalse, "0&&-5", "1")
AND_TEST_FALSE(AndLargeNumbers_ExpectedFalse, "1000000&&500000", "0")

#endif // AND_H
