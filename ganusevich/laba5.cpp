#include <stdio.h>
#include <stdlib.h>

struct Steckk
{
	struct St* head;
};
struct St
{
	int data;
	struct St* next;
};

void Puch(St** st, int value);
void Delete(St** st);
void Display(St** st);
void Copy(St** st1, St** st2);

int main()
{
	Steckk top1, top2;
	top1.head = NULL;
	top2.head = NULL;
	int mass1[]{ 2, 3, 4, 1, 65, 12, 69 };
	int mass2[]{ 6, 3, 1, 777,  0, -1, 1337 };
	for (int i = 0; i < 7; i++)
	{
		Puch(&top1.head, mass1[i]);
		Puch(&top2.head, mass2[i]);
	}
	Display(&top1.head);
	Display(&top2.head);
	Copy(&top1.head, &top2.head);
	while (top2.head)
	{
		Delete(&top2.head);
	}
	Display(&top1.head);
	while (top1.head)
	{
		Delete(&top1.head);
	}
}

void Puch(St** st, int value)
{
	St* p = (St*)malloc(sizeof(St));
	p->data = value;
	p->next = *st;
	*st = p;
}

void Delete(St** st)
{
	if (*st != NULL) 
	{
		St* p = *st;
		*st = (**st).next;
		free(p);
	}
}

void Display(St** st)
{
	St* p = *st;	
	if (p == NULL)
		printf("stack is empty");
	else
		printf("stack: ");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void Copy(St** st1, St** st2)
{
	St* p1 = *st1;
	St* p2 = *st2;
	while (*st1!=NULL)
	{
		Delete(st1);
	}
	if ((**st2).next != NULL) 
	{
		p2 = p2->next;
		Copy(st1, &p2);
	}
	Puch(st1, (*st2)->data);
}