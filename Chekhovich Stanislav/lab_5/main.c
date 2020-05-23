//Задание 5.1 Вариант 5
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define ERROR -100
#define QMAX 11
#define WRONG_INPUT -101

typedef struct queue
{
    int data[QMAX];
    int last, first;
} Queue;

typedef struct stk
{
    Queue *q;
    struct stk *next;
} Stk;

typedef struct stk2
{
    int number;
    struct stk2 *next;
} Stk2;

void initialize(Queue *q);
void insert(Queue *q, int x);
int isempty(Queue *q);
void randomfill(Queue *q);
void print(struct queue *q);
void push(Stk **head, Queue **q);
void push2(Stk2 **head, int x);
Stk* pop(Stk **head);
Stk2* pop2(Stk2 **head);
void findmaxvalq(const Stk* head);
void findmaxsumq(const Stk* head);

int main()
{
    Stk *head = NULL;
    Stk2 *head2 = NULL;
    int n;
    printf("How many queues are in the stack? ( > 0, <= 10)\n");
    scanf("%d", &n);
    if(n < 0 || n > 10)
    {
        exit(WRONG_INPUT);
    }
    Queue **queue = (Queue**)malloc(n * sizeof (Queue*));
    for(int i = 0; i < n; i++)
    {
        srand(i+1);
        queue[i] = (Queue*)malloc(QMAX * sizeof (Queue));
        initialize(queue[i]);
        randomfill(queue[i]);
        printf("%d queue : ", i + 1);
        print(queue[i]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        push(&head, &queue[i]);
    }
    findmaxvalq(head);
    findmaxsumq(head);
    while (head)
    {
        for(int i = 1; i < QMAX; i++)
        {
            push2(&head2, head->q->data[i]);
        }
        head = head->next;
    }
    printf("All numbers in new stack :");
    while(head2)
    {
        printf(" %d ", pop2(&head2)->number);
    }
    getch();
    for(int i = 0; i < n; i++)
    {
        free(queue[i]);
    }
    free(queue);
    Stk* temp;
    while(head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}

void push(Stk **head, Queue **q)
{
    Stk *tmp = malloc(sizeof(Stk));
    if (tmp != NULL)
    {
        tmp->next = *head;
        tmp->q = *q;
        *head = tmp;
    }
}

void push2(Stk2 **head, int x)
{
    Stk2 *tmp = malloc(sizeof(Stk2));
    if (tmp != NULL)
    {
        tmp->next = *head;
        tmp->number = x;
        *head = tmp;
    }
}

Stk* pop(Stk **head)
{
    Stk *out;
    if ((*head) == NULL)
    {
        exit(ERROR);
    }
    out = *head;
    *head = (*head)->next;
    return out;
}

Stk2* pop2(Stk2 **head)
{
    Stk2 *out;
    if ((*head) == NULL)
    {
        exit(ERROR);
    }
    out = *head;
    *head = (*head)->next;
    return out;
}

void initialize(struct queue *q)
{
  q->first = 1;
  q->last = 0;
}

void insert(Queue *q, int x)
{
  if(q->last < QMAX - 1)
  {
    q->last++;
    q->data[q->last]=x;
  }
  else
  {
    printf("Queue is overfilled");
  }
}

int isempty(Queue *q)
{
   return (q->last < q->first) ? 1 : 0;
}

void randomfill(Queue *q)
{
    for(int i = 0; i < QMAX - 1; i++)
    {
        int r = rand() % 20;
        insert(q, r);
    }
}

void print(Queue *q)
{
  if(isempty(q) == 1)
  {
    printf("Queue is empty!\n");
    return;
  }
  for(int i = q->first; i <= q->last; i++)
  {
    printf("%d ",q->data[i]);
  }
  return;
}

void findmaxvalq(const Stk* head)
{
    int max_value_index = 0;
    int max_value = 0;
    int i = 0;
    const Stk *tmp = head;
    while (head)
    {
        for(int j = head->q->first; j <= head->q->last; j++)
        {
            if(head->q->data[j] > max_value)
            {
                max_value = head->q->data[j];
                max_value_index = i;
            }
        }
        head = head->next;
        i++;
    }
    head = tmp;
    i = 0;
    while (head)
    {
        if(i == max_value_index)
        {
            printf("This queue has the biggest number : ");
            print(head->q);
            printf("\n");
            break;
        }
        head = head->next;
        i++;
    }
}

void findmaxsumq(const Stk* head)
{
    int max_sum_index = 0;
    int max_sum = 0;
    int i = 0;
    const Stk *tmp = head;
    while (head)
    {
        int sum = 0;
        for(int j = head->q->first; j <= head->q->last; j++)
        {
            sum += head->q->data[j];
        }
        if(sum > max_sum)
        {
            max_sum = sum;
            max_sum_index = i;
        }
        head = head->next;
        i++;
    }
    head = tmp;
    i = 0;
    while (head)
    {
        if(i == max_sum_index)
        {
            printf("This queue has the biggest sum of numbers : ");
            print(head->q);
            printf("\n");
            break;
        }
        head = head->next;
        i++;
    }
}
