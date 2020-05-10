#define LENGTH 80
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int main()
{
    char letter;
    int amount = 0;
    char *str;
    int i = 0;

    printf("Enter the amount of line you'd like to enter: ");
    scanf("%d", &amount);
    str = (char *)malloc(LENGTH * amount * sizeof(char));

    for (int j = 0; j <= amount; j++)
    {
        do
        {
            letter = getchar();
            str[i++] = letter;
            if (i > amount * LENGTH - 2)
            {
                puts("U can't enter so much! <3");
                return 0;
            }
        } while (letter != '\n');
    }
    str[i] = '\0';

   while(i + 1)
   {
       printf("%c",str[i]);
       i--;
   }

    free(str);
    _getch();
    return 0;
}
