#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <Windows.h>
#include <alloc.h>
#include <string.h>

//------------------- Дубровский Константин гр.953506 --------------------
//-------------------          Л.Р.№5 (вар.24)       ---------------------

// Структура, описывающая элемент двунаправленного списка:
typedef struct item
{
	int digit;
	struct item *next;
	struct item *prev;
} Item;

// Структура, описывающая многоразрядное число:
typedef struct mnumber
{
	Item *head;   // указатели на начало и конец динамического двунаправленного списка  /
	Item *tail;   //		  в котором будут храниться цифры числа
	int length;   // количество цифр в нем
} Number;

Number CreateNumber(char *str);
void AddDigit(Number *number, int digit);
void PrintNumber(Number number);
void FreeNumber (Number number);
int CompareNumbers(Number a, Number b); //return (a>b)? 1 : (a<b)? 2 : 0

Number LongSumLong(Number n1, Number n2);
Number LongSubLong(Number n1, Number n2);
Number LongMulLong(Number n1, Number n2);
Number LongDivLong(Number n1, Number n2);

#define DECLARATIONS(length) \
	char *nullstr = (char *)malloc((length)*sizeof(char));  \
	for(int i=0; i<length; i++) strcat(nullstr, "0");   \
	Number rezult = CreateNumber(nullstr);   \
    free(nullstr); \
	Item *a = n1.head, *b = n2.head, *c = rezult.head;

int _tmain()
{
	Number a = CreateNumber("849256718556");
	Number b = CreateNumber("422781521083");

	int k = CompareNumbers(a, b);

	printf("a = ");
	PrintNumber(a);
	printf("\n");
	printf("b = ");
	PrintNumber(b);
	printf("\n");

	printf("|a| + |b| = "); //a + b
	PrintNumber(LongSumLong(a, b)); // 1272038239639‬
	printf("\n");

	if(k == 2) // если b > a
	{
		printf("|b| - |a| = "); //b - a
		PrintNumber(LongSubLong(b, a));
	}
	else // если a > b или a = b
	{
		printf("|a| - |b| = "); //a - b
		PrintNumber(LongSubLong(a, b)); //‭426475197473‬
	}
	printf("\n");

	printf("|a| * |b| = "); //a * b
	PrintNumber(LongMulLong(a, b)); // 359050047261062911316148‬
	printf("\n");

	FreeNumber(a);
	FreeNumber(b);

	system("pause");
	return 0;
}

// Создает многоразрядное число из цифр строки
Number CreateNumber(char str[])
{
	Number number = {NULL, NULL, 0};
	int n;
	//значения из принимаемой строки копируются в двунаправленный список, начиная с конца:
	for (n = strlen(str)-1; n >= 0; n--) AddDigit(&number, str[n]-'0');
	return number;
}

// Добавляет цифру в многоразрядное число:
void AddDigit(Number *number, int digit)
{
	Item *p = (Item *)malloc(sizeof(Item));
	p->digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL) number->head = number->tail = p;
	else
	{
		number->tail->next = p;
		p->prev = number->tail;
		number->tail = p;
	}
	number->length++;
}

int CompareNumbers(Number n1, Number n2)  //return k = (a>b)? 1 : (a<b)? 2 : 0
{
	int k = 0;
	Item *a = n1.tail, *b = n2.tail;

	if (n1.length > n2.length)
	{
		k = 1;
	}
	else if (n2.length > n1.length)
	{
		k = 2;
	}
	else while(a && b)
	{
		if (a->digit > b->digit)
		{
			k = 1; // a > b
			break;
		}
		if(b->digit > a->digit)
		{
			k = 2; // b > a
			break;
		}
		a = a->prev;
		b = b->prev;
	}
	return k;
}

// Возвращает сумму двух многоразрядных чисел:
Number LongSumLong(Number n1, Number n2)
{
	int length = (n1.length > n2.length)? (n1.length + 1) : (n2.length + 1);
	DECLARATIONS(length)

	for (int i = 0; i < length-1; i++)
	{
		c->digit += b->digit + a->digit; // суммируем последние разряды чисел
		c->next->digit += c->digit / 10; // если есть разряд для переноса, переносим его в следующий разряд
		c->digit %= 10; // если есть разряд для переноса он отсекается

		a=a->next;
		b=b->next;
        c=c->next;
	}
	return rezult;
}

// Возвращает разность двух многоразрядных чисел:
Number LongSubLong(Number n1, Number n2)
{
	int length = n1.length;
	DECLARATIONS(length)

	for (int i = 0; i < (length); i++)
	{
		if (i < (length - 1)) // если текущий разряд чисел не первый
        {
			a->next->digit--; // в следующуем разряде большего числа занимаем 1.
			c->digit += 10 + a->digit; // в ответ записываем сумму значения текущего разряда большего числа и 10-ти

        } else  // если текущий разряд чисел - первый
				c->digit += a->digit; // в ответ суммируем значение текущего разряда большего числа

		c->digit -= b->digit; // вычитаем значение текущего разряда меньшего числа

		if (c->digit >= 10) // если значение разряда >= 10
		{
			c->next->digit++;
			c->digit %= 10;
		}
		a = a->next;
		b = b->next;
		c = c->next;
	}
	return rezult;
}

// Возвращает произведение двух многоразрядных чисел:
Number LongMulLong(Number n1, Number n2)
{
	int length = n1.length + n2.length +1;
	DECLARATIONS(length)

	for (int i = 0; i < n1.length; i++)
	{
		for (int j = 0; j < n2.length; j++)
		{
			c->digit += a->digit * b->digit;
			b = b->next;
			c = c->next;
		}
		c = rezult.head;
		for (int j = 0; j <= i; j++) c = c->next;
		a = a->next;
		b = n2.head;
	}
    c = rezult.head;
	for (int i = 0; i < length -1; i++)
	{
		c->next->digit +=  c->digit / 10;
		c->digit %= 10;
		c = c->next;
	}
    return rezult;
}

// Выводит многоразрядное число на экран
void PrintNumber(Number number)
{
	Item *p = number.tail;   //выводим число в обратном порядке

	while(p->digit == 0)
	{
		if(!p->prev)  //если вся строка состоит из 0
		{
			printf("0"); //просто написать 0
			return;
		}
		p = p->prev; //пропускаем нули в начале
	}
	while (p)
	{
		printf("%d", p->digit);
		p = p->prev;
	}
}

void FreeNumber (Number number)
{
	Item *p = number.tail;
    while (p)
	{
		free(p);
		p = p->prev;
	}
}

