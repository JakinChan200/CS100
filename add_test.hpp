#ifndef ADD_TEST_HPP
#define ADD_TEST_HPP

#include "gtest/gtest.h"
#include <string>
#include "add.hpp"
#include "mockOp.hpp"
#include "mockOperation.hpp"

TEST(addTest, rationalNums) {
    Base* variable1 = new MockOp(2);
    Base* variable2 = new MockOp(3);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(5.000000, additTest->evaluate());
}

TEST(addTest, negativeFirst) {
    Base* variable1 = new MockOp(-2);
    Base* variable2 = new MockOp(3);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(1.000000, additTest->evaluate());
}

TEST(addTest, negativeSecond) {
    Base* variable1 = new MockOp(5);
    Base* variable2 = new MockOp(-3);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(2.000000, additTest->evaluate());
}

TEST(addTest, allNegative) {
    Base* variable1 = new MockOp(-4);
    Base* variable2 = new MockOp(-7);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(-11.000000, additTest->evaluate());
}

TEST(addTest, decimals) {
    Base* variable1 = new MockOp(2.35);
    Base* variable2 = new MockOp(3.45);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(2.35+3.45, additTest->evaluate());
}

TEST(addTest, decimalFirst) {
    Base* variable1 = new MockOp(-2.5);
    Base* variable2 = new MockOp(4);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(1.500000, additTest->evaluate());
}

TEST(addTest, decimalSecond) {
    Base* variable1 = new MockOp(2);
    Base* variable2 = new MockOp(3.2);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(5.200000, additTest->evaluate());
}

TEST(addTest, DoubleDigits) {
    Base* variable1 = new MockOp(23);
    Base* variable2 = new MockOp(22);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(45.000000, additTest->evaluate());
}

TEST(addTest, DoubleDigitsNegFirst) {
    Base* variable1 = new MockOp(-54);
    Base* variable2 = new MockOp(46);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(-8.000000, additTest->evaluate());
}

TEST(addTest, DoubleDigitsNegSecond) {
    Base* variable1 = new MockOp(24);
    Base* variable2 = new MockOp(-12);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(12.000000, additTest->evaluate());
}

TEST(addTest, DoubleDigitsAllNegative) {
    Base* variable1 = new MockOp(-34);
    Base* variable2 = new MockOp(-87);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ(-121.000000, additTest->evaluate());
}


TEST(addTest, addOperators) {
    Base* variable1 = new MockOp(2);
    Base* variable2 = new MockOp(3);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new MockOp(7);
    Base* additTest = new Add(operator1, variable3);
    EXPECT_EQ(12.000000, additTest->evaluate());
}

TEST(addTest, addOperatorsDecimal) {
    Base* variable1 = new MockOp(2.3);
    Base* variable2 = new MockOp(5.2);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new MockOp(7.4);
    Base* additTest = new Add(operator1, variable3);
    EXPECT_EQ(14.900000, additTest->evaluate());
}

TEST(addTest, addOperatorsNegative) {
    Base* variable1 = new MockOp(-2);
    Base* variable2 = new MockOp(-3);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new MockOp(-7);
    Base* additTest = new Add(operator1, variable3);
    EXPECT_EQ(-12.000000, additTest->evaluate());
}

TEST(addTest, addOperatorsNegDecimal) {
    Base* variable1 = new MockOp(-2.4);
    Base* variable2 = new MockOp(-3.5);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new MockOp(-8.9);
    Base* additTest = new Add(operator1, variable3);
    EXPECT_EQ(-14.800000, additTest->evaluate());
}

TEST(addTest, stringifyRegularNums) {
    Base* variable1 = new MockOp(2);
    Base* variable2 = new MockOp(3);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ("2.000000 + 3.000000 ", additTest->stringify());
}

TEST(addTest, stringifyNegativeSecond) {
    Base* variable1 = new MockOp(3);
    Base* variable2 = new MockOp(-4);
    Base* additTest = new Add(variable1, variable2);
    EXPECT_EQ("3.000000 + -4.000000 ", additTest->stringify());
}

#endif
