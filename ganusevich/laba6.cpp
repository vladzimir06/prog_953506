#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    int data; // ключ/данные
    Node* left; // указатель на левого потомка
    Node* right; // указатель на правого потомка
};

struct Tree
{
    Node* head;
};

void Print(Node* root);
void Add(Node** node, int value);
Tree Cat(Node** node1, Node** node2);
void AddCat(Node** node, Node** node1);
void DelTree(Node** root);

int main()
{
    Tree tree1, tree2;
    tree1.head = NULL;
    tree2.head = NULL;
    int mass1[]{ 2, 3, 4, 3};
    int mass2[]{ 2, 3, 7, 8 };
    for (int i = 0; i < 4; i++)
    {
        Add(&tree1.head, mass1[i]);
        Add(&tree2.head, mass2[i]);
    }
    Print(tree1.head);
    printf("\n");
    tree1 = Cat(&tree1.head, &tree2.head);
    DelTree(&tree2.head);
    Print(tree1.head);
    DelTree(&tree1.head);
}

void Print(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    Print(root->left); 
    printf("%d ", root->data);
    Print(root->right);
}


void Add(Node** node, int value) {
    if (*node == NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = value;
        *node = temp;
    }
    else if (value >= (*node)->data) {
        if ((*node)->right != NULL)
            Add(&(*node)->right, value);
        else 
        {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            (*node)->right=newNode;
        }
    }
    else {
        if ((*node)->left != NULL)
            Add(&(*node)->left, value);
        else {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            (*node)->left = newNode;
        }
    }
}

Tree Cat(Node** node1, Node** node2)
{
    Tree newTree;
    newTree.head = NULL;
    AddCat(&newTree.head, node1);
    AddCat(&newTree.head, node2);
    return newTree;
}

void AddCat(Node** node, Node** node1)
{
    if (*node1 == NULL)
        return;
    if (*node == NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = (*node1)->data;
        *node = temp;
    }
    else if ((*node1)->data > (*node)->data) 
    {
        if ((*node)->right != NULL)
            AddCat(&(*node)->right, node1);
        else
        {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = (*node1)->data;
            newNode->left = NULL;
            newNode->right = NULL;
            (*node)->right = newNode;
        }
    }
    else if(((*node1)->data < (*node)->data))
    {
        if ((*node)->left != NULL)
            AddCat(&(*node)->left, node1);
        else {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = (*node1)->data;
            newNode->left = NULL;
            newNode->right = NULL;
            (*node)->left = newNode;
        }
    }
    AddCat(node, &(*node1)->left);
    AddCat(node, &(*node1)->right);
}

void DelTree(Node** root)
{
    if ((*root)->left != NULL)
        DelTree(&(*root)->left);
    if ((*root)->right != NULL)
        DelTree(&(*root)->right);
    free(*root);
}