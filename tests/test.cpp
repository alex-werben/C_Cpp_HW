#include <gtest/gtest.h>

extern "C" {
  #include "interface.h"
  #include "consistent_algorithm.h"
}

TEST (Interface, test_consistent_alg) {
  sequence_generator(20, 3, 2);
  char arr[] = "EECCAABBDEEDDDCCDEE";
  consistent_algorithm(arr);
  // EXPECT_EQ(call_consistent_alg(), 2);
}
