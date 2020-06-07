#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "Unit1.h"

int _tmain()
{

    int arr[] = { 10, 12, 8, 9, 7, 3, 4 };
    Node* root = Create(arr, 7);// создаем список из массива

    printf("\n------ 1 tree -------\n");
    Print(root, 0); //дерево
    PrintTree(root, "root", 0); //подробная информация о дереве

    Node* copyroot = NULL;
    copyroot = CopyOf(root);
    printf("\n----- 2 tree -------\n");
    PrintTree(copyroot, "root", 0);

    printf("----- Compare (1, 2): %d -------\n", Compare(copyroot, root));  // 1 = true, 0 = false
    int arr2[] = { 4, 1, 15, 9, 21, 5, 8 };
    Node* root2 = Create(arr2, 7);

    printf("\n----- 3 tree -------\n");//Вывод
    Print(root2, 0);
    PrintTree(root2, "root", 0);

    printf("----- Compare (1, 3): %d -------\n", Compare(root2, root)); // 1 = true, 0 = false
    Free(root);// освобождение памяти
    Free(copyroot);
    Free(root2);
    system("pause");
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
