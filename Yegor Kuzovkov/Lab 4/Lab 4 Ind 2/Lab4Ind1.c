#define STACK_MAX_SIZE 1000
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct stack
{
    int elem[STACK_MAX_SIZE];
    int top;
};

void init(struct stack *stk)
{
    stk -> top = 0;
}

void Push(struct stack *stk, int value)
{
    if(stk -> top < STACK_MAX_SIZE)
    {
        stk -> elem[stk -> top] = value;
        stk -> top++;
    }
    else
        printf("The stack is full, the number of elements is: %d !\n", stk -> top);
}

int Pop(struct stack *stk)
{
    int elem;
    if((stk -> top) > 0)
    {
        stk -> top--;
        elem = stk -> elem[stk -> top];
        return elem;
    }
    else
    {
        printf("The stack is empty!\n");
        return 0;
    }
}

int GetTop(struct stack *stk)
{
    if((stk -> top) > 0)
    {
        return stk -> elem[stk -> top - 1];
    }
    else
    {
        printf("The stack is empty!\n");
        return 0;
    }
}

int IsEmpty(struct stack *stk)
{
    if(stk -> top == 0)
        return 1;
    else
        return 0;
}

int main()
{
    char text[200];
    int amount_open = 0, amount_closed = 0;

    FILE *fp;
    fp = fopen("C:\\Users\\George_PC\\Desktop\\Labs\\sem 2\\Programmirovanie\\Lab4\\Lab4 Ind 2\\words.txt", "r");
    if (fp == NULL) printf ("Error.\n");
    else
    {
        fgets(text, 200, fp);
    }

    struct stack *hooks, *positions;
    hooks = (struct stack*)malloc(sizeof(struct stack));
    positions = (struct stack*)malloc(sizeof(struct stack));
    init(hooks);
    init(positions);


    for(int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '{' || text[i] == '(' || text[i] == '[')
        {
            Push(hooks, text[i]);
            Push(positions, i);
        }

        if (text[i] == '}')
        {
            if(GetTop(hooks) == '{')
                continue;
            else
            {
                text[GetTop(positions)] = '{';
                Pop(hooks);
                Pop(positions);
            }
        }

        if(text[i] == ')')
        {
            if(GetTop(hooks) == '(')
                continue;
            else if (GetTop(hooks) == '{' || GetTop(hooks) == '[')
            {
                text[GetTop(positions)] = '(';
                Pop(hooks);
                Pop(positions);
            }
            else
                continue;
        }

        if(text[i] == ']')
        {
            if(GetTop(hooks) == '[')
                continue;
            else
            {
                text[GetTop(positions)] = '[';
                Pop(hooks);
                Pop(positions);
            }
        }
    }
    free(hooks);
    free(positions);

    printf("\n");
    printf("%s\n", text);


    fclose(fp);
    getch();
    return 0;
}
