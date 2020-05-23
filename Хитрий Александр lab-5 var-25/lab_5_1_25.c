#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif




typedef struct stag
{
	int* mass;
	size_t size;
	size_t top;
} Stag;

void menu()
{
system("cls");
 printf("Меню: для обращения введите\n1 - Ввод числа в стек\n2 - Вывод числа из стека с удалением\n3 - вывод числа стека без удаления \n");
 printf("4 - вывод всех чисел стека\n5- Вывод размера стека\n6 - реверс стека\n7 - выход из программы\n(если вы введете что-либо другое, программа завершится)\n(читается только первый символ!!!Все остальное просто стирается)\n ");

}


Stag* createSt()
{
  Stag* out=NULL;
   out = malloc(sizeof(Stag));
	if (out == NULL) {
	printf("Ошибка при создании стека #1");
		exit(0);
	}
	out->size=6;
  out->mass=(int*)malloc(6*sizeof(int));
  if(out->mass==NULL)
  {
	 printf("Ошибка при создании стека #2");
	 exit(0);
  }
  out->top=0;
  return out;
}

void deleteS(Stag **st)
{
	free((*st)->mass);
	free(*st);
	*st=NULL;
	printf("Стек удален");
	getch();
	return;
}
void resize(Stag* st)
{
  st->size+=4;
  st->mass=(int*)realloc(st->mass,st->size*sizeof(int));
  if(st->mass==NULL){
  printf("Ошибка при увеличении емкости стека");
	 exit(0);
  }
}

void push(Stag* st)
{
char aa;
system("cls");
printf("Введите число:");
fflush (stdin);
if(scanf("%d",&st->mass[st->top])!=1||((aa=getchar())!='\n'))
{
	if(st->top==st->size)
	resize(st);
	printf("Неверный ввод");
	fflush (stdin);
	getch();
	return;
}
++st->top;
fflush (stdin);
}

void pop(Stag* st)
{
system("cls");
  if(st->top==0)
  {printf("Стек пуст");
  getch();
  return;}
  --st->top;
  printf("Число в стеке:%d",(int)st->mass[st->top]);
  getch();
}

void peek(Stag* st)
{
  system("cls");
  if(st->top==0)
  {printf("Стек пуст");
  getch();
  return;}
  printf("Число в стеке:%d",(int)st->mass[st->top-1]);
  getch();
}

void cout(Stag* st)
{
system("cls");
if(st->top==0)
  printf("Стек пуст");
   for(int i=0;i<st->top;++i)
   printf("Элемент %d равен %d\n",i,st->mass[i]);
getch();
}
void siz_e(Stag* st)
{
  system("cls");
  printf("Размер стека:%d",st->top);
  getch();
  return;
}

void reverse(Stag *st)
{
system("cls");
	int a;
	for(int i=0;i<(st->top/2);++i)
	{
	a=st->mass[i];
	st->mass[i]=st->mass[st->top-1-i];
	st->mass[st->top-i-1]=a;
	}
	printf("Реверс произведен");
	getch();
	return;
}


int _tmain(int argc, _TCHAR* argv[])
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
	Stag* st=NULL;
	st=createSt();
	int ist=1;
	char ch;
	printf("");
while(ist==1)
{
ist=1;
menu();
fflush (stdin);
gets(&ch);
fflush (stdin);
switch(ch)
{
case '1':{push(st);ist=1;break;}
case '2':{pop(st);ist=1;break;}
case '3':{peek(st);ist=1;break;}
case '4':{cout(st);ist=1;break; }
case '5':{siz_e(st);ist=1;break; }
case '6':{reverse(st);ist=1;break;}
case '7':{ist=0;break;       }
default:{ist=0;break;}
}
}
	deleteS(&st);
	return 0;
}
