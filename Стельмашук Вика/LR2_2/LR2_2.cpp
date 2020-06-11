// Задание 2.2(6) Стельмашук В.А.(гр. №953506)

/* Численно убедиться в справедливости равенства, для чего для
заданного значения х вычислить его левую часть и разложение,
стоящее в правой части. При каком n исследуемое выражение
отличается от sin x менее, чем на заданную погрешность ε?
Испытать разложение на сходимость при разных значениях х.
*/

#include <stdio.h>
#include <math.h>

int fact(int n) //вычисление факториала 
{
    int factor = 1;
    for (int i = 1; i <= n; ++i) {
        factor *= (n + i);
        factor /= i;
    }
    return factor;
}

int Rec(double x, double e, int n, double sum) 
{
	if (fabs(sin(x) - sum) < e) {
		printf("Recursion: sin x = expression\n\n %lf = %lf\n\n", sin(x), sum);
		return n;
	}

	n++;
	sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
	return Rec(x, e, n, sum);
}

int main() 
{
	double x, e;
	printf("Enter x:\nx = ");
	scanf_s("%lf.20", &x);
	printf("Enter e:\ne = ");
	scanf_s("%lf", &e);
	printf("n = %d", Rec(x, e, 1., x));
	printf("\n");
	return 0;
}