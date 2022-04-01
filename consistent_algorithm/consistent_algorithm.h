#ifndef CONSISTENT_SERIES
#define CONSISTENT_SERIES

#define BLOCK_SIZE 8

typedef struct {
  char* arr;
  char* representer;
  int* occurancies;
  int* length;
  int current_length;
  int arr_size;
  int max_size;
} RLE;

int consistent_algorithm(char*);
RLE* init_RLE(char*);
int delete_RLE(RLE*);
int fill_RLE(RLE*);
int check_length_existance(int[], int, int);
int increase_arr_size(RLE*);
int get_max_occurance_length(RLE*);
void print_info(RLE*);

#endif