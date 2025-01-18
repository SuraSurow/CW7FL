#ifndef ADDITION_H
#define ADDITION_H

#include <gtest/gtest.h>
#include <string>

struct Addition {
    Addition();
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult);
};

#endif // ADDITION_H

