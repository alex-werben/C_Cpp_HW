#include <gtest/gtest.h>

extern "C" {
  #include "interface.h"
  #include "consistent_algorithm.h"
}

TEST (Interface, test_consistent_alg) {
  
  EXPECT_EQ(sequence_generator(20, 3, 2), call_consistent_alg());
}

// TEST (Interface, test_length_series) {
//   EXPECT_EQ(length_series(2), 2);
// }