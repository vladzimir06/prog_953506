#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//узел
typedef struct node
{
int numb;
struct node *lev;
struct node *prav;
struct node *parent;
int size;
} Node;


void siz_e(Node* par)
{
 if(par!=NULL)
  { par->size++;
   return siz_e(par->parent);
  }
  return;
}


Node* createN(Node* par)
{
   Node* tmp=(Node*)malloc(sizeof(Node));
   if(tmp==NULL)
   {
	   printf("Ошибка при создании узла");
	   exit(0);
   }
   tmp->prav=NULL;
   tmp->lev=NULL;
   tmp->parent=par;
   if(par!=NULL&&(par->lev==NULL&&par->prav==NULL))
   siz_e(par);
   tmp->numb=0;
   tmp->size=1;
   return tmp;
}

//проверка при добавлении элемента
Node* sravn(Node* parent, int niw)
{
	if(niw>parent->numb)
	{
	if(parent->prav==NULL)
	parent->prav=createN(parent);
	return parent->prav;
	}
	else if(niw<parent->numb)
	{
	if(parent->lev==NULL)
	parent->lev=createN(parent);
	return parent->lev;
	}
	return NULL;
}

//поиск места создания узла
int vvod(Node* tmp)
{
  int a;
  char aa;
  if(scanf("%d",&a)!=1||((aa=getchar())!='\n'))
  {
	  printf("Ошибка при вводе элемента, программа завершена");
	  return 0;
  }
  if(a==0)
  return 0;

  while(tmp->numb!=0)
  {
  if(tmp->numb==a)
  return 1;
  tmp=sravn(tmp,a);
  }
  tmp->numb=a;
  return 1;
}


//очистка дерева
void deleteN(Node** tmp,Node** clean)
{
	if((*tmp)->lev!=NULL)
	{
	return deleteN(&((*tmp)->lev),clean);
	}
	if((*tmp)->prav!=NULL)
	{
	return deleteN(&((*tmp)->prav),clean);
	}
	(*clean)->parent=(*tmp)->parent;
	free((*tmp));
	(*tmp)=NULL;
	if((*clean)->parent==NULL)
	return;
	return deleteN(&((*clean)->parent),clean);
}

int vybor()
{
int a;
char aa;
lp:printf("Есть несколько ветвей одинаковой длины. По какой пойти?\n 1 - по левой\n -1 - по правой\n ");
fflush (stdin);
	 if(scanf("%d",&a)!=1||((aa=getchar())!='\n')||(a!=1&&a!=-1))
  {
	  fflush (stdin);
	  printf("Ошибка при выборе пути,попробуйте вновь\n");
	  goto lp;
  }
  return a;
}
//поиск суммы самого большого элемента
int sum(Node* par)
{
if(par==NULL)
  {
   return 0;
  }
int a=par->numb;
int b=0;
int c=0;

if(par->size==0)
return a;
if(par->lev==NULL)
b=0;
else b=par->lev->size;
if (par->prav==NULL)
c=0;
else c=par->prav->size;
int vyb=0;
if(b==c&&b!=0&&c!=0)
{
vyb=vybor();
b+=vyb;
}
if(b>c)
	return a+sum(par->lev);
	else   return a+sum(par->prav);
}


int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
	 Node* a;
	 Node* clean;
	 int i=1;
	 a=createN(NULL);
	 clean=createN(NULL);
	 printf("Вводите числа для создания бинарного дерева поиска\n");
	 while(i==1)
	 {
	 i=vvod(a);
	 }
	 printf("\nСумма самой длинной ветви равна %d",sum(a));
	 deleteN(&a,&clean);
	 free(clean);
	 getch();
	return 0;
}
