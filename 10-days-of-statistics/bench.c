#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i;

  clock_t start = clock();
  for (i = 0; i <= 100000000; i++) {
    sqrt(i);
  }
  printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
  return EXIT_SUCCESS;
}
