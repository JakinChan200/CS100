
#include "gtest/gtest.h"

#include "movieComp_test.hpp"
#include "main_test.hpp"
#include "visitor_test.hpp"
#include "decorator_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
/*
// If more efficient we can split the unit_testing into multiple files based on what we want to test

#include "gtest/gtest.h"

// #include any necessary classes here

using namespace std;


Write tests here of format..

TEST(TestType, TestName) {
	...
	...
	EXPECT_EQ(expression1, expression2);
}
*/
