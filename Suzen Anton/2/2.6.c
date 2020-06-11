#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

float fact(float N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

int main() {
	int number = 0, n = 0;
	float f1 = 0, f2 = 0, x = 0, e = 0, h = 0;

	printf("Enter x \n");
	scanf("%f", &x);
	printf("Enter n \n");
	scanf("%d", &n);
	printf("Enter e \n");
	scanf("%d", &e);
	h = e;

	f1 = sin(x);
	for (int i = 1; i <= n; i++) {

		f2 += pow(-1, i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1);
		if (fabs(f2 - f1) > e) {
			number = i;

		}
	}

	printf("The accuracy achieved(yes) \n");
	printf("\n Number: \n");
	printf("%d \n", number);

	printf("The accuracy is not achieved(no) \n");




	printf("Left part: \n");
	printf("%f", f1);
	printf("\nRight part:  \n");
	printf("%f", f2);
	return 0;
}