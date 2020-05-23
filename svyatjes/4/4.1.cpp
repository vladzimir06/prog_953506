#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    const char* str[] = { "11", "+", "22", "/", "11","*","2" };

    int mainSize = sizeof(str) / sizeof(str[0]);
    int numberNumbers = mainSize / 2 + 1;
    int numberSymbols = mainSize / 2;
    int* arr_numbers = (int*)malloc(numberNumbers * sizeof(int));
    const char* str_symb[] = { "" };
    int size_symb = 0, size_num = 0;

    //инициализируем два массива символами и цифрами
    for (int i = 0; i < mainSize; i++)
    {
        if (strcmp(str[i], "*") == 0 || strcmp(str[i], "/") == 0 || strcmp(str[i], "+") == 0 || strcmp(str[i], "-") == 0)
        {
            str_symb[size_symb] = (char*)str[i];
            size_symb++;
        }
        else
        {
            const char* a = str[i];
            arr_numbers[size_num] = atoi(a);
            size_num++;
        }
    }

    // производим операции 
    for (int i = 0; i < size_symb; i++)
    {
        if (strcmp(str_symb[i], "*") == 0 || strcmp(str_symb[i], "/") == 0)
        {
            arr_numbers[i] = (strcmp(str_symb[i], "*") == 0) ? (arr_numbers[i] * arr_numbers[i + 1]) : (arr_numbers[i] / arr_numbers[i + 1]);

            //сдвигаем массив чисел влево на 1 
            for (int n = i + 1; n < size_num; n++)
            {
                if (n == size_num - 1)
                {
                    break;
                }
                arr_numbers[n] = arr_numbers[n + 1];

            }
            size_num--;

            //сдвигаем массив знаков влево на 1 
            for (int j = i; j < size_symb; j++)
            {
                if (j == size_symb - 1)
                {
                    break;
                }
                str_symb[j] = str_symb[j + 1];
            }
            size_symb--;
            i = 0;
            if (size_symb == 1)
            {
                arr_numbers[0] = (strcmp(str_symb[0], "*") == 0) ? (arr_numbers[0] * arr_numbers[1]) : (arr_numbers[0] / arr_numbers[1]);
            }
        }
    }

    for (int i = 0; i < size_symb; i++)
    {
        if (strcmp(str_symb[0], "+") == 0 || strcmp(str_symb[0], "-") == 0)
        {
            arr_numbers[i] = (strcmp(str_symb[i], "+") == 0) ? (arr_numbers[i] + arr_numbers[i + 1]) : (arr_numbers[i] - arr_numbers[i + 1]);

            //сдвигаем массив чисел влево на 1 
            for (int n = i + 1; n < size_num; n++)
            {
                if (n == size_num - 1)
                {
                    break;
                }
                arr_numbers[n] = arr_numbers[n + 1];
            }
            size_num--;

            //сдвигаем массив знаков влево на 1 
            for (int j = i; j < size_symb; j++)
            {
                if (j == size_symb - 1)
                {
                    break;
                }
                str_symb[j] = str_symb[j + 1];
            }
            size_symb--;
            i = 0;
            if (size_symb == 1)
            {
                arr_numbers[0] = (strcmp(str_symb[0], "+") == 0) ? (arr_numbers[0] + arr_numbers[1]) : (arr_numbers[0] - arr_numbers[1]);
            }
        }
    }
    printf("=%d", arr_numbers[0]);
    free(arr_numbers);
}