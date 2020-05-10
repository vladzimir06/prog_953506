//Задание 3.2 (21) Карпенко И.В.(гр. №953506)

/*  Обратная матрица. Найти матрицу, обратную заданной a(n, n), 
методом Гаусса (в любой модификации). */

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

static int n;


void obrat(float* arr) {

	float* edd;
	edd = (float*)malloc(n * n * sizeof(float));

	/*Заполняем единичную матрицу единицами*/
        for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (i == j) *(edd + n * i + j) = 1;
			else *(edd + n * i + j) = 0;
		}
	}

        /*Проверка диагональных элементов на равенство нулю и перестановка строк*/
	for (int t = 0; t < n; t++) {
		if (*(arr + n * t + t) == 0) {
			bool nullcheck = false;
			for (int r = t + 1; r < n; r++) {
				if (*(arr + n * r + t) == 0) {
					nullcheck = true;
					continue;
				}
				else {
					nullcheck = false;
					for (int j = 0; j < n; j++)
					{
						float vrem;
						vrem = *(arr + n * t + j);
						*(arr + n * t + j) = *(arr + n * r + j);
						*(arr + n * r + j) = vrem;

						vrem = *(edd + n * t + j);
						*(edd + n * t + j) = *(edd + n * r + j);
						*(edd + n * r + j) = vrem;
					}
					break;
				}
			}
			if (nullcheck) {
				printf("\nThe inverse matrix does not exist.\n");
				return;
			}
		}
		/*Делим строку на значение дигоналного элемнта*/
		float vremdel = *(arr + n * t + t);
		for (int j = 0; j < n; j++) {
			
			*(arr + n * t + j) = *(arr + n * t + j) / vremdel ;
				*(edd + n * t + j) = *(edd + n * t + j) / vremdel;
		}
		/*Приводим столбец к нулю*/
		for (int i = 0; i < n; i++) {
			float mnozh = *(arr + n * i + t);
			if (i == t) continue;
			for (int j = 0; j < n; j++) {
				*(arr + n * i + j) -= *(arr + n * t + j) * mnozh;
				*(edd + n * i + j) -= *(edd + n * t + j) * mnozh;
			}
		}
		/*Проверка на нулевые строки*/
		for (int i = t + 1; i < n; i++)
		{
			bool nullcheck = false;
			for (int j = 0; j < n; j++) {
				if (*(arr + n * i + j) == 0) nullcheck = true;
				else {
					nullcheck = false;
					break;
				}
			}
			if (nullcheck) {
				printf("\nThe inverse matrix does not exist.\n");
				return;
			}
		}		
	}	
	/*Значение элементов единичной матрицы присваивается нашей*/
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			*(arr + n * i + j) = *(edd + n * i + j);

	/*Вывод матрицы*/
	printf("\nInvers matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%0.3f ", *(arr + n * i + j));
		printf("\n");
	}
	free(edd);
}


int main()
{	
	float* arr;

	printf("Enter the dimension of the square matrix:\n");	
	scanf_s("%d", &n);	
	if (n <= 0) {
		printf("\nThe inverse matrix does not exist.\n");
		return 0;
	}
	arr = (float*)malloc(n*n * sizeof(float));
	
	printf("Enter matrix elements:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%f", arr + n * i + j);
	system("cls");
	
	printf("Your matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%0.3f ", *(arr + n * i + j));
			printf("\n");
	}

	obrat(arr);

	free(arr);
	return 0;
}

