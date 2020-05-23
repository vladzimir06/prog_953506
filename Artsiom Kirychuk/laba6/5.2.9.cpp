#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

struct Node
{
	char number[1];
	int done;
	Node* left, * right;
};


Node* AddToTree(Node* Tree , char* numeral,int i);
void Printout(Node* Tree);
void PrintTree(Node* Tree, int r);
void treeremove(Node* Tree);


int main()
{
	Node* Tree = (Node*)malloc(sizeof(Node));
	Tree->right = Tree->left = NULL;
	Tree->number[0] = '<';
	FILE* myfile;
	fopen_s(&myfile, "read.txt", "r");
	if (myfile == NULL)
	{

		printf_s("Файл не найден");
		return -1;
	}
	char buf[6];
	int i = 0, count = 16;
	while (!feof(myfile))
	{
		if (!count) break;
		fgets(buf, 6, myfile);
		if (buf[0] == '0')
			Tree->left = AddToTree(Tree->left, buf, 0);
		else
			Tree->right = AddToTree(Tree->right, buf, 0);
		count--;
	}
	fclose(myfile);
	//Printout(Tree);
	PrintTree(Tree, 0);
	treeremove(Tree);
}

Node* AddToTree(Node* Tree, char* number,int i)
{
	if (Tree == NULL)
	{
		Tree = (Node*)malloc(sizeof(Node));
		if (Tree == NULL)
		{
			printf_s("Ошибка");
			exit(1);
		}
		Tree->number[0] = number[i];
		Tree->left = NULL;
		Tree->right = NULL;
		if (number[i + 1] == '\n')
		{
		    int power = 0;
			Tree->done = 0;
			for (int j = 3; j >= 0; j--)
				Tree->done += (number[j] - 48) * pow(2, power++);
			return Tree;
		}
		if(number[i+1]=='0')
		   Tree->left= AddToTree(Tree->left, number, i + 1);
		else 
			Tree->right=AddToTree(Tree->right, number, i + 1);
		return Tree;
	}
	if (number[i] == Tree->number[0] && number[i + 1] == '1')
		Tree->right = AddToTree(Tree->right, number, i + 1);
	if (number[i] == Tree->number[0] && number[i + 1] == '0')
		Tree->left = AddToTree(Tree->left, number, i + 1);
	return Tree;
}

void Printout(Node* Tree)
{
	Node* temp = Tree;
	if (temp->left) Printout(temp->left);
	if (temp->left == NULL && temp->right == NULL)
	{
		printf_s("%c", temp->number[0]);
		printf_s("\n");
	}
	if (temp->right) Printout(temp->right);
}

void PrintTree(Node* Tree, int r)
{
	if (Tree != NULL)
	{
		PrintTree(Tree->right, r + 5);
		if (Tree->right == NULL && Tree->left == NULL)
		{
			for (int i = 0; i < r; i++)
				printf(" ");
			printf("%c---------%d\n", Tree->number[0],Tree->done);
			return;
		}
		for (int i = 0; i < r; i++)
			printf(" ");
		printf("%c\n", Tree->number[0]);
		PrintTree(Tree->left, r + 5);
	}
}

void treeremove(Node *Tree)
{
	if (Tree != NULL)
	{
		treeremove(Tree->left);
		tree_remove(Tree->right);
		free(Tree);
	}

