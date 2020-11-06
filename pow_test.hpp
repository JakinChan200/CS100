#ifndef POW_TEST_HPP
#define POW_TEST_HPP

#include "gtest/gtest.h"
#include "pow.hpp"
#include "mockOp.hpp"
#include "mockOperation.hpp"

TEST(powTesting, regularNumbers) {
    Base* variable1 = new MockOp(2);
    Base* variable2 = new MockOp(3);
    Base* powerTest = new Pow(variable1, variable2);
    EXPECT_EQ(8, powerTest->evaluate());
}

TEST(powTesting, zeroPower) {
    Base* variable1 = new MockOp(2);
    Base* variable2 = new MockOp(0);
    Base* powerTest = new Pow(variable1, variable2);
    EXPECT_EQ(1, powerTest->evaluate());
}

TEST(powTesting, zeroBase) {
    Base* variable1 = new MockOp(0);
    Base* variable2 = new MockOp(2);
    Base* powerTest = new Pow(variable1, variable2);
    EXPECT_EQ(0, powerTest->evaluate());
}

TEST(powTesting, decimalPower) {
    Base* variable1 = new MockOp(81);
    Base* variable2 = new MockOp(0.75);
    Base* powerTest = new Pow(variable1, variable2);
    EXPECT_EQ(27, powerTest->evaluate());
}

TEST(powTesting, negativeBaseOddPower) {
    Base* variable1 = new MockOp(-2);
    Base* variable2 = new MockOp(5);
    Base* powerTest = new Pow(variable1, variable2);
    EXPECT_EQ(-32, powerTest->evaluate());
}

TEST(powTesting, negativeBaseEvenPower) {
    Base* variable1 = new MockOp(-2);
    Base* variable2 = new MockOp(4);
    Base* powerTest = new Pow(variable1, variable2);
    EXPECT_EQ(16, powerTest->evaluate());
}

TEST(powTesting, operatorBase) {
    Base* variable1 = new MockOp(2);
    Base* variable2 = new MockOp(4);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new MockOp(2);
    Base* powerTest = new Pow(operator1, variable3);
    EXPECT_EQ(36, powerTest->evaluate());
}

TEST(powTesting, operativePower) {
    Base* variable1 = new MockOp(-2);
    Base* variable2 = new MockOp(5);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new MockOp(2);
    Base* powerTest = new Pow(variable3, operator1);
    EXPECT_EQ(8, powerTest->evaluate());
}

TEST(powTesting, stringifyWithNumbers) {
    Base* variable1 = new MockOp(-3);
    Base* variable2 = new MockOp(4);
    Base* powerTest = new Pow(variable1, variable2);
    EXPECT_EQ("(-3.000000) ** (4.000000) ", powerTest->stringify());
}

TEST(powTesting, stringifyWithOperations) {
    Base* variable1 = new MockOp(-2);
    Base* variable2 = new MockOp(5);
    Base* operator1 = new MockOperator(variable1, variable2);
    Base* variable3 = new MockOp(2);
    Base* powerTest = new Pow(variable3, operator1);
    EXPECT_EQ("(2.000000) ** (-2.000000 + 5.000000 ) ", powerTest->stringify());
}


#endif
