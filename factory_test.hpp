#include "gtest/gtest.h"
#include "factory.hpp"
#include "main.cpp"
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"
#include <iostream>
#include <vector>

TEST(FactoryTest, NullPtrTest){
    Factory* test = new Factory();
    int length = 0;
    char** input = new char[length];

    EXPECT_EQ(test->parse(input, length), nullptr); 
}

TEST(FactoryTest, SimpleAdd){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "1";
    input[1] = "+";
    input[2] = "6";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(1.000000) + (6.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 7);
}

TEST(FactoryTest, NegOutputSub){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "-6";
    input[1] = "+";
    input[2] = "1";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(-6.000000) + (1.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), -5);
}

TEST(FactoryTest, SimpleSub){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "6";
    input[1] = "-";
    input[2] = "1";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(6.000000) - (1.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 5);
}

TEST(FactoryTest, NegOutputSub){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "1";
    input[1] = "-";
    input[2] = "6";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(1.000000) - (6.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), -5);
}

TEST(FactoryTest, SimpleMult){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "1";
    input[1] = "*";
    input[2] = "6";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(1.000000) * (6.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 6);
}

TEST(FactoryTest, NegInputMult){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "-2";
    input[1] = "*";
    input[2] = "-6";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(-2.000000) * (-6.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 12);
}

TEST(FactoryTest, NegOutputMult){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "-2";
    input[1] = "*";
    input[2] = "6";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(-2.000000) * (6.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), -12);
}

TEST(FactoryTest, SimpleDiv){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "6";
    input[1] = "/";
    input[2] = "2";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(6.000000) / (2.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 3);
}

TEST(FactoryTest, NegInputDiv){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "-6";
    input[1] = "/";
    input[2] = "-2";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(-6.000000) / (-2.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 3);
}

TEST(FactoryTest, NegOutputDiv){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "-6";
    input[1] = "/";
    input[2] = "2";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(-6.000000) / (2.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), -3);
}

TEST(FactoryTest, SimplePow){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "1";
    input[1] = "**";
    input[2] = "6";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(1.000000) ** (6.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 1);
}

TEST(FactoryTest, NegInputPow){
    Factory* test = new Factory();
    int length = 3;
    char** input = new char[length];
    input[0] = "-1";
    input[1] = "**";
    input[2] = "-6";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(-1.000000) ** (-6.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 1);
}

TEST(FactoryTest, NegPow){
    Factory* test = new Factory();
    int length = 4;
    char** input = new char[length];
    input[0] = "2";
    input[1] = "*";
    input[2] = "*";
    input[3] = "-3";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(2.000000) ** (-3.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 0.125);
}

TEST(FactoryTest, NegOutputPow){
    Factory* test = new Factory();
    int length = 4;
    char** input = new char[length];
    input[0] = "-3";
    input[1] = "*";
    input[2] = "*";
    input[3] = "3";

    EXPECT_EQ(test->parse(input, length)->stringify(), "(-3.000000) ** (3.000000)");
    EXPECT_EQ(test->parse(input, length)->evaluate(), -27);
}

TEST(FactoryTest, ZeroOutput){
    Factory* test = new Factory();
    int length = 5;
    char** input = new char[length];
    input[0] = "0";
    input[1] = "/";
    input[2] = "2";
    input[3] = "*";
    input[4] = "3"

    EXPECT_EQ(test->parse(input, length)->stringify(), "(0.000000) / ((2.000000) * (3.000000))");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 0);
}

TEST(FactoryTest, TwoOperators){
    Factory* test = new Factory();
    int length = 5;
    char** input = new char[length];
    input[0] = "1.5";
    input[1] = "+";
    input[2] = "2";
    input[3] = "*";
    input[4] = "3"

    EXPECT_EQ(test->parse(input, length)->stringify(), "(1.500000) + ((2.000000) * (3.000000))");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 10.5);
}

TEST(FactoryTest, OneNegativeInput){
    Factory* test = new Factory();
    int length = 5;
    char** input = new char[length];
    input[0] = "1";
    input[1] = "+";
    input[2] = "3";
    input[3] = "*";
    input[4] = "-2"

    EXPECT_EQ(test->parse(input, length)->stringify(), "(1.000000) + ((3.000000) * (-2.000000))");
    EXPECT_EQ(test->parse(input, length)->evaluate(), -4);
}

TEST(FactoryTest, NegDecimalOutput){
    Factory* test = new Factory();
    int length = 5;
    char** input = new char[length];
    input[0] = "1.5";
    input[1] = "-";
    input[2] = "2";
    input[3] = "*";
    input[4] = "3"

    EXPECT_EQ(test->parse(input, length)->stringify(), "(1.500000) - ((2.000000) * (3.000000))");
    EXPECT_EQ(test->parse(input, length)->evaluate(), -1.5);
}

TEST(FactoryTest, DoubleDigitInput){
    Factory* test = new Factory();
    int length = 5;
    char** input = new char[length];
    input[0] = "15";
    input[1] = "/";
    input[2] = "3";
    input[3] = "*";
    input[4] = "20"

    EXPECT_EQ(test->parse(input, length)->stringify(), "(15.000000) / ((3.000000) * (20.000000))");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 100);
}

TEST(FactoryTest, DoubleDigitDecimalInput){
    Factory* test = new Factory();
    int length = 5;
    char** input = new char[length];
    input[0] = "35";
    input[1] = "/";
    input[2] = "0.5";
    input[3] = "*";
    input[4] = "20.2"

    EXPECT_EQ(test->parse(input, length)->stringify(), "(35.000000) / ((0.500000) * (20.200000))");
    EXPECT_EQ(test->parse(input, length)->evaluate(), 353.5);
}
