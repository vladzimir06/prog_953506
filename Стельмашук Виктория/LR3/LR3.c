// Задание 3.2(8) Стельмашук В.А.(гр. №953506)

/*Матрицу a(m, n) заполнить следующим образом. Для заданных k и l
элементу akl присвоить значение 1; элементам, окаймляющим его
(соседним с ним по вертикали, горизонтали и диагонали) – значение
2; элементам следующего окаймления – значение 3 и так далее до
заполнения всей матрицы.
Примечание. Алгоритм не изменится, если координаты элемента
(несуществующего) k и l находятся за пределами матрицы. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int m = 0, n = 0;
    printf("Enter m:\n");
    scanf_s("%d", &m);
    printf("Enter n:\n");
    scanf_s("%d", &n);

    int k = 0, l = 0;
    printf("Enter k:\n");
    scanf_s("%d", &k);
    k--;
    printf("Enter l:\n");
    scanf_s("%d", &l);
    l--;

    // выделение памяти
    int** arr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) 
    {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[k][l] = 1;
            arr[i][j] = (abs(k - i) > abs(l - j) ? abs(k - i) + 1 : abs(l - j) + 1 );
        }
    }

    printf("Matrix:\n");

    for(int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    //очищаем память
    for (int i = 0; i < m; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0; 
}