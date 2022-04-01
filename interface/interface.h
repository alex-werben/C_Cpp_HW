#include <stdio.h>
#ifndef INTERFACE
#define INTERFACE

// Error codes
#define OPEN_FILE_ERROR 4
#define WRITE_DATA_ERROR 5

typedef struct sequence {
  char* arr;
  int* occurancies;
  int size;
} sequence;

int call_parallel_alg(void);
int call_consistent_alg(void);
int call_sequence_generator(FILE* fp);
int interface(int const);
char* read_data_from_file(void);

sequence* init_sequence(int const, int const);
char get_random_char(void);
int delete_sequence(sequence*);
int check_occurancies(int[], int const, int const);
void gen_series(sequence*, int const);
int sequence_generator(int const, int const, int const);
int write_data_to_file(char*);

#endif