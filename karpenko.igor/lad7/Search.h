#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Crimes.h"

void SearchSc(Crime& C)
{
	printf("Enter the name of the country or city where the crime occurred\n");
	char CName[30], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CrimeNode* NewNode = C.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[30], mark[] = ",.?!;:\n\0";
		strcpy(text, NewNode->crimeScene);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->crimeScene);
				printf("%s", NewNode->participant);
				printf("%s", NewNode->consequences);
				printf("%s", NewNode->experComments);
				printf("\n");
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
void SearchPt(Crime& C)
{
	printf("Enter the full name of the participant in the crime\n");
	char CName[30], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CrimeNode* NewNode = C.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[120], mark[] = ",.?!;:\n\0";
		strcpy(text, NewNode->participant);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->crimeScene);
				printf("%s", NewNode->participant);
				printf("%s", NewNode->consequences);
				printf("%s", NewNode->experComments);
				printf("\n");
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
void SearchCq(Crime& C)
{
	printf("Enter the consequences of the crime(one word)\n");
	char CName[30], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CrimeNode* NewNode = C.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[50], mark[] = " ,.?!;:\n\0";
		strcpy(text, NewNode->consequences);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->crimeScene);
				printf("%s", NewNode->participant);
				printf("%s", NewNode->consequences);
				printf("%s", NewNode->experComments);
				printf("\n");
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
void SearchEc(Crime& C)
{
	printf("Enter the expert comments(one word)\n");
	char CName[30], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CrimeNode* NewNode = C.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[200], mark[] = " ,.?!;:\n\0";
		strcpy(text, NewNode->experComments);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->crimeScene);
				printf("%s", NewNode->participant);
				printf("%s", NewNode->consequences);
				printf("%s", NewNode->experComments);
				printf("\n");
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");

}
/*---------------------------*/
void SearchName(Organization& O)
{
	printf("Enter the name of organization\n");
	char CName[35], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	OrganizationNode* NewNode = O.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[35], mark[] = ",.?!;:\n\0";
		strcpy(text, NewNode->name);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->name);
				printf("%s", NewNode->occupation);
				printf("%s", NewNode->rating);
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
void SearchOc(Organization& O)
{
	printf("Enter the occupation of organization\n");
	char CName[35], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	OrganizationNode* NewNode = O.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[35], mark[] = ",.?!;:\n\0";
		strcpy(text, NewNode->occupation);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->name);
				printf("%s", NewNode->occupation);
				printf("%s", NewNode->rating);
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
void SearchRa(Organization& O)
{
	printf("Enter the rating of organization\n");
	char CName[35], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	OrganizationNode* NewNode = O.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[35], mark[] = ",.?!;:\n\0";
		strcpy(text, NewNode->rating);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->name);
				printf("%s", NewNode->occupation);
				printf("%s", NewNode->rating);
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
/*---------------------------*/
void SearchFn(Criminal& Cl)
{
	printf("Enter the full name of criminal\n");
	char CName[40], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		if (!strcmp(CName, NewNode->One.fullname))
		{
			printf("%d)%s", index + 1, NewNode->One.fullname);
			printf("%s", NewNode->One.nickname);
			printf("%s", NewNode->One.height);
			printf("%s", NewNode->One.weight);
			printf("%s", NewNode->One.color);
			printf("%s", NewNode->One.special);
			printf("%s", NewNode->One.nationality);
			printf("%s", NewNode->One.languages);
			printf("%s", NewNode->One.crimetype);
			PrintOrgName(NewNode->One.organizationlist);
			printf("\n");
			break;
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}

void SearchNn(Criminal& Cl)
{
	printf("Enter the nickname of criminal\n");
	char CName[40], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		if (!strcmp(CName, NewNode->One.nickname))
		{
			printf("%d)%s", index + 1, NewNode->One.fullname);
			printf("%s", NewNode->One.nickname);
			printf("%s", NewNode->One.height);
			printf("%s", NewNode->One.weight);
			printf("%s", NewNode->One.color);
			printf("%s", NewNode->One.special);
			printf("%s", NewNode->One.nationality);
			printf("%s", NewNode->One.languages);
			printf("%s", NewNode->One.crimetype);
			PrintOrgName(NewNode->One.organizationlist);
			printf("\n");
			break;
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}

void SearchHeight(Criminal& Cl)
{
	printf("Enter the height of criminal(in SI[176sm])\n");
	char CName[15], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		if (!strcmp(CName, NewNode->One.height))
		{
			printf("%d)%s", index + 1, NewNode->One.fullname);
			printf("%s", NewNode->One.nickname);
			printf("%s", NewNode->One.height);
			printf("%s", NewNode->One.weight);
			printf("%s", NewNode->One.color);
			printf("%s", NewNode->One.special);
			printf("%s", NewNode->One.nationality);
			printf("%s", NewNode->One.languages);
			printf("%s", NewNode->One.crimetype);
			PrintOrgName(NewNode->One.organizationlist);
			printf("\n");
			break;
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}

void SearchWeight(Criminal& Cl)
{
	printf("Enter the weight of criminal(in SI[73kg])\n");
	char CName[15], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		if (!strcmp(CName, NewNode->One.weight))
		{
			printf("%d)%s", index + 1, NewNode->One.fullname);
			printf("%s", NewNode->One.nickname);
			printf("%s", NewNode->One.height);
			printf("%s", NewNode->One.weight);
			printf("%s", NewNode->One.color);
			printf("%s", NewNode->One.special);
			printf("%s", NewNode->One.nationality);
			printf("%s", NewNode->One.languages);
			printf("%s", NewNode->One.crimetype);
			PrintOrgName(NewNode->One.organizationlist);
			printf("\n");
			break;
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}

void SearchHc(Criminal& Cl)
{
	printf("Enter the hair color of criminal\n");
	char CName[15], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		if (!strcmp(CName, NewNode->One.color))
		{
			printf("%d)%s", index + 1, NewNode->One.fullname);
			printf("%s", NewNode->One.nickname);
			printf("%s", NewNode->One.height);
			printf("%s", NewNode->One.weight);
			printf("%s", NewNode->One.color);
			printf("%s", NewNode->One.special);
			printf("%s", NewNode->One.nationality);
			printf("%s", NewNode->One.languages);
			printf("%s", NewNode->One.crimetype);
			PrintOrgName(NewNode->One.organizationlist);
			printf("\n");
			printf("\n");
			break;
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}

void SearchSp(Criminal& Cl)
{
	printf("Enter special of criminal\n");
	char CName[55], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[55], mark[] = ",.?!;:\n\0";
		strcpy(text, NewNode->One.special);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->One.fullname);
				printf("%s", NewNode->One.nickname);
				printf("%s", NewNode->One.height);
				printf("%s", NewNode->One.weight);
				printf("%s", NewNode->One.color);
				printf("%s", NewNode->One.special);
				printf("%s", NewNode->One.nationality);
				printf("%s", NewNode->One.languages);
				printf("%s", NewNode->One.crimetype);
				PrintOrgName(NewNode->One.organizationlist);
				printf("\n");
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
void SearchNat(Criminal& Cl)
{
	printf("Enter the nationality of criminal\n");
	char CName[25], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		if (!strcmp(CName, NewNode->One.nationality))
		{
			printf("%d)%s", index + 1, NewNode->One.fullname);
			printf("%s", NewNode->One.nickname);
			printf("%s", NewNode->One.height);
			printf("%s", NewNode->One.weight);
			printf("%s", NewNode->One.color);
			printf("%s", NewNode->One.special);
			printf("%s", NewNode->One.nationality);
			printf("%s", NewNode->One.languages);
			printf("%s", NewNode->One.crimetype);
			PrintOrgName(NewNode->One.organizationlist);
			printf("\n");
			printf("\n");
			break;
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
void SearchLang(Criminal& Cl)
{
	printf("Enter the language the criminal knows\n");
	char CName[50], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',' || ch == '\n') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		char* text_name, text[50], mark[] = ",.?!;:\n\0";
		strcpy(text, NewNode->One.languages);
		text_name = strtok(text, mark);
		while (text_name != NULL)
		{
			if (!strcmp(CName, text_name))
			{
				printf("%d)%s", index + 1, NewNode->One.fullname);
				printf("%s", NewNode->One.nickname);
				printf("%s", NewNode->One.height);
				printf("%s", NewNode->One.weight);
				printf("%s", NewNode->One.color);
				printf("%s", NewNode->One.special);
				printf("%s", NewNode->One.nationality);
				printf("%s", NewNode->One.languages);
				printf("%s", NewNode->One.crimetype);
				PrintOrgName(NewNode->One.organizationlist);
				printf("\n");
				printf("\n");
				break;
			}
			text_name = strtok(NULL, mark);
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
void SearchCt(Criminal& Cl)
{
	printf("Enter the crime type of criminal\n");
	char CName[30], ch;
	int i = 0;
	do {
		ch = getchar();
		if (ch == '.' || ch == ',') continue;
		CName[i++] = ch;
		if (i > 30) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	CName[i] = '\0';
	int index = 0;

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		if (!strcmp(CName, NewNode->One.crimetype))
		{
			printf("%d)%s", index + 1, NewNode->One.fullname);
			printf("%s", NewNode->One.nickname);
			printf("%s", NewNode->One.height);
			printf("%s", NewNode->One.weight);
			printf("%s", NewNode->One.color);
			printf("%s", NewNode->One.special);
			printf("%s", NewNode->One.nationality);
			printf("%s", NewNode->One.languages);
			printf("%s", NewNode->One.crimetype);
			PrintOrgName(NewNode->One.organizationlist);
			printf("\n");
			printf("\n");
			break;
		}
		NewNode = NewNode->pNext;
		index++;
	} while (NewNode);
	printf("\n");
}
/*-------------------------------------------------------------------*/
void SearchCrimeMenu(Crime& C)
{
	int choice;
	do {
		printf("Search for crime:\n");
		printf("1)Search by crime scene\n");
		printf("2)Search by participants\n");
		printf("3)Search by consequences(one word)\n");
		printf("4)Search by exper comments(one word)\n");
		printf("\n5)back\n");

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
			SearchSc(C);
			break;
		case 2:
			SearchPt(C);
			break;
		case 3:
			SearchCq(C);
			break;
		case 4:
			SearchEc(C);
			break;
		default:
			break;
		}
		if (choice == 5) break;

	} while (true);
}
void SearchOrgMenu(Organization& O)
{
	int choice;
	do {
		printf("Search for crime:\n");
		printf("1)Search by name\n");
		printf("2)Search by occupation\n");
		printf("3)Search by rating\n");
		printf("\n4)back\n");

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
			SearchName(O);
			break;
		case 2:
			SearchOc(O);
			break;
		case 3:
			SearchRa(O);
			break;
		default:
			break;
		}
		if (choice == 4) break;

	} while (true);
}
void SearchCriminalMenu(Criminal& Cl)
{
	int choice;
	do {
		printf("Search for crime:\n");
		printf("1)Search by full name\n");
		printf("2)Search by nickname\n");
		printf("3)Search by height\n");
		printf("4)Search by weight\n");
		printf("5)Search by hair color\n");
		printf("6)Search by specials\n");
		printf("7)Search by nationality\n");
		printf("8)Search by knowledge of languages\n");
		printf("9)Search by crime type\n");
		printf("\n10)back\n");

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
			SearchFn(Cl);
			break;
		case 2:
			SearchNn(Cl);
			break;
		case 3:
			SearchHeight(Cl);
			break;
		case 4:
			SearchWeight(Cl);
			break;
		case 5:
			SearchHc(Cl);
			break;
		case 6:
			SearchSp(Cl);
			break;
		case 7:
			SearchNat(Cl);
			break;
		case 8:
			SearchLang(Cl);
			break;
		case 9:
			SearchCt(Cl);
			break;
		default:
			break;
		}
		if (choice == 10) break;

	} while (true);
}

void SearchMenu(Crime& C, Organization& O, Criminal& Cl)
{
	int choice;
	do {
		printf("\n1)Search for crime\n");
		printf("2)Search for organization\n");
		printf("3)Search for criminal\n");
		printf("\n4)back\n");

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
			SearchCrimeMenu(C);
			break;
		case 2:
			SearchOrgMenu(O);
			break;
		case 3:
			SearchCriminalMenu(Cl);
			break;
		default:
			break;
		}
		if (choice == 4) break;

	} while (true);
}
