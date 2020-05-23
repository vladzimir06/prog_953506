#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <malloc.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//---------- Дубровский Константин __ гр.953506 __ Л.Р. №3 __ зад. 3.2(22) -------------------

//      Условие 3.2(22):
//	 	Гидрологами произведена серия замеров по прямой от берега до берега реки Волги
// 		перпендикулярно фарватеру. Получены данные: si – расстояние от левого берега, м;
//	 	hi – глубина реки, м; vi – скорость течения, м/с, i = 1, 2,..., n.
//		Каков расход воды в сечении, т.е. сколько кубометров воды протекает через сечение реки в секунду?
//---------------------------------------------------------------------------------------------

void DataInput (float *s, float *v, float *h, int n)
{
	printf("Enter your data in the table:\n");  //"Введите ваши данные в табилицу:"
	printf("n: \t S(m): \t V(m/s) \t H(m)\n");
	for(int i = 0; i < n; i++)
	{
		int mistake = 0;  //счетчик количества ошибок ввода

		//Заполнение i-той линии таблицы
		printf("%d. \t ", i + 1);
		scanf(" %f", &s[i]);
		printf(" \t ");
		scanf(" %f", &v[i]);
		printf(" \t ");
		scanf(" %f", &h[i]);
		printf("\n");
		//Проверка на неправильный ввод:
		if( (s[i] <= 0) || (s[i] > 40000) ) mistake++;  //если ширина Волги < 0 или > 40 км -- ошибка
		if( (v[i] <= 0) || (v[i] > 2) ) mistake++; //если скорость теч. Волги < 0 или > 7,2 км/ч (2 м/с)
		if( (h[i] <= 0) || (h[i] > 2.5) ) mistake++; //если глубина Волги < 0 или > 2.5 м
		if(mistake != 0)
		{
			printf("A mistake was found in the line. Enter the line again.\n");
			i--; //для возвращения на эту же линию на следующей итерации
		}
	}
}

float Consumption (float s, float v, float h)
{
	return s * h * v;	//расход воды в сечении
}

void DataOutput (float *s, float *v, float *h, int n)
{
	printf("n: \t  S(m): \t V(m/s):\t H(m):\t Water consumption: \n");
	for(int i = 0; i < n; i++)
	{
		float consumption = Consumption(s[i], v[i], h[i]);

		printf("%d. \t %.2f \t %.2f \t\t  %.2f \t\t  %.2f \n", i + 1, s[i], v[i], h[i], consumption);
	}
	printf("\n");
}

int _tmain()
{
	int n = 0;
	float *s, *v, *h;   //переменные названы как в условии

	printf("How many measurements were taken?\n"); // "Сколько измерений проведено?"
	scanf(" %d", &n);
	s = (float*) malloc(n * sizeof(float));  //выделение памяти под массивы
	v = (float*) malloc(n * sizeof(float));
	h = (float*) malloc(n * sizeof(float));
	//Диалог с пользователем:
	while(1)  //бесконеч. цикл (№1)
	{
		char answer;

		DataInput(s, v, h, n); //ввод данных
		while(2) //еще один цикл (№2)
		{
			system("cls");
			DataOutput(s, v, h, n); //вывод данных
			printf("Is everything right in the table?\n");  //диалог с пользователем
			printf("Y - yes, it's ok \nN - no, I want to change something\n");
			scanf(" %c", &answer);
			//при правильном вводе либбо 'y' либо 'n':
			if( (answer == 'y') || (answer == 'n') ) break; //выход из цикла 2 (else цикл бесконечн)
		}
		if(answer == 'y') break; //выход из цикла 1 (else снова на ввод)
		else system("cls");
	}
	//Очистка памяти:
	free(s);
	free(v);
	free(h);
    system("pause");
	return 0;
}
