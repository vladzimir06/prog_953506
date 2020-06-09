// Задание 2.1(9) Стельмашук В.А.(гр. №953506)

/* Меры длины.
 Разработать программу, меню которой позволяет выполнить следующие функции :
*1.Ввод значения длины(километры, метры, сантиметры,
   миллиметры).
* 2.Перевод длины в русские традиционные единицы(версты,
    аршины, сажени, вершки).
* 3.Перевод длины в английские традиционные единицы(мили,
    ярды, футы, дюймы).
* 4.Вывод отчета, представляющего введенное значение в 1)
    километрах, 2) метрах, 3) сантиметрах, 4) миллиметрах.
* 5.Информация о версии и авторе программы
* 6.Выход из программы.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void English(double lenght);//перевод в английские традиционные меры длины

void Russian(double lenght);//перевод в русские традиционные меры длины

void GetInfo(double lenght);

int main()
{
    int choise = 0;
    double lenght = 0;
    int value = 0;

    printf("\nHello! if you want enter lenght in mm - enter 1, in cm - enter 2, in m - enter 3, in km - enter 4: ");
    scanf_s("%d", &value);
    system("cls");  // очищаем экран
    switch (value)
    {
    case 1:
    {
        printf("\nlenght: ");
        scanf_s("%lf", &lenght);
        break;
    }
    case 2:
    {
        printf("\nlenght: ");
        scanf_s("%lf", &lenght);
        lenght = lenght / 10;
        break;

    }
    case 3:
    {
        printf("\nlenght: ");
        scanf_s("%lf", &lenght);
        lenght = lenght / 1000;
        break;
    }
    case 4:
    {
        printf("\nlenght: ");
        lenght = lenght / 1000000;
        scanf_s("%lf", &lenght);
        break;
    }
    default:
    {
        lenght = 0;
        break;
    }
    }

    system("cls");  // очищаем экран
    printf("\n\t\t\t\t\t\tMenu:\n");
    printf("\t\t1.Convert lengths to Russian traditional units (versts, arshins, sazhens, tops).  \n");
    printf("\t\t2.Convert lengths to English traditional units (miles, yards, feet, inches). \n");
    printf("\t\t3.Information output in 1) kilometers, 2) meters, 3) centimeters, 4) millimeters.\n");
    printf("\t\t4.Information about the version and author of the program\n");
    printf("\t\t5.Exit from the program\n\n");

    int otvet = 0;

    do {
        printf("\nYour choise: \n");
        scanf_s("%d", &choise);
        switch (choise)
        {
        case 1:
        {
            Russian(lenght);
            break;
        }
        case 2: {
            English(lenght);
            break;
        }
        case 3: {
            GetInfo(lenght);
            break;
        }
        case 4: {
            printf("\nBSUIR\n");
            printf("KSIS\n");
            printf("IITP\n");
            printf("group 953506\n");
            printf("Stelmashuk Victoria\n");
            break;
        }
        case 5: {
            printf("Goodbye!");
            return 0;
        }
        default: {
            printf("ERROR, you should have entered a number\n");
            return 0;
        }
        }
        printf("Want to proceed? if 'yes' - enter 1: ");
        scanf_s("%d", &otvet);
    } while (otvet == 1);
}

void English(double lenght)
{
    double inches, feet, yards, miles;
    printf("inches:\n");
    inches = lenght * 25.4;
    printf("%lf\n", inches);
    printf("feet:\n");
    feet = inches * 12;
    printf("%lf\n", feet);
    printf("yards:\n");
    yards = feet * 3;
    printf("%lf\n", yards);
    printf("miles:\n");
    miles = yards * 1760;
    printf("%lf\n", miles);
}

void Russian(double lenght)
{
    double tops, sazhens, arshins, versts;
    printf("tops:\n");
    tops = lenght * 44.45;
    printf("%lf\n", tops);
    printf("sazhens:\n");
    sazhens = tops * 16;
    printf("%lf\n", sazhens);
    printf("arshins:\n");
    arshins = sazhens * 3;
    printf("%lf\n", arshins);
    printf("versts:\n");
    versts = arshins * 500;
    printf("%lf\n", versts);
}

void GetInfo(double lenght)
{
    double km, m, cm, mm;
    printf("kilometers:\n");
    km = lenght * 1000000;
    printf("%lf\n", km);
    printf("meters:\n");
    m = lenght * 1000;
    printf("%lf\n", m);
    printf("centimeters:\n");
    cm = lenght * 10;
    printf("%lf\n", cm);
    printf("millimeters:\n");
    mm = lenght;
    printf("%lf\n", mm);
}