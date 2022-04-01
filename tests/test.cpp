#include <gtest/gtest.h>

extern "C" {
  #include "interface.h"
}

// TEST (Interface, test_check_occurancies) {
//   int arr1[] = {1, 6, 0, 3, 2};
//   int n1_good = 2, n1_bad = 4;

//   EXPECT_EQ(check_occurancies(arr1, n1_good), 1);
//   EXPECT_EQ(check_occurancies(arr1, n1_bad), 0);
// }

TEST (Interface, test_sequence_generator) {
  EXPECT_EQ(sequence_generator(2), 0);
}

TEST (Interface, test_length_series) {
  EXPECT_EQ(length_series(2), 2);
}