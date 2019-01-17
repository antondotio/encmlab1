// exG.c
// ENCM 369 Winter 2019 Lab 1 Exercise G

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ABS_F (5.0e-12)
#define POLY_DEGREE 4

double polyval(const double *a, int n, double x);
// Return a[0] + a[1] * x + ... + a[n] * pow(x, n).

int main(void)
{
    double f[ ] = {1.5, 0.7, -3.1, -1.2, 1.0};
    double dfdx[POLY_DEGREE];

    double guess;
    int max_updates;
    int update_count;
    int scan_count;
    int i;
    int close_enough = 0;
    
    double current_x, current_f, current_dfdx;

    printf("This program demonstrates use of Newton's Method to find\n"
           "approximate roots of the polynomial\nf(x) = ");
    printf("%.2f", f[0]);

    i = 1;
    first_for_start:
    if(i > POLY_DEGREE) goto first_for_end;
        if(f[i] < 0) goto first_else_code;
            printf(" + %.2f*pow(x,%d)", f[i], i);
            i++;
            goto first_for_start;
    first_else_code:
        printf(" - %.2f*pow(x,%d)", -f[i], i);
        i++;
        goto first_for_start;
    first_for_end: ;

    printf("\nPlease enter a guess at a root, and a maximum number of\n"
           "updates to do, separated by a space.\n");
    scan_count = scanf("%lf%d", &guess, &max_updates);

    if(scan_count == 2) goto correct_count;
        printf("Sorry, I couldn't understand the input.\n");
        exit(1);
    correct_count: ;
  
    if(max_updates >= 0) goto valid_input;
        printf("Sorry, a negative limit on updates does not make sense.\n");
        exit(1);
    valid_input: ;

    printf("Running with initial guess %f.\n", guess);

    i = POLY_DEGREE - 1;
    second_for_start:
    if(i < 0) goto second_for_end;
        dfdx[i] = (i + 1) * f[i + 1];
        i--;
        goto second_for_start;
    second_for_end: ;

    current_x = guess;
    update_count = 0;

    while_loop_start:
    if(!1) goto while_loop_end;
    current_f = polyval(f, POLY_DEGREE, current_x);
        printf("%d update(s) done; x is %.15f; f(x) is %.15e\n",
               update_count, current_x, current_f);

    if(fabs(current_f) > MAX_ABS_F) goto end_first_if;
        close_enough = 1;
            goto while_loop_end;
    end_first_if: ;

    if(update_count != max_updates) goto end_second_if;
        goto while_loop_end;
    end_second_if: ;

    current_dfdx = polyval(dfdx, POLY_DEGREE - 1, current_x);
        current_x -= current_f / current_dfdx;
        update_count++;
    goto while_loop_start;
    while_loop_end: ;
    
    if(!close_enough) goto second_else_code;
        printf("Stopped with approximate solution of %.12f.\n", 
               current_x);
        goto end_if;
    second_else_code:
        printf("%d updates performed, |f(x)| still >= %g.\n", 
               update_count, MAX_ABS_F);
        goto end_if;
    end_if: ;

    return 0;
}

double polyval(const double *a, int n, double x)
{
    double result = a[n];
    int i;

    i = n - 1;
    for_loop_start:
    if(i < 0) goto for_loop_end;
        result = x * result + a[i];
        i--;
        goto for_loop_start;
    for_loop_end: ;

    return result;
}
