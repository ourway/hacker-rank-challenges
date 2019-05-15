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

// Day 0: Mean, Median, and Mode
// day0.c
// https://www.hackerrank.com/challenges/s10-basic-statistics/problem
// Farsheed Ashouri
//  Thu 16 May 2019

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *elem1, const void *elem2) {
  //
  const int *ca = elem1;
  const int *cb = elem2;
  return (*ca > *cb) - (*ca < *cb);
}

int main() {

  // let's initialize vars
  int n = 0;
  int *numbers;

  int sum = 0;
  float mean = 0;
  // now let's get first input which is size of array:
  scanf("%d", &n);
  // now let's check n conditions
  if (n < 10 || n > 2500) {
    puts("array size must be between 10 and 2500");
    return EXIT_FAILURE;
  }

  // free memory:
  numbers = malloc(n * sizeof(*numbers));
  // let's read the array list from the rest
  // also I will keep record of sum of all
  for (int i = 0; i < n; i++) {
    scanf("%d", &numbers[i]);
    sum += numbers[i];
  };
  // ----------------------------------------------------------------------
  // Based on the problem, the first line is Mean:
  mean = sum / (float)n;
  printf("%.1f\n", mean);
  // ----------------------------------------------------------------------
  // Second line is the median.  For this, first we need to sort the data to
  // increasing or decreasing order
  // I will use qsort() for this, it gets array, number of elements, size of
  // each element and finally a comparison funciton. Comparison function will
  // get pointer to two numbers:
  // and of-course qsort will magicly sort the data:
  qsort(numbers, n, sizeof(*numbers), comp);
  // ----------------------------------------------------------------------
  // now that we have sorted numbers, let's see if the number count is odd or
  // even. if it's odd, we'll pick the middle number, else, we'll pick average
  // of two, so:
  float median;
  int middle_element = n / 2;
  if (n % 2 == 0) {
    // it's even
    median = (numbers[middle_element] + numbers[middle_element - 1]) / 2.0;

  } else {
    median = numbers[middle_element];
  }
  printf("%.1f\n", median);

  // ----------------------------------------------------------------------
  // now let's find mode.  It's the hardest part i guess since it will take
  // some calculations of count the number of occurences for each item.
  int *counts;
  // allocate memorty
  counts = malloc(n * sizeof(*counts));
  // now
  counts[0] = 1; // first item
  for (int i = 1; i < n; i++) {
    counts[i] = 1; // init
    for (int k = i - 1; k >= 0; k--) {
      if (numbers[i] == numbers[k]) {
        counts[i] += 1;
      }
    }
  }

  int max = counts[0];
  int loc = 0;
  for (int i = 1; i < n; i++) {
    if (counts[i] > max) {
      // set the max and get location
      max = counts[i];
      loc = i;
    }
  }

  // now that we have the location of most occurences, let's see how many
  // numbers has the same repeat number:

  int *modes;
  modes = malloc((n / max) * sizeof(*modes)); // max count is n/max
  modes[0] = numbers[loc];
  int mode_counter = 1;

  for (int i = 0; i < n; i++) {
    if (i != loc && counts[i] == max) {
      modes[mode_counter] = numbers[i];
      mode_counter += 1;
    }
  }

  int mode = modes[0];
  // if the mode_counter is 1:
  if (mode_counter > 1) {
    // let's find minimum of all:
    for (int i = 1; i < mode_counter; i++) {
      if (modes[i] < mode) {
        mode = modes[i];
      }
    }
  }
  printf("%d", mode);

  // ----------------------------------------------------------------------------------
  free(numbers);
  free(counts);
  free(modes);
  return EXIT_SUCCESS;
}
