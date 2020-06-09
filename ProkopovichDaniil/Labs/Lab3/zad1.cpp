#include <stdafx.h>
#include <cstdlib.h>
#include <stdio.h>

using namespace std;

const int max_n = 21;
int lab[max_n][max_n] = { 0 };
int n, i;  

struct queue
{
	int qu[100];
	int rear, front;
};

void Init(struct queue *q)
{
	q -> front = 1;
	q -> rear = 0;
	return;
}

void Push(struct queue *q, int x)
{
	if(q -> rear < 99)
	{
		q -> rear++;
		q -> qu[q -> rear] = x;
	}
	else
		printf("The queue is full!");
	return;
}

int IsEmpty(struct queue *q)
{
	if(q -> rear < q -> front)
		return 1;
	else
		return 0;
}

int Pop(struct queue *q) 
{
  int x, h;
  if(isempty(q)==1) 
  {
    printf("Очередь пуста!\n");
    return 0;
  }
  x = q -> qu[q -> frnt];
  for(h = q -> frnt; h < q -> rear; h++) 
  {
    q -> qu[h] = q -> qu[h+1];
  }
  q -> rear--;
  return x;
}

int Take(struct queue *q)
{
	return qu[rear - 1];
}

void Solution(int x, int y);


int main(int argc, _TCHAR* argv[])
{               
	int x, y;                             
	puts("Enter the labyrinth size! (less than 20 20) : ");
	scanf("%d", &n);
	if (n < max_n)
	{
		puts("Enter your coordinates!\n");
		scanf("%d", &x);
		scanf("%d", &y);
		for (int row = 0; row < n; ++row)               // Создаем лабиринт из 0 и 1
		{
			for (int col = 0; col < n; ++col)
			{
				lab[row][col] = rand() % 2;
				lab[x][y] = 8;                   		        // Местоположение человека		
			}
		}

		Solution(x, y);
	
		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < n; ++col)
				printf("%d", lab[row][col];
			puts("\n");
		}
	
		system("pause");
		return 0;
	}

	else
	{
		puts("The labyrinth is too big!\n");
		system("pause");
	}
}

void Solution(int x, int y)
{
	struct queue myQueue = (struct queue*)(malloc(sizeof(struct queue)));
	do
	{
		i++;
		Push(myQueue, lab[x - 1][y]);
		Push(myQueue, lab[x + 1][y]);
		Push(myQueue, lab[x][y - 1]);
		Push(myQueue, lab[x][y + 1]);
		if (Take(myQueue) == 0)
		{
			Take(myQueue) = 8;
		}
		else
		{
			Pop(myQueue);
		}
	} while (Take(myQueue) == 0);
}
