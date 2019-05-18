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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *elem1, const void *elem2) {
  const int *ca = elem1;
  const int *cb = elem2;
  return (*ca > *cb) - (*ca < *cb);
}

int main() {

  // we're going to subtract thirdquartile from firstquartile:
  // -------------------------------------------------------------------------------

  // lets find the length;
  int n = 0;
  scanf("%d", &n);

  if (n < 5 || n > 100) {
    puts("items count must be between 5 and 100");
    return EXIT_FAILURE;
  }

  // -------------------------------------------------------------------------------
  // let's get the last 2 lines (which includes n*2 items):

  int *array;
  array = malloc((2 * n) * sizeof(*array));

  // let's scan:
  int sum = 0; // sum of second line
  for (int i = 0; i < (2 * n); i++) {
    scanf("%d", &array[i]);
    if (i < n && (array[i] < 1 || array[i] > 100)) {
      puts("first line items must be between 1 and 100");
      free(array);
      return EXIT_FAILURE;
    }
    if (i >= n) {
      sum += array[i];
    }
    // check the conditions:
  }

  // check condition:
  if (sum < 1 || sum > 10 * 10 * 10) {
    puts("sum of first line items must be between 1 and 10*3");
    free(array);
    return EXIT_FAILURE;
  }

  // -------------------------------------------------------------------------------
  // let's generate second list:
  // int list[sum];
  int *list;
  list = malloc(sum * sizeof(int));

  int loc = 0;
  int newsum = 0;
  for (int i = 0; i < n; i++) {
    // let's iterate over items and add them to list:
    // { x1, x2, x3, f1, f2, f3}
    //   1    2   3  n+1 n+2 n+3
    int fi = array[i + n];
    for (int k = 0; k < fi; k++) {
      list[loc] = array[i];
      newsum += list[loc];
      loc++;
    }
  }

  // -------------------------------------------------------------------------------
  // let's write a compare function for qsort:
  /*
  https://en.wikipedia.org/wiki/Interquartile_range#Algorithm
  Quartiles are calculated recursively, by using median.[6]
  If the number of entries is an even number 2n, then the first
  quartile Q1 is defined as first quartile Q1 = median of the n smallest entries
  and the third quartile Q3 = median of the n largest entries[6]
  If the number of entries is an odd number 2n+1, then the first quartile Q1 is
  defined as first quartile Q1 = median of the n smallest entries and the third
  quartile Q3 = median of the n largest entries[6] The second quartile Q2 is the
  same as the ordinary median.[6]
     */
  qsort(list, sum, sizeof(*list), comp);
  int midpoint;
  float fq;
  float tq;
  midpoint = sum / 2;
  switch (midpoint % 2) {
  case 1:
    // printf("%d\n", midpoint);
    fq = (float)list[midpoint / 2];
    tq = (float)(list[midpoint + (int)ceil(midpoint / 2.0)] +
                 list[midpoint + (int)ceil(midpoint / 2.0)]) /

         2.0;
    break;

  case 0:
    fq = (float)(list[(midpoint / 2) - 1] + list[(midpoint / 2)]) / 2;
    tq = (float)(list[midpoint + (midpoint / 2)] +
                 list[midpoint + (midpoint / 2) + 1]) /
         2.0;
    break;
  }

  printf("%.1f", tq - fq);

  // -------------------------------------------------------------------------------
  // interquartile range is difference between third quartile and first
  // quartile:

  // -------------------------------------------------------------------------------
  // cleanups
  free(array);
  // free(list);
  return EXIT_SUCCESS;
}
