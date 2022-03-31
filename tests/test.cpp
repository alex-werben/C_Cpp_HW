#include <gtest/gtest.h>

extern "C" {
  #include "interface.h"
}

TEST (Interface, print_test) {
  EXPECT_EQ(1, 1);
}