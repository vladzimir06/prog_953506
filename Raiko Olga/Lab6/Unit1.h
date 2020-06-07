#ifndef Unit1H
#define Unit1H
#endif

#include <alloc.h>
#include <stdio.h>
#include <stdlib.h>


#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_RT(a, b) ((a) > (b))

typedef struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* GetFreeNode(int value, Node* parent);
void Insert(Node** root, int value);
Node* Create(int* arr, int len);
void Free(Node* tmp);
void Print(Node* tmp, int level);
void PrintTree(Node* root, const char* dir, int level);
Node* CopyOf(Node* node);
int Compare(Node* n1, Node* n2);
