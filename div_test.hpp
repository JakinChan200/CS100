#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, DivEvaluateZero) {
    Div* test = new Div(0,8);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivEvaluateNegative){
    Div* test = new Div(-4,2);
    EXPECT_EQ(test->evaluate(), -2);
}

TEST(DivTest, DivEvaluateDecimal){
    Div* test = new Div(5,2);
    EXPECT_EQ(test->evaluate(), 2.5);
}

TEST(DivTest, DivEvaluateEmpty){
    Div* test = new Div();
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(DivTest, DivStringifyZero) {
    Div* test = new Div(0,3);
    EXPECT_EQ(test->stringify(), "0");
}

TEST(DivTest, DivStringifyNegative){
    Div* test = new Div(-20,5);
    EXPECT_EQ(test->stringify(), "-4");
}

TEST(DivTest, DivStringifyDecimal){
    Div* test = new Div(3.4,2);
    EXPECT_EQ(test->stringify(), "1.7");
}

TEST(DivTest, DivStringifyEmpty){
    Div* test = new Div();
    EXPECT_EQ(test->stringify(), "0");
}
#endif //__DIV_TEST_HPP__