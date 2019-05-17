/*
   /\
   \ \
    \ \
    / /
   / /
  _\ \_/\/\
 /  *  \@@ =
|       |Y/
|       |~ The price of greatness is responsibility
 \ /_\ /                        - Winston Churchill
  \\ //     ___              _                   _
   |||     / __\_ _ _ __ ___| |__   ___  ___  __| |
  _|||_   / _\/ _` | '__/ __| '_ \ / _ \/ _ \/ _` |
 ( / \ ) / / | (_| | |  \__ \ | | |  __/  __/ (_| |
\^/^\^/^\\/   \__,_|_|  |___/_| |_|\___|\___|\__,_|
 --------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

  //-------------------------------------------------------------------------
  int n;
  // puts("please give me the size of your array:");
  scanf("%d", &n);
  if (n < 5 || n > 50) {
    puts("N must be between 5 and 50");
    return EXIT_FAILURE;
  }

  //-------------------------------------------------------------------------
  // allocate memory
  int *array;
  int *weights;
  array = malloc(n * sizeof(*array));
  weights = malloc(n * sizeof(*weights));

  //-------------------------------------------------------------------------
  //
  // puts("please enter items:");
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
    if (array[i] < 1 || array[i] > 100) {

      puts("Items must be between 0 and 100");
      free(array);
      free(weights);
      return EXIT_FAILURE;
    }
  }

  //-------------------------------------------------------------------------
  // now let's get weights:
  int sum = 0;
  int weighted_sum = 0;
  // puts("please enter weights:");
  for (int i = 0; i < n; i++) {
    scanf("%d", &weights[i]);
    if (weights[i] < 1 || weights[i] > 100) {

      puts("weights must be between 0 and 100");
      free(array);
      free(weights);
      return EXIT_FAILURE;
    }
    sum += weights[i];
    weighted_sum += weights[i] * array[i];
  }
  // now we have everything we need to calculate

  //-------------------------------------------------------------------------
  float result;

  result = (float)weighted_sum / (float)sum;
  printf("%.1f", result);

  //-------------------------------------------------------------------------
  // cleanup
  free(array);
  free(weights);

  return EXIT_SUCCESS;
}
