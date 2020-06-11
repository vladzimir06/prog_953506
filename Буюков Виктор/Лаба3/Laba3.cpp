+﻿//Laba#3  Variant 25 (Буюков Виктор 953506)
//Куб состоит из n^3 прозрачных и непрозрачных элементарных 
//кубиков. Построить полностью непрозрачный куб, используя ровно 
//n^2 непрозрачных элементарных кубиков.

#include <stdio.h>
#include <malloc.h>
#include <math.h>


int simple_check(int size)
{
    int exit = 0;
    int size_new_massiv = 0;
    int amount_of_circle = sqrt(size); // граница возможного варианта движения
    double b; // рабочая переменная

    for (int i = 2; i <= amount_of_circle; i++)
    {
        exit = 0;
        b = (double)size;
        while (exit < 3)
        {
            b = b / i;
            exit++;
        }
        if (b == 1)
        {
            size_new_massiv = i * i;
            printf("\n\nWe find chislo.\nSize_New_Massiv = %d", size_new_massiv);
            i = ++amount_of_circle;
        }
        else printf("\n");
    }

    if (size_new_massiv == 0)
    {
        printf("Right input -> 8 27 64 125 (n^3)\n");
    }

    return size_new_massiv;
}

void massiv(int size_new_massiv, int amount_elements_of_massiv) // построение необходимого кубика
{
    int*** massiv;
    massiv = (int***)malloc(size_new_massiv * sizeof(int));
    for (int i = 0; i < size_new_massiv; i++)
    {
        massiv[i] = (int**)malloc(size_new_massiv * sizeof(int));
        for (int j = 0; j < size_new_massiv; j++)
        {
            massiv[i][j] = (int*)malloc(size_new_massiv * sizeof(int));
            for (int k = 0; k < size_new_massiv; k++)
            {
                massiv[i][j][k] = 1;
                printf("\nmassiv[%d][%d][%d] = %d", i, j, k, massiv[i][j][k]);
            }
        }
    }
}


int main()
{
    int size; // высота куба, состоящего из n^3 кубиков
    int size_new_massiv = 0; // высота нового куба, состоящего из n^2 кубиков

    size_new_massiv = simple_check(size); // проверка возможно ли из size создать new size удовлетворающая условие
    if (size_new_massiv == 0) return 0; // программа с подобным результатом не может работать 

    int amount_elements_of_massiv;
    printf("\n\nA cube consists of n transparent and opaque elementary cubes\nWrite number of orague cubes =");
    scanf_s("%d", &amount_elements_of_massiv);

    while (amount_elements_of_massiv < size * size)
    {
        printf("\nMinimum %d.Try again =", size * size);
        scanf_s("%d", &amount_elements_of_massiv);
    }

    massiv(size_new_massiv, amount_elements_of_massiv);
}