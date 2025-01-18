//
// Created by bolo on 18.01.25.
//

#ifndef TST_INITTEST_H
#define TST_INITTEST_H
#include <gtest/gtest-assertion-result.h>

/*
PRZYKLAD

testing::AssertionResult IsEven(int n) {
  if ((n % 2) == 0)
    return testing::AssertionSuccess();
  else
    return testing::AssertionFailure() << n << " is odd";
}




 */


class Tests {
    test_addition




    testing::AssertionResult constructor_test();
    testing::AssertionResult parser_test();
    testing::AssertionResult addition_test();
    testing::AssertionResult subtraction_test();
    testing::AssertionResult division_test();
    testing::AssertionResult multiplication_test();
    testing::AssertionResult equals_to_test();
    testing::AssertionResult modulo_test();
    testing::AssertionResult ror_test();
    testing::AssertionResult rol_test();
    testing::AssertionResult lsh_test();
    testing::AssertionResult rsh_test();
    testing::AssertionResult xor_test();
    testing::AssertionResult or_test();
    testing::AssertionResult not_test();
    testing::AssertionResult and_test();
    testing::AssertionResult change_neg_pos_test();
};


#endif //TST_INITTEST_H
