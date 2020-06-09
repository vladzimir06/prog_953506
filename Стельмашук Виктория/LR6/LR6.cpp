//Задание 5.2(14) Стельмашук В.А.(гр. №953506)

/*В текстовом файле содержится произвольный текст. Построить на
его основе бинарное дерево поиска, каждый узел которого
содержит слово. Вывести из дерева на печать слова, начинающиеся
и заканчивающиеся на одну и ту же букву, упорядочив их по
алфавиту. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

/* Структура, описывающая узел дерева */
struct tree_node
{
    char word[100];
    struct tree_node* left;
    struct tree_node* right;
};

void treeremove(tree_node* root); 
struct tree_node* Add(struct tree_node* root, char* word);
int Check_Word(char* word);
void Find(struct tree_node** Tree_1, struct tree_node** Tree_2);
void Print_Tree(struct tree_node* tree);

int main()
{
    struct tree_node* root = NULL;
    char word[100];
    FILE* file;
    if (fopen_s(&file, "C:\\Лабораторные С\\LR6\\text.txt", "r"))
    {
        printf("\nError.");
        char c = getchar();
        exit(-1);
    }
    while (fgets(word, 20, file))
    {
        root = Add(root, word);
    }
    fclose(file);
    struct tree_node* Sorted_words = NULL;
    Find(&root, &Sorted_words);
    printf("Words begin and end with the same letter:\n\n");
    Print_Tree(Sorted_words);
    treeremove(root);
    return 0;
}

/* Добавить узел в бинарное дерево поиска */
struct tree_node* Add(struct tree_node* root, char* word) 
{
    int temp;
    if (!root) 
    {
        if (!(root = (struct tree_node*)malloc(sizeof(struct tree_node)))) 
        {
            printf("Error with memory allocation");
        }
        else {
            root->left = root->right = NULL;
            strcpy_s(root->word, word);
        }
    }
    else if ((temp = strcmp(word, root->word)) < 0) 
    {
        root->left = Add(root->left, word);
    }
    else 
    {
        root->right = Add(root->right, word);
    }
    return root;
}

/*функция для проверки слов начинающихся и оканчивающихся одной буквой*/
int Check_Word(char* word) 
{
    char first = word[0];
    char last;
    int i;
    for (i = 0; word[i]; i++);
    last = word[i - 2];
    if (last == first) return 1;
    else return 0;
}

/*функция для нахождения слов начинающихся и оканчивающихся одной буквой*/
void Find(struct tree_node** Tree_1, struct tree_node** Tree_2)
{
    if ((*Tree_1) != NULL)
    {
        Find(&(*Tree_1)->left, &(*Tree_2));
        if (Check_Word((*Tree_1)->word)) {
            (*Tree_2) = Add((*Tree_2), (*Tree_1)->word);
        }
        Find(&(*Tree_1)->right, &(*Tree_2));
    }
}

/* Обход дерева слева (вывод по алфавиту))*/
void Print_Tree(struct tree_node* tree) 
{
    if (tree->left)
    {
        Print_Tree(tree->left);
    }
    printf("%s\n", tree->word);
    if (tree->right)
    {
        Print_Tree(tree->right);
    } 
}

void treeremove(tree_node* root)// удаляет дерево
{
    if (root != NULL)
    {
        treeremove(root->left);
        treeremove(root->right);
        free(root);
    }
}
