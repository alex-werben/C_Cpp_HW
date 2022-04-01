// Copyright 2022 alex_werben
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "interface.h"

// Check number of series of different lengths
int check_occurancies(int arr[], int const n, int const max_length) {
  for (int i = 0; i < max_length; ++i) {
    if (i != n - 1) {
      if (arr[n - 1] - arr[i] <= 2) {  // not enough series
        return 0;
      }
    }
  }
  return 1;  // enough series
}

// Generate series of specific length
void gen_series(sequence *seq, int const length) {
  char sym = get_random_char();
  if (seq->size > 0) {
    while ((sym = get_random_char()) == seq->arr[seq->size - 1]) {
    }
  }
  // char sym = get_random_char();
  for (int i = 0; i < length; ++i) {
    seq->arr[seq->size++] = sym;
  }
  return;
}

// Save sequence into file
int write_data_to_file(char *sequence) {
  FILE *fp = NULL;
  fp = fopen("sequence.txt", "w");
  if (!fp) {
    return OPEN_FILE_ERROR;
  }

  if (fprintf(fp, "%s", sequence) < 0) {
    fclose(fp);
    return WRITE_DATA_ERROR;
  }

  fclose(fp);
  return 0;
}

// Sequence initialization
sequence *init_sequence(int const array_size, int const max_length) {
  sequence *obj = malloc(sizeof(sequence));
  if (!obj) {
    return NULL;
  }
  obj->arr = NULL;
  obj->occurancies = NULL;

  obj->arr = malloc(array_size * sizeof(char));
  if (!obj->arr) {
    delete_sequence(obj);
    return NULL;
  }
  obj->occurancies = malloc(max_length * sizeof(int));
  if (!obj->occurancies) {
    delete_sequence(obj);
    return NULL;
  }
  for (int i = 0; i < max_length; ++i) {
    obj->occurancies[i] = 0;
  }
  obj->size = 0;

  return obj;
}

// Handle sequence generation
int sequence_generator(int const array_size, int const max_length,
                       int const n) {
  srandom(time(NULL));

  sequence *seq = init_sequence(array_size, max_length);
  if (!seq) {
    return 1;
  }

  while (seq->size < array_size) {
    if (check_occurancies(seq->occurancies, n, max_length)) {
      int random_length = random() % max_length + 1;
      ++seq->occurancies[random_length - 1];
      gen_series(seq, random_length);
    } else {
      ++seq->occurancies[n - 1];
      gen_series(seq, n);
    }

    if (array_size - seq->size <= max_length) {
      ++seq->occurancies[array_size - seq->size - 2];

      gen_series(seq, array_size - seq->size - 1);

      seq->arr[seq->size++] = '\0';
    }
  }

  write_data_to_file(seq->arr);

  delete_sequence(seq);

  return n;
}

// Generate random char
char get_random_char() { return 'A' + random() % 5; }

// Free allocated memory
int delete_sequence(sequence *obj) {
  if (!obj) {
    return 1;
  }

  if (obj->arr) {
    free(obj->arr);
    obj->arr = NULL;
  }

  if (obj->occurancies) {
    free(obj->occurancies);
    obj->occurancies = NULL;
  }

  free(obj);
  obj = NULL;

  return 0;
}
