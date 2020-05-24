/*Элементы массива a(n,m) ниже главной диагонали равны нулю.
Выше и на главной диагонали нулевых элементов нет. Строки и
столбцы случайным образом перемешаны. Перестановкой строк и
столбцов восстановить исходный массив.*/

#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h> 
void Print(int** mas,int n, int m) //вывод массива на экран
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d ", mas[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int** mas, n, m, i, j, counter, t;
    system("chcp 1251");
    system("cls");
    printf("Введите количество строк: ");
    scanf_s("%d", &n);
    printf("Введите количество столбцов: ");
    scanf_s("%d", &m);
    mas = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        mas[i] = (int*)malloc(m * 8);
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf_s("%d", &mas[i][j]);
        }
    }
    Print(mas, n, m);
    printf("\n\n");
    //перестановка местами столбцов
    for (i = 0; i < n; i++)
    {
        counter = 0;
        for (j = 0; j < m; j++)
        {
            if (mas[i][j] == 0) counter++;
        }
        for (j = 0; j < m; j++)
        {
            t = mas[i][j];
            mas[i][j] = mas[counter][j];
            mas[counter][j] = t;
        }
    }
    //перестановка местами строк
   for (j = 0; j < m; j++)
    {
        counter = 0;
        for (i = 0; i < n; i++)
        {
            if (mas[i][j] == 0) counter++;
        }
        for (i = 0; i < n; i++)
        {
            t = mas[i][j];
            mas[i][j] = mas[i][n - counter - 1]; 
            mas[i][n - counter - 1] = t;
        }
    }
   Print(mas, n, m);
   for (i = 0; i < n; i++)
        free(mas[i]);
    free(mas);
    getchar();
}