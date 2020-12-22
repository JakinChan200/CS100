#include "../src/rectangle.cpp"
#include "gtest/gtest.h"

using namespace std;

TEST(testingArea, AreaTestZeroWidth){
    Rectangle *test1 = new Rectangle(0, 3);
    EXPECT_EQ(test1->area(), 0);
}

TEST(testingArea, AreaTestZeroHeight){
    Rectangle *test1 = new Rectangle(2, 0);
    EXPECT_EQ(test1->area(), 0);
}

TEST(testingArea, AreaTestNoRectangle){
    Rectangle *test1 = new Rectangle(0, 0);
    EXPECT_EQ(test1->area(), 0);
}

TEST(testingArea, AreaTestSquareRectangle){
    Rectangle *test1 = new Rectangle(2, 2);
    EXPECT_EQ(test1->area(), 4);
}

TEST(testingArea, AreaTestTwoByFour){
    Rectangle *test1 = new Rectangle(2, 4);
    EXPECT_EQ(test1->area(), 8);
}

TEST(testingPerimeter, PerimeterTestZeroWidth){
    Rectangle *test1 = new Rectangle(0, 3);
    EXPECT_EQ(test1->perimeter(), 6);
}

TEST(testingPerimeter, PerimeterTestZeroHeight){
    Rectangle *test1 = new Rectangle(4, 0);
    EXPECT_EQ(test1->perimeter(), 8);
}

TEST(testingPerimeter, PerimeterTestNoRectangle){
    Rectangle *test1 = new Rectangle(0, 0);
    EXPECT_EQ(test1->perimeter(), 0);
}

TEST(testingPerimeter, PerimeterTestSquareRectangle){
    Rectangle *test1 = new Rectangle(3, 3);
    EXPECT_EQ(test1->perimeter(), 12);
}

TEST(testingPerimeter, PerimeterTestTwoByFour){
    Rectangle *test1 = new Rectangle(2, 4);
    EXPECT_EQ(test1->perimeter(), 12);
}

TEST(testingConstructor, ConstructorTestWidthTwo){
    Rectangle *test1 = new Rectangle(2, 4);
    EXPECT_EQ(test1->getWidth(), 2);
}

TEST(testingConstructor, ConstructorTestHeightTwo){
    Rectangle *test1 = new Rectangle(3, 2);
    EXPECT_EQ(test1->getHeight(), 2);
}

TEST(testingConstructor, ConstructorTestZeroWidth){
    Rectangle *test1 = new Rectangle(0, 4);
    EXPECT_EQ(test1->getWidth(), 0);
}

TEST(testingConstructor, ConstructorTestZeroHeight){
    Rectangle *test1 = new Rectangle(2, 0);
    EXPECT_EQ(test1->getHeight(), 0);
}

TEST(testingConstructor, ConstructorTestSameWidthHeight){
    Rectangle *test1 = new Rectangle(2, 2);
    EXPECT_EQ(test1->getWidth(), 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
