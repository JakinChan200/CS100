#include "gtest/gtest.h"
#include "factory.hpp"
#include <cstdio>
#include <iostream>
#include <vector>

TEST(FactoryTest, NullPtrTest){
    Factory* test = new Factory();
    int length = 2;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "2";

    Base* equation = test->parse(const_cast <char**> (input), 1);

    EXPECT_EQ(equation, nullptr); 
}

TEST(FactoryTest, SimpleAdd){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "1";
    input[2] = "+";
    input[3] = "6";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "1.000000 + 6.000000 ");
    EXPECT_EQ(equation->evaluate(), 7);
}

TEST(FactoryTest, NegOutputAdd){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "-6";
    input[2] = "+";
    input[3] = "1";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "-6.000000 + 1.000000 ");
    EXPECT_EQ(equation->evaluate(), -5);
}

TEST(FactoryTest, SimpleSub){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "6";
    input[2] = "-";
    input[3] = "1";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "6.000000 - 1.000000");
    EXPECT_EQ(equation->evaluate(), 5);
}

TEST(FactoryTest, NegOutputSub){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "1";
    input[2] = "-";
    input[3] = "6";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "1.000000 - 6.000000");
    EXPECT_EQ(equation->evaluate(), -5);
}

TEST(FactoryTest, SimpleMult){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "1";
    input[2] = "*";
    input[3] = "6";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(1.000000) * (6.000000)");
    EXPECT_EQ(equation->evaluate(), 6);
}

TEST(FactoryTest, NegInputMult){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "-2";
    input[2] = "*";
    input[3] = "-6";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(-2.000000) * (-6.000000)");
    EXPECT_EQ(equation->evaluate(), 12);
}

TEST(FactoryTest, NegOutputMult){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "-2";
    input[2] = "*";
    input[3] = "6";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(-2.000000) * (6.000000)");
    EXPECT_EQ(equation->evaluate(), -12);
}

TEST(FactoryTest, SimpleDiv){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "6";
    input[2] = "/";
    input[3] = "2";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(6.000000) / (2.000000)");
    EXPECT_EQ(equation->evaluate(), 3);
}

TEST(FactoryTest, NegInputDiv){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "-6";
    input[2] = "/";
    input[3] = "-2";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(-6.000000) / (-2.000000)");
    EXPECT_EQ(equation->evaluate(), 3);
}

TEST(FactoryTest, NegOutputDiv){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "-6";
    input[2] = "/";
    input[3] = "2";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(-6.000000) / (2.000000)");
    EXPECT_EQ(equation->evaluate(), -3);
}

TEST(FactoryTest, SimplePow){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "1";
    input[2] = "**";
    input[3] = "6";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(1.000000) ** (6.000000) ");
    EXPECT_EQ(equation->evaluate(), 1);
}

TEST(FactoryTest, NegInputPow){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "-1";
    input[2] = "**";
    input[3] = "-6";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(-1.000000) ** (-6.000000) ");
    EXPECT_EQ(equation->evaluate(), 1);
}

TEST(FactoryTest, NegPow){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "2";
    input[2] = "**";
    input[3] = "-3";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(2.000000) ** (-3.000000) ");
    EXPECT_EQ(equation->evaluate(), 0.125);
}

TEST(FactoryTest, NegOutputPow){
    Factory* test = new Factory();
    int length = 4;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "-3";
    input[2] = "**";
    input[3] = "3";

    Base* equation = test->parse(const_cast <char**> (input), 4);

    EXPECT_EQ(equation->stringify(), "(-3.000000) ** (3.000000) ");
    EXPECT_EQ(equation->evaluate(), -27);
}

TEST(FactoryTest, ZeroOutput){
    Factory* test = new Factory();
    int length = 6;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "0";
    input[2] = "/";
    input[3] = "2";
    input[4] = "*";
    input[5] = "3";

    Base* equation = test->parse(const_cast <char**> (input), 6);

    EXPECT_EQ(equation->stringify(), "((0.000000) / (2.000000)) * (3.000000)");
    EXPECT_EQ(equation->evaluate(), 0);
}

TEST(FactoryTest, TwoOperators){
    Factory* test = new Factory();
    int length = 6;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "1.5";
    input[2] = "+";
    input[3] = "2";
    input[4] = "*";
    input[5] = "3";

    Base* equation = test->parse(const_cast <char**> (input), 6);

    EXPECT_EQ(equation->stringify(), "(1.500000 + 2.000000 ) * (3.000000)");
    EXPECT_EQ(equation->evaluate(), 10.5);
}

TEST(FactoryTest, OneNegativeInput){
    Factory* test = new Factory();
    int length = 6;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "1";
    input[2] = "+";
    input[3] = "3";
    input[4] = "*";
    input[5] = "-2";
    
    Base* equation = test->parse(const_cast <char**> (input), 6);

    EXPECT_EQ(equation->stringify(), "(1.000000 + 3.000000 ) * (-2.000000)");
    EXPECT_EQ(equation->evaluate(), -8);
}

TEST(FactoryTest, NegDecimalOutput){
    Factory* test = new Factory();
    int length = 6;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "1.5";
    input[2] = "-";
    input[3] = "2";
    input[4] = "*";
    input[5] = "3";

    Base* equation = test->parse(const_cast <char**> (input), 6);

    EXPECT_EQ(equation->stringify(), "(1.500000 - 2.000000) * (3.000000)");
    EXPECT_EQ(equation->evaluate(), -1.5);
}

TEST(FactoryTest, DoubleDigitInput){
    Factory* test = new Factory();
    int length = 6;
    const char** input = new const char*[length];
    input[0] = "./calculator";
    input[1] = "15"; 
    input[2] = "/"; 
    input[3] = "3"; 
    input[4] = "*"; 
    input[5] = "20";

    Base* equation = test->parse(const_cast <char**> (input), 6);

    EXPECT_EQ(equation->stringify(), "((15.000000) / (3.000000)) * (20.000000)");
    EXPECT_EQ(equation->evaluate(), 100);
}

TEST(FactoryTest, DoubleDigitDecimalInput){
    Factory* test = new Factory();
    int length = 6;
    const char** input = new const char*[length];
    input[1] = "35";
    input[2] = "/";
    input[3] = "0.5";
    input[4] = "*";
    input[5] = "20.2";

    Base* equation = test->parse(const_cast <char**> (input), 6);

    EXPECT_EQ(equation->stringify(), "((35.000000) / (0.500000)) * (20.200000)");
    EXPECT_EQ(equation->evaluate(), 1414);
}
