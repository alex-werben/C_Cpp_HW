#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interface.h"

// Check number of series of different lengths
int check_occurancies(int arr[], int const n) {
  for (int i = 0; i < MAX_LENGTH; ++i) {
    if (i != n - 1) {
      if (arr[n - 1] - arr[i] <= 1) { // Если кол-во нужных серий недостаточно
        return 0;
      }
    }
  }
  return 1; // Кол-во нужных серий достаточно
}

// Generate series of specific length
void gen_series(char* sequence, int const length, int *size) {
  char sym = '\0';
  while ((sym = get_random_char()) == sequence[*size - 1]) {}
  // char sym = get_random_char();
  for (int i = 0; i < length; ++i) {
    sequence[(*size)++] = sym;
  }
  return;
}

// Save sequence into file
int write_data_to_file(char* sequence) {
  FILE* fp = NULL;
  fp = fopen("sequence.txt", "w");

  if (!fp) {
    return 1;
  }
  
  if (fprintf(fp, "%s", sequence) < 0) {
    return 1;
  }

  if (fclose(fp) == 0) {
    return 0;
  } else {
    return 1;
  }
}

// Sequence initialization
sequence* init_sequence() {
  sequence* obj = malloc(sizeof(sequence));
  if (!obj) {
    return NULL;
  }

  obj->arr = malloc(ARRAY_SIZE * sizeof(char));
  if (!obj->arr) {
    delete_sequence(obj);
    return NULL;
  }
  obj->occurancies = malloc(MAX_LENGTH * sizeof(int));
  if (!obj->occurancies) {
    delete_sequence(obj);
    return NULL;
  }
  for (int i = 0; i < MAX_LENGTH; ++i) {
    obj->occurancies[i] = 0;
  }
  obj->size = 0;
  
  return obj;
}

// Handle sequence generation
sequence* sequence_generator(int const n) {
  srand(time (NULL));

  sequence* seq = init_sequence();
  if (!seq) {
    return NULL;
  }

  while (seq->size < ARRAY_SIZE) {
    if (check_occurancies(seq->occurancies, n)) {

      int random_length = rand() % MAX_LENGTH + 1;
      ++seq->occurancies[random_length - 1];

      gen_series(seq->arr, random_length, &seq->size);
    } else {
      ++seq->occurancies[n - 1];
      
      gen_series(seq->arr, n, &seq->size);
    } 

    if (ARRAY_SIZE - seq->size <= MAX_LENGTH) {
      ++seq->occurancies[ARRAY_SIZE - seq->size - 2];

      gen_series(seq->arr, ARRAY_SIZE - seq->size - 1, &seq->size);

      seq->arr[seq->size++] = '\0';
    }
  }

  write_data_to_file(seq->arr);

  return seq;
}

// Generate random char
char get_random_char() {
  return 'A' + rand() % 5;
}

// Free allocated memory
int delete_sequence(sequence* obj) {
  if (obj->arr) {
    free(obj->arr);
    obj->arr = NULL;
  } else {
    return 1;
  }

  if (obj->occurancies) {
    free(obj->occurancies);
    obj->occurancies = NULL;
  } else {
    return 1;
  }

  if (obj) {
    free(obj);
    obj = NULL;
  } else {
    return 1;
  }

  return 0;
}