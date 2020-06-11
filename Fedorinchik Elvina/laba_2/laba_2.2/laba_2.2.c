// laba 2 c
// elvina fedorinchik
// численно убедиться в справедливости равенства

#include <stdio.h>
#include <math.h>
#include "custom_function_calc.h"

#define M_PI 3.16159265358979323846

int main() {
    double x;
    double epsilon = 0.0001;
    int n;

    printf("Enter x : ");
    while (get_double(&x) != 0) {
        printf("Incorrect input, try again : ");
    }
    printf("Calculation by library function : sin(x) = %0.6f", sin(x));
    printf("\nCalculation by custom function : sin(x) = %0.6f ", iterative_calc(x, epsilon, &n));
    printf("(number of sequence members : %d)", n);
}