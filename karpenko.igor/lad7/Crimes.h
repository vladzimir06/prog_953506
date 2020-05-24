#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
/*База престпулений--------------------------------------------------*/
/*(место преступления, участники, последствия, комментарии
специалистов)*/
typedef char tCrimeScene[35];
typedef char tParticipant[120];
typedef char tConsequences[50];
typedef char tExperComments[200];

typedef struct CrimeNode
{
	tCrimeScene crimeScene;
	tParticipant participant;
	tConsequences consequences;
	tExperComments experComments;

	CrimeNode* pNext, * pPrev;
}CrimeNode;

typedef struct Crime
{
	int size;
	CrimeNode* head;
	CrimeNode* tail;
}Crime;

void AddCrime(Crime& C, char* cS, char* pt, char* cq, char* eC)
{
	CrimeNode* NewNode;
	NewNode = (CrimeNode*)malloc(sizeof(CrimeNode));
	NewNode->pPrev = C.tail;
	NewNode->pNext = NULL;
	int i;
	for (i = 0; cS[i] != '\0'; i++) NewNode->crimeScene[i] = cS[i];
	NewNode->crimeScene[i++] = '\0';
	for (i = 0; pt[i] != '\0'; i++) NewNode->participant[i] = pt[i];
	NewNode->participant[i++] = '\0';
	for (i = 0; cq[i] != '\0'; i++) NewNode->consequences[i] = cq[i];
	NewNode->consequences[i++] = '\0';
	for (i = 0; eC[i] != '\0'; i++) NewNode->experComments[i] = eC[i];
	NewNode->experComments[i++] = '\0';

	if (C.tail) C.tail->pNext = NewNode;
	C.tail = NewNode;
	if (!C.head) C.head = C.tail;
	C.size++;
	return;
}

bool DeleteCrime(Crime& C, int index)
{
	if (index > C.size - 1 || index < 0)
	{
		return false;
	}

	CrimeNode* NewNode = C.head;
	while (index > 0)
	{
		NewNode = NewNode->pNext;
		index--;
	}
	if (NewNode->pPrev != NULL)
		NewNode->pPrev->pNext = NewNode->pNext;
	else C.head = NewNode->pNext;
	if (NewNode->pNext != NULL)
		NewNode->pNext->pPrev = NewNode->pPrev;
	else C.tail = NewNode->pPrev;
	free(NewNode);
	C.size--;
	return true;
}

void ClearCrime(Crime& C)
{
	while (DeleteCrime(C, C.size - 1));
}

void LoadCrime(Crime& C)
{
	FILE* fp;
	ClearCrime(C);

	fopen_s(&fp, "Crime.txt", "r");

	char cS[35], pt[120], cq[50], eC[200];
	if (!fp) exit(1);
	while (fgets(cS, 35, fp) != NULL)
	{
		fgets(pt, 120, fp);
		fgets(cq, 50, fp);
		fgets(eC, 200, fp);
		AddCrime(C, cS, pt, cq, eC);
	}

	fclose(fp);
}

void SaveCrime(Crime& C)
{
	FILE* fp;

	fopen_s(&fp, "Crime.txt", "w");
	if (!fp) exit(1);

	CrimeNode* NewNode = C.head;
	if (NewNode == NULL) return;
	while (NewNode->pNext)
	{
		fprintf(fp, "%s", NewNode->crimeScene);
		fprintf(fp, "%s", NewNode->participant);
		fprintf(fp, "%s", NewNode->consequences);
		fprintf(fp, "%s", NewNode->experComments);
		NewNode = NewNode->pNext;
	}
	fprintf(fp, "%s", NewNode->crimeScene);
	fprintf(fp, "%s", NewNode->participant);
	fprintf(fp, "%s", NewNode->consequences);
	fprintf(fp, "%s", NewNode->experComments);

	fclose(fp);
}

void PrintCrime(Crime& C)
{
	CrimeNode* NewNode = C.head;
	if (NewNode == NULL) return;
	while (NewNode->pNext)
	{
		printf("%s", NewNode->crimeScene);
		printf("%s", NewNode->participant);
		printf("%s", NewNode->consequences);
		printf("%s", NewNode->experComments);
		printf("\n");
		NewNode = NewNode->pNext;
	}
	printf("%s", NewNode->crimeScene);
	printf("%s", NewNode->participant);
	printf("%s", NewNode->consequences);
	printf("%s", NewNode->experComments);
	printf("\n");
	printf("\n");
	return;
}


/*База преступных и террористических организаций---------------------*/
/*(название, род деятельности, рейтинг опасности)*/

typedef char tName[35];
typedef char tOccupation[35];
typedef char tRating[35];

typedef struct OrganizationNode
{
	tName name;
	tOccupation occupation;
	tRating rating;

	OrganizationNode* pNext, * pPrev;
}OrganizationNode;

typedef struct Organization
{
	int size;
	OrganizationNode* head;
	OrganizationNode* tail;
}Organization;

void AddOrganization(Organization& O, char* name, char* oc, char* ra)
{
	OrganizationNode* NewNode;
	NewNode = (OrganizationNode*)malloc(sizeof(OrganizationNode));
	NewNode->pPrev = O.tail;
	NewNode->pNext = NULL;
	int i;
	for (i = 0; name[i] != '\0'; i++) NewNode->name[i] = name[i];
	NewNode->name[i++] = '\0';
	for (i = 0; oc[i] != '\0'; i++) NewNode->occupation[i] = oc[i];
	NewNode->occupation[i++] = '\0';
	for (i = 0; ra[i] != '\0'; i++) NewNode->rating[i] = ra[i];
	NewNode->rating[i++] = '\0';

	if (O.tail) O.tail->pNext = NewNode;
	O.tail = NewNode;
	if (!O.head) O.head = O.tail;
	O.size++;
	return;
}

bool DeleteOrganization(Organization& O, int index)
{
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
	if (NewNode->pPrev != NULL)
		NewNode->pPrev->pNext = NewNode->pNext;
	else O.head = NewNode->pNext;
	if (NewNode->pNext != NULL)
		NewNode->pNext->pPrev = NewNode->pPrev;
	else O.tail = NewNode->pPrev;
	free(NewNode);
	O.size--;
	return true;
}

void ClearOrganization(Organization& O)
{
	while (DeleteOrganization(O, O.size - 1));
}

void LoadOrganization(Organization& O)
{
	FILE* fp;
	ClearOrganization(O);

	fopen_s(&fp, "Organization.txt", "r");

	char name[35], oc[35], ra[35];
	if (!fp) exit(1);
	while (fgets(name, 35, fp) != NULL)
	{
		fgets(oc, 35, fp);
		fgets(ra, 35, fp);
		AddOrganization(O, name, oc, ra);
	}

	fclose(fp);
}

void SaveOrganization(Organization& O)
{
	FILE* fp;

	fopen_s(&fp, "Organization.txt", "w");
	if (!fp) exit(1);

	OrganizationNode* NewNode = O.head;
	if (NewNode == NULL) return;
	while (NewNode->pNext)
	{
		fprintf(fp, "%s", NewNode->name);
		fprintf(fp, "%s", NewNode->occupation);
		fprintf(fp, "%s", NewNode->rating);
		NewNode = NewNode->pNext;
	}
	fprintf(fp, "%s", NewNode->name);
	fprintf(fp, "%s", NewNode->occupation);
	fprintf(fp, "%s", NewNode->rating);

	fclose(fp);
}

void PrintOrganization(Organization& O)
{
	OrganizationNode* NewNode = O.head;
	if (NewNode == NULL) return;
	while (NewNode->pNext)
	{
		printf("%s", NewNode->name);
		printf("%s", NewNode->occupation);
		printf("%s", NewNode->rating);
		printf("\n");
		NewNode = NewNode->pNext;
	}
	printf("%s", NewNode->name);
	printf("%s", NewNode->occupation);
	printf("%s", NewNode->rating);
	printf("\n");
	printf("\n");
	return;
}

void PrintOrgName(Organization& O)
{
	OrganizationNode* NewNode = O.head;
	if (NewNode == NULL) return;
	do
	{
		printf("%s", NewNode->name);
		NewNode = NewNode->pNext;
		if (NewNode) printf(", ");
	} while (NewNode);
	return;
}
/*База преступников--------------------------------------------------*/
/*(ФИО, кличка, рост, вес, цвет волос, особые приметы,
гражданство, знание языков, род преступления, причастность к
террористическим организациям, ссылки на список преступлений,
ссылки на список преступных организаций)*/
typedef char tFullName[40];
typedef char tNickName[40];
typedef char tHeight[15];
typedef char tWeight[15];
typedef char tHairColor[15];
typedef char tSpecial[55];
typedef char tNationality[25];
typedef char tLanguages[50];
typedef char tCrimeType[30];

typedef struct
{
	tFullName fullname;
	tNickName nickname;
	tHeight height;
	tWeight weight;
	tHairColor color;
	tSpecial special;
	tNationality nationality;
	tLanguages languages;
	tCrimeType crimetype;
	Crime crimelist;
	Organization organizationlist;
}OneCriminal;

typedef struct CriminalNode
{
	OneCriminal One;
	CriminalNode* pNext, * pPrev;
}CriminalNode;

typedef struct Criminal
{
	int size;
	CriminalNode* head;
	CriminalNode* tail;
}Criminal;

void AddCriminal(Criminal& Cl, OneCriminal OC, Crime& C, Organization& O, char* org)
{
	CriminalNode* NewNode;
	NewNode = (CriminalNode*)malloc(sizeof(CriminalNode));
	NewNode->pPrev = Cl.tail;
	NewNode->pNext = NULL;
	int i;
	for (i = 0; OC.fullname[i] != '\0'; i++) NewNode->One.fullname[i] = OC.fullname[i];
	NewNode->One.fullname[i++] = '\0';
	for (i = 0; OC.nickname[i] != '\0'; i++) NewNode->One.nickname[i] = OC.nickname[i];
	NewNode->One.nickname[i++] = '\0';
	for (i = 0; OC.height[i] != '\0'; i++) NewNode->One.height[i] = OC.height[i];
	NewNode->One.height[i++] = '\0';
	for (i = 0; OC.weight[i] != '\0'; i++) NewNode->One.weight[i] = OC.weight[i];
	NewNode->One.weight[i++] = '\0';
	for (i = 0; OC.color[i] != '\0'; i++) NewNode->One.color[i] = OC.color[i];
	NewNode->One.color[i++] = '\0';
	for (i = 0; OC.special[i] != '\0'; i++) NewNode->One.special[i] = OC.special[i];
	NewNode->One.special[i++] = '\0';
	for (i = 0; OC.nationality[i] != '\0'; i++) NewNode->One.nationality[i] = OC.nationality[i];
	NewNode->One.nationality[i++] = '\0';
	for (i = 0; OC.languages[i] != '\0'; i++) NewNode->One.languages[i] = OC.languages[i];
	NewNode->One.languages[i++] = '\0';
	for (i = 0; OC.crimetype[i] != '\0'; i++) NewNode->One.crimetype[i] = OC.crimetype[i];
	NewNode->One.crimetype[i++] = '\0';

	NewNode->One.crimelist = { 0, NULL, NULL };
	CrimeNode* NewCrime = C.head;
	if (NewCrime)
	{
		do
		{
			char text_name[120], mark[] = ",.?!;:\n\0";
			int marka = 0;
			for (int i = 0, j = 0; NewCrime->participant[i - 1] != '\0'; i++)
			{
				for (int k = 0; k < 9; k++)
				{
					if (NewCrime->participant[i] == mark[k])
					{
						text_name[j] = '\n';
						text_name[j + 1] = NULL;
						if (j != 0)
						{
							if (!strcmp(NewNode->One.fullname, text_name))
								AddCrime(NewNode->One.crimelist, NewCrime->crimeScene, NewCrime->participant, NewCrime->consequences, NewCrime->experComments);
						}
						j = 0;
						marka = 0;
						break;
					}
					marka = 1;
				}
				if (marka == 1)
				{
					text_name[j] = NewCrime->participant[i];
					j++;
				}
			}
			NewCrime = NewCrime->pNext;
		} while (NewCrime);
	}

	NewNode->One.organizationlist = { 0, NULL, NULL };
	OrganizationNode* NewOrg = O.head;
	if (NewOrg)
	{
		do
		{
			char text_name[120], mark[] = ",.?!;:\n\0";
			int marka = 0;
			for (int i = 0, j = 0; org[i - 1] != '\0'; i++)
			{
				for (int k = 0; k < 9; k++)
				{
					if (org[i] == mark[k])
					{
						text_name[j] = '\n';
						text_name[j + 1] = NULL;
						if (j != 0)
						{
							if (!strcmp(NewOrg->name, text_name))
							{
								text_name[j] = NULL;
								AddOrganization(NewNode->One.organizationlist, text_name, NewOrg->occupation, NewOrg->rating);
							}
						}
						j = 0;
						marka = 0;
						break;
					}
					marka = 1;
				}
				if (marka == 1)
				{
					text_name[j] = org[i];
					j++;
				}
			}
			NewOrg = NewOrg->pNext;
		} while (NewOrg);
	}

	if (Cl.tail) Cl.tail->pNext = NewNode;
	Cl.tail = NewNode;
	if (!Cl.head) Cl.head = Cl.tail;
	Cl.size++;
	return;
}

bool DeleteCriminal(Criminal& Cl, int index)
{
	if (index > Cl.size - 1 || index < 0)
	{
		return false;
	}

	CriminalNode* NewNode = Cl.head;
	while (index > 0)
	{
		NewNode = NewNode->pNext;
		index--;
	}
	if (NewNode->pPrev != NULL)
		NewNode->pPrev->pNext = NewNode->pNext;
	else Cl.head = NewNode->pNext;
	if (NewNode->pNext != NULL)
		NewNode->pNext->pPrev = NewNode->pPrev;
	else Cl.tail = NewNode->pPrev;
	ClearOrganization(NewNode->One.organizationlist);
	ClearCrime(NewNode->One.crimelist);
	free(NewNode);
	Cl.size--;
	return true;
}

void ClearCriminal(Criminal& Cl)
{
	while (DeleteCriminal(Cl, Cl.size - 1));
}

void LoadCriminal(Criminal& Cl, Organization& O, Crime& C)
{
	FILE* fp;
	ClearCriminal(Cl);

	fopen_s(&fp, "Criminal.txt", "r");

	char org[35];
	tHeight;
	tWeight;
	OneCriminal One;
	if (!fp) exit(1);
	while (fgets(One.fullname, 40, fp) != NULL)
	{
		fgets(One.nickname, 40, fp);
		fgets(One.height, 15, fp);
		fgets(One.weight, 15, fp);
		fgets(One.color, 15, fp);
		fgets(One.special, 55, fp);
		fgets(One.nationality, 25, fp);
		fgets(One.languages, 50, fp);
		fgets(One.crimetype, 30, fp);
		fgets(org, 35, fp);
		AddCriminal(Cl, One, C, O, org);
	}
	fclose(fp);
}

void SaveCriminal(Criminal& Cl)
{
	FILE* fp;

	fopen_s(&fp, "Criminal.txt", "w");
	if (!fp) exit(1);

	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		fprintf(fp, "%s", NewNode->One.fullname);
		fprintf(fp, "%s", NewNode->One.nickname);
		fprintf(fp, "%s", NewNode->One.height);
		fprintf(fp, "%s", NewNode->One.weight);
		fprintf(fp, "%s", NewNode->One.color);
		fprintf(fp, "%s", NewNode->One.special);
		fprintf(fp, "%s", NewNode->One.nationality);
		fprintf(fp, "%s", NewNode->One.languages);
		fprintf(fp, "%s", NewNode->One.crimetype);
		OrganizationNode* NewOrg = NewNode->One.organizationlist.head;
		if (NewOrg != NULL) {
			do
			{
				fprintf(fp, "%s", NewOrg->name);
				NewOrg = NewOrg->pNext;
				if (NewOrg) fprintf(fp, ",");
			} while (NewOrg);
			fprintf(fp, "\n");
		}
		NewNode = NewNode->pNext;
	} while (NewNode);

	fclose(fp);
}

void PrintCriminal(Criminal& Cl)
{
	CriminalNode* NewNode = Cl.head;
	if (NewNode == NULL) return;
	do
	{
		printf("%s", NewNode->One.fullname);
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
		PrintCrime(NewNode->One.crimelist);
		printf("\n");
		NewNode = NewNode->pNext;
	} while (NewNode);
	printf("\n");
	return;
}
/*-------------------------------------------------------------------*/
void WriteCrime(Crime& C)
{
	char Cs[35], Pc[120], Cq[50], Ec[200], ch;
	printf("Enter data so that there are no spaces near the comma!\n");
	int i = 0;
	printf("Crime Scene(City,Country):");
	do {
		ch = getchar();
		Cs[i++] = ch;
		if (i > 34) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	Cs[i] = '\0';
	printf("\nParticipant:");
	i = 0;
	do {
		ch = getchar();
		Pc[i++] = ch;
		if (i > 119) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	Pc[i] = '\0';
	printf("\nConsequencas:");
	i = 0;
	do {
		ch = getchar();
		Cq[i++] = ch;
		if (i > 50) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	Cq[i] = '\0';
	printf("Expert comments:");
	i = 0;
	do {
		ch = getchar();
		if (ch == '\n') continue;
		Ec[i++] = ch;
		if (i > 34) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	Ec[i] = '\0';
	int j = 0;
	for (j = 0; C.tail->experComments[j] != '\0'; j++);
	C.tail->experComments[j] = '\n';
	C.tail->experComments[j + 1] = '\0';
	AddCrime(C, Cs, Pc, Cq, Ec);
}

void WriteOrganization(Organization& O)
{
	char Name[35], Oc[35], Ra[35], ch;
	printf("Enter data so that there are no spaces near the comma!\n");
	int i = 0;
	printf("Name of organization:");
	do {
		ch = getchar();
		Name[i++] = ch;
		if (i > 34) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	Name[i] = '\0';
	printf("\nOccupation:");
	i = 0;
	do {
		ch = getchar();
		Oc[i++] = ch;
		if (i > 34) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	Oc[i] = '\0';
	printf("Rating(something from this : Wolf < Tiger < Dragon < Demonic < God\n):");
	i = 0;
	do {
		ch = getchar();
		if (ch == '\n') continue;
		Ra[i++] = ch;
		if (i > 34) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	Ra[i] = '\0';
	int j = 0;
	for (j = 0; O.tail->rating[j] != '\0'; j++);
	O.tail->rating[j] = '\n';
	O.tail->rating[j + 1] = '\0';
	AddOrganization(O, Name, Oc, Ra);
}
void WriteCriminal(Criminal& Cl, Crime& C, Organization& O)
{
	char ch, org[60];
	OneCriminal One;
	printf("Enter data so that there are no spaces near the comma!\n");
	int i = 0;
	printf("Full name of criminal:");
	do {
		ch = getchar();
		One.fullname[i++] = ch;
		if (i > 39) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.fullname[i] = '\0';
	printf("\nNickname of criminal:");
	i = 0;
	do {
		ch = getchar();
		One.nickname[i++] = ch;
		if (i > 39) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.nickname[i] = '\0';
	printf("\nHeight of criminal(in SI[179sm]):");
	i = 0;
	do {
		ch = getchar();
		One.height[i++] = ch;
		if (i > 14) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.height[i] = '\0';
	printf("\nWeight of criminal(in SI[73kg]):");
	i = 0;
	do {
		ch = getchar();
		One.weight[i++] = ch;
		if (i > 14) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.weight[i] = '\0';
	printf("\nHair color of criminal:");
	i = 0;
	do {
		ch = getchar();
		One.color[i++] = ch;
		if (i > 14) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.color[i] = '\0';
	printf("\nSpecials of criminal:");
	i = 0;
	do {
		ch = getchar();
		One.special[i++] = ch;
		if (i > 54) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.special[i] = '\0';
	printf("\nNationality:");
	i = 0;
	do {
		ch = getchar();
		One.nationality[i++] = ch;
		if (i > 24) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.nationality[i] = '\0';
	printf("\nThe language the criminal knows:");
	i = 0;
	do {
		ch = getchar();
		One.languages[i++] = ch;
		if (i > 49) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.languages[i] = '\0';
	printf("\nCrime type of criminal:");
	i = 0;
	do {
		ch = getchar();
		One.crimetype[i++] = ch;
		if (i > 29) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	One.crimetype[i] = '\0';
	printf("\nOrganizations the criminal is associated with:");
	i = 0;
	do {
		ch = getchar();
		org[i++] = ch;
		if (i > 59) {
			puts("The size of your text is larger than you can enter.");
			return;
		}
	} while (ch != '\n');
	org[i] = '\0';
	AddCriminal(Cl, One, C, O, org);
}
/*-------------------------------------------------------------------*/
void Suspects(CrimeNode* CNode, Organization& O, Criminal& Cl)
{
	if (CNode == NULL) return;
	CrimeNode* NewNode = CNode;
	OrganizationNode* OrgNode = O.head;
	CriminalNode* Crim = Cl.head;
	if (NewNode == NULL) return;
	if (OrgNode != NULL)
	{
		do
		{
			char* text_name, * text_node, text[200], text2[200], mark[] = " ,.?!;:\n\0";
			int number_of_word = 0;
			strcpy(text, OrgNode->occupation);
			text_name = strtok(text, mark);
			while (text_name != NULL)
			{
				strcpy(text2, NewNode->consequences);
				text_node = strtok(text2, mark);
				while (text_node != NULL)
				{
					char* test = text_name;
					if (!strcmp(text_node, test))
					{
						printf("The word %s is found in the description of the organization:\n", text_node);
						printf("%s", OrgNode->name);
					}
					text_node = strtok(NULL, mark);
				}
				strcpy(text2, NewNode->experComments);
				text_node = strtok(text2, mark);
				while (text_node != NULL)
				{
					char* test = text_name;
					if (!strcmp(text_node, test))
					{
						printf("The word \"%s\" is found in the description of the organization:\n", text_node);
						printf("%s", OrgNode->name);
					}
					text_node = strtok(NULL, mark);
				}
				number_of_word++;

				strcpy(text, OrgNode->occupation);
				text_name = strtok(text, mark);
				for (int i = 0; i < number_of_word; i++)
					text_name = strtok(NULL, mark);
			}
			OrgNode = OrgNode->pNext;
		} while (OrgNode);
	}
	if (Crim != NULL)
	{
		do
		{
			char* text_name, * text_node, text[200], text2[200], mark[] = " ,.?!;:\n\0";
			int number_of_word = 0;
			strcpy(text, Crim->One.special);
			text_name = strtok(text, mark);
			while (text_name != NULL)
			{
				strcpy(text2, NewNode->consequences);
				text_node = strtok(text2, mark);
				while (text_node != NULL)
				{
					char* test = text_name;
					if (!strcmp(text_node, test))
					{
						printf("The word %s is found in the description of the organization:\n", text_node);
						printf("%s", OrgNode->name);
					}
					text_node = strtok(NULL, mark);
				}
				strcpy(text2, NewNode->experComments);
				text_node = strtok(text2, mark);
				while (text_node != NULL)
				{
					char* test = text_name;
					if (!strcmp(text_node, test))
					{
						printf("The word \"%s\" is found in the description of the criminal:\n", text_node);
						printf("%s", Crim->One.fullname);
					}
					text_node = strtok(NULL, mark);
				}
				number_of_word++;

				strcpy(text, Crim->One.special);
				text_name = strtok(text, mark);
				for (int i = 0; i < number_of_word; i++)
					text_name = strtok(NULL, mark);
			}
			Crim = Crim->pNext;
		} while (Crim);
		Crim = Cl.head;
		do
		{
			char* text_name, * text_node, text[200], text2[200], mark[] = " ,.?!;:\n\0";
			int number_of_word = 0;
			strcpy(text, Crim->One.nationality);
			text_name = strtok(text, mark);
			while (text_name != NULL)
			{
				strcpy(text2, NewNode->consequences);
				text_node = strtok(text2, mark);
				while (text_node != NULL)
				{
					char* test = text_name;
					if (!strcmp(text_node, test))
					{
						printf("The word \"%s\" is found in the description of the criminal:\n", text_node);
						printf("%s", Crim->One.fullname);
					}
					text_node = strtok(NULL, mark);
				}
				strcpy(text2, NewNode->experComments);
				text_node = strtok(text2, mark);
				while (text_node != NULL)
				{
					char* test = text_name;
					if (!strcmp(text_node, test))
					{
						printf("The word \"%s\" is found in the description of the criminal:\n", text_node);
						printf("%s", Crim->One.fullname);
					}
					text_node = strtok(NULL, mark);
				}
				number_of_word++;

				strcpy(text, Crim->One.nationality);
				text_name = strtok(text, mark);
				for (int i = 0; i < number_of_word; i++)
					text_name = strtok(NULL, mark);
			}
			Crim = Crim->pNext;
		} while (Crim);
	}
}
