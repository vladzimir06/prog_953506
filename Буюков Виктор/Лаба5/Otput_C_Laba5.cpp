//Вариант 25 Разработать функцию, которая инвертирует заданный стек, т.е. первый элемент становится последним, второй – предпоследним и т.д. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define FALSE 0;
#define TRUE 1;

typedef struct item
{
    int position;
    int data;
    struct item* next;
}Item;

int Push(int numeric);
int Pop(int numeric);
void Display();
void Change(int numeric);

Item* top = NULL;

int main()
{
    int done = FALSE;
    int numeric = 0;
    char choice;

    while (!done)
    {
        Display();
        printf("\n\n A-Add \nD-Delete \nC-Change \nQ-Quit");
        choice = _getch();

        switch (toupper(choice))
        {
        case 'A':numeric = Push(numeric); break;
        case 'D':numeric = Pop(numeric); break;
        case 'C':Change(numeric); break;
        case 'Q': {while (numeric != 0) numeric = Pop(numeric); Display(); done = TRUE;} break;
        }
    }

    return 0;
}

int Push(int numeric)
{
    Item* p;

    p = (Item*)malloc(sizeof(Item));
    p->data = rand();
    p->position = ++numeric;
    p->next = top;
    top = p;

    return numeric;
}

int Pop(int numeric)
{
    Item* p;

    if (top != NULL)
    {
        p = top;
        top = top->next;
        free(p);
        --numeric;

        return numeric;
    }

    return numeric;
}


void Display()
{
    Item* p = top;

    system("cls");

    if (p == NULL) printf("Stack is empty");
    else
    {
        printf("Stack:");
        while (p != NULL)
        {
            printf("\n(%d) -> %d", p->position, p->data);
            p = p->next;
        }
    }
}

void Change(int numeric)
{
    int element_for_change1 = 0, element_for_change2 = 0, condition = (numeric + 1) / 2, const elements_of_stack = numeric;
    bool exit = false;

    for (int n = 0;n < condition;n++)
    {
        exit = false;
        Item* p = top;
        if (p == NULL) { printf("Stack is empty"); }
        else
        {
            while (exit == false)
            {
                if (numeric + 1 == p->position) p->data = element_for_change2;
                if (numeric == p->position) element_for_change1 = p->data;
                if (numeric + p->position == elements_of_stack + 1)
                {
                    element_for_change2 = p->data;
                    p->data = element_for_change1;

                    exit = true;
                    --numeric;

                    if ((n == condition - 1) && (elements_of_stack % 2 == 0))
                    {
                        Item* p = top;
                        while (numeric + 1 != p->position) p = p->next;

                        p->data = element_for_change2;
                    }
                }

                p = p->next;
            }
        }
    }
    numeric = elements_of_stack;
}