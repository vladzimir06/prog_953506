//Задание 2.1 Вариант 8
#include <stdio.h>
#include <stdlib.h>

void PrintMenu()
{
	printf_s(" Entering input parameters for the tariff - 1");
	printf_s("\n Calculationg of the optimal tariff - 2");
	printf_s("\n Information services - 3");
	printf_s("\n Feedback - 4");
	printf_s("\n Exit from the programm - 5");
	printf_s("\n **unlim == 999999, So if you want to choose unlim, enter 999999\n");
}

void Print(char* Name, int Minutes, float Traffic, int MinutesToAllOpearators, float Price)
{
	printf_s(" Name of tarrif: %s", Name);
	printf_s("\n Amount of minutes: %d", Minutes);
	printf_s("\n Amount of traffic: %f", Traffic);
	printf_s("\n Amount of minutes to all operators: %d ", MinutesToAllOpearators);
	printf_s("\n Price: %f \n\n", Price);
}

int SearchMax(int t[])
{
	int max = 0, max2 = 0;
	for (int i = 0; i < 6; i++)
	{
		if (t[i] > max)
		{
			max = t[i];
			max2 = i;
		}
	}
	return max2;
}

int main()
{
	int par = 0,
		Minutes[7] = { 0, 400, 999999, 400, 200, 1000, 999999 },
		MinutesToAllOperators[7] = { 0, 400, 999999, 400, 0, 1000, 999999 },
		cycle = 1,
		t[6] = {0,0,0,0,0,0},
		max = 0;
	float  Price[7] = { 0, 16.5, 25, 17.7, 10.4, 52.98, 143.41 }, Traffic[7] = { 0, 999999, 20, 8, 1, 10, 999999 };
	char Name[6][12] = { "Bezlimit2.0" , "SuperMax", "SuperEight", "Super", "Ultra", "Absolut" };
	do
	{
		PrintMenu();
		printf_s(" Your choose: ");
		scanf_s("%d", &par);
		switch (par)
		{
		case 1: system("cls"), printf_s("Enter amount of minutes = "), 
				scanf_s("%d", &Minutes[0]), printf_s("Enter amount of traffic(gb) = "), 
				scanf_s("%f", &Traffic[0]), printf_s("Enter amount of minutes to all operators = "),
				scanf_s("%d", &MinutesToAllOperators[0]), printf_s("Enter price that you can pay = "),
				scanf_s("%f", &Price[0]),system("cls"); break;
		case 2: for (int i = 1, j = 0; i < 7; i++, j++)
		{
			if (Minutes[i] >= Minutes[0]) t[j]++;
			if (Traffic[i] >= Traffic[0]) t[j]++;
			if (MinutesToAllOperators[i] >= MinutesToAllOperators[0]) t[j]++;
			if (Price[i] <= Price[0]) t[j]++;
		}
			max = SearchMax(t);
			printf_s("%d", max);
			Print(Name[max], Minutes[max+1], Traffic[max+1], MinutesToAllOperators[max+1], Price[max+1]); 
			break;
		case 3:system("cls");
			for(int i = 0, j = 1; i < 6; i++, j++)
			{
				Print(Name[i], Minutes[j], Traffic[j], MinutesToAllOperators[j], Price[j]);
			}; break;
		case 4:system("cls"),
			   printf_s("Feedback: www.mts.by \n\n\n"); break;
		default: cycle = 0; break;
		}
	} while (cycle);
	exit(0);
}


