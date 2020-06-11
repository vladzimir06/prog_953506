// Задание 4.2(2) Стельмашук В.А.(гр. №953506)

/*Текст в файле содержит многократно вложенные круглые скобки.
Если баланс скобок соблюден, исправить текст, оставив скобки
первого уровня круглыми, второго – заменить на квадратные,
третьего и последующих – на фигурные. 
*/

#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int mystrlen(char s[]);

int main()
{
	char s[100] = { 0 };
	FILE* fp = NULL;
	int l = 0;
	int maxl = 0;

	if (fopen_s(&fp, "C:\\Лабораторные С\\text4lr.txt", "r"))
	{
		perror("Cannot open file.\n");
	}

	while (!feof(fp))
	{
		if (fgets(s, 126, fp))
			printf("string  before: %s ", s);
	}

	fclose(fp);
	printf("\n");

	for (int i = 0; i < mystrlen(s); i++)
	{
		if (s[i] == '(')
		{
			s[i] = '{';
			l++;
			if (l > maxl)
			{
				maxl = l;
			}
		}
		if (s[i] == ')')
		{
			s[i] = '}';
			l--;
		}
	}

	for (int i = 0; i < mystrlen(s); i++)
	{

		if (s[i] == '{')
		{
			l++;
			if (l == maxl) s[i] = '(';
			if (l == maxl - 1) s[i] = '[';
		}
		if (s[i] == '}')
		{
			if (l == maxl) s[i] = ')';
			if (l == maxl - 1) s[i] = ']';
			l--;
		}
	}
	printf("string after: %s ", s);
	printf("\n");
	free(fp);
	return 0;
}

int mystrlen(char s[]) {
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;

	return i;
}