// laba 4 c
// elvina fedorinchik
/*Пусть слово – это последовательность от 1 до 8
символов, не включающая пробелов. Вводится n слов s1, ..., sn.
Можно ли их упорядочить так, чтобы получилась «цепочка», 
в которой первая буква каждого слова si совпадает с последней буквой
предыдущего слова, а последняя буква последнего слова совпадает с
первой буквой первого слова? В цепочку должны входить все n слов
без повторений. Если такое упорядочение возможно, то вывести
цепочку слов.
*/

#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#define N 5

int my_strlen(char* c_str)
{
	int count = 0;
	while (*c_str++) ++count;
	return count;
}

int main()
{
	static char* words[256] = { "elephant", "open", "kengoo", "name", "tick" };    // для проверки можно закомментировать
	//static char* words[256] = {"year", "open", "kengoo", "name", "tick"};      // а это раскомментировать
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int r = my_strlen((words[i])) - 1;
			if (words[j][0] == words[i][r])
			{
				char* temp = words[i + 1];
				words[i + 1] = words[j];
				words[j] = temp;
				break;
			}
			else if (words[j][0] != words[i][r] && i + 1 >= N)
			{
				printf("\nERROR\n");
				return 0;
			}
		}
	for (int q = 1; words[q] != NULL; q++)
		printf("%s ", words[q]);
	printf("\n");

	return 0;
}