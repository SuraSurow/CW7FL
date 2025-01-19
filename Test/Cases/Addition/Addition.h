#ifndef ADDITION_H
#define ADDITION_H

#include <gtest/gtest.h>
#include <string>
// Created by bolo on 18.01.25.
//


struct Addition {
    Addition()= default;
    testing::AssertionResult performTest(const std::string& expression, const std::string& expectedResult);
};

#endif // ADDITION_H

