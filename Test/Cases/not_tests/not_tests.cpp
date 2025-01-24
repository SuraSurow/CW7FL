#ifndef NOT_H
#define NOT_H

#include <gtest/gtest.h>
#include <string>

#include "Calculator.h"
// Created by bolo on 18.01.25.
//

class Not {
public:
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult) {
        Calculator test(expression);
        if (test.result == expectedResult)
            return testing::AssertionSuccess();
        else
            return testing::AssertionFailure() << "Oczekiwany wynik: " << expectedResult << ", ale otrzymano: " << test.result;
    }
};

#define NOT_TEST_TRUE(name, expression, expected) \
TEST(NotTests, name) {                   \
Not notTest;                        \
EXPECT_TRUE(notTest.performTest(expression, expected)); \
}

#define NOT_TEST_FALSE(name, expression, expected) \
TEST(NotTests, name) {                   \
Not notTest;                        \
EXPECT_FALSE(notTest.performTest(expression, expected)); \
}

// True cases
NOT_TEST_TRUE(NotTrue_ExpectedFalse, "!1", "0")
NOT_TEST_TRUE(NotFalse_ExpectedTrue, "!0", "1")
NOT_TEST_TRUE(NotPositiveNumber_ExpectedFalse, "!5", "0")
NOT_TEST_TRUE(NotNegativeNumber_ExpectedFalse, "!-5", "0")
NOT_TEST_TRUE(NotZero_ExpectedTrue, "!0", "1")
NOT_TEST_TRUE(NotLargePositive_ExpectedFalse, "!1000", "0")
NOT_TEST_TRUE(NotLargeNegative_ExpectedFalse, "!-1000", "0")
NOT_TEST_TRUE(NotMaxInt_ExpectedFalse, "!2147483647", "0")
NOT_TEST_TRUE(NotMinInt_ExpectedFalse, "!-2147483648", "0")
NOT_TEST_TRUE(NotExpressionTrue_ExpectedFalse, "!(1&&1)", "0")



// False cases
NOT_TEST_FALSE(NotTrue_ExpectedTrue, "!1", "1")
NOT_TEST_FALSE(NotFalse_ExpectedFalse, "!0", "0")
NOT_TEST_FALSE(NotPositiveNumber_ExpectedTrue, "!5", "1")
NOT_TEST_FALSE(NotNegativeNumber_ExpectedTrue, "!-5", "1")
NOT_TEST_FALSE(NotZero_ExpectedFalse, "!0", "0")
NOT_TEST_FALSE(NotLargePositive_ExpectedTrue, "!1000", "1")
NOT_TEST_FALSE(NotLargeNegative_ExpectedTrue, "!-1000", "1")
NOT_TEST_FALSE(NotMaxInt_ExpectedTrue, "!2147483647", "1")
NOT_TEST_FALSE(NotMinInt_ExpectedTrue, "!-2147483648", "1")
NOT_TEST_FALSE(NotExpressionTrue_ExpectedTrue, "!(1&&1)", "1")



#endif // NOT_H