/*
    Вариант 30
    Напишите программу, которая вводит строку текста, разделяет
предложение на отдельные слова, вставляет слова в бинарное
дерево поиска, а затем распечатывает их, обходя дерево слева и
справа.
*/

#include <stdio.h>
#include <malloc.h>

typedef struct
{
    char *data;
    struct Node *left;
    struct Node *right;
} Node;

void AddNode(char *data, Node **node)
{
    if (!(*node))
    {
        *node = (Node*)calloc(1, sizeof(Node));
        (*node)->data = data;
        (*node)->left = (*node)->right = NULL;
    }
    else 
    {
        if (strcmp(data, (*node)->data) <= 0)
        {
            AddNode(data, &(*node)->left);
        }
        else
        {
            AddNode(data, &(*node)->right);
        }
    }
}

void DeleteNode(char *data, Node **root)
{
    Node *current = *root;
    Node *parent = NULL;
    Node *toDelete;

    while (current) 
    {
        if (!strcmp(current->data, data)) 
        {
            break;
        }
        else 
        {
            parent = current;

            if (strcmp(current->data, data) > 0) 
            {
                current = current->left;
            }
            else 
            {
                current = current->right;
            }
        }
    }
    if (!current) return;

    if (!current->right) 
    {
        if (!parent) 
        {
            toDelete = *root;
            *root = current->left;
        }
        else 
        {
            if (current == parent->left) 
            {
                toDelete = parent->left;
                parent->left = current->left;
            }
            else 
            {
                toDelete = parent->right;
                parent->right = current->left;
            }
        }
    }
    else 
    {
        Node *leftMost = current->right;
        parent = NULL;

        while (leftMost->left) 
        {
            parent = leftMost;
            leftMost = leftMost->left;
        }
        if (parent) 
        {
            toDelete = parent->left;
            parent->left = leftMost->right;
        }
        else 
        {
            toDelete = current->right;
            current->right = leftMost->right;
        }
        current->data = leftMost->data;
        free(toDelete);
    }
}

void LeftOrder(Node *root)
{
    if (root)
    {
        LeftOrder(root->left);
        printf("%s ", root->data);
        LeftOrder(root->right);
    }
}

void RightOrder(Node *root)
{
    if (root)
    {
        RightOrder(root->right);
        printf("%s ", root->data);
        RightOrder(root->left);
    }
}

void PrintTree(Node *root, int level)
{
    if (root)
    {
        PrintTree(root->right, level + 1);
        for (int i = 0; i < level; i++)
            printf("   ");
        printf("%s\n", root->data);
        PrintTree(root->left, level + 1);
    }
}

void DeleteTree(Node *root)
{
    if (root)
    {
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
    }
}

int main() {
    int j = 0;
    char symb;
    char* word = (char*)calloc(20, sizeof(char*));
    int isInputEmpty = 1;
    Node* root = NULL;

    printf_s("Input : ");

    while (symb = getchar())
    {
        if (symb == ' ' || symb == '\n')
        {
            word[j] = '\0';

            if (j > 0)
            {
                AddNode(word, &root);
                isInputEmpty = 0;
                word = (char*)calloc(20, sizeof(char));
            }
            j = 0;

            if (symb == '\n') break;
        }
        else
        {
            word[j++] = symb;
        }
    }

    if (!isInputEmpty)
    {
        printf_s("Left order : ");
        LeftOrder(root);
        printf_s("\nRight order : ");
        RightOrder(root);
        puts("\nTree:");
        printTree(root, 0);
    }
    else
    {
        printf_s("Empty input");
    }

    DeleteTree(root);
    free(word);
    return 0;
}