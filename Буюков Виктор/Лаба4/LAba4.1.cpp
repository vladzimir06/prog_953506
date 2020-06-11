/*С клавиатуры вводится многострочный текст.Оставить в тексте
только первые вхождения каждой буквы, остальные – удалить.
Вывести слова полученного текста, которые начинаются и
заканчиваются одной и той же буквой.*/



#include<stdlib.h>
#include <stdio.h>
#include <string.h>

#define LONG_STR 200 /* длина вводимой строки */
#define MAX_WORD 80 /* максимальное количество слов в строке */
#define LETTER 27 /*количество букв + нулевой символ*/

char alphabet[LETTER] = { 'a','b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o','p', 'q', 'r', 's', 't', 'u', 'v' ,'w', 'x','y','z' };
int wordCount(char* str)
{
	int word_count = 1;
    for (int i = 0; i < LONG_STR; i++)
	{
		if (str[i] == ' ' && str[i + 1] == '\0')
			continue;
		if ((str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '!' || str[i] == '?') && str[i + 1] == ' ')
			continue;
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '!' || str[i] == '?')
			word_count++;
	}
	return word_count;
}



void wordStartIndex(int* word_start_index, char* str, int word_count)
{
	word_start_index[0] = 0;
	for (int i = 1, j = 1; j < LONG_STR; j++)
		for (int alpha = 0; alpha < LETTER; alpha++)
		{
			if (str[j] == alphabet[alpha] && str[j - 1] == ' ')
			{
				word_start_index[i] = j;
				i++;
			}

		}

}



void wordFinishIndex(int* word_finish_index, char* str, int word_count)
{
	for (int i = 0, j = 0; j < LONG_STR; j++)
		for (int alpha = 0; alpha < LETTER; alpha++)
		{
			if (str[j] == alphabet[alpha] && (str[j + 1] == ' ' || str[j + 1] == '.' || str[j + 1] == ',' || str[j + 1] == '!' || str[j + 1] == '?' || str[j + 1] == '\0'))
			{
				word_finish_index[i] = j;
				i++;
			}
		}
}

void writeCommonLetterInWord(char* str, int* word_start_index, int* word_finish_index, int word_count)
{
	printf("\n ");
	for (int j = 0; j < word_count; j++)
	{
		if (str[word_start_index[j]] == str[word_finish_index[j]])
		{
			for (int k = word_start_index[j]; k <= word_finish_index[j]; k++)
				printf("%c", str[k]);
			printf(" ");
		}
	}

}



void deleteDoubleLetter(char* str, int* word_start_index, int* word_finish_index, int word_count)
{
	printf("\n");
	int finish = word_finish_index[word_count - 1];
	for (int i = 1; i <= finish; )
	{
		if (str[i] == str[i - 1])
		{
			for (int j = i; j < finish; j++)
			{
				str[j] = str[j + 1];
			}

			str[finish] = '\n';
			finish--;

			for (int k = 0; k < word_count; k++)
			{
				if (i < word_start_index[k])
					word_start_index[k]--;
				if (i < word_finish_index[k])
					word_finish_index[k]--;
			}
		}
		else
			i++;
	}



}

int main()
{
	system("chcp 1251");
	system("cls");
	char str[LONG_STR];
	gets_s(str);
	int word_count = wordCount(str);
	int* word_start_index = (int*)calloc(word_count, sizeof(int));
	if (!word_start_index)
	{
		printf_s("Ошибка выделения памяти");
		return 1;
	}

	int* word_finish_index = (int*)calloc(word_count, sizeof(int));

	if (!word_finish_index)
	{
		printf_s("Ошибка выделения памяти");
		return 1;
	}

	wordStartIndex(word_start_index, str, word_count);
	wordFinishIndex(word_finish_index, str, word_count);
	puts("Удаление повторных букв:");
	deleteDoubleLetter(str, word_start_index, word_finish_index, word_count);
	printf("%s", str);
	puts("Слова, которые начинаются и оканчиваются одной буквой:");
	writeCommonLetterInWord(str, word_start_index, word_finish_index, word_count);

}