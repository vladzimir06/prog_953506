#define NMAX 100
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//Считываем сумму кодов слова.
int getCode(char word[])
{
    int result = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        result += (int)word[i];
    }
    return result;
}

//Сам стек.
typedef struct Stack
{
    char elem[NMAX][NMAX];
    int top;
}stack;

//Инициализация пустого стека.
void init(stack *stk)
{
    stk -> top = 0;
}

//Добавляем элемент.
void push(stack *stk, char word[])
{
    if(stk -> top < NMAX)
    {
        strcpy_s(stk -> elem[stk -> top], strlen(stk -> elem[stk -> top]), word);
        stk -> top++;
    }
    else
        printf("The stack is full!");
}

//Удаляем элемент.
void pop(stack *stk)
{
    if(stk -> top > 0)
    {
        stk -> top--;
    }
    else
        printf("The stack is empty!");
}

//Получаем элемент с верхушки стека.
char* getTop(stack *stk)
{
    if((stk -> top) > 0) {
        return stk -> elem[stk -> top - 1];
    } else {
        printf("The stack is empty!\n");
        return 0;
    }
}

//Все число элементов стека.
int getCount(stack *stk)
{
    return stk -> top;
}

//Дерево.
typedef struct TNode
{
    char field[NMAX];
    struct tnode *left;
    struct tnode *right;
}tnode;

//Добавление элемента в дерево.
tnode * AddNode(char string[], tnode *tree) {
    if (tree == NULL)                                                               // Если дерева нет, то формируем корень.
    {
        tree = (tnode*)malloc(sizeof(tnode));                                       //Выделяем память под дерево.
        strcpy_s(tree -> field, strlen(tree -> field), string);                     //Закидываем переданную строку в поле.
        tree->left =  NULL;
        tree->right = NULL;                                                         //Ветви инициализируем пустотой.
    }
    else if (getCode(string) < getCode(tree->field))                                //В зависимости от суммы кодов строки,
        tree->left = AddNode(string, tree-> left);                                  //элементы распределяются по возрастанию.
    else    // условие добавление правого потомка
        tree->right = AddNode(string,tree -> right);
    return(tree);
}

//Удаление поддерева/всего дерева.
void freeMem(tnode *tree)
{
    if(tree!=NULL)
    {
        freemem(tree->left);
        freemem(tree->right);
        free(tree);
    }
}

//Обходим дерево, если сумма кодов строки четная, выводим ее и закидываем в стек.
void treePush(tnode *tree, stack *stk)
{
    if (tree != NULL)                                //Пока не встретится пустой узел
    {
        if((getCode(tree -> field) % 2) == 0)
        {
            puts(tree -> field);
            push(stk, tree -> field);
        }
        treePush(tree -> left, stk);                //Рекурсивная функция для левого поддерева
        treePush(tree -> right, stk);               //Рекурсивная функция для правого поддерева
    }
}

int main()
{
    int amount;
    char word[NMAX];
    printf("How many words would you like to enter?");
    scanf_s("%d", &amount);

    //Создание стека и дерева.
    stack *words = (stack*)(malloc(sizeof(stack)));
    init(words);
    tnode *myTree;

    //Строим дерево на основе слов, введенных пользователей.
    for(int i = 0; i < amount; i++)
    {
        gets_s(word, NMAX);
        AddNode(word, myTree);
    }

    treePush(myTree, words);
	freeMem(myTree);
	
}
