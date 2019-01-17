// exH.c
// ENCM 369 Winter 2019 Lab 1 Exercise H

#include <stdio.h>

void print_array(const char *str, const int *a, int n);
// Prints the string given by str on stdout, then
// prints a[0], a[1], ..., a[n - 1] on stdout on a single line.

void sort_array(int *a, int n);
// Sorts a[0], a[1], ..., a[n - 1] from smallest to largest.

int main(void)
{
  int test_array[] = {440, 220, 330, 550, 330, 660, 110, 330, 440};

  print_array("before sorting ...", test_array, 9);
  sort_array(test_array, 9);
  print_array("after sorting ...", test_array, 9);
  return 0;
}

void print_array(const char *str, const int *a, int n)
{
  int i;
  puts(str);
  
  i = 0;
  for_loop_start:
  if(i >= n) goto for_loop_end;
    printf("    %d", a[i]);
    i++;
    goto for_loop_start;
  for_loop_end: ;

  printf("\n");
}

void sort_array(int *a, int n)
{
  // This is an implementation of an algorithm called selection sort.

  int i, j, min, j_of_min;
  
  i = 0;
  outer_for_start:
  if(i >= n-1) goto outer_for_end;
    min = a[i];
    j_of_min = i;
  j = i + 1;
  inner_for_start:
  if(j >= n) goto inner_for_end;
    if(a[j] >= min) goto end_if;
      min = a[j];
      j_of_min = j;
  end_if: ;
      j++;
      goto inner_for_start;
  inner_for_end: ;
    a[j_of_min] = a[i];
    a[i] = min;
    i++;
    goto outer_for_start;
  outer_for_end: ;

}
