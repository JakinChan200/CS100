#ifndef SUB_TEST_HPP
#define SUB_TEST_HPP

#include "gtest/gtest.h"
#include <string>
#include "sub.hpp"
#include "mockOp.hpp"

TEST(subTesting, regularNumbers) {
    Base* variable1 = new MockOp(3);
    Base* variable2 = new MockOp(2);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ(1.000000, subtrTest->evaluate());
}

TEST(subTesting, negativeAnswer) {
    Base* variable1 = new MockOp(2);
    Base* variable2 = new MockOp(5);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ(-3.000000, subtrTest->evaluate());
}

TEST(subTesting, zeroAnswer) {
    Base* variable1 = new MockOp(4);
    Base* variable2 = new MockOp(4);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ(0.000000, subtrTest->evaluate());
}

TEST(subTesting, negativeFirst) {
    Base* variable1 = new MockOp(-3);
    Base* variable2 = new MockOp(2);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ(-5.000000, subtrTest->evaluate());
}

TEST(subTesting, negativeSecond) {
    Base* variable1 = new MockOp(4);
    Base* variable2 = new MockOp(-4);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ(8.000000, subtrTest->evaluate());
}

TEST(subTesting, bothNegative) {
    Base* variable1 = new MockOp(-3);
    Base* variable2 = new MockOp(-4);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ(1.000000, subtrTest->evaluate());
}

TEST(subTesting, decimals) {
    Base* variable1 = new MockOp(4.3);
    Base* variable2 = new MockOp(2.45);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ(4.3-2.45, subtrTest->evaluate());
}

TEST(subTesting, withOperations) {
    Base* variable1 = new MockOp(4);
    Base* variable2 = new MockOp(-4);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new MockOp(3);
    Base* subtrTest = new Sub(operator1, variable3);
    EXPECT_EQ(-3.000000, subtrTest->evaluate());
}


TEST(subTesting, stringifyPositiveNum) {
    Base* variable1 = new MockOp(3);
    Base* variable2 = new MockOp(2);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ("3.000000 - 2.000000 ", subtrTest->stringify());
}

TEST(subTesting, stringifyNegativeNum) {
    Base* variable1 = new MockOp(3);
    Base* variable2 = new MockOp(-4);
    Base* subtrTest = new Sub(variable1, variable2);
    EXPECT_EQ("3.000000 - -4.000000 ", subtrTest->stringify());
}


#endif
