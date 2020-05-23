//Задание 5.2 (23) Карпенко И.В.(гр. №953506)

/* В текстовом файле содержится произвольный текст. Построить на
его основе бинарное дерево поиска, каждый узел которого
содержит слово. Вывести на печать те слова, в которых встречаются
три и более гласных букв латинского алфавита. */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_LENGTH 30
#define TEXT_LENGTH 300

typedef struct Node
{
	char word[MAX_LENGTH];
	Node* left;
	Node* right;
}Node;

/*Функция для подсчета гласных в словах*/
int Vowels(char* word)
{
	int v = 0;
	char vowels[] = "eioau";
	for (int i = 0; word[i] != '\0'; i++)
		for (int j = 0; j < 5; j++)
			if (word[i] == vowels[j]) v++;
	return v;
}

/*Добавляет узел в дерево, основываясь на количестве гласных в слове*/
void AddNode( Node*& node, char* word)
{
	if (node == NULL) 
	{
		node = (Node*)malloc(sizeof(Node));
		node->left = NULL;
		node->right = NULL;
		int i;
		for (i = 0; word[i] != '\0'; i++) node->word[i] = word[i];
		node->word[i++] = '\0';
		return;
	}
	if (Vowels(word) == Vowels(node->word))
	{
		int same = 0;
	    for(int i = 0; word[i] != '\0' || node->word[i] != '\0'; i++)
		{
			if (word[i] == node->word[i]) same = 1;
			else 
			{
				same = 0;
				break;
			}
		}
		if (same == 1) return;
	}
	if (Vowels(word) < Vowels(node->word)) 
		AddNode(node->left, word);
	else AddNode(node->right, word);
}

void LeftOrder(Node *node)
{
	if (node->left)
		LeftOrder(node->left);
		printf("%s", node->word);
	if (node->right)
		LeftOrder(node->right);
}

/*Выводит на печать те слова элементов дерева, гласных букв в которых больше заданного числа*/
void PrintMoreThan(Node *node, int number)
{
	if (node == NULL) return;
	if(Vowels(node->word) < number)
	{
		PrintMoreThan(node->right, number);
		return;
	}
	PrintMoreThan(node->left, number);
	for(int i = 0; node->word[i] != '\0'; i++) printf("%c", node->word[i]);
	printf("\n");
	PrintMoreThan(node->right, number);
}

void DeleteTree(Node *node)
{
	if (node == NULL) return;
	DeleteTree(node->left);
	DeleteTree(node->right);

	free(node);
}

int main()
{
	FILE* fp;
	Node* root = NULL;
	int marka = 0;
	char word[MAX_LENGTH], text[TEXT_LENGTH], mark[] = " ,.?!;:\n\0";

	fopen_s(&fp, "Text.txt", "r");

	if (!fp) exit(1);
	while (fgets(text, TEXT_LENGTH, fp) != NULL)
	{
	    for(int i = 0, j = 0; text[i - 1] != '\0'; i++)
		{
			for (int k = 0; k < 10; k++) 
			{
				if(text[i] == mark[k])
				{
					word[j] = NULL;
					if (j != 0) AddNode(root, word);
					j = 0;
					marka = 0;
					break;
				}
				marka = 1;
			}
			if(marka == 1)
			{
				word[j] = text[i];
				j++;
			}
		}
	}
	fclose(fp);
	printf("Words from a text with more than three (or three) letters:\n");
	PrintMoreThan(root, 3);
	DeleteTree(root);

	return 0;
}

