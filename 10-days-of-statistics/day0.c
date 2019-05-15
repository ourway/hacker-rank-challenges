// Day 0: Mean, Median, and Mode
// day0.c
// https://www.hackerrank.com/challenges/s10-basic-statistics/problem
// Farsheed Ashouri
//  Thu 16 May 2019

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  // Based on the problem, the first line is Mean:
  mean = sum / (float)n;
  printf("%.1f", mean);
  return EXIT_SUCCESS;
}
