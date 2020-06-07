#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)



Node* GetFreeNode(int value, Node* parent)//получение нового узла
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}


void Insert(Node** root, int value)//функция добавления 
{
	Node* tmp = NULL;//добавляем узел
	Node* ins = NULL;
	if (*root == NULL)// проверка на то, пустое ли дерево 
	{
		*root = GetFreeNode(value, NULL);
		return;
	}

	tmp = *root;
	while (tmp)
	{
		if (CMP_RT(value, tmp->data))// если значение больше чем екущий узел, то переходим на правую ветвь
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else // если правой ветви нет, то вставляем узел справа
			{
				tmp->right = GetFreeNode(value, tmp);
				return;
			}
		}
		else // то же с левой ветвью
			if (CMP_LT(value, tmp->data))
			{
				if (tmp->left)
				{
					tmp = tmp->left;
					continue;
				}
				else
				{
					tmp->left = GetFreeNode(value, tmp);
					return;
				}
			}
			else
			{
				exit(2);
			}
	}
}

Node* Create(int* arr, int len)//создание
{
	Node* root = NULL;
	for (int i = 0; i < len; i++)
		Insert(&root, arr[i]);
	return root;
}

void Free(Node* tmp)//отчистка 
{
	if (tmp)
	{
		Free(tmp->left);
		Free(tmp->right);
		free(tmp);
	}
}

void Print(Node* tmp, int level) // вывод дерева
{
	if (tmp)
	{
		Print(tmp->left, level + 1);
		for (int i = 0; i < level; i++)
			printf(" ");
		printf("%d\n", tmp->data);
		Print(tmp->right, level + 1);
	}
}

void PrintTree(Node* root, const char* dir, int level) //подробная информация
{
	if (root)
	{
		printf("lvl %d %s = %d\n", level, dir, root->data);
		PrintTree(root->left, "left", level + 1);
		PrintTree(root->right, "right", level + 1);
	}
}

Node* CopyOf(Node* node)
{
	if (node == NULL)
		return NULL;

	Node* newnode = GetFreeNode(node->data, node->parent);//новые узлы
	newnode->left = CopyOf(node->left);
	newnode->right = CopyOf(node->right);

	return newnode;
}

int Compare(Node* n1, Node* n2)//сравнение 
{
	if (n1->data != n2->data || (n1->left == NULL && n2->left != NULL) ||
		(n1->left != NULL && n2->left == NULL) ||
		(n1->right == NULL && n2->right != NULL) ||
		(n1->right != NULL && n2->right == NULL))
	{
		return 0;
	}
	if (n1->left == NULL && n1->right == NULL && n2->left == NULL && n2->right == NULL)
	{
		return 1;
	}
	if (n1->left == NULL && n2->left == NULL && n1->right != NULL && n2->right != NULL)
	{
		return Compare(n1->right, n2->right);
	}
	if (n1->left != NULL && n2->left != NULL && n1->right == NULL && n1->right == NULL)
	{
		return Compare(n1->left, n2->left);
	}
	return (Compare(n1->left, n2->left) * Compare(n1->right, n2->right));
}
