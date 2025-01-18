//
// Created by bolo on 18.01.25.
//

#ifndef ADDITION_H
#define ADDITION_H
#include <gtest/gtest-assertion-result.h>
using namespace ::testing

struct Addition{

    AssertionResult additionMinusNumberToMinusNumber();
    AssertionResult additionMinusNumberToPlusNumber();
    AssertionResult additionPlusNumberToPlusNumber();
    AssertionResult additionZeroToMinusNumber();
    AssertionResult additionZeroToPlusNumber();
    AssertionResult additionZeroToZero();


 };




#endif //ADDITION_H
