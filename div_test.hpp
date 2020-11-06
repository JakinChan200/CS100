#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, DivEvaluateZero) {
    Base* variable1 = new Op(0);
    Base* variable2 = new Op(8);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivEvaluateNegative){
    Base* variable1 = new Op(-4);
    Base* variable2 = new Op(2);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), -2);
}

TEST(DivTest, DivEvaluateDecimal){
    Base* variable1 = new Op(5);
    Base* variable2 = new Op(2);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), 2.5);
}

TEST(DivTest, DivEvaluateDoubleDigits){
    Base* variable1 = new Op(20);
    Base* variable2 = new Op(10);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), 2);
}

TEST(DivTest, DivEvaluateDoubleDigitBothNeg){
    Base* variable1 = new Op(-50);
    Base* variable2 = new Op(-25);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), 2);
}

TEST(DivTest, DivEvaluateDoubleDigitDenomNeg){
    Base* variable1 = new Op(35);
    Base* variable2 = new Op(-7);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), -5);
}

TEST(DivTest, DivEvaluateDoubleDigitNumerNeg){
    Base* variable1 = new Op(-22);
    Base* variable2 = new Op(11);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), -2);
}

TEST(DivTest, DivEvaluateDoubleDigitDecimal){
    Base* variable1 = new Op(32);
    Base* variable2 = new Op(5);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), 6.4);
}

TEST(DivTest, DivEvaluateFraction){
    Base* variable1 = new Op(2);
    Base* variable2 = new Op(5);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), 0.4);
}

TEST(DivTest, DivEvaluateEmpty){
    Base* variable1 = new Op(0);
    Base* variable2 = new Op(2);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivStringifyZero) {
    Base* variable1 = new Op(0);
    Base* variable2 = new Op(3);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->stringify(), "(0.000000) / (3.000000)");
}

TEST(DivTest, DivStringifyNegative){
    Base* variable1 = new Op(-20);
    Base* variable2 = new Op(5);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->stringify(), "(-20.000000) / (5.000000)");
}

TEST(DivTest, DivStringifyDecimal){
    Base* variable1 = new Op(3.4);
    Base* variable2 = new Op(2);
    Div* test = new Div(variable1,variable2);
    EXPECT_EQ(test->stringify(), "(3.400000) / (2.000000)");
}

TEST(DivTest, DivStringifyEmpty){
    Div* test = new Div();
    EXPECT_EQ(test->stringify(), "(0.000000) / (1.000000)");
}
#endif //__DIV_TEST_HPP__
