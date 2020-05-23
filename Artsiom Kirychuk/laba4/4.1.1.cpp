#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int wordcount(char* str, int word);
void lenghtofword(char* str, int* se);
void sort(char* str, int* se, int word);

int main()
{	
	int word = 0;
	char str[100];
	memset(str, '\0', 100);
	gets_s(str);
	word= wordcount(str,word+1);								//количество слов в строке
	int* startend = (int*)malloc(word * 3 * sizeof(int));		// массив, в котором будут храниться индексы начала/конца слова + длина слова
	if (!startend)
	{
		printf_s("Ошибка выделения памяти");
		return 1;
	}
	lenghtofword(str, startend);
	sort(str, startend,word);	
	for (int i = 0; i < word; i++)
	{
		for (int k = startend[i * 3]; k < startend[i * 3 + 1]; k++)
			printf_s("%c", str[k]);
		printf_s("\n");
	}
	free(startend);
}

void lenghtofword(char* str, int* se)
{
	int word = 0;
	se[word * 3 + 0] = 0;
	for (int i = 0; str[i]!= '\0'; i++)
	{
		if (str[i] == ' ')
		{
			se[word * 3 + 1] = i;													//	записываем индекс пробела
			se[word * 3 + 2] = se[word * 3 + 1] - se[word * 3 + 0];					//	длина слова=индекс пробела-индекс начала слова
			word++;
			se[word * 3 + 0] = i + 1;
		}
		if (str[i + 1] == '\0')
		{
			se[word * 3 + 1] = i + 1;
			se[word * 3 + 2] = se[word * 3 + 1] - se[word * 3 + 0];
		}
	}
}

int wordcount(char* str,int word)													
{
	for (int i = 0; i < 100; i++)
	if (str[i] == ' ') word++;
	return word;
}

void sort(char* str, int* se,int word)												//Шейкер сортировка
{
	int begin = 0, end = word-1,flag = 0;
	while (begin < end && flag==0)
	{
		flag = 1;
		for (int i = begin; i < end; i++)
		{
			if (se[i * 3 + 2] < se[(i + 1) * 3 + 2])
			{
				int buf1 = se[i * 3 + 2];
				se[i * 3 + 2] = se[(i + 1) * 3 + 2];
				se[(i + 1) * 3 + 2] = buf1;
				int buf2 = se[i * 3 + 1];
				se[i * 3 + 1] = se[(i + 1) * 3 + 1];
				se[(i + 1) * 3 + 1] = buf2;
				int buf3 = se[i * 3 + 0];
				se[i * 3 + 0] = se[(i + 1) * 3 + 0];
				se[(i + 1) * 3 + 0] = buf3;
				flag = 0;
			}
		}
		end--;
		for (int i = end; i > begin; i--)
		{
			if (se[i * 3 + 2] > se[(i - 1) * 3 + 2])
			{
				int buf1 = se[i * 3 + 2];
				se[i * 3 + 2] = se[(i - 1) * 3 + 2];
				se[(i - 1) * 3 + 2] = buf1;
				int buf2 = se[i * 3 + 1];
				se[i * 3 + 1] = se[(i - 1) * 3 + 1];
				se[(i - 1) * 3 + 1] = buf2;
				int buf3 = se[i * 3 + 0];
				se[i * 3 + 0] = se[(i - 1) * 3 + 0];
				se[(i - 1) * 3 + 0] = buf3;
				flag = 0;
			}
		}
		begin++;
	}
}