#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#define N 12  /* количество символов в строке */

//------------------- ƒубровский  онстантин гр.953506 --------------------
//-------------------          Ћ.–.є4 (вар.13)       ---------------------
//  4.2(13):  “екст в файле содержит числа, которые записаны в восьмеричной
//			 системе счислени€. ѕреобразовать эти числа в дес€тичную систему
//			 счислени€ и записать отредактированный текст обратно в файл.
//------------------------------------------------------------------------

void IntToSrt(int n, char *str);
int MyFoo(char *str);

int _tmain()
{
	char buffer[N];
	FILE *fin, *fout;   // указатель на файл

	fin = fopen("C:\\work\\prog\\laba4\\file_in.txt", "r"); // открыть файл file_in.txt
	fout = fopen("C:\\work\\prog\\laba4\\file_out.txt", "w"); // открыть файл file_out.txt
	if (!fin || !fout)  // если файл не найден Ц выход
	{
		printf("file is not open! :( \n");
        getch();
		exit(1);
	}
	printf("num8 = num10\n------------------\n");
	// считываем данные из файла в buffer построчно
	while (fgets(buffer, N, fin) != NULL)
	{
		char num10[N] = "\0";
		int n = 0;

		n = MyFoo(buffer); //преобразует восмирич. число строкового типа в дес€тич. число типа int		
		// Bывод на экран:
		printf("num8: ");
		puts(buffer);  
		printf("num10: %d\n------------------\n", n);

		IntToSrt(n, num10); //число в строку

		fputs(num10, fout); //вывод в файл
	}

	fclose(fin); /* закрыть файлы */
	fclose(fout);

    system ("pause");
	return 0;
}

int MyFoo(char *str)
{
	int len = 0, n = 0; 
	bool minus = false;
	
	while(str[len] != '\n')
	{
		if (str[len] == '-') minus = true; //дл€ отрицательных чисел
		len++; //определ€ем длину строки
	}

	if(!minus) //дл€ положительных чисел
	{
		int i = 0;
		
		while(i < len)
		{
			n += (str[i] - '0') * pow(8, len - i - 1);  //по ф-ле перевода из 8-чн. в 10-чн. сист. сч.
			i++;	
		}
	}
	else //дл€ отрицательных чисел
	{
		int i = 1;
		
		while(i < len)
		{
			n += (str[i] - '0') * pow(8, len - i - 1);  //по ф-ле перевода из 8-чн. в 10-чн. сист. сч.
			i++;	
		}
		n *= -1; //добавить знак минуса	
	}
	return n;
}

void IntToSrt(int n, char *str)
{
	char strrev[N]; //содержит число задом-наперед
	int len = 0; //длина числа n в символах               
	bool minus = false;        

	if(n < 0) //если n отрицательное
	{
		minus = true; //запоминаем минус
		n *= -1;  //возвращаем n положительное значение
	}
	
	while(n >= 10)
	{
		char ch = '0' + n % 10;
		strrev[len] = ch;
		n /= 10;
		len++;
	}  	
	strrev[len] = '0' + n;

	if(!minus) //дл€ положительных
	{
		int i = 0, j = len;

		while(j >= 0)
		{
			str[i] = strrev[j];  //реверсируем строку
			i++;
			j--;	
		}
		str[len + 1] = '\n';
	}
	else //дл€ отрицательных
	{
		int i = 1, j = len;
		
		str[0] = '-';
		while(j >= 0)
		{
			str[i] = strrev[j];  //реверсируем строку 
			i++;
			j--;	
		}
		str[len + 2] = '\n';
	}	
}
