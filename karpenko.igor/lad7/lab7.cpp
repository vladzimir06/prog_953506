//Задание 6.2 (27) Карпенко И.В.(гр. №953506)

/*Интерпол. База Интерпола содержит информацию о 
международных преступлениях и преступниках. База преступлений 
(место преступления, участники, последствия, комментарии 
специалистов), база преступных и террористических организаций 
(название, род деятельности, рейтинг опасности), база 
преступников (ФИО, кличка, рост, вес, цвет волос, особые приметы, 
гражданство, знание языков, род преступления, причастность к 
террористическим организациям, ссылки на список преступлений, 
ссылки на список преступных организаций). Просмотр и поиск 
информации по всем полям. Установление связей между 
преступниками и между организациями. Анализ, кто мог совершить 
данное преступление. Выборка «завязавших» в архив; удаление – 
только после смерти. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Menu.h"
#include "Search.h"
int main()
{
	Crime C = {0, NULL, NULL};
	Organization O = { 0, NULL, NULL};
	Criminal Cl = { 0, NULL, NULL};
	LoadCrime(C);
	LoadOrganization(O);
	LoadCriminal(Cl, O, C);
	int choice;
	do
	{
		MainMenu();
		scanf_s("%d", &choice);
		char unn = getchar();
		rewind(stdin);
		system("cls");
		if (unn != '\n') 
		{
			printf("You entered an invalid value!\n");
			continue;
		}
		switch(choice) 
		{
		case 1:
			CrimeMenu(C, O, Cl);
			break;
		case 2:
			OrgMenu(O);
			break;
		case 3:
			CriminalMenu(Cl,C,O);
			break;
		case 4:
			SearchMenu(C, O, Cl);
			break;
		case 5:
			SaveCrime(C);
			SaveOrganization(O);
			SaveCriminal(Cl);
			LoadCrime(C);
			LoadOrganization(O);
			LoadCriminal(Cl, O, C);
			printf("Data updated!\n");
			break;
		case 6:
			SaveCrime(C);
			SaveOrganization(O);
			SaveCriminal(Cl);
			printf("Data save!\n");
			break;
		case 7:
			LoadCrime(C);
			LoadOrganization(O);
			LoadCriminal(Cl, O, C);
			printf("Data uploaded!\n");
			break;
		case 8:
			exit(1);
			break;
		default: 
			puts("There is no such action");
		}
	} while (true);
	ClearCriminal(Cl);
	ClearCrime(C);
	ClearOrganization(O);
}