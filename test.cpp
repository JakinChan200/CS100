#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, LastSpotEmpty){
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "testBlank";
    EXPECT_EQ("testBlank", echo(3,test_val));
}

TEST(EchoTest, FirstSpotEmpty){
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[2] = "Blanktest";
    EXPECT_EQ("Blanktest", echo(3,test_val));
}

TEST(EchoTest, MiddleSpotEmpty){
    char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "testBlank"; test_val[3] = "Blanktest";
    EXPECT_EQ("testBlank Blanktest", echo(4,test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
