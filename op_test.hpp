#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateNegative){
    Op* test = new Op(-12);
    EXPECT_EQ(test->evaluate(), -12);
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
    EXPECT_EQ(test->stringify(), "8");
}

TEST(OpTest, OpStringifyNegative){
    Op* test = new Op(-12);
    EXPECT_EQ(test->stringify(), "-12");
}

TEST(OpTest, OpStringifyDecimal){
    Op* test = new Op(2.3);
    EXPECT_EQ(test->stringify(), "2.3");
}

TEST(OpTest, OpStringifyEmpty){
    Op* test = new Op();
    EXPECT_EQ(test->stringify(), "0");
}
#endif //__OP_TEST_HPP__
