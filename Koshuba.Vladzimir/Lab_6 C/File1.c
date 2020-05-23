#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>

#else
  typedef char _TCHAR;
  #define _tmain main
#endif
typedef struct item {
int data;
struct item *left;
struct item *right;
} Item;

void AddNode(int data, Item **node)
{
 if (*node == NULL) {
 *node = (Item *)calloc(1, sizeof(Item));
 (*node)->data = data;
 (*node)->left = (*node)->right = NULL;
 }
 else {
   AddNode(data, &(*node)->right);
 }
}

void Free(Item *node)
{
if (node -> left)
 {Free(node->left);}
 free(node);
if (node -> right)
 {Free(node -> right);}
}

void RightOrder(Item *node)
{
if (node -> left)
RightOrder(node->left);
printf("%d ", node->data);
if (node -> right)
RightOrder(node->right);
}
  
int _tmain(int argc, _TCHAR* argv[])
{
char buffer[128];
int i;
Item *root = NULL;
FILE *fp = fopen("ex52.txt", "r");
if (!fp) exit(1); 
while (fgets(buffer, 128, fp) != NULL) AddNode(atoi(buffer), &root); 
RightOrder(root);
fclose(fp);
getch();
return 0;
}






