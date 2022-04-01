#include <gtest/gtest.h>

extern "C" {
  #include "interface.h"
  #include "consistent_algorithm.h"
}

TEST (Interface, test_consistent_alg) {
  // char str[] = "EECCAABBDEEDDDCCDEE";
  // char* arr = (char*)malloc(20 * sizeof(char));
  // for (int i = 0; i < 20; ++i) {
  //   arr[i] = str[i];
  // }
  // consistent_algorithm(arr);
  // call_consistent_alg();
  // EXPECT_EQ(call_consistent_alg(), 2);
  EXPECT_EQ(sequence_generator(20, 3, 2), 2);
  // free(arr);
}
