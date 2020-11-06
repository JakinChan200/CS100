#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateDoubleDigits) {
    Op* test = new Op(12);
    EXPECT_EQ(test->evaluate(), 12);
}

TEST(OpTest, OpEvaluateDoubleDigitNegative) {
    Op* test = new Op(-13);
    EXPECT_EQ(test->evaluate(), -13);
}

TEST(OpTest, OpEvaluateThreeDigits) {
    Op* test = new Op(132);
    EXPECT_EQ(test->evaluate(), 132);
}

TEST(OpTest, OpEvaluateNonTripleDigitNeg) {
    Op* test = new Op(-154);
    EXPECT_EQ(test->evaluate(), -154);
}

TEST(OpTest, OpEvaluateNegative){
    Op* test = new Op(-12);
    EXPECT_EQ(test->evaluate(), -12);
}

TEST(OpTest, OpEvaluateFraction) {
    Op* test = new Op(0.5);
    EXPECT_EQ(test->evaluate(), 0.5);
}

TEST(OpTest, OpEvaluateNegFraction) {
    Op* test = new Op(-0.2);
    EXPECT_EQ(test->evaluate(), -0.2);
}

TEST(OpTest, OpEvaluateDecimal){


    Op* test = new Op(2.3);
    EXPECT_EQ(test->evaluate(), 2.3);
}

TEST(OpTest, OpEvaluateEmpty){
    Op* test = new Op();
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringifyNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpStringifyNegative){
    Op* test = new Op(-12);
    EXPECT_EQ(test->stringify(), "-12.000000");
}

TEST(OpTest, OpStringifyDecimal){
    Op* test = new Op(2.3);
    EXPECT_EQ(test->stringify(), "2.300000");
}

TEST(OpTest, OpStringifyEmpty){
    Op* test = new Op();
    EXPECT_EQ(test->stringify(), "0.000000");
}
#endif //__OP_TEST_HPP__
