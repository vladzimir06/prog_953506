#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Функция для корректного ввода
void Input(double *x1, double *x2, double *x3, double *y1, double *y2, double *y3);

//Проверка на тип треугольника
void CheckType();

//Периметр
double Perimeter(double a, double b, double c);

//Площадь
double Area(double a, double b, double c);

//Радиусы
void ShowRadius(double a, double b, double c);

//Инфо об авторе
void ShowInfo();

//Менюшка
void ShowMenu();


int main()
{
    double x1,x2,x3,y1,y2,y3;
    double sideOne, sideTwo, sideThree;
    int decision = 0;

    printf("Hello! This program works with triangles!");
    system("pause");

    //Ввод начальных данных и расчет сторон
    printf("You have to enter the data first: \n");

    Input(&x1, &x2, &x3, &y1, &y2, &y3);
    sideOne = sqrt(pow(x2-x1,2) +pow(y2-y1,2));
    sideTwo = sqrt(pow(x3-x1,2) + pow(y3-y1, 2));
    sideThree = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));

    do
    {
        ShowMenu();
        scanf_s("%d", &decision);

        switch (decision)
        {
            //Потворный ввод
            case 1:
            {
                Input(&x1, &x2, &x3, &y1, &y2, &y3);

                sideOne = sqrt(pow(x2-x1,2) +pow(y2-y1,2));
                sideTwo = sqrt(pow(x3-x1,2) + pow(y3-y1, 2));
                sideThree = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));

                system("pause");
                break;
            }

            //Проверка типа треугольника
            case 2:
            {
                CheckType(sideOne, sideTwo, sideThree);
                break;
            }

            //Расчет периметра
            case 3:
            {
                Perimeter(sideOne, sideTwo, sideThree);
                break;
            }

            //Расчет площади
            case 4:
            {
                Area(sideOne, sideTwo, sideThree);
                break;
            }

            //Расчет радиусов окружностей
            case 5:
            {
                ShowRadius(sideOne, sideTwo, sideThree);
                break;
            }

            //Вывод информации об авторе
            case 6:
            {
                ShowInfo();
                break;
            }

            //Завершает работу меню
            case 7:
            {
                break;
            }

            default:
            {
                printf("Error!\n");
                break;
            }
        }

    } while(decision != 7);

}

void Input(double *x1, double *x2, double *x3, double *y1, double *y2, double *y3)
{
    double value = 0;
    char input[50];
    size_t amount = sizeof(input);

    while(value <= 0)
    {
        printf("Now enter the value for x1: ");
        scanf_s("%s", input);
        value = strtod(input, NULL);

        memset(input, '\0', amount);

        if(value <= 0)
            printf("Error. Please enter a valid number.\n\n");
        else
            *x1 = value;
    }

    while(value <= 0)
    {
        printf("Now enter the value for y1: ");
        scanf_s("%s", input);
        value = strtod(input, NULL);

        memset(input, '\0', amount);

        if(value <= 0)
            printf("Error. Please enter a valid number.\n\n");
        else
            *y1 = value;
    }

    while(value <= 0)
    {
        printf("Now enter the value for x2: ");
        scanf_s("%s", input);
        value = strtod(input, NULL);

        memset(input, '\0', amount);

        if(value <= 0)
            printf("Error. Please enter a valid number.\n\n");
        else
            *x2 = value;
    }

    while(value <= 0)
    {
        printf("Now enter the value for y2: ");
        scanf_s("%s", input);
        value = strtod(input, NULL);

        memset(input, '\0', amount);

        if(value <= 0)
            printf("Error. Please enter a valid number.\n\n");
        else
            *y2 = value;
    }

    while(value <= 0)
    {
        printf("Now enter the value for x3: ");
        scanf_s("%s", input);
        value = strtod(input, NULL);

        memset(input, '\0', amount);

        if(value <= 0)
            printf("Error. Please enter a valid number.\n\n");
        else
            *x3 = value;
    }

    while(value <= 0)
    {
        printf("Now enter the value for y3: ");
        scanf_s("%s", input);
        value = strtod(input, NULL);

        memset(input, '\0', amount);

        if(value <= 0)
            printf("Error. Please enter a valid number.\n\n");
        else
            *y3 = value;
    }

}

void CheckType(double a, double b, double c)
{
    //Таки определяем вид
    if(b == b && a == a && b == c)
        printf("This one is equilateral!\n"); //равносторнний

    else if(a == b || a == c || b == c)
        printf("This one is isosceles!\n"); //равнобедренный

    else if(a * a == b * b + c * c || b * b == a * a + c * c || c * c == b * b + a * a)
        printf("This one is rectangular!\n"); //прямоугольный

    else if(a * a > b * b + c * c || b * b > a * a + c * c || c * c > b * b + a * a)
        printf("This one is obtuse!\n"); //тупоугольный

    else
        printf("This one is acute-angled!\n"); //остроугольный
}

double Perimeter(const double a, const double b, const double c)
{
    double perimeter = a + b + c;
    printf("The perimeter is: %f\n", perimeter);
    return perimeter;
}

double Area(const double a, const double b, const double c)
{
    double half = (a + b + c) / 2;
    double area = sqrt(half * (half - a) * (half - b) * (half - c));
    printf("The area is: %f\n", area);
    return area;
}

void ShowRadius(const double a, const double b, const double c)
{
    double little_rad = Area(a, b, c) / (Perimeter(a, b ,c) / 2);
    double big_rad = (a * b * c) / (4 * Area(a, b, c));
    printf("Internal and external circle radius: %f\t%f", little_rad, big_rad);
}

void ShowInfo()
{
    printf("Author: Daniil Prokopovich.\n");
    printf("Faculty: Computer Systems and Networks.\n");
    printf("Group: 953506.");
    printf("I hope I gotta get through this!!!\n");
}

void ShowMenu()
{
    system("cls");
    printf("You can do the following: \n");
    printf("1. Enter the data about the triangle.\n");
    printf("2. Check the triangle type.\n");
    printf("3. Calculate the perimeter.\n");
    printf("4. Calculate the area.\n");
    printf("5. Calculate the internal and external circles' radius.\n");
    printf("6. Get info about the creator.\n");
    printf("7. Exit.\n");
}
