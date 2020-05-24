//Lab7 Var2
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>
#include "Dormitory.h"
#include <stdio.h>
#include <stdlib.h>

void Menu()
{
	printf_s("\n1 - Add a member to the dormitory");
	printf_s("\n2 - Delete a member from the dormitory");
	printf_s("\n3 - Serach by Name");
	printf_s("\n4 - Search by room number");
	printf_s("\n5 - Report");
	printf_s("\n6 - Info about workers");
	printf_s("\n7 - Add info to base");
	printf_s("\n8 - Exit\n");
}

int main()
{
	struct list *List = Init();
	Workers *workers;
	workers = (Workers*)malloc(5 * sizeof(Workers));
	LoadWorkers(workers);
	printf_s("Welcome to the Dormitory!");
	bool cycle = true;
	do
	{
		Menu();
		int switcher = 0;
		scanf_s("%d", &switcher);

		switch (switcher)
		{
			case 1: AddMember(List); break;
			case 2: DeleteMember(List); break;
			case 3: SearchName(List); break;
			case 4: SearchRoom(List); break;
			case 5: Report(List); break;
			case 6: 
				for (int i = 0; i < 5; i++)
				{
					printf_s("\n%s", workers[i].name);
					printf_s("\n%s", workers[i].number);
				}; break;
			case 7: AddToBase(List); break;
			case 8: cycle = false; break;
		}
	} 
	while (cycle);
	Delete(List, workers);
}