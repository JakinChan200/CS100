#include "gtest/gtest.h"

#include "vectorContainer_test.hpp"
#include "selectionSort_test.hpp"

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
