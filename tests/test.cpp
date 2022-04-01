#include <gtest/gtest.h>

extern "C" {
  #include "interface.h"
  #include "consistent_algorithm.h"
}

TEST (Interface, test_consistent_alg) {
  char str[] = "EECCAABBDEEDDDCCDEE";
  char* arr = (char*)malloc(20 * sizeof(char));
  for (int i = 0; i < 20; ++i) {
    arr[i] = str[i];
  }

  // call_consistent_alg();
  EXPECT_EQ(consistent_algorithm(arr), 2);
  // free(arr);
}

TEST (Interface, test_sequence_generator) {
  EXPECT_EQ(sequence_generator(20, 3, 2), 2);
}