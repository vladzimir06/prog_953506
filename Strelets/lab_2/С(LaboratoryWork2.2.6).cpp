//Задание 2.2 Вариант 6
#include <stdio.h>
#include <math.h>

double Teylor(int n,float x)
{
    int n1 = 2 * n - 1;
    double value = powl((-1), (n - 1)) * powl(x, (2 * n - 1));
    for (int i = 1; i <= n1; i++)
        value /= i;
    return value;
}

int fact(int factorial)
{
    if(factorial == 1)
        return factorial;
    else
        return fact(factorial - 1) * factorial;
}

double TeylorRec(float value, int &n, float x, float eps)
{
    double prom = powl((-1), (n - 1)) * powl(x, (2 * n - 1));
    int k = 2 * n - 1;
    for (int i = 1; i <= k; i++)
        prom /= i;
    n++;
    value += prom;
    if(fabs(sin(x) - value) < eps)
        return value;
    else
        return TeylorRec(value, n, x, eps);
}

int main()
{
    float x = 0, Eps = 0, a = 0;
    int n = 1, n1 = 1;
    double TeylorValue = 0, TeylorRecValue = 0;
    printf_s("Enter value of x = ");
    scanf_s("%f", &x);
    printf_s("Enter value of epsilon(size of error) = ");
    scanf_s("%f", &Eps);
    for (n = 1; fabs(sin(x) - TeylorValue) >= Eps; n++)
    {
       TeylorValue += Teylor(n, x);
    }
    TeylorRecValue = TeylorRec(a,n1,x,Eps);
    printf_s("\n Value of sin = %f", sin(x));
    printf_s("\n Value of Teylor sin = %f", TeylorValue);
    printf_s("\n Value of Teylor with recursion sin = %f", TeylorRecValue);
    printf_s("\n n = %d", n);
    printf_s("\n n with recursion = %d", n1);
}
