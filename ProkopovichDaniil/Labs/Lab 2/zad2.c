#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>


int fact(int n);
void recursion(const float argument, const float compare, int n);
void iteration(const float argument, const float compare);


int main()
{
    printf("Hello! This program will compare the values of sinus, which is expanded into Taylor's row and the sinus itself.\n\n");
    system("pause");

    while(1)
    {
        system("cls");
        float compare = 0;
        float arg = 0;
        char check = 0;

        printf("First of all, you need to enter the value which will be used in comparison: ");
        scanf("%f", &compare);
        check = getchar();
        rewind(stdin);

        printf("\n\n");

        printf("Now enter your argument: ");
        scanf("%f", &arg);
        check = getchar();
        rewind(stdin);
        printf("\n\n");

        int start_time = clock();
        iteration(arg, compare);
        int end_time = clock();
        printf("It took %d milliseconds for iterative version to calculate the values.\n\n", end_time - start_time);


          start_time = clock();
          recursion(arg, compare, 1);
          end_time = clock();
          printf("It took %d milliseconds for recursive version to calculate the values.\n\n", end_time - start_time);


        printf("\nNow, if you want to continue, press y on your keyboard.\nOtherwise press n.\n");

        switch(getch())
        {
            case 'y':
            {
                printf("\n\n");
                continue;
            }
            case 'n':
            {
                printf("Thank you!");
                getch();
                return 0;
            }
        }
    }
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

void iteration(const float argument, const float compare)
{
    float result = 0;
    int j = 1;
    while (1)
    {
        result += pow(-1, j - 1) * (pow(argument, 2 * j - 1) / fact(2 * j - 1));
        if( result <= compare)
            break;
        j++;
    }
    printf("Value of Taylor's row:   %f\n", result);
    printf("Value of original sinus: %f\n", sin(argument));
    printf("The number of members of rows needed to get the result of comparison: %d\n", j);
}

void recursion(const float argument, const float compare, int n)
{
    static float result = 0;
    result += pow(-1, n - 1) * (pow(argument, 2 * n - 1) / fact(2 * n - 1));
    if( result <= compare)
    {
        printf("Value of Taylor's row:   %f\n", result);
        printf("Value of original sinus: %f\n", sin(argument));
        printf("The number of members of rows needed to get the result of comparison: %d\n", n);
        result = 0;
        return;
    }

    else
        recursion(argument, compare, n + 1);
}
