//Задание 5.1 (11) Карпенко И.В. 953506

/*Задана очередь, указывающая порядок обработки одного из n 
стеков. Элементы очереди содержат номер обрабатываемого стека i
(i <= n); признак выполняемого действия: ‘А’ – элемент из очереди 
добавляется в i-й стек, ‘D’ – из i-го стека удаляется элемент; данные 
(целые число d). Разработать функцию обработки стеков в 
соответствии с заданной очередью.  */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctime>

#define N 10

typedef struct stacknode
{
	int data;
	stacknode* prev;
	stacknode* next;
} StackNode, *StackPNode;

typedef struct 
{
	StackPNode Head, Tail;
} Stack;

void PushStack(Stack& S, int x)
{
	StackPNode NewNode;
	NewNode = (StackNode*)malloc(sizeof(StackNode));
	NewNode->data = x;
	NewNode->next = S.Head;
	NewNode->prev = nullptr;
	
	if(S.Head)  S.Head->prev = NewNode;
		S.Head = NewNode;
	
	if (!S.Tail) S.Tail = S.Head;

}

int PopStack(Stack& S)
{
	StackPNode TopNode = S.Head;
	if (!TopNode) return NULL;
	int x = TopNode->data;
	S.Head = TopNode->next;
	if (S.Head) S.Head->prev = nullptr;
	else S.Tail = nullptr;
	free(TopNode);
	return x;
}

/*------------------------------------------------------------------------------------------------------------*/
typedef struct queueNode
{
	int num;
	char operation;
	queueNode* prev;
	queueNode* next;
} QueueNode, *QueuePNode;

typedef struct 
{
	QueuePNode Head, Tail;
} Queue;

void PushTail(Queue& Q, int x, char a)
{
	QueuePNode NewNode;
	NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->prev = Q.Tail;
	NewNode->next = nullptr;
	NewNode->num = x;
	NewNode->operation = a;

	if (Q.Tail) Q.Tail->next = NewNode;
	Q.Tail = NewNode;
	if (!Q.Head) Q.Head = Q.Tail;

}

int PopQueue(Queue& Q, int& x, char& a)
{
	QueuePNode TopNode = Q.Head;
	if (!TopNode) return NULL;

	x = TopNode->num;
	a = TopNode->operation;
	Q.Head = TopNode->next;
	if (Q.Head) Q.Head->prev = nullptr;
	else Q.Tail = nullptr;
	free(TopNode);
	return 1;
}
/*---------------------------------------------------------------------------------------------------------*/

void Processing(Queue& Q, Stack* S)
{
	int num;	
	char operation;
	srand(time(NULL));
	while (PopQueue(Q, num, operation))
	{
		if (operation == 'A')
		{
			int data;
			PushStack(S[num], data = rand());
			printf("Added value %d to stack number %d\n", data, num + 1);
		}
		else
		{
			int data = PopStack(S[num]);
			if(data == NULL) printf("Stack number %d is empty\n", num + 1);
			else printf("Value %d removed from stack number %d\n", data , num + 1);
		}
	}
}

void GetStack(Stack* S)
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		int data = PopStack(S[i]);
		if (data == NULL) printf("Stack number %d is empty", i + 1);
		else printf("Numbers from stack number %d:", i + 1);
		while (data != NULL)
		{			
			printf(" %d", data);
			data = PopStack(S[i]);
		}
		printf("\n");
	}
}
/*---------------------------------------------------------------------------------------------------------*/
int main()
{
	Queue Q{nullptr, nullptr};
	Stack S[N];
	for (int i = 0; i < N; i++)
	{
		S[i].Head = nullptr;
		S[i].Tail = nullptr;
	}
	srand(time(NULL));
	int QLength = rand() % 100 + 1;
	printf("Queue length is %d\n\n", QLength);
	for(int i = 0; i < QLength; i++)
	{
		int op = rand() % 2;
		if (op) PushTail(Q, rand() % N, 'A');
		else PushTail(Q, rand() % N, 'D');
	}
	Processing(Q, S);
	GetStack(S);
   
}


