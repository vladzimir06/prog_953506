#include <stdio.h>
#include <stdlib.h>

void menu();

int valueConnections = 0, valueFloor = 0;
float height=0, width=0, mediumLenght=0;

void setConnections()
{
	printf("\nВведите количество подключений.\n");
	scanf_s("%d", &valueConnections);
}

void setFloor()
{
	printf("\nВведите количества этажей, которые хотят подключиться к сети\n");
	scanf_s("%d", &valueFloor);
}

void setHeight()
{
	printf("\nВведите высоту потолков и толщину перекрытий дома.\n");
	scanf_s("%f", &height);
	scanf_s("%f", &width);
}

void setLenght()
{
	printf("\nВведите среднее расстояние от точки подключения до распределительного шкафа на этаже. \n");
	scanf_s("%f", &mediumLenght);
}

void getValueProjekting()
{
	float value;
	value = (valueConnections * 3 + valueFloor * 163 + ((double)mediumLenght + (((double)height + (double)width) * ((double)valueFloor - 1))) * 1.5) * 0.3;
	printf("\nстоимость проектирования = %f\n", value);
}

void getLenghtCable()
{
	float LenghtCable;
	LenghtCable = mediumLenght + (height + width) * (valueFloor - 1);
	printf("\nдлина кабеля = %f\n", LenghtCable);
}

void getValueHardware()
{
	float value;
	value = (valueConnections * 3 + valueFloor * 110+(mediumLenght + ((height + width) * (valueFloor - 1)))) * 1.5;
	printf("\nстоимость оборудования = %f\n", value);
}

void getValueProjekt()
{
	float value;
	value = (valueConnections * 3 + valueFloor * 163 + (mediumLenght + (((double)height + (double)width) * ((double)valueFloor - 1)) * 1.5)) * 1.3;
	printf("\nстоимость проекта = %f\n", value);
}

void getInformation()
{
	printf("\nМонтажная фирма VBL\n+375297777777");
}

void main() 
{
	system("chcp 1251");

	int Exit=0;

	do
	{
		menu();
		switch (getch())
		{
		case '1': 
		{
			setConnections();
			break; 
		}
		case '2':
		{
			setFloor();
			break;
		}
		case '3':
		{
			setHeight();
			break; }
		case '4':
		{
			setLenght();
			break;
		}
		case '5':
		{
			getValueProjekting();
			break;
		}
		case '6':
		{
			getLenghtCable();
			break;
		}
		case '7':
		{
			getValueHardware();                                                   
			break;
		}
		case '8':
		{
			getValueProjekt();
			break;
		}
		case '9':
		{
			getInformation();
			break;
		}
		case '0':
		{
			Exit++;
			break;
		}
	
		default:
		{
			printf("Ошибка, попробуйте снова");
			break; 
		}
	}
	} 
	while (Exit == 0);
}

void menu()
{
	printf("\nВыберите пункт:\n");
	printf("1. Ввод количества подключений.\n");
	printf("2. Ввод количества этажей, которые хотят подключиться к сети\n");
	printf("3. Ввод высоты потолков и толщины перекрытий дома.\n");
	printf("4. Ввод среднего расстояния от точки подключения до распределительного шкафа на этаже. \n");
	printf("5. Расчет стоимости проектирования сети. \n");
	printf("6. Расчет общей длины кабеля. \n");
	printf("7. Расчет стоимости необходимого сетевого оборудования. \n");
	printf("8. Расчет общей стоимости проекта.\n");
	printf("9. Краткая информация о фирме и контакты.\n");
	printf("0. Выход из программы. \n");
}