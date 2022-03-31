#ifndef INTERFACE
#define INTERFACE

// Size of symbol array
// #define ARRAY_SIZE 100 * 1000 * 1000
#define ARRAY_SIZE 20
// Maximum length of series
#define MAX_LENGTH 3

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
void gen_series(char*, int const, int*);
int sequence_generator(int const);
int write_data_to_file(char*);

// TEST FUNC
void print_values(char*);

#endif