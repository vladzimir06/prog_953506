#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

void size(int*, int*);
int** sozdanie(int**, int*, int*);
int** zapolnenie1(int**, int*, int*);
void vivod(int**, int*, int*);
int** deleterow1(int**, int*, int*);
int** deleterow2(int**, int*, int*);
int** deletecolumn(int**, int*, int*);
void deletearr(int**, int*, int*);

int main()
{
	setlocale(LC_ALL, "Rus");

	int n = 0, m = 0;
	int** A = 0;

	// задаём размер массива
	size(&n, &m);

	//выделяем память
	A = sozdanie(A, &n, &m);

	//инициализируем
	A = zapolnenie1(A, &n, &m);

	vivod(A, &n, &m);

	//удаляем строки сверху-вниз
	A = deleterow1(A, &n, &m);

	//удаляем строки снизу-вверх
	A = deleterow2(A, &n, &m);

	//удаляем столбцы
	A = deletecolumn(A, &n, &m);

	vivod(A, &n, &m);

	//удаляем память под массив
	deletearr(A, &n, &m);
}

void size(int* n, int* m)
{
	printf("Введите кол-во строк в массиве: ");
	scanf_s("%d", n);
	printf("Введите кол-во столбцов в массиве: ");
	scanf_s("%d", m);
	printf("\n");
}

int** sozdanie(int** A, int* n, int* m)
{
	A = (int**)malloc(*n * sizeof(int*));
	for (int i = 0; i < *n; i++)
	{
		A[i] = (int*)malloc(*m * sizeof(int*));
	}
	return A;
}

int** zapolnenie1(int** A, int* n, int* m)
{
	printf("Введите элементы матрицы:\n");
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *m; j++)
		{
			printf("A[%d][%d]= ", i, j);
			scanf_s("%d", &A[i][j]);
			printf("\n");
		}
	}
	return A;
}

void vivod(int** A, int* n, int* m)
{
	printf("\n");
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *m; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int** deleterow1(int** A, int* n, int* m)
{
	for (int i = 0; i < *n; i++)
	{
		int counter = 0;
		for (int j = 0; j < *m; j++)
		{
			if (A[i][j] == 1)
			{
				counter++;
			}
		}

		if (counter == 1)
		{
			if (i == *n - 1)
			{
				free(*(A + *n - 1));
				*n = *n - 1;
			}

			else if (i < *n - 1)
			{
				for (int k = i; k < *n - 1; k++)
				{
					for (int j = 0; j < *m; j++)
					{
						A[k][j] = A[k + 1][j];
					}
				}
				free(*(A + *n - 1));
				*n = *n - 1;
			}
		}
	}
	return A;
}

int** deleterow2(int** A, int* n, int* m)
{
	for (int i = *n - 1; i >= 0; i--)
	{
		int counter = 0;
		for (int j = 0; j < *m; j++)
		{
			if (A[i][j] == 1)
			{
				counter++;
			}
		}

		if (counter == 1)
		{
			if (i == *n - 1)
			{
				free(*(A + *n - 1));
				*n = *n - 1;
			}

			else if (i < *n - 1)
			{
				for (int k = i; k < *n - 1; k++)
				{
					for (int j = 0; j < *m; j++)
					{
						A[k][j] = A[k + 1][j];
					}
				}
				free(*(A + *n - 1));
				*n = *n - 1;
			}
		}
	}
	return A;
}

int** deletecolumn(int** A, int* n, int* m)
{
	for (int j = *m - 1; j >= 0; j--)
	{
		int counter = 0;
		for (int i = 0; i < *n; i++)
		{
			if (A[i][j] == 1)
			{
				counter++;
			}
		}

		if (counter == 1)
		{
			if (j == *m - 1)
			{
				*m = *m - 1;
			}

			if (j < *m - 1)
			{
				for (int k = j; k < *m - 1; k++)
				{
					for (int i = 0; i < *n; i++)
					{
						A[i][k] = A[i][k + 1];
					}
				}
				*m = *m - 1;
			}
		}
	}
	return A;
}

void deletearr(int** A, int* n, int* m)
{
	for (int i = 0; i < *n; i++)
	{
		free(A[i]);
	}
	free(A);
}