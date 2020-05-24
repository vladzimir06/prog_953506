/*Разработать рекурсивную функцию бинарного поиска заданного
элемента в целочисленном массиве.*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//функция сравнения для сортировки
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int FindNumber(int* array, int find, int left, int right) //бинарный поиск числа
{
    if (left <= right && left >= 0)
    {
        int pos = (right + left) / 2;
        if (find == array[pos]) return pos;
        else if (find < array[pos])
        {
            right = pos - 1;
            pos = (right + left) / 2;
            return FindNumber(array, find, left, right);
        }
        else
        {
            left = pos + 1;
            pos = (right + left) / 2;
            return FindNumber(array, find, left, right);
        }
    }
    else return 0;
}

int main()
{
    int i = 0, n = 0, find = 0;
    printf("Input array size: ");
    scanf_s("%d", &n);

    int *array = (int*)malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf_s("%d", &array[i]);
    }
    
    printf("Input find number ");
    scanf_s("%d", &find);
    qsort(array, n, sizeof(int), compare );
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d ",i, array[i]);
    }
    if (find == array[0]) printf("\nNumber find %d on posotion 0", find);
    else
    {
        i = FindNumber(array, find, 0, n );
        if (i != 0) printf("\nNumber find %d on position %d", array[i], i);
        else printf("\nNumber not find");
    }
    return 0;
    free(array);
}