#ifndef LAB7_LIST_H
#define LAB7_LIST_H

#endif //LAB7_LIST_H

#define bool int
#define true 1
#define false 0
#include <string.h>
#include <malloc.h>
#include <windows.h>

//Тайпдефы для преступника.
typedef char tSurname[20];
typedef char tName[20];
typedef char tNickname[20];
typedef char tHairColor[20];
typedef char tSpecial[30];
typedef char tCitizenship[20];
typedef char tLanguages[30];
typedef char tCrime[25];
typedef char tOrganization[20];
typedef unsigned int tHeight;
typedef unsigned int tWeight;

//Тайпдефы для преступления.
typedef char tPlace[20];
typedef char tParticipants[40];
typedef char tConsequences[20];
typedef char tSpecialists[40];

//Тайпдефы для организации.
typedef char tTitle[20];
typedef char tActivity[25];
typedef char tRating[20];

//Преступник.
struct Criminal
{
    tSurname surname;
    tName name;
    tNickname nickname;
    tHeight height;
    tWeight weight;
    tHairColor hairColor;
    tSpecial signs;
    tCitizenship nationality;
    tLanguages languages;
    tCrime crimeType;
    tOrganization crimeOrganization;

    struct Criminal *prev, *next;
};

struct CriminalList
{
    int size;
    struct Criminal *head, *tail;
};

//Преступление.
struct Crime
{
    tPlace crimePlace;
    tParticipants participants;
    tConsequences consequences;
    tSpecialists commentary;

    struct Crime *prev, *next;
};

struct CrimeList
{
    int size;
    struct Crime *head, *tail;
};

//Организация.
struct Organization
{
    tTitle name;
    tActivity occupation;
    tRating danger;

    struct Organization *prev, *next;
};

struct OrganizationList
{
    int size;
    struct Organization *head, *tail;
};


//Функции для преступников.

//Добавление
void AddCriminal(struct CriminalList *C, char* Surname, char* Name, char* Nickname, unsigned int Height,
        unsigned int Weight, char* Color, char* Signs, char* Nationality, char* Languages, char* Crimes, char* Organizations)
{
    struct Criminal* newCrime;
    newCrime = (struct Criminal*)malloc(sizeof(struct Criminal));

    newCrime -> prev = C -> tail;
    newCrime -> next = NULL;
    strcpy_s(newCrime -> surname, sizeof(newCrime -> surname), Surname);
    strcpy_s(newCrime -> name, sizeof(newCrime -> name), Name);
    strcpy_s(newCrime -> nickname, sizeof(newCrime -> nickname), Nickname);
    newCrime -> height = Height;
    newCrime -> weight = Weight;
    strcpy_s(newCrime -> hairColor, sizeof(newCrime -> hairColor), Color);
    strcpy_s(newCrime -> signs, sizeof(newCrime -> signs), Signs);
    strcpy_s(newCrime -> nationality, sizeof(newCrime -> nationality), Nationality);
    strcpy_s(newCrime -> languages, sizeof(newCrime -> languages), Languages);
    strcpy_s(newCrime -> crimeType, sizeof(newCrime -> crimeType), Crimes);
    strcpy_s(newCrime -> crimeOrganization, sizeof(newCrime -> crimeOrganization), Organizations);

    if(C -> tail)
        C -> tail -> next = newCrime;
    else
        C -> head = C -> tail;
    C -> size++;
}

//Удаление
bool DeleteCriminal(struct CriminalList *C, int position)
{
    if(position < 0 || position > C -> size)
    {
        printf("Error.");
        return false;
    }
    else
    {
        struct Criminal *temp  = C -> head;
        while(position--)
        {
            temp = temp -> next;
        }

        if(temp -> prev)
            temp -> prev -> next = temp -> next;
        if(temp -> next)
            temp -> next -> prev = temp -> prev;
        free(temp);
        C -> size--;
        return true;
    }
}

//Очистка.
void RecoveredCriminal(struct CriminalList *C)
{
    while(DeleteCriminal(C, C -> size -1));
}

//Загрузка из файла.
void LoadCriminal(struct CriminalList *C)
{
    FILE *file;
    RecoveredCriminal(C);

    fopen_s(&file, "Criminals.txt", "r");
    if(!file)
        exit(1);
    else
    {
        char Name[20], Surname[20], Nickname[20], height[4], weight[4], Color[20], Signs[30], Nationality[20],
        Languages[30], Crimes[25], Organization[20];
        while(fgets(Surname, 20, file))
        {
            fgets(Name, 20, file);
            fgets(Nickname, 20, file);
            fgets(height, 4, file);
            fgets(weight, 4, file);
            fgets(Color, 20, file);
            fgets(Signs, 30, file);
            fgets(Nationality, 20, file);
            fgets(Languages, 30, file);
            fgets(Crimes, 25, file);
            fgets(Organization, 20, file);
            fclose(file);
            AddCriminal(C, Name, Surname, Nickname, atoi(height), atoi(weight), Color, Signs, Nationality, Languages, Crimes, Organization);
        }
    }
}

//Загрузка в файл
void SaveCriminal(struct CriminalList * C)
{
    FILE *file;
    fopen_s(&file, "Crime.txt", "w");
    struct Criminal *temp = C -> head;

    if(!file || ! (temp -> next))
        exit(1);
    else
    {
        while(temp -> next)
        {
            char weight[4], height[4];
            _itoa_s(temp -> weight, weight, sizeof(weight) , 10);
            _itoa_s(temp -> height, height, sizeof(height), 10);

            fputs(temp -> surname, file);
            fputs(temp -> name, file);
            fputs(temp -> nickname, file);
            fputs(height, file);
            fputs(weight, file);
            fputs(temp -> hairColor, file);
            fputs(temp -> signs, file);
            fputs(temp -> nationality, file);
            fputs(temp -> languages, file);
            fputs(temp -> crimeType, file);
            fputs(temp -> crimeOrganization, file);
            temp = temp -> next;
        }
        fclose(file);
    }
}

//Вывод.
void ShowCriminals(struct CriminalList *C)
{
    struct Criminal *temp = C -> head;
    char weight[4], height[4];
    while(temp -> next)
    {
        _itoa_s(temp -> weight, weight, sizeof(weight), 10);
        _itoa_s(temp -> weight, weight, sizeof(weight), 10);
        puts(temp -> name);
        puts(temp -> surname);
        puts(temp -> nickname);
        puts(height);
        puts(weight);
        puts(temp -> hairColor);
        puts(temp -> signs);
        puts(temp -> nationality);
        puts(temp -> languages);
        puts(temp -> crimeType);
        puts(temp -> crimeOrganization);
        temp = temp -> next;
    }

    _itoa_s(temp -> weight, weight, sizeof(weight), 10);
    _itoa_s(temp -> weight, weight, sizeof(weight), 10);
    puts(temp -> name);
    puts(temp -> surname);
    puts(temp -> nickname);
    puts(height);
    puts(weight);
    puts(temp -> hairColor);
    puts(temp -> signs);
    puts(temp -> nationality);
    puts(temp -> languages);
    puts(temp -> crimeType);
    puts(temp -> crimeOrganization);
    puts("\n\n");
}

void PrintCriminal(struct Criminal *person)
{
    char weight[4], height[4];
    _itoa_s(person -> height, height, sizeof(height), 10);
    _itoa_s(person -> weight, weight, sizeof(weight), 10);
    puts(person -> name);
    puts(person -> surname);
    puts(person -> nickname);
    puts(height);
    puts(weight);
    puts(person -> hairColor);
    puts(person -> signs);
    puts(person -> nationality);
    puts(person -> languages);
    puts(person -> crimeType);
    puts(person -> crimeOrganization);
    puts("\n");
}

//Функции для преступлений.

//Добавление.
void AddCrime(struct CrimeList *C, char *Place, char *Participants, char *Consequences, char *Commentary)
{
    struct Crime *temp;
    temp = (struct Crime*)malloc(sizeof(struct Crime));
    temp -> prev = C -> tail;
    temp -> next = NULL;
    strcpy_s(temp -> crimePlace, sizeof(temp -> crimePlace), Place);
    strcpy_s(temp -> participants, sizeof(temp -> participants), Participants);
    strcpy_s(temp -> consequences, sizeof(temp -> consequences), Consequences);
    strcpy_s(temp -> commentary, sizeof(temp -> commentary), Commentary);

    if(C -> tail)
        C -> tail -> next = temp;
    else
        C -> head = C -> tail;
    C -> size++;
}

//Удаление
bool DeleteCrime(struct CrimeList *C, int position)
{
    if(position < 0 || position > C -> size)
    {
        printf("Error.");
        return false;
    }
    else
    {
        struct Crime *temp  = C -> head;
        while(position--)
        {
            temp = temp -> next;
        }

        if(temp -> prev)
            temp -> prev -> next = temp -> next;
        if(temp -> next)
            temp -> next -> prev = temp -> prev;
        free(temp);
        C -> size--;
        return true;
    }
}

//Очистка.
void RecoveredCrime(struct CrimeList *C)
{
    while(DeleteCrime(C, C -> size - 1));
}

//Загрузка из файла.
void LoadCrime(struct CrimeList *C)
{
    FILE *file;
    RecoveredCrime(C);

    fopen_s(&file, "Crimes.txt", "r");
    if(!file)
        exit(1);
    else
    {
        char Place[20], Participants[20], Consequences[20], Commentary[40];
        while (fgets(Place, 20, file))
        {
            fgets(Participants, 20, file);
            fgets(Consequences, 20, file);
            fgets(Commentary, 40, file);
            AddCrime(C, Place, Participants, Consequences, Commentary);
        }
        fclose(file);
    }
}

//Загрузка в файл.
void SaveCrime(struct CrimeList *C)
{
    FILE *file;
    fopen_s(&file, "Crimes.txt", "w");

    if(!file)
        exit(1);

    struct Crime *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while(temp -> next)
        {
            fputs(temp -> crimePlace, file);
            fputs(temp -> participants, file);
            fputs(temp ->consequences, file);
            fputs(temp ->commentary, file);
            temp = temp -> next;
        }
        fputs(temp -> crimePlace, file);
        fputs(temp -> participants, file);
        fputs(temp ->consequences, file);
        fputs(temp ->commentary, file);

        fclose(file);
    }
}

//Вывод на экран.
void ShowCrimes(struct CrimeList *C)
{
    struct Crime *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while(temp -> next)
        {
            puts(temp -> crimePlace);
            puts(temp -> participants);
            puts(temp -> consequences);
            puts(temp -> commentary);
            puts("\n");
            temp = temp -> next;
        }
        puts(temp -> crimePlace);
        puts(temp -> participants);
        puts(temp -> consequences);
        puts(temp -> commentary);
        puts("\n\n");
    }
}

void PrintCrime(struct Crime *crime)
{
    puts(crime -> crimePlace);
    puts(crime -> participants);
    puts(crime -> consequences);
    puts(crime -> commentary);
    puts("\n");
}

//Функции для организации.

//Добавление.
void AddOrganization(struct OrganizationList* C, char* Name, char* Activity, char* Danger)
{
    struct Organization *temp;
    temp = (struct Organization*)malloc(sizeof(struct Organization));
    temp -> prev = C -> tail;
    temp -> next = NULL;

    strcpy_s(temp -> name, sizeof(temp -> name), Name);
    strcpy_s(temp -> occupation, sizeof(temp -> occupation), Activity);
    strcpy_s(temp -> danger, sizeof(temp -> danger), Danger);

    if(C -> tail)
        C -> tail -> next = temp;
    if(!C -> head)
        C -> head = C -> tail;
    C -> size++;
}

//Удаление организации.
bool DeleteOrganization(struct OrganizationList* C, int position)
{
    if(position < 0 || position > C -> size - 1)
        return false;

    struct Organization* temp = C -> head;
    while(position--)
    {
        temp = temp -> next;
    }

    if(temp -> prev)
        temp -> prev -> next = temp -> next;
    if(temp -> next)
        temp -> next -> prev = temp -> prev;
    free(temp);
    C -> size--;
    return true;
}

//Очистка.
void RecoveredOrganization(struct OrganizationList *C)
{
    while(DeleteOrganization(C, C -> size - 1));
}

//Загрузка из файла.
void LoadOrganization(struct OrganizationList *C)
{
    FILE *file;
    RecoveredOrganization(C);
    fopen_s(&file, "Organizations.txt", "r");

    if(!file)
        exit(1);
    else
    {
        char Name[20], Activity[25], Danger[20];
        while(fgets(Name, 20, file))
        {
            fgets(Activity, 25, file);
            fgets(Danger, 20, file);
            AddOrganization(C, Name, Activity, Danger);
        }
        fclose(file);
    }
}

//Загрузка в файл.
void SaveOrganization(struct OrganizationList *C)
{
    FILE *file;
    fopen_s(&file, "Organizations.txt", "w");

    if(!file)
        exit(1);
    else
    {
        struct Organization *temp = C -> head;
        if(!temp)
            return;
        else
        {
            while(temp -> next)
            {
                fputs(temp->name, file);
                fputs(temp->occupation, file);
                fputs(temp->danger, file);
                temp = temp -> next;
            }
        }
        fputs(temp->name, file);
        fputs(temp->occupation, file);
        fputs(temp->danger, file);
        fclose(file);
    }
}

//Вывод на экран.
void ShowOrganizations(struct OrganizationList *C)
{
    struct Organization *temp = C -> head;
    if(!temp)
        return;

    while(temp -> next)
    {
        puts(temp -> name);
        puts(temp -> occupation);
        puts(temp -> danger);
        temp = temp -> next;
    }
    puts(temp -> name);
    puts(temp -> occupation);
    puts(temp -> danger);
    puts("\n\n");
}

void PrintOrganization(struct Organization *org)
{
    puts(org -> name);
    puts(org -> occupation);
    puts(org -> danger);
    puts("\n");
}

//Функции поиска и установления связей.

//Поиск по данным преступника.
//Заголовки для удобства
void SearchCriminalSurname(struct CriminalList *C, char Surname[]);
void SearchCriminalName(struct CriminalList *C, char Name[]);
void SearchCriminalNickname(struct CriminalList *C, char Nickname[]);
void SearchCriminalWeight(struct CriminalList *C, int Weight);
void SearchCriminalHeight(struct CriminalList *C, int Height);
void SearchCriminalColor(struct CriminalList *C, char Color[]);
void SearchCriminalFeature(struct CriminalList *C, char Feature[]);
void SearchCriminalNationality(struct CriminalList *C, char Nationality[]);
void SearchCriminalLanguages(struct CriminalList *C, char Language[]);
void SearchCriminalCrimes(struct CriminalList *C, char Crime[]);
void SearchCriminalOrganization(struct CriminalList *C, char Organization[]);



void SearchCriminal(struct CriminalList *C, int parameter)
{
    switch(parameter)
    {
        case 1:
        {
            char Surname[20];
            puts("Enter the surname to search for: ");
            gets_s(Surname, sizeof(Surname));
            SearchCriminalSurname(C, Surname);
            break;
        }

        case 2:
        {
            char Name[20];
            puts("Enter the name to search for: ");
            gets_s(Name, sizeof(Name));
            SearchCriminalName(C, Name);
            break;
        }

        case 3:
        {
            char Nickname[20];
            puts("Enter the nickname to search for: ");
            gets_s(Nickname, sizeof(Nickname));
            SearchCriminalNickname(C, Nickname);
            break;
        }

        case 4:
        {
            char Height[4];
            puts("Enter the height to search for: ");
            gets_s(Height, sizeof(Height));
            SearchCriminalHeight(C, atoi(Height));
            break;
        }

        case 5:
        {
            char Weight[4];
            puts("Enter the weight to search for: ");
            gets_s(Weight, sizeof(Weight));
            SearchCriminalWeight(C, atoi(Weight));
            break;
        }

        case 6:
        {
            char HairColor[20];
            puts("Enter the hair color to search for: ");
            gets_s(HairColor, sizeof(HairColor));
            SearchCriminalColor(C, HairColor);
            break;
        }

        case 7:
        {
            char Feature[30];
            puts("Enter the special sign to search for: ");
            gets_s(Feature, sizeof(Feature));
            SearchCriminalFeature(C, Feature);
            break;
        }

        case 8:
        {
            char Nationality[20];
            puts("Enter the nationality to search for: ");
            gets_s(Nationality, sizeof(Nationality));
            SearchCriminalNationality(C, Nationality);
            break;
        }

        case 9:
        {
            char Language[30];
            puts("Enter the language to search for: ");
            gets_s(Language, sizeof(Language));
            SearchCriminalLanguages(C, Language);
            break;
        }

        case 10:
        {
            char Crime[25];
            puts("Enter the crime to search for: ");
            gets_s(Crime, sizeof(Crime));
            SearchCriminalCrimes(C, Crime);
            break;
        }

        case 11:
        {
            char Organization[20];
            puts("Enter the organization to search for: ");
            gets_s(Organization, sizeof(Organization));
            SearchCriminalOrganization(C, Organization);
            break;
        }

        default:
        {
            break;
        }
    }
}

void SearchCriminalSurname(struct CriminalList *C, char Surname[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> surname, Surname))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalName(struct CriminalList *C, char Name[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> name, Name))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalNickname(struct CriminalList *C, char Nickname[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> name, Nickname))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalWeight(struct CriminalList *C, int Weight)
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if( (temp -> weight) == Weight)
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalHeight(struct CriminalList *C, int Height)
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if( (temp -> height) == Height)
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalColor(struct CriminalList *C, char Color[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> hairColor, Color))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalFeature(struct CriminalList *C, char Feature[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(strstr(temp -> signs, Feature))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalNationality(struct CriminalList *C, char Nationality[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> nationality, Nationality))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalLanguages(struct CriminalList *C, char Language[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(strstr(temp -> languages, Language))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalCrimes(struct CriminalList *C, char Crime[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(strstr(temp -> crimeType, Crime))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCriminalOrganization(struct CriminalList *C, char Organization[])
{
    struct Criminal *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> crimeOrganization, Organization))
            {
                PrintCriminal(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}



//Поиск по преступлениям.
void SearchCrimePlace(struct CrimeList *C, char Place[]);
void SearchCrimeParticipants(struct CrimeList *C, char Person[]);
void SearchCrimeConsequence(struct CrimeList *C, char Consequence[]);

void SearchCrime(struct CrimeList *C, int parameter)
{
    switch(parameter)
    {
        case 1:
        {
            char Place[20];
            puts("Enter the place to search for:");
            gets_s(Place, sizeof(Place));
            SearchCrimePlace(C, Place);
        }

        case 2:
        {
            char Participant[20];
            puts("Enter the participant to search for:");
            gets_s(Participant, sizeof(Participant));
            SearchCrimeParticipants(C, Participant);
        }

        case 3:
        {
            char Consequence[20];
            puts("Enter the consequence to search for:");
            gets_s(Consequence, sizeof(Consequence));
            SearchCrimeConsequence(C, Consequence);
        }
    }
}

void SearchCrimePlace(struct CrimeList *C, char Place[])
{
    struct Crime *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> crimePlace, Place))
            {
                PrintCrime(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCrimeParticipants(struct CrimeList *C, char Person[])
{
    struct Crime *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(strstr(temp -> participants , Person))
            {
                PrintCrime(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchCrimeConsequence(struct CrimeList *C, char Consequence[])
{
    struct Crime *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(strstr(temp -> consequences , Consequence))
            {
                PrintCrime(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}



//Поиск по организациям.
void SearchOrgName(struct OrganizationList *C, char Name[]);
void SearchOrgActivity(struct OrganizationList *C, char Activity[]);
void SearchOrgRating(struct OrganizationList *C, char Rating[]);

void SearchOrganization(struct OrganizationList* C, int parameter)
{
    switch(parameter)
    {
        case 1:
        {
            char Name[20];
            puts("Enter the name to search for: ");
            gets_s(Name, sizeof(Name));
            SearchOrgName(C, Name);
            break;
        }

        case 2:
        {
            char Activity[20];
            puts("Enter the activity to search for: ");
            gets_s(Activity, sizeof(Activity));
            SearchOrgActivity(C, Activity);
            break;
        }

        case 3:
        {
            char Rating[20];
            puts("Enter the rating to search for: ");
            gets_s(Rating, sizeof(Rating));
            SearchOrgRating(C, Rating);
        }

    }
}

void SearchOrgName(struct OrganizationList *C, char Name[])
{
    struct Organization *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> name, Name))
            {
                PrintOrganization(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchOrgActivity(struct OrganizationList *C, char Activity[])
{
    struct Organization *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(strstr(temp -> occupation , Activity))
            {
                PrintOrganization(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}

void SearchOrgRating(struct OrganizationList *C, char Rating[])
{
    struct Organization *temp = C -> head;
    if(!temp)
        return;
    else
    {
        while (temp -> next)
        {
            if(!strcmp(temp -> danger, Rating))
            {
                PrintOrganization(temp);
                temp  = temp -> next;
            }
            else
                temp = temp -> next;
        }
    }
}


