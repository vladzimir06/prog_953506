#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>

void search(char* arr, int word);
int chek(int* replay, int usedword);
void countreplay(int* replay, int i, int k);

int main()
{
	system("chcp 1251");
	system("cls");
	char buf;
	int lenalpha = -1, word = 1, i = 0, j = 0, k = 0;
	FILE *myfile;
	if (fopen_s(&myfile, "pampam.txt", "r")) printf_s("файл не найден");
	while (!feof(myfile))
	{
		buf=fgetc(myfile);
		lenalpha++;
	}

	char* str = (char*)calloc(lenalpha,sizeof(char));
	if (!str) printf_s("что-то не то");
	fseek(myfile, 0, 0);
	for( i=0;i<lenalpha;i++)
	{buf = fgetc(myfile);
		if(buf=='\n')
		str[i] =' ';
		else str[i] = buf;
	}
	fclose(myfile);

	str[lenalpha] = '\0';
	
	for ( i = 0, lenalpha = strlen(str); i < lenalpha; i++)
		if (str[i] == ' ')word++;
	
	char* split = (char*)malloc(word*20);
	i = 0;
	j = 0;

	while (true)
	{
		if (k == strlen(str))
		{
			split[i * 20 + j] = '0';
			break;
		}
		if (str[k] == ' ')
		{
			split[i*20+j] = '0';
			 i++; j = 0; k++;
			continue;
		}
		split[i*20+j] = str[k];
		j++;
		k++;
	}
	search(split,word);
	free(str);
	free(split);
}

int chek(int* replay, int usedword)
{
	for (int a = 0; a < 20; a++)
	{
		if (replay[a] == usedword)
			return 1;
	}
	return 0;
}

void countreplay(int* replay, int i, int k)
{
	static int amount = 0;
	replay[amount++] = i;
	replay[amount++] = k;
}

void search(char* arr, int word)
{
	int lenght = 0, k = 1, j = 0, i = 0, l = 0;
	char buffer[20];
	int* replay = (int*)calloc(word, sizeof(int));
	memset(buffer, 0, 20);
	while (true)
	{
		while (true)
		{
			if (arr[k * 20 + l] == '0')
			{
				l = 0;
				break;
			}
			lenght++;
			l++;
		}
		while (true)
		{
			if (arr[i * 20 + j] == arr[k * 20 + lenght - 1])
				buffer[j] = arr[i * 20 + j];
			else
			{
				j = 0;
				lenght = 0;
				break;
			}
			lenght--;
			j++;
			if (lenght == 0 && arr[i * 20 + j] == '0')
			{
				countreplay(replay, i, k);
				printf_s("%s-", buffer);
				for (j = strlen(buffer) - 1; j >= 0; j--)
					printf("%c", buffer[j]);
				printf("\n");
				j = 0;
				memset(buffer, 0, 20);
				do { i++; k = i; } while (chek(replay, i));
			}
			if (i == k) break;
		}
		do { k++; } while (chek(replay, k));
		if (k == word)
		{
			i++; k = i + 1;
		}
	}
}