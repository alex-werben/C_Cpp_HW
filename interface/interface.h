#ifndef INTERFACE
#define INTERFACE

// Size of symbol array
#define ARRAY_SIZE 100 * 1000
// Maximum length of series
#define MAX_LENGTH 32

typedef struct sequence {
  char* arr;
  int* occurancies;
  int size;
} sequence;

int length_series(int);  
char* read_data_from_file(void);

sequence* init_sequence(void);
char get_random_char(void);
int delete_sequence(sequence*);
int check_occurancies(int[], int const);
void gen_series(sequence*, int const);
int sequence_generator(int const);
int write_data_to_file(char*);

#endif