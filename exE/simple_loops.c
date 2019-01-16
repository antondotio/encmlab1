// simple_loops.c
// ENCM 369 Winter 2019 Lab 1 Exercise E

// INSTRUCTIONS:
//   Recode the definition of main in Goto-C
//   Make sure your modified program produces exactly the same
//   output as the original.

#include <stdio.h>

int main(void)
{
  int a[4] = { 1200, 3400, 5600, 7800 };
  int *p;
  int i;

  p = a;
  for_loop_start:
    if(p >= a + 4) goto for_loop_end;
      printf("%d\n", *p);
      p++;
      goto for_loop_start;
  for_loop_end:

  i = 234567;

  while_loop_start:
    if(i <= 0) goto while_loop_end;
      printf("%d\n", i);
      i /= 16;
      goto while_loop_start;
  while_loop_end:

  return 0;
}
