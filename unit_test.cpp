#include "gtest/gtest.h"

#include "pow_test.hpp"
#include "sub_test.hpp"
#include "add_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
