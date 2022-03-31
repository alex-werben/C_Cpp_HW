#include <stdlib.h>
#include <stdio.h>
#include "interface.h"

// Handle Run-Length Series
int length_series() {
  sequence* seq = NULL;

  seq = sequence_generator(2);

  print_values(seq->arr);

  delete_sequence(seq);

  return 0;
}

void print_values(char* arr) {
  for (size_t i = 0; i < 100; i++)
  {
    printf("%c", arr[i]);
  }
  printf("\n");
  
}