// Лабораторнаяси2,1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "stdio.h"
#include "math.h"
#include <locale.h>
typedef struct
{
    int real, imagine;
}
complexNumber;
void vvod(complexNumber*chislo ); //прототип функции вводящей кч
void vivodAlg(complexNumber*);//вывод в алгебраической форме
void vivodPok(complexNumber*);//Вывод комплексного числа в показательной форме.
void poluchSopr(complexNumber*);//Получение сопряженного комплексного числа.
void vozvStep(complexNumber*);//Возведение комплексного числа в целую положительную степень.
int main()
{
    setlocale(LC_ALL, "Rus");
    int c;
    complexNumber* chislo = NULL;
    printf(" 1. Ввод комплексного числа.");
    fputc('\n', stdout);
    printf(" 2. Вывод комплексного числа в алгебраической форме.");
    fputc('\n', stdout);
    printf(" 3. Вывод комплексного числа в показательной форме.");
    fputc('\n', stdout);
    printf(" 4. Получение сопряженного комплексного числа.");
    fputc('\n', stdout);
    printf(" 5. Возведение комплексного числа в целую положительную степень.");
    fputc('\n', stdout);
    printf(" 6. Информация о версии и авторе программы.");
    fputc('\n', stdout);
    printf(" 7. Выход из программы. ");
    scanf_s("%i", &c);
    while (c < 1 || c>7)//проверка на правильно введенную цифру
    {
        printf("Error");
        scanf_s("%i", &c);
    }
    while (1)
    {
        switch (c)
        {
        case 1: { if (!(chislo = (complexNumber*)malloc(sizeof(complexNumber))))
        {
			printf("не хватает памяти"); 
        }
				vvod(chislo); free(chislo);  break; }
        case 2: {if(!chislo)
        {
            printf("Число не введено");
        }
              vivodAlg(chislo); break;
        }
        case 3: {if (!chislo)
        {
            printf("Число не введено");
        }
              vivodPok(chislo); break;
        }
        case 4: {if (!chislo)
        {
            printf("Число не введено");
        }
              poluchSopr(chislo); break;
        }
        case 5: {if (!chislo)
        {
            printf("Число не введено");
        }
              vozvStep(chislo); break;
        }
        case 6: 
        {
            printf("Программа работающая с комплексным числом, автор Райко "); break;
        }
        case 7: break;
        }
        printf("Хотите продолжить? Если нет, нажмите N");
        if (c = getchar() == 'N' || c == 'n');
        else
        {
            scanf_s("%i", &c);
            while (c < 1 || c>7)
            {
                printf("Error");
                scanf_s("%i", &c);
            }
        }
       
    }
}
void vvod(complexNumber* chislo)
{
    printf("voobrashaemaya chasti");
    scanf_s("%i", &(chislo->imagine));
    printf("realinya chasti chasti");
    scanf_s("%i", &(chislo->real));
}
void vivodAlg(complexNumber* chislo)
{
    printf("Vashe chislo \n %i + %i i", chislo->real, chislo->imagine);
}
void vivodPok(complexNumber* chislo)
{
    int z = (int)(hypot((double)chislo->imagine, (double)chislo->real));
    printf("Vashe chislo \n %i * (cos(%f)+i*sin(%f)", z, (float)cos((double)(chislo->real / z)),
        (float)sin((double)(chislo->imagine / z)));
}
void poluchSopr(complexNumber* chislo)
{
    printf("Vashe sopryashennoe %i + %i i", chislo->real, chislo->imagine * (-1));
}
void vozvStep(complexNumber* chislo)
{
    int z = (int)(hypot((double)chislo->imagine, (double)chislo->real));
    double step;
    printf("Vvedite stepen");
    scanf_s("%i", &step);
    printf("Chislo,vozvedennoe w stepen %i * (cos(%f)+i*sin(%f)", pow((double)z, step), step * (float)cos((double)(chislo->real / z)),
        step * (float)sin((double)(chislo->imagine / z)));
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
