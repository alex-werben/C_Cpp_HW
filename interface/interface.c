// Copyright 2022 alex_werben
#include <stdlib.h>
#include <stdio.h>
#include "consistent_algorithm.h"
#include "interface.h"

// Handle Run-Length Series
int length_series(int n) {
  if (sequence_generator(n)) {
    return 1;
  }

  char* seq = read_data_from_file();

  int res = consistent_algorithm(seq);

  return res;
}

char* read_data_from_file(void) {
  FILE* fp = NULL;
  fp = fopen("sequence.txt", "r");
  if (!fp) {
    return NULL;
  }

  char* seq = NULL;
  seq = malloc(ARRAY_SIZE * sizeof(char));
  if (!seq) {
    fclose(fp);
    return NULL;
  }

  while (fscanf(fp, "%s", seq) != EOF) {}

  if (fclose(fp) == 0) {
    return seq;
  } else {
    if (seq) {
      free(seq);
    }
    return NULL;
  }

  return seq;
}
