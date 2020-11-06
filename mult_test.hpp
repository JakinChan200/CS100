#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"

TEST(MultTest, MultEvaluateZero) {
    Mult* test = new Mult(0,8);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateNegative){
    Mult* test = new Mult(-1,2);
    EXPECT_EQ(test->evaluate(), -2);
}

TEST(MultTest, MultEvaluateDecimal){
    Mult* test = new Mult(2.5,2);
    EXPECT_EQ(test->evaluate(), 5);
}

TEST(MultTest, MultEvaluateEmpty){
    Mult* test = new Mult();
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(MultTest, MultStringifyZero) {
    Mult* test = new Mult(3,0);
    EXPECT_EQ(test->stringify(), "0");
}

TEST(MultTest, MultStringifyNegative){
    Mult* test = new Mult(-2,5);
    EXPECT_EQ(test->stringify(), "-10");
}

TEST(MultTest, MultStringifyDecimal){
    Mult* test = new Mult(1.7,2);
    EXPECT_EQ(test->stringify(), "3.4");
}

TEST(MultTest, MultStringifyEmpty){
    Mult* test = new Mult();
    EXPECT_EQ(test->stringify(), "0");
}
#endif //__MULT_TEST_HPP__
