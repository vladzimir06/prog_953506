/*
	Вариант 4
	Дано n матриц. В каждой строке каждой матрицы записано одно
слово. Если в слове нет повторяющихся символов – преобразовать
все буквы слова в прописные, в противном случае – в строчные
буквы. Полученные матрицы вывести
*/

#include <stdio.h>

void Input(int *x)
{
	char c;
	int a;

	while (1)
	{
		scanf_s("%d", &a);
		c = getchar();
		if (c == '\n' && a >= 0)
			break;
		rewind(stdin);
	}
	*x = a;
}

int strlength(char *str)
{
	int i = 0, len = 0;

	while (str[i++])
		len++;

	return len;
}

int isLower(char *str)
{
	return str >= 'a' && str <= 'z';
}

int isUpper(char *str)
{
	return str >= 'A' && str <= 'Z';
}

void ToLower(char *str)
{
	int i = 0;
	
	while (str[i])
	{
		if (isUpper(str[i]))
		{
			str[i] += 32;
		}
		i++;
	}
}

void ToUpper(char *str)
{
	int i = 0;
	
	while (str[i])
	{
		if (isLower(str[i]))
		{
			str[i] -= 32;
		}
		i++;
	}
}

int onlyUniqueSymbs(char *str)
{
	for (int i = 0; i < strlength(str) - 1; i++)
	{
		for (int j = i + 1; j < strlength(str); j++)
		{
			if (str[i] == str[j] || str[i] == str[j] - 32 || str[i] == str[j] + 32)
			{
				return 0;
			}
		}
	}
	return 1;
}

void main(void)
{
	int n, amountOfWords;
	char arrayOfWords[10][80];

	printf("amount of matrix = ");
	Input(&n);

	for (int k = 0; k < n; k++)
	{
		puts("--------------------");
		printf("amount of words = ");
		Input(&amountOfWords);

		for (int i = 0; i < amountOfWords; i++)
		{
			gets_s(arrayOfWords[i], 80);
		}
		puts("");

		for (int i = 0; i < amountOfWords; i++)
		{
			onlyUniqueSymbs(arrayOfWords[i]) ? ToUpper(arrayOfWords[i]) : ToLower(arrayOfWords[i]);
			printf("%s\n", arrayOfWords[i]);
		}
	}
}