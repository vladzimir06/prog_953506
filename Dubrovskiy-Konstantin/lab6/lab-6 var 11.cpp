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

	int arr[] = {10, 12, 8, 9, 7, 3, 4};
	Node *root = Create(arr, 7);

	printf("\n------ 1 tree -------\n");
	Print(root, 0); //pohorze na derevo ( +- shematichno)
	PrintTree(root, "root", 0); //podrobnaya informaciya

	Node *copyroot = NULL;
	copyroot = CopyOf(root);
	printf("\n----- 2 tree -------\n");
	PrintTree(copyroot, "root", 0);

	printf("----- Compare (1, 2): %d -------\n", Compare(copyroot, root));  // 1 = true, 0 = false

	int arr2[] = {4, 1, 15, 9, 21, 5, 8};
	Node *root2 = Create(arr2, 7);

	printf("\n----- 3 tree -------\n");
	Print(root2, 0);
	PrintTree(root2, "root", 0);

	printf("----- Compare (1, 3): %d -------\n", Compare(root2, root)); // 1 = true, 0 = false

	Free(root);
	Free(copyroot);
	Free(root2);
	system("pause");
	return 0;
}
