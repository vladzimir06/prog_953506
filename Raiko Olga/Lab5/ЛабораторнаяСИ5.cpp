/*5.1 Разработать функцию, которая инвертирует заданную очередь, т.е.
первый элемент становится последним, второй – предпоследним и
т.д. */

#include <iostream>
#include <stdio.h>
#include <locale.h>
#define N 9
int main()
{
    setlocale(LC_ALL, "Rus");
    printf("Введите через пробел 9 чисел\n");
    int a[N], i, b;
    for (i = 0; i < N; i++) scanf_s("%d", &a[i]);// заполнеение и вывод массива
    for (i = 0; i < N / 2; i++) //отражение очереди 
    {
        b = a[i];
        a[i] = a[N - i - 1];
        a[N - i - 1] = b;
    }
    for (i = 0; i < N; i++) printf("%d ", a[i]);// заполнение нового массива 
	printf("\n");
	
	//memset(a, 0, sizeof (N));
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
