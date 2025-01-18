
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../CW7FL/Calculator.h"
using namespace testing;

//OGOLNIE TO TESTY DZIALAJA !!! mozna uzywac
TEST(CalculatorBackendTest, Constructor) {
    Calculator calc("54321");
    EXPECT_EQ("54321", calc.init);
}
TEST(CalculatorBackendTest, Parser) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, Addition) {
    Calculator calc("1+1");
    EXPECT_EQ(2, calc.result);
}
TEST(CalculatorBackendTest, Subtraction) {
    Calculator calc("1-1");
    EXPECT_EQ(0, calc.result);
}
TEST(CalculatorBackendTest, Division) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, Multiplication) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, EqualsTo) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, Modulo) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, RoR) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, RoL) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, XOR) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, OR) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, NOT) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, AND) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, lsh) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, rsh) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}
TEST(CalculatorBackendTest, changePlusMinus) {
    Calculator calc("8/2");
    EXPECT_EQ(4, calc.result);
}