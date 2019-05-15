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

  return EXIT_SUCCESS;
}
