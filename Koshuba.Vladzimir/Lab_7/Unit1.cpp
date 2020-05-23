//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <stdlib.h>
#include <stdio.h>
#include <alloc.h>
#include <string.h>
#include "Unit1.h"

#define SIZE 128

 List lst;
 void MyList_Initialize() //типо Конструктор
 {
	lst.Head = NULL;
	lst.Tail = NULL;
	lst.length = 0;
 }

void MyList_Clear() //типо Деструктор
 {
	 while (lst.Head)
     {
		 lst.Tail = lst.Head->Next;
		 free(lst.Head);
		 lst.length--;
		 lst.Head = lst.Tail;
	 }
 }

 void MyList_Add(char x[SIZE])
 {
   char * str;
   Node *temp = (Node*)malloc(sizeof(Node));
   temp->Next = NULL;
   strcpy(temp->x, x);
   str = strtok (x, " \n");
   strcpy(temp->code, str);
   str = strtok(NULL, " \n");
   strcpy(temp->name, str);
   str = strtok(NULL, " \n");
   temp->price = atof(str);
   temp->count = 0;

   if (lst.Head != NULL) //Если список не пуст
   {
	   temp->Prev = lst.Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
	   lst.Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
	   lst.Tail = temp;                     //Меняем адрес хвоста
   }
   else //Если список пустой
   {
	   temp->Prev = NULL;
	   lst.Head = lst.Tail = temp;
   }
   lst.length++;
 }

 void MyList_Show()
 {
	 Node *temp = lst.Head;
	  while (temp != NULL)
     {
		 printf("%s", temp->x);
		 temp = temp->Next;
	 }
 }
