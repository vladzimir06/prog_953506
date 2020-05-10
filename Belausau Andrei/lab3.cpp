/*
		Вариант 27
	Массив a(n, m) состоит из нулей и единиц. Требуется удалить из него
	совпадающие строки, а оставшиеся упорядочить по возрастанию
	двоичных чисел, формируемых из данных соответствующей строки. 
*/

#include <stdio.h>
#include <malloc.h>

void ReadArray(int **arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
}

void ShowArray(int **arr, int n, int m)
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			printf_s("%d ", arr[i][j]);
		}
		puts("");
	}
}

int Compare(int *arr1, int *arr2, int size)
{
	while (size--)
	{
		if (*arr1 > *arr2) return 1;
		if (*arr1++ < *arr2++) return -1;
	}
	return 0;
}

void DeleteSimilar(int** arr, int *size, int m)
{
	int n = *size;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Compare(arr[i], arr[j], m) == 0) {
				int* tmp = arr[n - 1];
				arr[n - 1] = arr[j];
				arr[j--] = tmp;
				n--;
			}
		}
	}
	realloc(arr, n * sizeof(int));
	*size = n;
}

void Sort(int *arr, int n, int m) {
	for (int i = 1; i < n; i++) {
		int x = arr[i], j = i - 1;

		while (Compare(x, arr[j], m) < 0)
		{
			arr[j + 1] = arr[j];
			j--;
			if (j < 0) break;
		}
		arr[j + 1] = x;
	}
}

int main()
{
	int n, m;
	puts("enter n, m");
	scanf_s("%d",&n);
	scanf_s("%d",&m);
	int **arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(m * sizeof(int));
	}

	ReadArray(arr, n, m);
	puts("");
	DeleteSimilar(arr, &n, m);
	Sort(arr, n, m);
	ShowArray(arr, n, m);

	return 0;
}