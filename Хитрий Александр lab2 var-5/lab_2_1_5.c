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

void menu()
{
 printf("Меню: для обращения введите\n1 - Заказ картофеля \n2 - Заказ моркови \n3 - Заказ свеклы\n");
 printf("4 - вывод размера заказанных овощец\n5- вывод общей стоимости \n6 - информация о магазинк \n7 - выход из программы\n(если вы введете что-либо другое, программа завершится)\n(читается только первый символ!!!Все остальное просто стирается)\n ");
}

//требуется ввести два числа, первое - числитель, второе -  знаменатель
void vvodPotato(float* potato)
{
char c;
system("cls");
	  printf("Введите массу заказываемого картофеля\t");
	  if(scanf("%f",potato)!=1||(c=getchar())!='\n'||*potato<0)
	  {
		  printf("Неверный ввод");
		  fflush (stdin);
          	  getch();
		  return;
	  }
}

void vvodMorkov(float* morkov)
{
char c;
system("cls");
	  printf("Введите массу заказываемой моркови\t");
	  if(scanf("%f",morkov)!=1||(c=getchar())!='\n'||*morkov<0)
	  {
		  printf("Неверный ввод");
		  fflush (stdin);
          	  getch();
		  return;
	  }
}

void vvodSvekla(float* svekla)
{
char c;
system("cls");
	  printf("Введите массу заказываемой моркови\t");
	  if(scanf("%f",svekla)!=1||(c=getchar())!='\n'||*svekla<0)
	  {
		  printf("Неверный ввод");
		  fflush (stdin);
          	  getch();
		  return;
	  }
}

void vyvodRazmer(float* potato,float* morkov,float* svekla)
{
system("cls");
printf("Масса картофеля = %f кг,его стоимость равна %d р.\n Масса моркови = %f кг,ее стоимость равна %d р.\n Масса свеклы равна %f кг,ее стоимость равна %d р.\n",*potato,(int)(500*(*potato)),*morkov,(int)(1000*(*morkov)),*svekla,(int)((*svekla)*700));
getch();
}


void vyvodDengi(float* potato,float* morkov,float* svekla)
{
system("cls");
printf("Масса картофеля = %f кг,его стоимость равна %d р.\n Масса моркови = %f кг,ее стоимость равна %d р.\n Масса свеклы равна %f кг,ее стоимость равна %d р.\n",*potato,(int)(500*(*potato)),*morkov,(int)(1000*(*morkov)),*svekla,(int)((*svekla)*700));
printf("Доставка стоит 15.000 рублей\n");
float sum=*potato+*morkov+*svekla;
float skidka=1;
if(sum>10&&sum<25)
skidka=0.9;
else if(sum>=25&&sum<50)
skidka=0.79;
else if(sum>=50)
skidka=0.7;
printf("Скидка равна %d\n",(int)(100-100*skidka));
printf("Стоимость заказа равна %d\n",(int)((500*(*potato)+1000*(*morkov)+700*(*svekla)+15000)*(skidka+0.01)));
getch();
}


void vers()
{
system("cls");
	printf("Все ясно, Автору 10 лет");
	getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 int a=1;
 char r;
 float potato=0;
 float morkov=0;
 float svekla=0;

 while(a==1)
 {
 system("cls");
 menu();
 fflush (stdin);
 r=getchar();
 fflush (stdin);
 switch(r)
	{
 	case '1': vvodPotato(&potato); break;
 	case '2': vvodMorkov(&morkov); break;
 	case '3': vvodSvekla(&svekla); break;
 	case '4': vyvodRazmer(&potato,&morkov,&svekla); break;
 	case '5': vyvodDengi(&potato,&morkov,&svekla); break;
 	case '6': vers(); break;
 	case '7':a=0; break;
 	default: printf("Неверный ввод,нечего программу ломать"); getch(); a = 0;
 	}
}
return 0;
}
