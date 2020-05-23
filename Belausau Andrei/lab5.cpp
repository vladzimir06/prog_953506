/*
    Вариант 25
    Разработать функцию, которая инвертирует заданный стек, т.е.
первый элемент становится последним, второй – предпоследним и
т.д. 
*/

#include <stdio.h>
#include <malloc.h>
#include <time.h>

typedef int T;

typedef struct
{
    T value;
    struct Node *next;
} Node;

void push(Node **head, T value)
{
    Node* tmp = malloc(sizeof(Node));
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}

T pop(Node **head)
{
    if (*head)
    {
        T out = (*head)->value;
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return out;
    }
    return 0;
}

void show(Node *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    puts("");
}

T peek(Node *head)
{
    if(head) return head->value;
}

size_t getSize(Node *head)
{
    size_t size = 0;
    
    while (head)
    {
        size++;
        head = head->next;
    }
    return size;
}

void reverse(Node **head)
{
    if (!(*head)->next) return;

    Node *tmpPrev = (*head);
    Node *current = tmpPrev;
    Node *tmpNext = current->next;
    current->next = NULL;

    while (tmpNext)
    {
        tmpPrev = current;
        current = tmpNext;
        tmpNext = tmpNext->next;
        current->next = tmpPrev;
    }

    *head = current;
}

void deleteStack(Node **root)
{
    while (*root)
    {
        pop(root);
    }
}

int main() {
    int Size;
    const int N = 10;
    Node *head = NULL;

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        push(&head, rand() % 10);
    }
    puts("default :");
    show(head);
    
    reverse(&head);
    puts("\nreversed :");
    show(head);

    deleteStack(&head);
    return 0;
}