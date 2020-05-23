#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <alloc.h>


#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#define SIZE 128
const char FILE_IN[] = "c:\\Users\\Владимир\\Desktop\\file_in.txt";
const char FILE_OUT[] = "c:\\Users\\Владимир\\Desktop\\file_out.txt";

#include "Unit1.h"
#include "Unit2.h"
extern List lst;

int _tmain()
{
	FILE *fin, *fout;
	char ch, buffer[SIZE];
	double price;

	fin = fopen(FILE_IN, "r");
	fout = fopen (FILE_OUT, "w");
	MyList_Initialize();
	if(!fin || !fout)
	{
		printf("File is not open! ");
		exit(1);
	}

	while (fgets(buffer, SIZE, fin) != NULL)
	{
		MyList_Add(buffer);
	}
	MyList_Show();
	printf("\n");

	price = Dialog(fout);
    printf("\n");

	MyList_Clear();
	fclose(fin);
	fclose(fout);
	system ("pause");
	return 0;
}
