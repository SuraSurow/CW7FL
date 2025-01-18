
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../CW7FL/Calculator.h"
using namespace testing;

//OGOLNIE TO TESTY DZIALAJA !!! mozna uzywac
TEST(CalculatorTest, Constructor) {
    Calculator calc("54321");
    EXPECT_EQ("54321", calc.init);
}
TEST(CalculatorTest, Addition) {
    Calculator calc("1+1");
    EXPECT_EQ(2, calc.result);
}
TEST(CalculatorTest, Subtraction) {
    Calculator calc("1-1");
    EXPECT_EQ(0, calc.result);
}
TEST(CalculatorTest, Division) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}