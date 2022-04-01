#include <gtest/gtest.h>

extern "C" {
  #include "interface.h"
  #include "consistent_algorithm.h"
}

TEST (Interface, test_consistent_alg) {
  char str1[] = "EECCAABBDEEDDDCCDEE";
  char* arr1 = (char*)malloc(20 * sizeof(char));
  for (int i = 0; i < 20; ++i) {
    arr1[i] = str1[i];
  }
  EXPECT_EQ(consistent_algorithm(arr1), 2);

  char str2[] = "BBEEAADDDDBBDDDDDDDDAAAAABBBBBBEEEEEEAADDDDDEEEBBBBBCCEEECEEEEEEEEEEBBBBBBBCCCCCCBBBBBBDDCCCCCCDDBAAAAAEEEAAAAAAAAAADDDDDBBBBBBBBBBEEEAAAAAAAACCCCCCCCCDDDDDDDDDEEEEEEEEEAAAABBBBBBDDEEEEEEEEEBBBBBBBBB";
  char* arr2 = (char*)malloc(200 * sizeof(char));
  for (int i = 0; i < 200; ++i) {
    arr2[i] = str2[i];
  }
  EXPECT_EQ(consistent_algorithm(arr2), 2);
}

TEST (Interface, test_sequence_generator) {
  EXPECT_EQ(sequence_generator(20, 3, 2), 2);
}

TEST (Interface, test_interface) {
  EXPECT_EQ(delete_sequence(NULL), 1);
  FILE* fp = NULL;
  char str1[] = "20 3 2\n";
  fp = fmemopen(str1, 8, "r");
  EXPECT_EQ(call_sequence_generator(fp), 1);
  // EXPECT_EQ(call_consistent_alg(), 2);
  fclose(fp);
}

TEST (Consistent_algorithm, consistent_alg_functions) {
  EXPECT_EQ(delete_RLE(NULL), NOT_ALLOCATED);
  EXPECT_EQ(increase_arr_size(NULL), POINTER_ERROR);
}