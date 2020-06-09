// Задание 5.1(21) Стельмашук В.А.(гр. №953506)

/*Создать тип данных Многоразрядное число.Разработать следующие
функции :
· Equal() – сравнение двух многоразрядных чисел(возвращает 0,
если числа равны, 1 – если первое число больше, -1 – если второе
число больше);
· LongModShort() – возвращает остаток от деления
многоразрядного числа на короткое число типа int;
· LongDivShort() – возвращает результат целочисленного деления
многоразрядного числа на короткое число типа int;
· LongMulShort() – возвращает результат умножения
многоразрядного числа на короткое число типа int.
Для хранения многоразрядного числа использовать динамический
двунаправленный список.*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <iostream>

/* Структура, описывающая элемент двунаправленного списка */
typedef struct item
{
    int digit;          
    struct item* next,* prev;   //указатель на сдедующий и предыдущий элемент
} Item;

/* Структура, описывающая многоразрядное число */
typedef struct mnumber
{
    Item* head, * tail;     //голова,хвост
    int n;
} MNumber;

MNumber CreateMNumber(char* initStr);
void AddDigit(MNumber* number, int digit);
void PrintMNumber(MNumber number); 
MNumber LongDivShort(MNumber n1, int del);
MNumber LongModShort(MNumber n1, int del);
int Equal(MNumber p1, MNumber p2);
MNumber LongMulShort(MNumber n1, int x);
void Remove(MNumber number);

int main()
{
    setlocale(LC_ALL, "Russian");
    char n1[1000];
    char n2[1000];
    int n3;
    printf("Введите первое многорозрядное число!(Long(1))\n");
    gets_s(n1);
    MNumber a = CreateMNumber(n1);
    printf("Введите второе многорозрядное число!(Long(2))\n");
    gets_s(n2);
    MNumber b = CreateMNumber(n2);
    printf("Введите число типа int!(short)\n");
    scanf_s("%d", &n3);
    printf("Результат сравнения = %d.\n", Equal(a, b));
    MNumber c = LongDivShort(a, n3);
    printf("LongDivShort = ");
    PrintMNumber(c);
    Remove(c);
    MNumber c1 = LongModShort(a, n3);
    printf("LongModShort = ");
    PrintMNumber(c1);
    Remove(c);
    printf("Long(1)MulShort = ");
    MNumber d1 = LongMulShort(a, n3);
    PrintMNumber(d1);
    Remove(d1);
    printf("Long(2)MulShort = ");
    MNumber d2 = LongMulShort(b, n3);
    PrintMNumber(d2);
    Remove(d2);
    Remove(a);
    Remove(b);
}

MNumber CreateMNumber(char initStr[])//создает многоразрядное число из цифр строки
{
    MNumber number = { NULL, NULL, 0 };
    int n;
    for (n = strlen(initStr) - 1; n >= 0; n--)
        AddDigit(&number, initStr[n] - '0');
    return number;
}

void AddDigit(MNumber* number, int digit)//добавляет цифру в многоразрядное число
{
    Item* p = (Item*)malloc(sizeof(Item));
    p->digit = digit;
    p->next = p->prev = NULL;
    if (number->head == NULL)
        number->head = number->tail = p;
    else
    {
        number->tail->next = p;
        p->prev = number->tail;
        number->tail = p;
    }
    number->n++;
}

int Equal(MNumber p1, MNumber p2)//сравнение двух многоразрядных чисел(0 - числа равны, 1 – первое число больше, -1 – второе число больше)
{
    int x1 = 0, x2 = 0;
    Item* P1 = p1.head;
    Item* P2 = p2.head;
    while (P1)
    {
        x1++;
        P1 = P1->next;
    }
    while (P2)
    {
        x2++;
        P2 = P2->next;
    }
    if (x1 > x2) return 1;
    if (x1 < x2) return -1;
    if (x1 = x2)
    {
        P1 = p1.head;
        P2 = p2.head;
        while (P1 && P2)
        {
            x1 = P1->digit;
            x2 = P2->digit;
            if (x1 > x2) return 1;
            if (x1 < x2) return -1;
            P1 = P1->next;
            P2 = P2->next;
        }
        return 0;
    }

}

MNumber LongModShort(MNumber n1, int del)//возвращает остаток от деления многоразрядного числа на короткое число типа int
{
    char a[2] = "";
    MNumber mod = CreateMNumber(a);
    Item* p1 = n1.tail;
    int digit, s1 = 0;
    while (p1)
    {
        if (p1) { s1 += p1->digit; p1 = p1->prev; }
        digit = s1 / del;
        s1 = (s1 % del) * 10;
    }
    AddDigit(&mod, s1 / 10);
    return mod;
}
MNumber LongDivShort(MNumber n1, int del)//возвращает результат целочисленного деления многоразрядного числа на короткое число типа int
{
    char a[2] = "";
    MNumber div = CreateMNumber(a);
    Item* p1 = n1.tail;
    int digit, s1 = 0;
    while (p1)
    {
        if (p1) { s1 += p1->digit; p1 = p1->prev; }
        digit = s1 / del;
        AddDigit(&div, digit);
        s1 = (s1 % del) * 10;
    }
    return div;
}

MNumber LongMulShort(MNumber n1, int x)//возвращает результат умножения многоразрядного числа на короткое число типа int.
{
    char a[2] = "";
    MNumber mul = CreateMNumber(a);
    Item* p1 = n1.head;
    int s1, digit = 0, pos = 0;
    int mod = 0;
    mod = x % 10;
    x /= 10;
    if (mod != 0)
    {
        while (p1)
        {
            if (p1) { s1 = p1->digit; p1 = p1->next; }
            digit = (s1 * mod + pos) % 10;
            pos = (s1 * mod + pos) / 10;
            AddDigit(&mul, digit);
        }
        if (pos) AddDigit(&mul, pos);
        LongMulShort(mul, mod);
    }
    return mul;
}

void PrintMNumber(MNumber number)// выводит многоразрядное число на экран
{
    Item* p = number.head;
    while (p)
    {
        printf("%d", p->digit);
        p = p->next;
    }
    printf("\n");
}
void Remove(MNumber number)//удаляет структуру
{
    Item* temp;
    while (number.head)
    {
        temp = number.head;
        number.head = number.head->next;
        free(temp);
    }
    free(number.head);
}