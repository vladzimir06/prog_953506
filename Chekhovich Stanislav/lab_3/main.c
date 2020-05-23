//Задание 3.2 Вариант 3
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define STR_MAX_SIZE 100

int main()
{
    while(1)
    {
        system("cls");
        int n, K;
        printf("1.Encrypt message"
               "\n2.Decrypt message"
               "\n3.Exit the program\n");
        scanf("%d", &K);
        if(K < 1 || K > 3)
        {
            printf("Wrong input");
            getch();
            continue;
        }
        system("cls");
        switch (K)
        {
        case 1:
        {
            char* str = (char*)malloc(STR_MAX_SIZE * sizeof(char));
            char* str2 = (char*)malloc(STR_MAX_SIZE * sizeof(char));
            printf("Write string you want to encrypt: ");
            fflush(stdin);
            fgets(str, STR_MAX_SIZE, stdin);
            str[strlen(str) - 1] = '\0';
            for(n = 1; n * n < strlen(str); n++){ }
            for(int i = 0; i < n * n; i++)
            {
                if(i < strlen(str))
                {
                    str2[i] = str[i];
                }
                else
                {
                    str2[i] = ' ';
                }
            }
            str2[n * n] = '\0';
            char a[n][n];
            int k = 0,s = 1;
            for(int j = 0; j < n * n; s++)
            {
                for (int i = s - 1; i < n - (s - 1); i++, j++)
                {
                    a[i][s - 1] = str2[k];
                    k++;
                }
                for (int i = s; i < n - (s - 1); i++, j++)
                {
                    a[n - s][i] = str2[k];
                    k++;
                }
                for (int i = n - (s + 1);i >= s - 1; i--, j++)
                {
                    a[i][n - s] = str2[k];
                    k++;
                }
                for (int i = n - (s + 1); i >= s; i--, j++)
                {
                    a[s - 1][i] = str2[k];
                    k++;
                }
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    printf("%c",a[i][j]);
                }
                printf("\n");
            }
            free(str);
            free(str2);
            printf("\nPress any button...");
            getch();
            break;
        }
        case 2:
        {
            printf("How many strings are in message?\n");
            scanf("%d", &n);
            if(n < 1 || n > 100)
            {
                printf("Wrong input");
                getch();
                continue;
            }
            fflush(stdin);
            char** str = (char**)malloc(n * sizeof(char*));
            for(int i = 0; i < n; i++)
            {
                str[i] = (char *)malloc(STR_MAX_SIZE * sizeof(char));
            }
            for(int i = 0; i < n; i++)
            {
                fgets(str[i], STR_MAX_SIZE, stdin);
                str[i][strlen(str[i]) - 1] = '\0';
            }
            char* str2 = (char*)malloc(STR_MAX_SIZE * sizeof(char));
            int k = 0, s = 1;
            for(int j = 0; j < n * n; s++)
            {
                for (int i = s - 1; i < n - (s - 1); i++, j++)
                {
                    str2[k] = str[i][s - 1];
                    k++;
                }
                for (int i = s; i < n - (s - 1); i++, j++)
                {
                    str2[k] = str[n - s][i];
                    k++;
                }
                for (int i = n - (s + 1);i >= s - 1; i--, j++)
                {
                    str2[k] = str[i][n - s];
                    k++;
                }
                for (int i = n - (s + 1); i >= s; i--, j++)
                {
                    str2[k] = str[s - 1][i];
                    k++;
                }
            }
            str2[k] = '\0';
            printf("%s", str2);
            for(int i = 0; i < n; i++)
            {
                free(str[i]);
            }
            free(str);
            free(str2);
            printf("\nPress any button...");
            getch();
            break;
        }
        case 3:
        {
            return 0;
        }
        }
    }
}
