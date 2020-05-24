/*В текстовом файле содержится произвольный текст. С помощью
бинарного дерева определить частоту вхождения каждого слова в
текст. Вывести слова по убыванию частоты вхождения.
Примечание. Каждый элемент дерева должен хранить слово.
Кроме этого, необходимо вести счетчик числа вхождений этого
слова в текст. */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct TreeNode
{
	char *word;
	int count;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct List
{
	char *word;
	int count;
	struct List* next;
};

struct TreeNode* AddTree(struct TreeNode* tree, char* word);
struct TreeNode* Write(struct TreeNode* tree);
void WriteInList(struct TreeNode* tree, struct List** list);
struct List* AddList(struct List* list, char* word, int count);
void PrintList(struct List* list);
void FreeMemoryTree(struct TreeNode** node);
void FreeMemoryList(struct List** item);

int main()
{
	struct TreeNode* tree = NULL;
	struct List* list = NULL;

	tree=Write(tree);
	//ShowTree(tree);

	WriteInList(tree, &list);
	printf("\n");
	PrintList(list);
	FreeMemoryTree(&tree);
	FreeMemoryList(&list);
	
}

struct TreeNode *Write(struct TreeNode *tree)
{
	FILE* fp;
	char letter;
	char word[30] = "\0";
	fopen_s(&fp, "lr6.txt", "r");
	if (!fp)
	{
		puts("Eror:file isn't open!");
		exit(0);
	}

	int i = 0;
	while (!feof(fp))
	{

		letter = fgetc(fp);
		if (letter != ' ' && letter != ',' && letter != '.' && letter != '!' && letter != '?')
		{
			word[i] = letter;
			i++;
		}
		else
		{
			printf("%s ", word);
			tree = AddTree(tree, word);
			for (int i = 0; i < 30; i++)
			{
				word[i] = '\0';
			}
			i = 0;

		}
	}

	fclose(fp);
	return tree;
}

struct TreeNode* AddTree(struct TreeNode* tree, char* word)
{
	
	if (!tree) {

		tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		tree->word = _strdup(word);
		tree->count = 1;
		tree->left = NULL;
		tree->right = NULL;
		return tree;
	}

	else if (strcmp(word, tree->word) == 0)
		tree->count++;

	else if (strcmp(word, tree->word) < 0)
		tree->left = AddTree(tree->left, word);

	else
		tree->right = AddTree(tree->right, word);

	return tree;
}

void WriteInList(struct TreeNode* node, struct List** list)
{
	if (!node)
		return;

	WriteInList(node->left, &(*list));

	(*list) = AddList((*list), node->word, node->count);

	WriteInList(node->right, &(*list));

}

struct List* AddList(struct List* list, char* word, int count)
{
	struct List* item = (struct List*)malloc(sizeof(struct List));
	item->word = _strdup(word);
	item->count = count;
	item->next = NULL;

	if (!list) {

		list = item;
		return list;
	}

	if (list->count <= item->count) {

		item->next = list;
		list = item;
		return list;
	}

	struct List* place  = list->next, *prev=list;

	while (place) {

		if (place->count <= item->count) {
			prev->next = item;
			item->next = place;
			place = item;
			return list;
		}
		place = place->next;
		prev = prev->next;
	}
	place->next = item;
	return list;
}

void PrintList(struct List* list)
{
	struct List* place; place = list;

	while (place) {

		printf("%d - %s\n", place->count, place->word);
		place = place->next;
	}
}

void FreeMemoryTree(struct TreeNode** node)
{
	if (*node) {

		FreeMemoryTree(&((*node)->left));
		FreeMemoryTree(&((*node)->right));
		free(*node);
	}
}

void FreeMemoryList(struct List** item)
{
	struct List* temp;

	while (*item) {

		temp = *item;
		*item = (*item)->next;
		free(temp);
	}
}

