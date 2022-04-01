// Copyright 2022 alex_werben
#include "interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dlfcn.h>

#include "consistent_algorithm.h"

// Handle consistent algorithm work
int call_consistent_alg() {
  char *seq = read_data_from_file();
  clock_t start, stop;

  start = clock();
  int res = consistent_algorithm(seq);
  stop = clock();

  printf("Consistent algorithm work time - %lu\n", (stop - start));

  return res;
}

// Handle sequence generation
int call_sequence_generator(FILE* fp) {
  int arr_size = 0;
  int max_length = 0;
  int length = 0;

  printf("Enter size of symbol array that will be generated: ");
  if (fscanf(fp, "%d", &arr_size) == EOF) {
    printf("Error: number must be written.\n");
    return 1;
  }

  printf("Enter maximum length of series: ");
  if (fscanf(fp, "%d", &max_length) == EOF) {
    printf("Error: number must be written.\n");
    return 1;
  }

  printf("Enter what length should occur most frequently: ");
  if (fscanf(fp, "%d", &length) == EOF) {
    printf("Error: number must be written.\n");
    return 1;
  }

  sequence_generator(arr_size, max_length, length);

  return 0;
}

// // Handle parallel algorithm work
// int call_parallel_alg() {
//   // void* library;
//   char *seq = read_data_from_file();
//   clock_t start, stop;

//   start = clock();
//   int res = parallel_algorithm(seq);
//   stop = clock();

//   printf("Parallel algorithm work time - %lu\n", (stop - start));

//   return res;
// }

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
    free(seq);
    return NULL;
  }
}
