#include <stdio.h>
#include <stdlib.h>

void ChoicePrint();
int choice(int k);
int enterBYN();
void value(int k);

int main()
{
	int k = -1;
	do
	{
		rewind(stdin);
		k = choice(k);
		printf("\n");
	} while (k != -2);



	return 0;
}


void ChoicePrint()
{
	printf("1. Enter in BYN    ");
	printf("2. BYN in USD, EUR, RUB   ");
	printf("3. The exchange rate   ");
	printf("4. The most valueable exchange for the bank   ");
	printf("5. Info   ");
	printf("6. Exit\n ");
}

int choice(int k)
{
	ChoicePrint();
	int t;
	t = getchar();
	switch (t) {
	case '1': {
		return enterBYN();
	}
	case '2': {
		if (k < 0)
		{
			printf("You've not entered cash in BYN\n\n");
			return k;
		}
		else
		{
			float l = k;
			printf("\n USD:  %f, EUR:  %f, RUB:  %f", l / (2.389), l / (2.699), l / (0.0354));
			return k;
		}
	}
	case '3': {
		printf("\nUSD: 2.389BYN\n EUR: 2.699BYN\n 100RUB: 3.54BYN");
		return k;
	}

	case '4':
	{
		value(1000);
		return k;
	}
	case '5':
	{
		printf("Nemiga st. 30,      +375 17 289 90 90\n");
		return k;
	}
	case '6': {
		return -2;
	}

			return k;
	}
}



int enterBYN()
{
	int res, n;
	do
	{
		printf("Enter cash in BYN\n>> ");
		res = scanf("%d", &n);
		rewind(stdin);
		if (res != 1 || n < 0) printf("\nInvalid input\n");
	} while (res != 1 || n < 0);
	return n;
}


void value(int k)
{
	float l = k;
	float u, e, r;
	u = l - ((l / 2.389) * 2.356);
	e = l - ((l / 2.699) * 2.66);
	r = l - ((l / 0.0354) * 0.0340);
	if (u > e && u > r) printf("the most valueable exchange is USD");
	if (e > r && e > u) printf("the most valueable exchange is EUR");
	if (r > e && r > u) printf("the most valueable exchange is RUB");
}