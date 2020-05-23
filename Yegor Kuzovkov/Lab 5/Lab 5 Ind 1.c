/* Кузовков Егор, группа 953506.
   Лабораторная №5, вариант 2.
   
   Разработать функцию разложения многоразрядного числа на простые множители. 
   Для хранения многоразрядного числа использовать динамический двунаправленный список.

   Основные функции работы с такими числами были написаны в методичке, по-моему, они очевидные. Работаем, как с массивом и двигаем указатели,
   не забывая про переполнение разряда или, наоборот, нехватку.
   Использовал стандартный алгоритм факторизации числа, работает за квадрат. Пришлось добавить функции деления, получения остатка и сравнения.
   Я их подробно раскомментил, как и сам алгоритм.
 */

#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <malloc.h>

// Накидал дефайнов для удобства работы с bool, последний стандарт Си использовать не додумался. ¯\_(ツ)_/¯ 
#define true 1
#define false 0
#define bool int

// Структура, описывающая элемент двунаправленного списка. 
typedef struct item
{
    int digit;
    struct item *next;
    struct item *prev;
} Item;

// Структура, описывающая многоразрядное число. 
typedef struct number
{
    Item *head;
    Item *tail;
    int size;
} Number;


// Добавляет цифру в многоразрядное число. 
void AddDigit(Number *number, int digit)
{
	//Выделяем память под циферку. Оба указателя пока пустые.
    Item *p = (Item *)malloc(sizeof(Item));
    p -> digit = digit;
    p -> next = p -> prev = NULL;

    //Если число изначальное пустое, инициализируем первый же указатель.
    if (number -> head == NULL)
    {
        number -> head = number -> tail = p;
    }

	//Если нет, вставляем нашу цифру, двигая указатели.
    else
    {
        number -> tail -> next = p;
        p -> prev = number -> tail;
        number -> tail = p;
    }
	//Увеличиваем количество разрядов.
    number -> size++;
}

// Создает многоразрядное число из цифр строки. 
Number CreateMNumber(char initStr[])
{
	//Создаем пустое число.
    Number number = {NULL, NULL, 0};
    int n;
	
	//Пока строка не закончится, закидываем в число по цифре через вышеописанную функцию.
    for (n = strlen(initStr)-1; n >= 0; n--)
    {
        AddDigit(&number, initStr[n]-'0');
    }

    return number;
}

// Возвращает сумму двух многоразрядных чисел. 
Number SumMNumber(Number n1, Number n2)
{
    Number sum = CreateMNumber("");
    Item *p1 = n1.head, *p2 = n2.head;
    int digit, pos = 0, s1, s2;

    while (p1 || p2)
    {
        if (p1)
        {
            s1 = p1->digit;
            p1 = p1->next;
        }

        else s1 = 0;

        if (p2)
        {
            s2 = p2->digit;
            p2 = p2->next;
        }

        else s2 = 0;

        digit = (s1 + s2 + pos) % 10;
        pos = (s1 + s2 + pos) / 10;
        AddDigit(&sum, digit);
    }

    if (pos) AddDigit(&sum, pos);

    free(p1);
    free(p2);
    return sum;
}

// Возвращает разность двух многоразрядных чисел. 
Number RaznMNumber(Number n1, Number n2)
{
    Number razn = CreateMNumber("");
    Item *p1 = n1.head, *p2 = n2.head;
    int digit = 0, pos = 0, s1 = 0, s2 = 0;

    while (p1 || p2)
    {
        if (p1)
        {
            if((s1 - s2) >= 0) s1 = p1->digit;
            else s1 = p1->digit - 1;
            p1 = p1->next;
        }
        else s1 = 0;

        if (p2)
        {
            s2 = p2->digit;
            p2 = p2->next;
        }
        else s2 = 0;

        if ((s1 - s2) >= 0) digit = (s1 - s2 + pos) % 10;
        else digit = (10 + s1 - s2 + pos) % 10;

        pos = (s1 + s2 + pos) / 10;
        AddDigit(&razn, digit);
    }

    if (pos) AddDigit(&razn, pos);

    free(p1);
    free(p2);
    return razn;
}

// Сравнивает два многоразрядных числа. 
bool Check(Number first, Number second)
{
    if(first.size > second.size)
    {
        return true;
    }

    else if (first.size < second.size)
    {
        return false;
    }
    else
    {
		Item *one = first.tail, *two = second.tail;
		while(one || two)
		{
			if(one -> digit > two -> digit)
				return true;
			
			else if(one -> digit == two -> digit)
			{
				one = one -> next;
				two = two -> next;
			}
			
			else 
				return false
		}
    }
}

//Возвращает частное от деления двух многоразрядных чисел.
Number DivideNumber(Number n1, Number n2)
{
	//Использовал деление вычитанием, наше частное - число шагов деления. Массив создал, чтобы потом создать строку и вернуть уже число на ее основе. 
    int count = 0;
	char buffer[33];
	
	//Пока разность больше нуля, отнимаем. 
	Number temp = n1; 
	while(Check(temp, n2))
	{
		temp = RaznMNumber(temp, n2);
		count++;
	}
	//Наш ответ - число шагов такого деления.
	Number result = CreateMNumber(itoa(count, buffer, 10));
	return result;
}

//Возвращает остаток от деления двух чисел.
Number GetRemains(Number n1, number n2)
{
	//При делении вычитанием то, что получилось в конце, и будет являться остатком, нужно только проверить его на корректность. 
	Number result = DivideNumber(n1, n2);
	if(result -> digit >= 0)
		return result;
	else
		return CreateMNumber("0");
}

//Выводит число.
void PrintMNumber(Number number)
{
	//Просто выводим каждую цифру с конца, проверяя каждый указатель на корректность. 
    Item *p = number.tail, *temp = number.tail;
    printf("\nNumber: ");

    while (p)
    {
        if((temp->digit == 0) && (p->prev != NULL))
        {
            temp = temp->prev;
            p = p->prev;
        }
        else
        {
            printf("%d", p->digit);
            p = p->prev;
        }
    }

    free(p);
}

void DeleteMNumber(Number number)
{
	Item *p = number.tail;
	while(p)
	{
		p = p -> prev;
		free(p -> next);
	}
	free(p);
}



int main()
{
	//Создаем 3 числа, value - само число, divisor - делитель для цикла, increment - для удобства увеличения числа на 1.
	char[20] input;
	gets_s(input);
    Number value = CreateMNumber(input);
    Number divisor = CreateMNumber("1");
    Number increment = CreateMNumber("1");

	//Пока число больше 1.
   while(Check(value, increment))
   {
	   //Пока число делится нацело. 
	   while(GetRemains(value,divisor))
	   {
		   //В этом случае делитель как раз является множителем, его выводим, потом для продолжения делим число на него.
		   PrintMNumber(divisor);
		   value = DivideNumber(value, divisor);
	   }
	   //Инкремент делителя.
	   divisor = SumMNumber(divisor, increment);
   }
   
	DeleteMNumber(value);
	DeleteMNumber(divisor);
	DeleteMNumber(increment);
   return 0;
}
