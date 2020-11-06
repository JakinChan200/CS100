#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "mockOperation.hpp"
TEST(MultTest, MultEvaluateZero) {
    Base* variable1 = new Op(0);
    Base* variable2 = new Op(0);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateNegative){
    Base* variable1 = new Op(-1);
    Base* variable2 = new Op(2);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->evaluate(), -2.000000);
}

TEST(MultTest, MultEvaluateNegativeSecond){
    Base* variable1 = new Op(2);
    Base* variable2 = new Op(-3);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->evaluate(), -6.000000);
}

TEST(MultTest, MultEvaluateAllNegative){
    Base* variable1 = new Op(-2);
    Base* variable2 = new Op(-3);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->evaluate(), 6.000000);
}

TEST(MultTest, MultEvaluateNegativeDecimal){
    Base* variable1 = new Op(-3.5);
    Base* variable2 = new Op(2);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->evaluate(), -7.000000);
}

TEST(MultTest, MultEvaluateAllNegativeDecimal){
    Base* variable1 = new Op(-4.5);
    Base* variable2 = new Op(-3.2);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->evaluate(), 14.400000);
}

TEST(MultTest, MultEvaluateDecimal){
    Base* variable1 = new Op(2.5);
    Base* variable2 = new Op(2);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->evaluate(), 2.5*2);
}

TEST(MultTest, MultEvaluateOperation){
    Base* variable1 = new Op(3);
    Base* variable2 = new Op(2);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new Op(4);
    Mult* test = new Mult(operator1, variable3);
    EXPECT_EQ(test->evaluate(), 20.000000);
}

TEST(MultTest, MultEvaluateOperatorNegative){
    Base* variable1 = new Op(3);
    Base* variable2 = new Op(2);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new Op(-4);
    Mult* test = new Mult(operator1, variable3);
    EXPECT_EQ(test->evaluate(), -20.000000);
}

TEST(MultTest, MultEvaluateOperationAllNegative){
    Base* variable1 = new Op(-3);
    Base* variable2 = new Op(-2);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new Op(-4);
    Mult* test = new Mult(operator1, variable3);
    EXPECT_EQ(test->evaluate(), 20.000000);
}

TEST(MultTest, MultEvaluateOperationDecimal){
    Base* variable1 = new Op(3.2);
    Base* variable2 = new Op(2.5);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new Op(5.1);
    Mult* test = new Mult(operator1, variable3);
    EXPECT_EQ(test->evaluate(), 29.070000);
}


TEST(MultTest, MultStringifyZero) {
    Base* variable1 = new Op(3);
    Base* variable2 = new Op(0);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->stringify(), "(3.000000) * (0.000000)");
}

TEST(MultTest, MultStringifyNegative){
    Base* variable1 = new Op(-2);
    Base* variable2 = new Op(5);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->stringify(), "(-2.000000) * (5.000000)");
}

TEST(MultTest, MultStringifyBothNegative){
    Base* variable1 = new Op(-3);
    Base* variable2 = new Op(-4);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->stringify(), "(-3.000000) * (-4.000000)");
}


TEST(MultTest, MultStringifyDecimal){
    Base* variable1 = new Op(1.7);
    Base* variable2 = new Op(2);
    Mult* test = new Mult(variable1, variable2);
    EXPECT_EQ(test->stringify(), "(1.700000) * (2.000000)");
}
#endif //__MULT_TEST_HPP__
