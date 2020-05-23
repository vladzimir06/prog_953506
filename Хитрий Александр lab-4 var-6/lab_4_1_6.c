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

int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
printf("введите текст на английском, а я выведу слова, буквы которых стоят в алфавитном порядке\n");
char str[40];
char prover='1';
char prevChar=0;
int i=0;
_Bool bol=1;

while((prover=getchar())!='\n')
{
//проверка на заглавные буквы
  if(prover>='A'&&prover<='Z')
  prover+=32;

//проверка на алфавитный порядок
  if(prover>='a'&&prover<='z'&&prover>=prevChar&&i<40)
  {
	  prevChar=prover;
	  str[i]=prevChar;
	  ++i;

  }
//провека на знаки препинания
  else if((prover>=' '&&prover<=47)||(prover>=91&&prover<96))
  {
	if(i!=0)
	{prevChar=0;
	str[i]=0;
	puts(str);
	i=0;
	bol=0;
	}
  }
//проверка на неалфавитный порядок
   else if(prevChar>prover) {
		prevChar=0;
		i=0;
		str[0]=0;
		//избавление от ненужных уже в проверке слов
		for(;;)
		if((prover=getchar())<'a')
		{
			if(prover=='\n')
			{
				getch();
				return 0;
			}
			break;
		}
		}
		//проверка на все остальное
  else
  {
	prevChar=0;
	str[0]=0;
	i=0;
    		for(;;)
		if((prover=getchar())<'a')
		{
			if(prover=='\n')
			{
				getch();
				return 0;
			}
			break;
		}
  }
}
if(bol==1)
printf("Нет слов, идуших по алфавиту");
	getch();
	return 0;
}
