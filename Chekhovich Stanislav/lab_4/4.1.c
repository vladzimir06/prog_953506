//Задание 4.1 Вариант 27
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <time.h>

#define WRONG_ARGUMENT -100
#define STR_MAX_SIZE 100

static const char *existingHolidays[] = {"Birthday", "New Year", "Christmas"};
static const char *compliments[] = {"Happy birthday to you!", "Happy new Year!", "Merry Christmas!"};
static const char *otherCompliments[] = {"every success", "the best of everything", "happiness",
                                         "good luck", "good mood", "much money"};

int strLen(char *str);

int strEquals(char* str1, char* str2);

int holidaysCmp(char *holidays);

void randomizer(int *r1, int *r2);

int main()
{
    int n, j, r1, r2;
    printf("How many surnames are in list?\n");
    scanf("%i", &n);
    if(n < 1 || n > 10)
    {
        printf("Wrong input! You should enter 1 < surnames < 11");
        exit(WRONG_ARGUMENT);
    }
    char** surnames = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        surnames[i] = (char *)malloc(STR_MAX_SIZE * sizeof(char));
    }
    char** holidays = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        holidays[i] = (char *)malloc(STR_MAX_SIZE * sizeof(char));
    }
    system("cls");
    for(int i = 0; i < n; i++)
    {
        printf("Write surname:  %i.", i + 1);
        scanf("%99s", surnames[i]);
    }
    system("cls");
    for(int i = 0; i < n; i++)
    {
        printf("What holiday does %s celebrate?\n", surnames[i]);
        fflush(stdin);
        fgets(holidays[i], STR_MAX_SIZE, stdin);
        holidays[i][strLen(holidays[i]) - 1] = '\0';
    }
    while(1)
    {
        system("cls");
        printf("Congratulate");
        for(int i = 0; i < n; i++)
        {
            printf("\n%i.%s (%s)", i + 1, surnames[i], holidays[i]);
        }
        printf("\n");
        scanf("%i", &j);
        if(j < 0 || j > n)
        {
            exit(WRONG_ARGUMENT);
        }
        j -= 1;
        system("cls");
        randomizer(&r1, &r2);
        if(holidaysCmp(holidays[j]) == -1)
        {
            printf("I wish you %s and %s!", otherCompliments[r1], otherCompliments[r2]);
        }
        else
        {
            printf("%s I wish you %s and %s!", compliments[holidaysCmp(holidays[j])], otherCompliments[r1], otherCompliments[r2]);
        }
        getch();
        system("cls");
        printf("1.Continue"
               "\n2.Exit the program\n");
        scanf("%i", &j);
        if(j == 2)
        {
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        free(surnames[i]);
    }
    free(surnames);
    for(int i = 0; i < n; i++)
    {
        free(holidays[i]);
    }
    free(holidays);
    return 0;
}

int strLen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

int strEquals(char* str1, char* str2)
{
    if(strLen(str1) == strLen(str2))
    {
        int equals = 1;
        for(int i = 0; i < strLen(str1); i++)
        {
            if(str1[i] != str2[i])
            {
                equals = 0;
            }
        }
        return equals;
    }
    else
    {
        return 0;
    }
}

int holidaysCmp(char *holidays)
{
    int cmp = -1;
    for(int i = 0; i < 3; i++)
    {
        if(strEquals(holidays, existingHolidays[i]))
        {
            cmp = i;
        }
    }
    return cmp;
}

void randomizer(int *r1, int *r2)
{
    srand(time(NULL));
    *r1 = rand()%6;
    *r2 = rand()%6;
    while(*r1 == *r2)
    {
        *r1 = rand()%6;
        *r2 = rand()%6;
    }
}
