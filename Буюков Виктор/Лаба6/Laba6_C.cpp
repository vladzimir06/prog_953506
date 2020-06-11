// Вариант 25  Разработать функцию, которая принимает в качестве аргумента троичное 
// дерево и определяет, сколько уровней оно содержит. 

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct tree {
    int  key;    
    struct tree* left;
    struct tree* center;
    struct tree* right;
} Tree;
int  Tree_Add(Tree** tr, int key);
void Tree_Print(FILE* _out, const Tree* tr);
void Tree_Clear(Tree* tr);
unsigned int Tree_Height(const Tree* tr);

int main(void) {
    Tree* tr = NULL;

    Tree_Add(&tr, 32);
    Tree_Add(&tr, 26);
    Tree_Add(&tr, 64);
    Tree_Add(&tr, 16);
    Tree_Add(&tr, 48);
    Tree_Add(&tr, 32);
    Tree_Add(&tr, 26);
    Tree_Add(&tr, 64);
    Tree_Add(&tr, 16);
    Tree_Add(&tr, 48);
    Tree_Print(stdout, tr);

    printf("height tree: %u\n", Tree_Height(tr));
    Tree_Clear(tr);
    return 0;
}

//вставка
int Tree_Add(Tree** tr, int key) {
    Tree* p = *tr;
    while (p != NULL) {
        if (key < p->key) {
            tr = &p->left;
            p = p->left;
        }
        else if (key == p->key) {
            tr = &p->center;
            p = p->center;
        }
        else if (key > p->key) {
            tr = &p->right;
            p = p->right;
        }
        else
            return 0;
    }

    p = (Tree*)malloc(sizeof(Tree));
    if (p != NULL) {
        p->left = p->right = p->center = NULL;
        p->key = key;       
        *tr = p;
    }
    return (p != NULL);
}

//печать
void Tree_Print(FILE* _out, const Tree* tr) {
    if (tr != NULL) {
        if (tr->left != NULL)
            Tree_Print(_out, tr->left);

        fprintf(_out, "key: %d \n", tr->key);

        if (tr->right != NULL)
            Tree_Print(_out, tr->right);

        if (tr->center != NULL)
            Tree_Print(_out, tr->center);
    }
}

//удаление всех
void Tree_Clear(Tree* tr) {
    if (tr != NULL) {
        if (tr->left != NULL)
            Tree_Clear(tr->left);
        if (tr->right != NULL)
            Tree_Clear(tr->right);
        if (tr->center != NULL)
            Tree_Clear(tr->center);
        free(tr);
    }
}

//высота дерева
unsigned int Tree_Height(const Tree* tr) {
    unsigned int l, r, p;
    if (tr != NULL) {
        l = (tr->left != NULL) ? Tree_Height(tr->left) : 0;
        r = (tr->right != NULL) ? Tree_Height(tr->right) : 0;
        p = (tr->center != NULL) ? Tree_Height(tr->center) : 0;

        if (l >= r && l >= p) return l+1;
        if (r >= l && r >= p) return r+1;      
        return p+1;
    }
    return 0;
}