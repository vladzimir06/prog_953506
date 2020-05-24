#include <iostream>

using namespace std;

int COUNT = 10;

struct Tree
{
	int key;
	unsigned char height;
	Tree* left, *right;
	Tree(int value) { key = value; left = right = 0; height = 1; }
}*root;

unsigned char Height(Tree* pointer)
{
	return pointer ? pointer->height : 0;
}

int Bfactor(Tree* pointer)
{
	return Height(pointer->right) - Height(pointer->left);
}

void Fixheight(Tree* pointer)
{
	unsigned char symbol1 = Height(pointer->left);
	unsigned char symbol2 = Height(pointer->right);
	pointer->height = (symbol1 > symbol2 ? symbol1 : symbol2) + 1;
}

Tree* Rotateright(Tree* pointer) 
{
	Tree* helper = pointer->left;
	pointer->left = helper->right;
	helper->right = pointer;
	Fixheight(pointer);
	Fixheight(helper);
	return helper;
}

Tree* Rotateleft(Tree* check)
{
	Tree* pointer = check->right;
	check->right = pointer->left;
	pointer->left = check;
	Fixheight(check);
	Fixheight(pointer);
	return pointer;
}

Tree* Balance(Tree* pointer)
{
	Fixheight(pointer);
	if (Bfactor(pointer) == 2)
	{
		if (Bfactor(pointer->right) < 0)
			pointer->right = Rotateright(pointer->right);
		return Rotateleft(pointer);
	}
	if (Bfactor(pointer) == -2)
	{
		if (Bfactor(pointer->left) > 0)
			pointer->left = Rotateleft(pointer->left);
		return Rotateright(pointer);
	}
	return pointer;
}

Tree* Insert(Tree* pointer, int value)
{
	if (!pointer)
	{
		Tree* p = (Tree*)malloc(sizeof(Tree));
		p->key = value;
		return p;
	}
	if (value < pointer->key)
		pointer->left = Insert(pointer->left, value);
	else
		pointer->right = Insert(pointer->right, value);
	return Balance(pointer);
}

Tree* Findmin(Tree* pointer)
{
	return pointer->left ? Findmin(pointer->left) : pointer;
}

Tree* Removemin(Tree* pointer)
{
	if (pointer->left == 0)
		return pointer->right;
	pointer->left = Removemin(pointer->left);
	return Balance(pointer);
}

Tree* Remove(Tree* pointer, int value) 
{
	if (!pointer) return 0;
	if (value < pointer->key)
		pointer->left = Remove(pointer->left, value);
	else if (value > pointer->key)
		pointer->right = Remove(pointer->right, value);
	else 
	{
		Tree* check = pointer->left;
		Tree* help = pointer->right;
		delete pointer;
		if (!help) return check;
		Tree* min = Findmin(help);
		min->right = Removemin(help);
		min->left = check;
		return Balance(min);
	}
	return Balance(pointer);
}

void Printl(Tree* root, int space)
{

	if (root == NULL)
		return;
	space += COUNT;
	Printl(root->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->key << "\n";
	Printl(root->left, space);
}

void DeleteAll(Tree* t) 
{
	if (t != NULL)
	{
		DeleteAll(t->left);
		DeleteAll(t->right);
		free(t);
	}
}

int main()
{
	root = (Tree*)malloc(sizeof(Tree));
	root->left = root->right = 0;
	root->height = 1;
	root->key = 0;
	while (true)
	{
		int value = 0;
		cin >> value;
		if (value == 0)
			break;
		root = Insert(root, value);
	}
	Printl(root, 0);
	DeleteAll(root);
}

