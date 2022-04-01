// Copyright 2022 alex_werben
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "consistent_algorithm.h"

// Handle interface
int call_consistent_alg() {
  char* seq = read_data_from_file();

  int res = consistent_algorithm(seq);

  return res;
}

// Handle sequence generation
int call_sequence_generator() {
  int arr_size = 0;
  int max_length = 0;
  int length = 0;

  printf("Enter size of symbol array that will be generated: ");
  if (scanf("%d", &arr_size) == 0) {
      printf("Error: number must be written.\n");
      return 1;
  }

  printf("Enter maximum length of series: ");
  if (scanf("%d", &max_length) == 0) {
      printf("Error: number must be written.\n");
      return 1;
  }

  printf("Enter what length should occur most frequently: ");
  if (scanf("%d", &length) == 0) {
      printf("Error: number must be written.\n");
      return 1;
  }

  sequence_generator(arr_size, max_length, length);

  return 0;
}

char *read_data_from_file(void) {
  FILE *fp = NULL;
  fp = fopen("sequence.txt", "r");
  if (!fp) {
    return NULL;
  }

  int array_size = 0;
  fseek(fp, 0, SEEK_END);
  array_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *seq = NULL;
  seq = malloc(array_size * sizeof(char));
  if (!seq) {
    fclose(fp);
    return NULL;
  }

  while (fscanf(fp, "%s", seq) != EOF) {
  }

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
