#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//поиск факториала
int fact(int a)
{
	if(a==0)
	return 1;
	return a*fact(a-1);
}

//поиск числа через формулу
double razl(double* rasch, double *pogresh,double *siin)
{
	double formul=0;
	for(int i=1;i<1000;++i)
	{
	 formul+=pow(-1,i-1)*((powl(*rasch,2*i-1))/(fact(2*i-1)));

	 if(formul>*siin)
	 	{
		if((formul-*siin)<*pogresh)
	 	return formul;
	 	}
	 else
	 	{ 
	 	if((*siin-formul)<*pogresh)
	 	return formul;
	 	}
	}
	return formul;
}

int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

//ввод числа, по которому идет расчет
 double rasch;
 char a;
ln:printf("Введите число, по которому будет идти расчет: ");
if(scanf("%lf",&rasch)!=1||(a=getchar())!='\n')
{
	printf("Неверный ввод,попробуйте снова\n");
	fflush (stdin);
	goto ln;
}
fflush (stdin);
//ввод погрешности в формуле
double pogresh;
li:printf("Введите погрешность: ");
if(scanf("%lf",&pogresh)!=1||(a=getchar())!='\n')
{
	printf("Неверный ввод,попробуйте снова\n");
	fflush (stdin);
	goto li;
}

double siin=sin(rasch);
double formul=razl(&rasch,&pogresh,&siin);
printf("Синус от числа равен %f\n",siin);
printf("Сумма числа по формуле равна%f",formul);
getch();
	return 0;
}
