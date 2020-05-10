//Задание 4.1 Вариант 21
#include <iostream>
#include <stdlib.h>

int i = 0;

void ItoB(int number, char string, int countsystem)
{

    if (number == 0)
    {
        return;
    }

    int answer = number % countsystem;

    if (answer <= 9) 
    { 
        ItoB(number / countsystem, NULL ,countsystem);
        string = answer + '0';
        printf_s("%c", &string);
    }
    else 
    { 
        ItoB(number / countsystem, NULL ,countsystem);
        string = (answer - 10 + 'A') + '0'; 
        std::cout << string;
    }
}

int main()
{
    int num, countsystem;
    char string = ' ';
    printf_s("Enter your number: ");
    scanf_s("%d", &num);
    printf_s("Enter your count system: ");
    scanf_s("%d", &countsystem);

    if (countsystem > 36 || countsystem < 2) return 0;
    if (num == 0) {
        printf_s("your number = 0");
        return 0;
    }

    ItoB(num, string, countsystem);

}



