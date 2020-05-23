#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

//------------------- Дубровский Константин гр.953506 --------------------
//-------------------          Л.Р.№4 (вар.13)       ---------------------
//  4.1(13):  Ввести с клавиатуры натуральное число n <= 1000 и символ, указывающий падеж.
//			  Вывести на экран введенное число русскими словами в заданном падеже.
//------------------------------------------------------------------------

void Proverka (int *n, char *ch); //проверка правильности ввода числа и падежа
void Tysiachi(int *n, char *ch);  // склоняем 1000
void Edinici(int *n, char *ch);  //склоняем единицы
void Sotni(int *n, char *ch);  //склоняем сотни
void Desiatki(int *n, char *ch); //склоняем десятки
void Desiatki_alternativ(int *n, char *ch); //склоняем 10,11,12...19

int _tmain()
{
	SetConsoleCP(1251); 		// Включаем русские буквы
	SetConsoleOutputCP(1251); 	//

	int n = 0; //вводимое число
	char ch; //падеж
	int sotni = 0, desiatki = 0, edinici = 0; // Переменные для хранения сотен, десятков и едениц числа n

	printf("Введите с клавиатуры натуральное число n <= 1000\n");
	scanf(" %d", &n);  //Ввод n
	printf("Введите с клавиатуры символ, указывающий падеж (русской прописной(заглавной) буквой\n");
	scanf(" %c", &ch); //Ввод ch
	Proverka(&n, &ch); //проверка правильности ввода числа и падежа
	printf("\nЧисло: %d, Падеж: %c(для неодуш.)\n", n, ch);
	if(ch == 'П')printf("(о) ");

	if(n == 1000) Tysiachi(&n, &ch); //в случае n = 1000
	else
	{
		edinici = n % 10;  //единицы
		n /= 10;
		desiatki = n % 10;  //десятки
		n /= 10;
		sotni = n % 10; //сотни
	}
	//В остальных случаях:
	if(sotni)
	{
		Sotni(&sotni, &ch);  //выводим сотни
		printf(" ");
	}
	if(desiatki)
	{
		if(desiatki == 1) //если 10,11,12...19
        {
			int x = desiatki * 10 + edinici;

			Desiatki_alternativ(&x, &ch); //выводим [10,19]
			printf(" ");
		}
		else
		{
			Desiatki(&desiatki, &ch); //выводим десятки
			printf(" ");
		}
	}
	if(edinici && desiatki != 1)  //если не 10,11...19
	{
		Edinici(&edinici, &ch); //выводим единицы
		printf(" ");
	}
	//Добавим для удобства существительное:
	if(edinici != 1 || desiatki == 1)
		switch(ch)
		{
			case 'И': printf("(стульев)\n"); break;
			case 'Р': printf("(стульев)\n"); break;
			case 'Д': printf("(стульям)\n"); break;
			case 'В': printf("(стульев)\n"); break;
			case 'Т': printf("(стульями)\n"); break;
			case 'П': printf("(стульях)\n"); break;
		}
	else
		switch(ch)
		{
			case 'И': printf("(стул)\n"); break;
			case 'Р': printf("(стула)\n"); break;
			case 'Д': printf("(стулу)\n"); break;
			case 'В': printf("(стул)\n"); break;
			case 'Т': printf("(стулом)\n"); break;
			case 'П': printf("(стуле)\n"); break;
		}

	system("pause");
	return 0;
}

void Proverka (int *n, char *ch) //проверка правильности ввода числа и падежа
{
    char paderzi[] = "ИРДВТП";  // Строка содержащая все падежи
	bool paderz = false; // Совпадение падежа

	//Проверка падежа ch
	for(int i = 0; i < 6; i++)
	{
		if(*ch == paderzi[i])
		{
			paderz = true;   // Как только нашли совпадение по падежам - break
			break;
		}
	}
	if(!paderz)
	{
		printf("Т.к. при вводе падежа была допущена ошибка, дальнейший вывод будет в Именительном падеже (И)\n");
		*ch = 'И';
	}
	//Проверка числа n
	if(*n <= 0)
	{
		printf("Т.к. введенное число не является натуральным, ему было присвоено минимальное возможное значение (1)\n");
		*n = 1; // присвоим минимально возможное (1)
	}
	else if(*n > 1000)
	{
		printf("Т.к. введенное число n > 1000, ему было присвоено максимальное возможное значение (1000)\n");
		*n = 1000; // присвоим максимально возможное (1000)
	}
}

void Tysiachi(int *n, char *ch)
{
	printf("%d в (%c) падеже:\n", *n, *ch);
	switch(*ch)
	{
		case 'И': printf("тысяча"); return;
		case 'Р': printf("тысячи"); return;
		case 'Д': printf("тысяче"); return;
		case 'В': printf("тысячу"); return;
		case 'Т': printf("тысячей"); return;
		case 'П': printf("тысяче"); return;
	}
}

void Edinici(int *n, char *ch)
{
	switch(*n)
	{
		case 1: switch(*ch)
				{
					case 'И': printf("один"); return;
					case 'Р': printf("одного"); return;
					case 'Д': printf("одному"); return;
					case 'В': printf("один"); return;
					case 'Т': printf("одним"); return;
					case 'П': printf("одном"); return;
				}
		case 2: switch(*ch)
				{
					case 'И': printf("два"); return;
					case 'Р': printf("двух"); return;
					case 'Д': printf("двум"); return;
					case 'В': printf("два"); return;
					case 'Т': printf("двумя"); return;
					case 'П': printf("двух"); return;
				}
		case 3: switch(*ch)
				{
					case 'И': printf("три"); return;
					case 'Р': printf("трех"); return;
					case 'Д': printf("трем"); return;
					case 'В': printf("три"); return;
					case 'Т': printf("тремя"); return;
					case 'П': printf("трех"); return;
				}
		case 4: switch(*ch)
				{
					case 'И': printf("четыре"); return;
					case 'Р': printf("четырех"); return;
					case 'Д': printf("четырем"); return;
					case 'В': printf("четыре"); return;
					case 'Т': printf("четырьмя"); return;
					case 'П': printf("четырех"); return;
				}
		case 5: switch(*ch)
				{
					case 'И': printf("пять"); return;
					case 'Р': printf("пяти"); return;
					case 'Д': printf("пяти"); return;
					case 'В': printf("пять"); return;
					case 'Т': printf("пятью"); return;
					case 'П': printf("пяти"); return;
				}
		case 6: switch(*ch)
				{
					case 'И': printf("шесть"); return;
					case 'Р': printf("шести"); return;
					case 'Д': printf("шести"); return;
					case 'В': printf("шесть"); return;
					case 'Т': printf("шестью"); return;
					case 'П': printf("шести"); return;
				}
		case 7: switch(*ch)
				{
					case 'И': printf("семь"); return;
					case 'Р': printf("семи"); return;
					case 'Д': printf("семи"); return;
					case 'В': printf("семь"); return;
					case 'Т': printf("семью"); return;
					case 'П': printf("семи"); return;
				}
		case 8: switch(*ch)
				{
					case 'И': printf("восемь"); return;
					case 'Р': printf("восьми"); return;
					case 'Д': printf("восьми"); return;
					case 'В': printf("восемь"); return;
					case 'Т': printf("восьемью"); return;
					case 'П': printf("восьми"); return;
				}
		case 9: switch(*ch)
				{
					case 'И': printf("девять"); return;
					case 'Р': printf("девяти"); return;
					case 'Д': printf("девяти"); return;
					case 'В': printf("девять"); return;
					case 'Т': printf("девятью"); return;
					case 'П': printf("девяти"); return;
				}
	}
}

void Sotni(int *n, char *ch)
{
	switch(*n)
	{
		case 1: switch(*ch)
				{
					case 'И': printf("сто"); return;
					case 'Р': printf("ста"); return;
					case 'Д': printf("ста"); return;
					case 'В': printf("сто"); return;
					case 'Т': printf("ста"); return;
					case 'П': printf("ста"); return;
				}
		case 2: switch(*ch)
				{
					case 'И': printf("двести"); return;
					case 'В': printf("двести"); return;
				}
		case 3: switch(*ch)
				{
					case 'И': printf("триста"); return;
					case 'В': printf("триста"); return;
				}
		case 4: switch(*ch)
				{
					case 'И': printf("четыреста"); return;
					case 'В': printf("четыреста"); return;
				}
		default:
		{
			Edinici(n, ch);
			switch(*ch)
				{
					case 'И': printf("сот"); return;
					case 'Р': printf("сот"); return;
					case 'Д': printf("стам"); return;
					case 'В': printf("сот"); return;
					case 'Т': printf("стами"); return;
					case 'П': printf("стах"); return;
				}
		}
	}
}

void Desiatki(int *n, char *ch)
{
	switch(*n)
	{
		case 1: switch(*ch)
				{
					case 'И': printf("десять"); return;
					case 'Р': printf("десяти"); return;
					case 'Д': printf("десяти"); return;
					case 'В': printf("десять"); return;
					case 'Т': printf("десятью"); return;
					case 'П': printf("десяти"); return;
				}
		case 2: switch(*ch)
				{
					case 'И': printf("двадцать"); return;
					case 'Р': printf("двадцати"); return;
					case 'Д': printf("двадцати"); return;
					case 'В': printf("двадцать"); return;
					case 'Т': printf("двадцатью"); return;
					case 'П': printf("двадцати"); return;
				}
		case 3: switch(*ch)
				{
					case 'И': printf("тридцать"); return;
					case 'Р': printf("тридцати"); return;
					case 'Д': printf("тридцати"); return;
					case 'В': printf("тридцать"); return;
					case 'Т': printf("тридцатью"); return;
					case 'П': printf("тридцати"); return;
				}
		case 4: switch(*ch)
				{
					case 'И': printf("сорок"); return;
					case 'Р': printf("сорока"); return;
					case 'Д': printf("сорока"); return;
					case 'В': printf("сорок"); return;
					case 'Т': printf("сорока"); return;
					case 'П': printf("сорока"); return;
				}
		case 9: switch(*ch)
				{
					case 'И': printf("девяносто"); return;
					case 'Р': printf("девяноста"); return;
					case 'Д': printf("девяноста"); return;
					case 'В': printf("девяносто"); return;
					case 'Т': printf("девяноста"); return;
					case 'П': printf("девяноста"); return;
				}
		default:
		{
			Edinici(n, ch);
			switch(*ch)
				{
					case 'И': printf("десят"); return;
					case 'Р': printf("десяти"); return;
					case 'Д': printf("десяти"); return;
					case 'В': printf("десят"); return;
					case 'Т': printf("десятью"); return;
					case 'П': printf("десяти"); return;
				}
		}
	}
}

void Desiatki_alternativ(int *n, char *ch)
{
    switch(*n)
	{
		case 10: switch(*ch)
				{
					case 'И': printf("десять"); return;
					case 'Р': printf("десяти"); return;
					case 'Д': printf("десяти"); return;
					case 'В': printf("десять"); return;
					case 'Т': printf("десятью"); return;
					case 'П': printf("десяти"); return;
				}
		case 11: printf("один"); break;
		case 12: printf("две"); break;
		case 13: printf("три"); break;
		case 14: printf("четыр"); break;
		case 15: printf("пят"); break;
		case 16: printf("шест"); break;
		case 17: printf("сем"); break;
		case 18: printf("восем"); break;
		case 19: printf("девят"); break;
	}
    switch(*ch)
	{
		case 'И': printf("надцать"); return;
		case 'Р': printf("надцати"); return;
		case 'Д': printf("надцати"); return;
		case 'В': printf("надцать"); return;
		case 'Т': printf("надцатью"); return;
		case 'П': printf("надцати"); return;
	}
}
