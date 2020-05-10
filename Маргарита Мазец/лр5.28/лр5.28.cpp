/*Разработать функцию, которая инвертирует заданный список, т.е.
первый элемент становится последним, второй – предпоследним и
т.д. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct item
{
	int data;
	struct item* next;
	struct item* prev;
}Item;
Item* head = NULL, * tail = NULL;

void Insert(int value);
void Delete(int value);
void Invert();
void Display();

void main()
{
	system("chcp 1251");
	system("cls");
	int number, data;
	while (true)
	{
		puts("\nВведите номер операции:");
		puts("1-добавить элемент");
		puts("2-удалить элемент");
		puts("3-инвентирировать");
		puts("4-изобразить");
		puts("5-выйти из программы");
		scanf_s("%d", &number);
		switch (number)
		{
		case 1: 
			puts("Введите элемент:");
			scanf_s("%d", &data);
			Insert(data);
			break;
		case 2:
			puts("Введите элемент:");
			scanf_s("%d", &data);
			Delete(data);
			break;
		case 3:
			Invert();
			break;
		case 4:
			Display();
			break;
		case 5:
			return;
		default:
			puts("Такого действия нет.\nПопробуй ещё раз");
			break;
		}
	}
}

void Insert(int value)
{
	Item* p, * cur = head;
	p = (Item*)malloc(sizeof(Item));
	p->data = value;
	p->next = p->prev = NULL;
	if (head == NULL)
	{
		head = p;
		tail = p;
		return;
	}
	while (cur != NULL && value > cur->data)
		cur = cur->next;
	if (cur == head)
	{
		p->next = head;
		head->prev = p;
		head = p;
	}
	if (cur == NULL)
	{
		tail->next = p;
		p->prev = tail;
		p->next = NULL;
		tail = p;
	}
	else
	{
		cur->prev->next = p;
		p->prev = cur->prev;
		cur->prev = p;
		p->next = cur;
	}
}

void Delete(int value)
{
	Item* p = head;
	
	while (p != NULL && p->data != value)
		p = p->next;
	if (p == NULL)
		return;
	if (p == head)
	{
		head = head->next;
		head->prev = NULL;
	}
	else if (p == tail)
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	free(p);
}

void Display()
{
	Item* p = head;
	if (p == NULL)
		puts("Список пуст!");
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
}

void Invert()
{
	Item* p, *temp;
	if (head == NULL)
		return;
	if (head->next == tail)
	{
		temp = head;
		head = tail;
		head->next = tail->prev;
		head->prev = NULL;
		tail =temp;
		tail->next = NULL;
		tail->prev = head;
	}
	//------------
	else
	{
		p = head->next;
		while (p != tail)
		{
			Item* temp1 = p->next;
			p->next = p->prev;
			p->prev = temp1;
			p = temp1;
		}
		temp = head;
		head = tail;
		head->next = tail->prev;
		head->prev = NULL;
		tail = temp;
		tail->next = NULL;
		tail->prev = temp->next;
	}
}

