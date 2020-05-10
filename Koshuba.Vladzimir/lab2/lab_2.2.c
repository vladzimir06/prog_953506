#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
#include <stdio.h>
#include <math.h>

double fact(int n, double g)
{
   if(n != 0){
	   g /= n;
	   return n *= fact(n - 1, g);

   }
   else if(n == 0) return g;
}

int iter(double x, double e, double rez)
{
    double a = 0, g;
    int n = 1;
    for ( ; ; n++){
        g = pow(-1, (n-1)) * pow(x , (2 * n - 1));
        for(int i = 1; i <= (2 * n - 1); i++)
        {
            g /= i;
        }
        a += g;
        if(a - e <= rez && rez <= a + e){
            break;
        }
        printf("\nIteration: %lf", a);
    }
    return n;
}

double rec(double x, double e, double rez, double sum, int n)
{
    double g = pow(-1, (n-1)) * pow(x , (2 * n - 1));
	   int f = fact((2 * n) - 1, g);
    for(int i = 1; i <= (2 * n - 1); i++)
    {
            g /= i;
    }
    sum += g;
    printf("\nRekursia: %lf", sum);
    if(sum - e <= rez && rez <= sum + e){
        return n;
    }
    return rec(x, e, rez, sum, n + 1);
}

int main()
{
    double e, rez, x, sum = 0;
    int n = 1, rez2;
    printf ("Write x:\n");
    scanf ("%lf", &x);
    printf ("Write e:\n");
    scanf ("%lf", &e);

    rez = sin(x);
    rez2 = iter(x, e, rez);
    printf("\nNecessary n with iteration: %d",rez2);
    rez2 = rec(x, e, rez, sum, n);
    printf("\nNecessary n with recursion: %d",rez2);
    printf("\nRezult(sin): %lf",rez);
    return 0;
}
