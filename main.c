#include <stdio.h>
#include "interface.h"

int main(int argc, char* argv[]) {
  int n = 0;
  
  n = length_series(atoi(argv[1]));

  return 0;
}