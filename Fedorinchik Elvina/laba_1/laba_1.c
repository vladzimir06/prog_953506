// laba #1 c
// elvina fedorinchik, 953506
// дано натуральное число n, вычислить функцию 

#include <stdio.h>

int fact(int n)                                //рекурсивная функция факториала
{
    if (n == 0) return 1;
    else return n * fact(n - 1);
}

int main()
{
    int n;
    do {                                        //проверка на отрицательное значение n
        printf("Enter  n:\n");
        scanf_s("%d", &n);
    } while (n <= 0);

    printf("\nn = %d", n);
    double sum = 0;
    double multi = 1;

    for (int i = 1; i <= n; i++)                //считаем сумму
    {

        printf("\ns = %f", sum);
        multi = 1;
        for (int j = 1; j <= i; j++)            //считаем произведение
            multi *= fact(j + i) / fact(i);
        printf("\np = %f", multi);
    }
    sum += multi;


    printf("\ns = %f", sum);
    return 0;
}