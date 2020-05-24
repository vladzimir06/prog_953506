#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Crimes.h"

void MainMenu()
{
	printf("Select an action:\n");
	printf("1)Show all crimes\n");
	printf("2)Show all organization\n");
	printf("3)Show all criminals\n");
	printf("4)Search\n");
	printf("5)Update info(Save all and Load all again.)\n");
	printf("6)Save\n");
	printf("7)Reload\n");
	printf("8)Exit\n");
}
/*-----------------------------*/
void OneCrimeMenu(Crime& C, int index, Organization& O, Criminal& Cl)
{
	int i = index;
	if (index > C.size - 1 || index < 0)
	{
		return;
	}
	CrimeNode* NewNode = C.head;
	while (index > 0)
	{
		NewNode = NewNode->pNext;
		index--;
	}
	int choice;
	do {
		printf("Crime scene:\t\t%s", NewNode->crimeScene);
		printf("Participants:\t\t%s", NewNode->participant);
		printf("Consequences:\t\t%s", NewNode->consequences);
		printf("Experts comments:\t%s", NewNode->experComments);
		printf("\n\n1)Search for suspects\n2)Delete\n3)back\n");

		scanf_s("%d", &choice);
		char unn = getchar();
		rewind(stdin);
		system("cls");
		if (unn != '\n' || (choice > C.size + 1 && choice < 1))
		{
			printf("You entered an invalid value!\n");
			continue;
		}
		if (choice == 1)
		{
			Suspects(NewNode, O, Cl);
		}
		if (choice == 2)
		{
			printf("Are you sure you want to delete this organization?\n1)Yes\n2)No\n");
			scanf_s("%d", &choice);
			system("cls");
			char unn = getchar();
			rewind(stdin);
			if (unn != '\n' || (choice > C.size + 1 && choice < 1))
			{
				printf("You entered an invalid value!\n");
				continue;
			}
			if (choice == 1)
				DeleteCrime(C, i);
			else continue;
			return;
		}
		if (choice == 3) break;
	} while (true);
	return;
}
void CrimeMenu(Crime& C, Organization& O, Criminal& Cl)
{
	int choice;
	do {
		CrimeNode* NewNode = C.head;
		if (NewNode == NULL) return;
		int i = 1;
		do
		{
			printf("%d)%s", i, NewNode->crimeScene);
			printf("%s", NewNode->participant);
			printf("%s", NewNode->consequences);
			printf("%s", NewNode->experComments);
			printf("\n");
			NewNode = NewNode->pNext;
			i++;
		} while (NewNode);
		printf("\n");
		printf("\n");

		printf("\n%d)Add\n%d)back\n", i, i + 1);

		scanf_s("%d", &choice);
		char unn = getchar();
		rewind(stdin);
		system("cls");
		OneCrimeMenu(C, choice - 1, O, Cl);
		if (unn != '\n')
		{
			printf("You entered an invalid value!\n");
			continue;
		}
		if (choice == i) WriteCrime(C);
		if (choice == i + 1) break;
	} while (true);
}


/*-----------------------------*/
int OrgNames(Organization& O)
{
	OrganizationNode* NewNode = O.head;
	if (NewNode == NULL) return 1;
	int i = 0;
	do
	{
		i++;
		printf("%d)%s", i, NewNode->name);
		NewNode = NewNode->pNext;
	} while (NewNode);
	return i + 1;
}

bool PrintOneOrg(Organization& O, int index)
{
	int i = index;
	if (index > O.size - 1 || index < 0)
	{
		return false;
	}
	OrganizationNode* NewNode = O.head;
	while (index > 0)
	{
		NewNode = NewNode->pNext;
		index--;
	}

	int choice;
	do {
		printf("Name:\t\t%s", NewNode->name);
		printf("Activities:\t%s", NewNode->occupation);
		printf("Rating:\t\t%s", NewNode->rating);
		printf("\n\n1)Delete\n2)back\n");

		scanf_s("%d", &choice);
		char unn = getchar();
		rewind(stdin);
		system("cls");
		if (unn != '\n' || (choice > O.size + 1 && choice < 1))
		{
			printf("You entered an invalid value!\n");
			continue;
		}
		if (choice == 1)
		{
			printf("Are you sure you want to delete this organization?\n1)Yes\n2)No\n");
			scanf_s("%d", &choice);
			system("cls");
			char unn = getchar();
			rewind(stdin);
			if (unn != '\n' || (choice > O.size + 1 && choice < 1))
			{
				printf("You entered an invalid value!\n");
				continue;
			}
			if (choice == 1)
				DeleteOrganization(O, i);
			else continue;
			return true;
		}
		if (choice == 2) break;
	} while (true);
	return true;
}

void OneOrgMenu(Organization& O, int index)
{
	PrintOneOrg(O, index);
}

void OrgMenu(Organization& O)
{
	int choice;
	do {
		printf("Choose an organization:\n");
		int back = OrgNames(O);
		printf("\n%d)Add\n%d)back\n", back, back + 1);

		scanf_s("%d", &choice);
		char unn = getchar();
		rewind(stdin);
		system("cls");
		if (unn != '\n' || (choice > O.size + 1 && choice < 1))
		{
			printf("You entered an invalid value!\n");
			continue;
		}
		if (choice == back) WriteOrganization(O);
		if (choice == back + 1) break;
		OneOrgMenu(O, choice - 1);

	} while (true);

}
/*-----------------------------*/
int CriminalNames(Criminal& Cl)
{
	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return 1;
	int i = 0;
	do
	{
		i++;
		printf("%d)%s", i, NewNode->One.fullname);
		NewNode = NewNode->pNext;
	} while (NewNode);
	return i + 1;
}

CriminalNode* PrintOneCriminal(Criminal& Cl, int index)
{
	if (index > Cl.size - 1 || index < 0)
	{
		return NULL;
	}
	CriminalNode* NewNode = Cl.head;
	while (index > 0)
	{
		NewNode = NewNode->pNext;
		index--;
	}
	printf("Fullname:\t%s", NewNode->One.fullname);
	printf("Nickname:\t%s", NewNode->One.nickname);
	printf("Height:\t\t%s", NewNode->One.height);
	printf("Weight:\t\t%s", NewNode->One.weight);
	printf("Hair color:\t%s", NewNode->One.color);
	printf("Specials:\t%s", NewNode->One.special);
	printf("Nationality:\t%s", NewNode->One.nationality);
	printf("Languages:\t%s", NewNode->One.languages);
	printf("Crime type:\t%s", NewNode->One.crimetype);
	printf("Organizations:\t");
	PrintOrgName(NewNode->One.organizationlist);
	printf("\n");
	return NewNode;
}

void OneCriminalMenu(Criminal& Cl, int index)
{
	int choice;
	do {
		CriminalNode* NewNode = PrintOneCriminal(Cl, index);
		printf("\n\nSelect an action:\n");
		printf("1)Show crime\n");
		printf("2)Delete\n");
		printf("\n3)back\n");

		scanf_s("%d", &choice);
		char unn = getchar();
		rewind(stdin);
		system("cls");
		if (unn != '\n')
		{
			printf("You entered an invalid value!\n");
			continue;
		}

		switch (choice)
		{
		case 1:
			PrintCrime(NewNode->One.crimelist);
			break;
		case 2:
		{
			printf("Are you sure you want to delete this organization?\n1)Yes\n2)No\n");
			scanf_s("%d", &choice);
			system("cls");
			char unn = getchar();
			rewind(stdin);
			if (unn != '\n' || (choice > Cl.size + 1 && choice < 1))
			{
				printf("You entered an invalid value!\n");
				continue;
			}
			if (choice == 1)
			{
				DeleteCriminal(Cl, index);
				return;
			}
			else continue;
			break;
		}
		default:
			break;
		}
		if (choice == 3) break;

	} while (true);

}
void CriminalMenu(Criminal& Cl, Crime& C, Organization& O)
{
	int choice;
	do {
		printf("Choose a criminal:\n");
		int back = CriminalNames(Cl);
		printf("\n%d)Add\n%d)back\n", back, back + 1);

		scanf_s("%d", &choice);
		char unn = getchar();
		rewind(stdin);
		system("cls");
		if (unn != '\n' || (choice > Cl.size + 1 && choice < 1))
		{
			printf("You entered an invalid value!\n");
			continue;
		}
		if (choice == back) WriteCriminal(Cl, C, O);
		if (choice == back + 1) break;
		OneCriminalMenu(Cl, choice - 1);

	} while (true);

}

