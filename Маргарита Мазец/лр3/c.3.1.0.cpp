#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

bool randomBool()
{
	return 0 + (rand() % (1 - 0 + 1)) == 1;
}

void dateInput(int& width, int& length, int& heigth)
{
	do
	{
		printf("Enter width:");
		rewind(stdin);
	} while ((!scanf_s("%d", &width)) || width < 1);

	do
	{
		printf("Enter length:");
		rewind(stdin);
	} while ((!scanf_s("%d", &length)) || length < 1);

	do
	{
		printf("Enter heigth:");
		rewind(stdin);
	} while ((!scanf_s("%d", &heigth)) || heigth < 1);
}



void filling(bool*** matrix, int width, int length, int heigth)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < length; j++)
			for (int k = 0; k < heigth; k++)
			{
				*(*(*(matrix + i) + j) + k) = randomBool() ;
				printf("%d", *(*(*(matrix + i) + j) + k));
			}
}

void horizontalLayerMatrix(bool*** matrix, int width, int length, int heigth)
{
	for (int i = 0; i < width; i++)
	{
		printf("\ni=%d\n", i);
		for (int j = 0; j < length; j++)
		{
			for (int k = 0; k < heigth; k++)
			{
				printf("%d", *(*(*(matrix + i) + j) + k));
			}
			printf("\n");

		}
	}
}


void horizontalShadow(bool*** matrix, bool** matrix1, int width, int length, int heigth)
{
	
		for (int j = 0; j < length; j++)
			for (int k = 0; k < heigth; k++)
			{
				int flag = 0;
				//сравеиваем определенный элемент на любой высоте
				for (int t = 0; t < width; t++)
				{
					if (*(*(*(matrix + t) + j) + k) == 1) flag++;
				}

				if (flag > 0)
					*(*(matrix1 + j)+ k) = 1;
				else
					*(*(matrix1 + j) + k) = 0;

			}


	for (int i = 0; i < length; i++)
	{
		printf("\n");
		for (int j = 0; j < heigth; j++)
			printf("%d", *(*(matrix1 + i) + j));
	}
}


void profilLayerMatrix(bool*** matrix, int width, int length, int heigth)
{
	for (int i = 0; i < length; i++)
	{
		printf("\nj=%d\n", i);
		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < heigth; k++)
			{
				printf("%d", *(*(*(matrix + j) + i) + k));
			}
			printf("\n");
		}
	}
}


void profilShadow(bool*** matrix, bool** matrix2, int width, int length, int heigth)
{
	for (int w= 0; w < width; w++)
		for (int h = 0; h < heigth; h++)
		{
			int flag = 0;
			for (int l = 0; l < length; l++)
			{
				if (*(*(*(matrix + w) + l) + h ) == 1) flag++;
			}

			if (flag > 0)
				*(*(matrix2 + w) + h) = 1;
			else
				*(*(matrix2 + w) + h) = 0;

		}


	for (int i = 0; i < width; i++)
	{
		printf("\n");
		for (int j = 0; j < heigth; j++)
			printf("%d", *(*(matrix2 + i) + j));
	}
}


void verticalLayerMatrix(bool*** matrix, int width, int length, int heigth)
{
	for (int i = 0; i < heigth; i++)
	{
		printf("\n\nk=%d", i);
		for (int j = 0; j < width; j++)
		{
			printf("\n");
			for (int k = 0; k < length; k++)
				printf("%d", *(*(*(matrix + j) + k) + i));
		}
	}
}

//Ошибка:не выводит матрицу+  неправильный вывод 1 и 0 
void verticalShadow(bool*** matrix, bool** matrix3, int width, int length, int heigth)
{
	for (int w = 0; w < width; w++)
		for (int l = 0; l < length; l++)
		{
			int flag = 0;
			//сравеиваем определенный элемент на любой высоте
			for (int h = 0; h < heigth; h++)
			{
				if (*(*(*(matrix + w) + l) + h) == 1) flag++;
			}

			if (flag > 0)
				*(*(matrix3 + w) + l) = 1;
			else
				*(*(matrix3 + w) + l) = 0;

		}


	for (int i = 0; i < width; i++)
	{
		printf("\n");
		for (int j = 0; j < length; j++)
			printf("%d", *(*(matrix3 + i) + j));
	}
}

int main()
{
	int width, length, heigth;
	bool*** matrix, **matrix1, **matrix2, **matrix3;
	srand(time(0));

	dateInput(width, length, heigth);

	//выделение трехмерного массива и проверка		
	if (!(matrix = (bool***)calloc(width, sizeof(bool**))))
	{
		printf("Error");
		return 0;
	}
	else {
		for (int i = 0; i < length; i++)
			if (!(*(matrix + i) = (bool**)calloc(length, sizeof(bool*))))
			{
				for (; i - 1 >= 0; i--)
					free(*(matrix + i));
				free(matrix);
				printf("Error");
				return 0;
			}


		for (int i = 0; i < length; i++)
			for (int j = 0; j < heigth; j++)
				if (!(*(*(matrix + i) + j) = (bool*)calloc(heigth, sizeof(bool))))
				{
					for(;i-1>=0; i--)
					  for (; j - 1 >= 0; j--)
						free(*(*(matrix + i) + j));

					for (int i=length-1; i>= 0; i--)
						free(*(matrix + i));
					free(matrix);
					printf("Error");
					return 0;
				}
	}
	//выделение массива под горизонтальную тень и его проверка
	if (!(matrix1 = (bool**)calloc(length, sizeof(bool*))))
	{
		printf("Error");
		return 0;
	}
	else 
	{
		for (int i = 0; i < heigth; i++)
			if (!(*(matrix1 + i) = (bool*)calloc(heigth, sizeof(bool))))
			{
				for (; i - 1 >= 0; i--)
					free(*(matrix1 + i));
				free(matrix1);
				printf("Error");
				return 0;
			}
	}
	
	filling(matrix, width, length, heigth);
	printf("\n\n Your horizontal layer matrix:\n");
	horizontalLayerMatrix(matrix, width, length, heigth);
	printf("\n\n Your horizontal Shadow:\n");
	horizontalShadow(matrix, matrix1, width, length, heigth);
	
	//выделение массива под профильную тень и его проверка
	if (!(matrix2 = (bool**)calloc(width, sizeof(bool*))))
	{
		printf("Error");
		return 0;
	}
	else
	{
		for (int i = 0; i < heigth; i++)
			if (!(*(matrix2 + i) = (bool*)calloc(heigth, sizeof(bool))))
			{
				for (; i - 1 >= 0; i--)
					free(*(matrix2 + i));
				free(matrix2);
				printf("Error");
				return 0;
			}
	}

	printf("\n\n Your profil layer matrix:\n");
	profilLayerMatrix(matrix, width, length, heigth);
	printf("\n\n Your profil Shadow:\n");
	profilShadow(matrix, matrix2, width, length, heigth);

	//выделение массива под вертикальную тень и его проверка
	if (!(matrix3 = (bool**)calloc(width, sizeof(bool*))))
	{
		printf("Error");
		return 0;
	}
	else
	{
		for (int i = 0; i < length; i++)
			if (!(*(matrix3 + i) = (bool*)calloc(length, sizeof(bool))))
			{
				for (; i - 1 >= 0; i--)
					free(*(matrix3 + i));
				free(matrix3);
				printf("Error");
				return 0;
			}
	}

	printf("\n\n Your vertical layer matrix:\n");
	verticalLayerMatrix(matrix, width, length, heigth);
	printf("\n\n Your vertical Shadow:\n\n");
	verticalShadow(matrix, matrix2, width, length, heigth);
}


	
