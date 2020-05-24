#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define E 0.001

void Tesla(double x, double sum, int n);
void Iter(double x);
int fact(int n);

void main()
{
	double x;
	system("chcp 1251");
	system("cls");
	printf("¬ведите значение х\n -> x = ");
	scanf_s("%lf", &x);
	for(;x-3.14>=0; x-=3.14){}
	Iter(x);
	Tesla(x, 0, 1);
}

int fact(int n) {
	if (n < 2) return 1;
	return n * fact(n - 1);
}

void Iter(double x) {
	int n = 2;
	double sum = x;
	for (; fabs(sin(x) - sum) > E; n++) sum += pow(-1, n - 1) * powl(x, 2 * n - 1) / fact(2 * n - 1);
	printf(" ->сумма= %lf\n", sum);
	printf(" ->sin(x)= %lf\n", sin(x));
	printf(" ->n= %d\n\n", n);
}

void Tesla(double x, double sum, int n) {
	if (n == 1) 
		sum = x;
	else 
		sum += pow(-1, n - 1) * powl(x, 2 * n - 1) / fact(2 * n - 1);
	if (fabs(sin(x) - sum) > E) 
		Tesla(x, sum, n + 1);
	else 
	{
		printf(" ->сумма= %lf\n", sum);
		printf(" ->sin(x)=%lf\n", sin(x));
		printf(" ->n=%d\n\n", n);
	}
}