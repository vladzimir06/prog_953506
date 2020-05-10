//Задание 3.2 Вариант 7
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int firstindex = 0, secondindex = 0, row = 0, column = 0, size = 0;
	char ForArray = '*';
	printf_s("Enter matrix size: ");
	scanf_s("%d %d", &firstindex, &secondindex);
	int amountelements = firstindex * secondindex;
	char** array = (char**)malloc(firstindex * sizeof(char*));

	for (char i = 0; i < secondindex; i++)
		array[i] = (char*)malloc(secondindex * sizeof(char));

	for (int i = 0; i < firstindex; i++)
		for (int j = 0; j < secondindex; j++)
			array[i][j] = '*';

	bool firstcycle = true;
	printf_s("Enter how much elements you want to change ");
	scanf_s("%d", &size);
	while (firstcycle)
	{
		bool secondcycle = true;
		int data = 0;

		printf_s("Enter triplet: ");
		do 
			scanf_s("%c", &ForArray);
		while (ForArray == '\n' || ForArray == '\r');
		scanf_s("%d %d", &row, &column);
		if (row == -1 || column == -1)
			break;
		array[row][column] = ForArray;
		while (secondcycle)
		{
			printf_s("\nDo you want to reenter data?(yes - 1, no - any other key)");
			scanf_s("%d", &data);
			if (data == 1)
			{
				scanf_s("%d", &row);
				scanf_s("%d", &column);
				do
					scanf_s("%c", &ForArray);
				while (ForArray == '\n' || ForArray == '\r');
				data++;
			}
			else
				secondcycle = false;
		}
		size--;
		if (size <= 0)
			firstcycle = false;

	}
	for (int i = 0; i < firstindex; i++)
	{
		printf_s("\n");
		for(int j = 0; j < secondindex; j++)
			printf_s("%c", array[i][j]);
	}
}