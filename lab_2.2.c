#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
#include <cstdio>
#include <cmath>
int _tmain(int argc, _TCHAR* argv[]) 
{
double x,e,sinX, element, rs;
do
{
printf("Enter x:");
rewind(stdin);
} while (!scanf_s("%lf", &x));


do
{
printf("Enter e:");
rewind(stdin);
} while (!scanf_s("%lf", &e));

sinX = sin(x);
printf("sin(x)=%lf\n", sinX);

element = x;
rs = 1 + e;

double sum = 0.0;
int i;
for (i = 1; rs > e; i++)
{
sum += element;
element *= (-1.0) * x * x / (2.0 * i) / (2.0 * i + 1.0);
rs = fabs(sinX - sum);
}

printf("sum=%lf\n", sum);
printf("When n=%d,  error", i-1);

getch();
return 0;

}

