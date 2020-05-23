#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void CheckMistakes(char* str);
void CheckSpace(char* str);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char str[200];

    FILE* file;
    fopen_s(&file,"4.4.txt", "r");


    if (file != NULL)
    {
        printf_s("File newfile.txt was successfully opened");
        fgets(str, 200, file);
        printf("\n%s", str);
    }
    else
        printf_s("File was not opened(");

    CheckSpace(str);
    CheckMistakes(str);

	printf("\n%s", str);
	getch();
}

void CheckMistakes(char* str)
{
    int check = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
            if (check == 0)
            {
                str[i] = toupper(str[i]);
                check++;
            }
        if (str[i] == '.')
            check = 0;

    }
}

void CheckSpace(char* str)
{
    char str2[200];
    for (int i = 0; i < 200; i++)
        str2[i] = ' ';
    for (int i = 0, j = 0; str[i] != '\0'; i++, j++)
    {
        if (str[i] == (char)32 && str[i + 1] == (char)32)
        {
            j--;
            continue;
        }
        str2[j] = str[i];
    }
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = str2[i];
}
