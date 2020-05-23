#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

void clrscr();
void scantime(int*, int*, int*, int*, int*, int*);
void scanmembers(int*);
void timeprojects(int, int, int, int, int*, int*, int, int);
void trudoemkost(int, int, int*);
void financial_parameters(int* , int*, int, int, int);
void fullprofit(int, int);
void author(void);

int main()
{
	setlocale(LC_ALL, "Rus");

	int day_start=0, month_start=0, year_start=0;
	int day_end=0, month_end=0, year_end=0;
	int calendar_days=0, work_days=0;
	int number_of_developers=0;
	int hours = 0;
	int total_cost=0, sum_of_salarys, cost, profit=0;
	int a, x=0;


	while (true)
	{
		clrscr();
		printf("1.Ввод даты начала и даты окончания проекта\n2.Ввод количества разработчиков\n3.Вывод длительности проекта\n4.Расчет трудоемкости проекта\n5.Расчет финансовых параметров\n6.целесообразности принятия проекта\n7.Информация о версии и авторе программы\n8.Выход из программы\n");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:		
			clrscr();
			scantime(&day_start, &month_start, &year_start, &day_end, &month_end, &year_end);
			clrscr();

		case 2:		
			clrscr();
			scanmembers(&number_of_developers);
				break;

		case 3:		
			clrscr();
			timeprojects(year_start, year_end, month_start, month_end, &calendar_days, &work_days, day_start, day_end);
			printf("\nНажмите 1 чтобы перейти в меню\n");
			scanf_s("%d",&x);
			if (x == 1)
			{
				break;
			}
					
		case 4:		
			clrscr();
			trudoemkost(number_of_developers, work_days, &hours); 
			printf("\nНажмите 1 чтобы перейти в меню\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}

		case 5:		
			clrscr();
			financial_parameters(&total_cost, &profit, number_of_developers, calendar_days, hours);
			printf("\nНажмите 1 чтобы перейти в меню\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}

		case 6:		
			clrscr();
			fullprofit(profit, total_cost);
			printf("\nНажмите 1 чтобы перейти в меню\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}

		case 7:		
			clrscr();
			author();
			printf("\nНажмите 1 чтобы перейти в меню\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}
		}
		if (a == 8)
			break;
	}
}

void clrscr()
{
	system("@cls||clear");
}


void scantime(int* d_s, int* m_s, int* y_s, int* d_e, int* m_e, int* y_e)
{
	printf("Введите дату начала проекта: ");
	scanf_s("%d.", d_s);
	scanf_s("%d.", m_s);
	scanf_s("%d", y_s);

	printf("Введите дату окончания проекта: ");
	scanf_s("%d.", d_e);
	scanf_s("%d.", m_e);
	scanf_s("%d", y_e);
}


void scanmembers(int* develop)
{
	printf("Введите кол-во разработчиков: ");
	scanf_s("%d", develop);
}


void timeprojects(int year_start, int year_end, int month_start, int month_end, int* calendar_days, int* work_days, int day_start, int day_end)
{
	int day = 0, month = 0, year = 0;
	int Calendardays = 0, workdays = 0;


	if (year_start == year_end)
	{

		day = abs(day_start - day_end);
		month = abs(month_start - month_end);
		Calendardays = day + month * 30;
		workdays = (Calendardays / 7) * 5 + Calendardays % 7;
	}

	if (abs(year_start - year_end) == 1)
	{
		day = abs(day_start - day_end);
		month = (-1) * month_start + month_end + 12;
		Calendardays = day + month * 30;
		workdays = (Calendardays / 7) * 5 + Calendardays % 7;
	}

	if (abs(year_start - year_end) > 1)
	{
		day = abs(day_start - day_end);
		month = -month_start + month_end + 12;
		year = abs(year_start - year_end);
		Calendardays = day + month * 30 + (year - 1) * 12 * 30;
		workdays = (Calendardays / 7) * 5 + Calendardays % 7;
	}
	*calendar_days = Calendardays;
	*work_days = workdays;
	printf("\nкалендарные дни: %d\nрабочие дни: %d\n", *calendar_days, *work_days);

}


void trudoemkost(int number_of_developers, int work_days, int* hours)
{
	int  man_hours, man_days, all_time;
	all_time = work_days * 8;
	man_hours = number_of_developers * all_time;
	man_days = number_of_developers * work_days;
	*hours = all_time;
	printf("\nкол-во человеко-дней: %d\nкол-во человеко-часов: %d\n", man_days, man_hours);
}


void financial_parameters(int* total_cost, int* profit, int number_of_developers, int calendar_days, int hours)
{

	int sum_of_salarys, cost, profit_, totalcost;
	sum_of_salarys = number_of_developers * 400 * calendar_days / 30;
	cost = sum_of_salarys * 2, 5;
	profit_ = hours * number_of_developers * 9;
	totalcost = sum_of_salarys + cost;
	*profit = profit_;
	*total_cost = totalcost;
	printf("Общая стоимость проекта: %d\nсумма зарплаты программистам: %d\nнакладные расходы: %d\nприбыль компании: %d\n", *total_cost, sum_of_salarys, cost, *profit);
}

void fullprofit(int profit, int total_cost)
{
	int net_profit;
	net_profit = profit - total_cost;
	if (net_profit > 1000)
	{
		printf("чистая прибыль компании: %d\nпроект считается целесообразным\n", net_profit);
	}
	else
	{
		printf("чистая прибыль компании: %d\nпроект считается нецелесообразным\n", net_profit);

	}
}

void author(void)
{
	printf("автор: Матийко С.В\nномер группы: 953506\n");
}