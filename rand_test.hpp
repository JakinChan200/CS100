#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluateLess100) {
    Rand* test = new Rand();
    EXPECT_EQ(test->evaluate(), 100);
}

TEST(RandTest, RandStringifyLess100) {
    Rand* test = new Rand();
    EXPECT_LT(stod(test->stringify()), 100);
}

TEST(RandTest, RandEvaluateGreater0) {
    Rand* test = new Rand();
    EXPECT_GT(test->evaluate(), 0);
}

TEST(RandTest, RandStringifyGreater0) {
    Rand* test = new Rand();
    EXPECT_GT(stod(test->stringify()), 0);
}

#endif //__RAND_TEST_HPP__
