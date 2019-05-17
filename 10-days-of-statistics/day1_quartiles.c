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

int comp(const void *elem1, const void *elem2) {

  const int *ca = elem1;
  const int *cb = elem2;

  return (*ca > *cb) - (*ca < *cb);
}

int main() {
  // --------------------------------------------------------------------------------
  // let's get the array size:
  int n = 0;
  scanf("%d", &n);
  // check if n is in coorect range:
  if (n < 5 || n > 50) {
    puts("array size must be between 5 and 50");
    return EXIT_FAILURE;
  }

  // --------------------------------------------------------------------------------
  // now let's define and allocate memory for array:
  int *array;
  array = malloc(n * sizeof(*array));

  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
    // check for items validity:
    if (array[i] < 1 || array[i] > 100) {
      puts("items must be between 1 and 100");
      free(array);
      return EXIT_FAILURE;
    }
  }

  // -------------------------------------------------------------------------------
  // let's find median of items
  // remember that based on the task, the results guaranteed to be integers.
  qsort(array, n, sizeof(*array), comp);

  int midpoint = n / 2;
  // -------------------------------------------------------------------------------
  // first quartile is median of the first half.
  int first_half_midpoint = 0;
  int first_quartile = 0;
  int second_half_midpoint = 0;
  int third_quartile = 0;
  int second_quartile = 0;
  if (n % 2 != 0) {
    // if it's like {1, 2, 3, 4, 5, 6, 7} which midpoint is 7/2 =~ 3
    // so first half is 1 and second half is 5
    // 3 5 7 8 13 14 18 21
    second_quartile = array[midpoint];
    first_half_midpoint = ((n / 2) - 1) / 2; // =~ 1
    second_half_midpoint = first_half_midpoint + midpoint + 1;
    if (midpoint % 2 != 0) {
      first_quartile = array[first_half_midpoint];
      third_quartile = array[second_half_midpoint];
    } else {
      first_quartile =
          (array[first_half_midpoint] + array[first_half_midpoint - 1]) / 2;

      third_quartile =
          (array[second_half_midpoint] + array[second_half_midpoint - 1]) / 2;
    }
  } else {
    second_quartile = (array[midpoint] + array[midpoint - 1]) / 2;
    // if it's like {1, 2, 3, 4, 5, 6, 7, 8} which midpoint is 8/2 =~ 4
    // so first half is 2 and second half is 6
    first_half_midpoint = (n / 2) / 2;
    second_half_midpoint = first_half_midpoint + midpoint;

    if (midpoint % 2 != 0) {
      first_quartile = array[first_half_midpoint];
      third_quartile = array[second_half_midpoint];
    } else {
      // 3 4 4 4 7 10  | 12 12 14 16 17 18 | n=12, mid=6,
      first_quartile =
          (array[first_half_midpoint] + array[first_half_midpoint - 1]) / 2;

      third_quartile =
          (array[second_half_midpoint] + array[second_half_midpoint - 1]) / 2;
    }
  }
  // -------------------------------------------------------------------------------

  printf("%d\n", first_quartile);
  printf("%d\n", second_quartile);
  printf("%d\n", third_quartile);

  // --------------------------------------------------------------------------------
  // cleanups
  free(array);
  return EXIT_SUCCESS;
}
