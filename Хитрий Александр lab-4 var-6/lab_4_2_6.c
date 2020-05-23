#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//циклический сдвиг строки из файла на п букв
void smen(int razmer,char fail[j])
{
	char smen=fail[0];
	char smen2;
	for(int i=0;i<razmer;++i)
	{
    if(i==razmer-1)
	{fail[0]=smen;return;}
	smen2=fail[i+1];
	fail[i+1]=smen;
	smen=smen2;
	}
}


int _tmain(int argc, _TCHAR* argv[]) 
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
FILE *fp;

if((fp=fopen("E:\\text.txt","r"))==NULL)
{
	printf("Ошибка при открытии файла для чтения");
	getch();
	exit(EXIT_FAILURE);
}
// поиск кол-ва букв в файле
 char ch=getc(fp);
 int razmer=0;
 char aa;
 while(ch!=EOF)
 {
++razmer;
ch=getc(fp);
 }
fseek(fp,0L,SEEK_SET);
int sdvig;

char fail[razmer];
for(int i=0;i<razmer;++i)
fail[i]=getc(fp);

printf("Имеющийся файл:");
puts(fail);

printf("На сколько Вы хотите сдвинуть файл вправо? На  ");
if((scanf("%d",&sdvig)!=1&&razmer>sdvig)||(aa=getchar())!='\n')
{
	printf("Ошибка при вводе");
	getch();
	return 0;
}


fseek(fp,0L,SEEK_SET);

for(int i=0;i<sdvig;++i)
smen(razmer,fail);
if(fclose(fp)!=0)
printf("Ошибка при закрытии файла для чтения");

if((fp=fopen("E:\\text.txt","w"))==NULL)
{
	printf("Ошибка при открытии файла для записи");
	getch();
	exit(EXIT_FAILURE);
}

fprintf(fp,"%s",fail);
printf("Получившийся файл:");
puts(fail);

if(fclose(fp)!=0)
printf("Ошибка при закрытии файла для записи");



	getch();
	return 0;
}
