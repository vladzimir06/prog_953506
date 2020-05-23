/* Кузовков Егор, группа 953506.
   Лабораторная №7, вариант 27.

    Базаа данных интерпола.
    В файле Crimes.h лежат все структуры и функции для работы с ними, здесь только сама программа.
*/

#include <stdio.h>
#include "Crimes.h"

void menu();
void cleanCrimes(struct *CrimeList);
void cleanCriminals(struct CriminalList *C);
void cleanOrganizations(struct OrganizationList *C);

int main()
{
    struct CrimeList *crimeBase;
    crimeBase = (struct CrimeList*)malloc(sizeof(struct CrimeList));
    crimeBase -> size = 0;
    crimeBase -> head = crimeBase -> tail =  NULL;

    struct OrganizationList *orgBase;
    orgBase = (struct OrganizationList*)malloc(sizeof(struct OrganizationList));
    orgBase -> size = 0;
    orgBase -> head = orgBase -> tail = NULL;

    struct CriminalList *criminalBase;
    criminalBase = (struct CriminalList*)malloc(sizeof(struct CriminalList));
    criminalBase -> size = 0;
    criminalBase -> tail = criminalBase -> head = NULL;

    LoadCrime(crimeBase);
    LoadOrganization(orgBase);
    LoadCriminal(criminalBase);
    puts("Welcome to the Interpol base!");
    int decision = 0;
    while(decision != 6)
    {
        system("cls");
        menu();
        scanf_s("%d", &decision);
        switch(decision)
        {
            //Добавление.
            case 1:
            {
                int choice = 0;
                puts("Choose what would you like to add. Enter 1 for criminal, 2 for crime and 3 for organization.");
                scanf_s("%d", &choice);
                switch(choice)
                {
                    case 1:
                    {
                        puts("Enter the data: ");
                        char Name[20], Surname[20], Nickname[20], height[4], weight[4], Color[20], Signs[30], Nationality[20],
                        Languages[30], Crimes[25], Organization[20];

                        gets_s(Name, sizeof(Name));
                        gets_s(Surname, sizeof(Surname));
                        gets_s(Nickname, sizeof(Nickname));
                        gets_s(height, sizeof(height));
                        gets_s(weight, sizeof(weight));
                        gets_s(Color, sizeof(Color));
                        gets_s(Signs, sizeof(Signs));
                        gets_s(Nationality, sizeof(Nationality));
                        gets_s(Languages, sizeof(Languages));
                        gets_s(Crimes, sizeof(Crimes));
                        gets_s(Organization, sizeof(Organization));

                        AddCriminal(criminalBase, Name, Surname, Nickname, atoi(height), atoi(weight), Color, Signs, Nationality, Languages, Crimes, Organization);
                        break;
                    }

                    case 2:
                    {
                        puts("Enter the data: ");
                        char Place[20], Participants[40], Consequences[20], Commentary[40];

                        gets_s(Place, sizeof(Place));
                        gets_s(Participants, sizeof(Participants));
                        gets_s(Consequences, sizeof(Consequences));
                        gets_s(Commentary, sizeof(Commentary));

                        AddCrime(crimeBase, Place, Participants, Consequences, Commentary);
                        break;
                    }

                    case 3:
                    {
                        puts("Enter the data: ");
                        char Name[20], Activity[25], Danger[20];

                        gets_s(Name, sizeof(Name));
                        gets_s(Activity, sizeof(Activity));
                        gets_s(Danger, sizeof(Danger));

                        AddOrganization(orgBase, Name, Activity, Danger);
                        break;
                    }

                    default:
                    {
                        puts("Error!");
                        break;
                    }
                }
            }

            //Удаление.
            case 2:
            {
                puts("Choose what would you like to delete. Enter 1 for criminal, 2 for crime and 3 for organization.");
                int deleter = 0;
                scanf_s("%d", &deleter);
                switch(deleter)
                {
                    case 1:
                    {
                        puts("Enter the position: ");
                        int position = 0;
                        scanf_s("%d", &position);
                        DeleteCriminal(criminalBase, position);
                        break;
                    }

                    case 2:
                    {
                        puts("Enter the position: ");
                        int position = 0;
                        scanf_s("%d", &position);
                        DeleteCrime(crimeBase, position);
                        break;
                    }

                    case 3:
                    {
                        puts("Enter the position: ");
                        int position = 0;
                        scanf_s("%d", &position);
                        DeleteOrganization(orgBase, position);
                        break;
                    }

                    default:
                    {
                        puts("Error!");
                        break;
                    }
                }
            }

            //Вывод любой категории.
            case 3:
            {
                puts("Choose what would you like to see. Enter 1 for criminal, 2 for crime and 3 for organization.");
                int toShow = 0;
                scanf("%d", &toShow);
                switch(toShow)
                {
                    case 1:
                    {
                        ShowCriminals(criminalBase);
                        break;
                    }

                    case 2:
                    {
                        ShowCrimes(crimeBase);
                        break;
                    }

                    case 3:
                    {
                        ShowOrganizations(orgBase);
                        break;
                    }

                    default:
                    {
                        puts("Error!");
                        break;
                    }
                }
            }

            //Поиск с анализом.
            case 4:
            {
                puts("What would you like to search for. Enter 1 for criminal, 2 for crime and 3 for organization.");
                int search = 0;
                scanf_s("%d", &search);
                switch(search)
                {
                    case 1:
                    {
                        puts("Choose the category: ");
                        int category = 0;
                        scanf_s("%d", &category);
                        SearchCriminal(criminalBase, category);
                        break;
                    }

                    case 2:
                    {
                        puts("Choose the category: ");
                        int category = 0;
                        scanf_s("%d", &category);
                        SearchCrime(crimeBase, category);
                        break;
                    }

                    case 3:
                    {
                        puts("Choose the category: ");
                        int category = 0;
                        scanf_s("%d", &category);
                        SearchOrganization(orgBase, category);
                        break;
                    }

                    default:
                    {
                        puts("Error.");
                        break;
                    }
                }
            }

            case 5:
            {
                puts("What would you like to search for. Enter 1 for criminal, 2 for crime and 3 for organization.");
                int clean = 0;
                scanf_s("%d", &clean);
                switch(clean)
                {
                    case 1:
                    {
                        RecoveredCriminal(criminalBase);
                        break;
                    }

                    case 2:
                    {
                        RecoveredCrime(crimeBase);
                        break;
                    }

                    case 3:
                    {
                        RecoveredOrganization(orgBase);
                        break;
                    }

                    default:
                    {
                        puts("Error.");
                        break;
                    }
                }

                case 6:
                    break;

                default:
                {
                    puts("Error.");
                    break;
                }
            }
        }
    }
	DeleteCrime(crimeBase);
	DeleteCriminal(criminalBase);
	DeleteOrganization(orgBase);
	free(crimeBase);
	free(criminalBase);
	free(orgBase);
}

void menu()
{
    puts("You can do the following: ");
    puts("1. Add another crime, criminal, organization.");
    puts("2. Delete crime, criminal or organization.");
    puts("3. Show all crimes, criminals or organizations.");
    puts("4. Search for some specific crime, criminal or organization.");
    puts("5. Clear the specific branch.");
    puts("6. Exit");
}

void cleanCrimes(struct CrimeList *C )
{
	struct *temp = C -> tail;
	while(temp -> prev)
	{
		temp  = temp -> prev;
		free(temp -> next);
	}
	free(temp);
}

void cleanCriminals(struct CriminalList *C)
{
	struct *temp = C -> tail;
	while(temp -> prev)
	{
		temp  = temp -> prev;
		free(temp -> next);
	}
	free(temp);
}

void cleanOrganizations(struct OrganizationList *C)
{
	struct *temp = C -> tail;
	while(temp -> prev)
	{
		temp  = temp -> prev;
		free(temp -> next);
	}
	free(temp);
}

