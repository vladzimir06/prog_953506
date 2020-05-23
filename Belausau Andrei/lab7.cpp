/*
	Вариант 16
	Рейтинг студентов. Программа рассчитывает рейтинг студентов
специальности «Информатика». Рейтинг учитывает все оценки,
полученные студентами во время сессий – как положительныfе, так
и отрицательные. Можно просмотреть рейтинг по курсам, по
группам. Отображается текущий средний балл, рост
(положительный или отрицательный) относительно последней
сессии, изменение места в рейтинге.
*/

#define _CRT_SECURE_NO_WARNINGS
#define NUM_OF_MARKS 5		//кол-во оценок за семестр
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

typedef struct TermMarks
{
	int marks[NUM_OF_MARKS];
	double averageMark;
} TermMarks;

typedef struct
{
	char *firstName;
	char *lastName;
	struct TermMarks termMarks[8];
	double currentAverageMark;			//средний балл за последний семестр
	double totalAverageMark;
	double rise;						//рост среднего балла за последний семестр
	int group;
	int course;
	int rank;							//текущая позиция в рейтинге по среднему баллу
	int prevRank;						//соответственно предыдущая позиция
	struct Student *left;
	struct Student *right;
} Student;

//для работы со студентами
void ReadFromFile(Student **root, FILE *fp);
void WriteToFile(Student *root, FILE *fp);
void AddStudent(Student **root);
void DeleteStudent(double averageMark, char *firstName, char *lastName, Student **root);
Student* FindStudent(double averageMark, char *firstName, char *lastName, Student *root);
void ShowStudentMarks(Student *st);								//показывает все оценки за каждый семестр
void ShowStudentInfo(Student *st);
void SetRanks(Student **root, char field, int fieldValue);		//выставляет рейтинг в зависимости от выбранного поля (группа | курс | поток)
void PrintGroupRating(Student *root, int group);
void PrintCourseRating(Student *root, int course);

//для работы с деревом
int GetSize(Student *root);
void AddNode(Student **root, Student *student);
void PrintTree(Student *root);
void DeleteTree(Student *root);
void BalanceTree(Student **root);					//балансировка добавлена, т.к. список студентов 
void MakeVine(Student **root);						//сохраняется(читается) из файла как вырожденное дерево
void BalanceVine(Student **root);
void RotateLeft(Student **parrent, Student **current, Student **root);
void RotateRight(Student **parrent, Student **current, Student **root);


int main()
{
	Student *root = NULL;
	int numOfGroup, numOfCourse;
	double averageMark;
	char choice;
	char *firstName = (char*)malloc(20 * sizeof(char));
	char *lastName = (char*)malloc(20 * sizeof(char));
	char field;
	FILE *fin;
	FILE *fout;

	do
	{
		puts("1 - Read from file");
		puts("2 - Write to file");
		puts("3 - Add new student");
		puts("4 - Show all students");
		puts("5 - Show students of *number* group");
		puts("6 - Show students of *number* course");
		puts("7 - Show any student's marks");
		puts("8 - Show full information about the student");
		puts("9 - Delete student");
		puts("0 - Delete all students");
		puts("q - Quit");

		scanf("%c", &choice);

		switch (choice)
		{
			case '1':
				fin = fopen("file.txt", "r");
				ReadFromFile(&root, fin);
				break;

			case '2':
				fout = fopen("file.txt", "w");
				WriteToFile(root, fout);
				fclose(fout);
				break;

			case '3':					//добавление студента
				AddStudent(&root);
				break;

			case '4':					//просмотр всех студентов
				system("cls");
				PrintTree(root);
				_getch();
				break;

			case '5':					//просмотр рейтинга по группе
				system("cls");
				printf("num of group - ");
				scanf("%d", &numOfGroup);
				SetRanks(&root, 'g', numOfGroup);
				PrintGroupRating(root, numOfGroup);
				_getch();
				SetRanks(&root, 'a', 0);
				SetRanks(&root, 'a', 0);
				break;

			case '6':					//просмотр рейтинга по курсу
				system("cls");
				printf("num of course - ");
				scanf("%d", &numOfCourse);
				SetRanks(&root, 'c', numOfCourse);
				PrintCourseRating(root, numOfCourse);
				_getch();
				SetRanks(&root, 'a', 0);
				SetRanks(&root, 'a', 0);
				break;

			case '7':					//просмотр оценок студента
				system("cls");
				PrintTree(root);
				printf("first name - ");
				scanf("%s", firstName);
				printf("last name - ");
				scanf("%s", lastName);
				printf("average mark - ");
				scanf("%lf", &averageMark);

				system("cls");
				ShowStudentMarks(FindStudent(averageMark, firstName, lastName, root));
				_getch();
				break;

			case '8':					//просмотр информации о студенте
				system("cls");
				PrintTree(root);
				printf("first name - ");
				scanf("%s", firstName);
				printf("last name - ");
				scanf("%s", lastName);
				printf("average mark - ");
				scanf("%lf", &averageMark);
				system("cls");

				ShowStudentInfo(FindStudent(averageMark, firstName, lastName, root));
				_getch();
				break;
			case '9':					//удаление студента
				system("cls");
				PrintTree(root);
				printf("first name - ");
				scanf("%s", firstName);
				printf("last name - ");
				scanf("%s", lastName);
				printf("average mark - ");
				scanf("%lf", &averageMark);

				DeleteStudent(averageMark, firstName, lastName, &root);
				break;

			case '0':					//удаление всех студентов
				system("cls");
				DeleteTree(root);
				root = NULL;
				break;
		}
		system("cls");
	} while (choice != 'q');
	
	DeleteTree(root);
	free(firstName);	
	free(lastName);

	return 0;
}

//чтение из файла
void ReadFromFile(Student **root, FILE *fp)
{
	while (!feof(fp))
	{
		int numOfTerms = 0;
		Student *st = (Student*)malloc(sizeof(Student));

		st->firstName = (char*)malloc(20 * sizeof(char));
		st->lastName = (char*)malloc(20 * sizeof(char));
		st->rank = 0;
		st->prevRank = 0;
		st->totalAverageMark = 0;

		if (fscanf(fp, "%s", st->firstName) == EOF)
		{
			SetRanks(root, "a", 0);
			return;
		}
		fscanf(fp, "%s", st->lastName);
		fscanf(fp, "%d", &st->course);
		fscanf(fp, "%d", &st->group);

		for (numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
		{
			st->termMarks[numOfTerms].averageMark = 0;
		}

		for (numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
		{
			for (int i = 0; i < NUM_OF_MARKS; i++)
			{
				fscanf(fp, "%d", &st->termMarks[numOfTerms].marks[i]);
				st->termMarks[numOfTerms].averageMark += st->termMarks[numOfTerms].marks[i];
			}
			st->termMarks[numOfTerms].averageMark /= NUM_OF_MARKS;
			st->totalAverageMark += st->termMarks[numOfTerms].averageMark;
		}
		st->totalAverageMark /= numOfTerms;
		st->currentAverageMark = st->termMarks[numOfTerms - 1].averageMark;
		st->rise = st->termMarks[numOfTerms - 1].averageMark - st->termMarks[numOfTerms - 2].averageMark;

		fgetc(fp);
		AddNode(root, st);
	}

	SetRanks(root, "a", 0);
}

//запись в файл
void WriteToFile(Student *root, FILE *fp)
{
	if (root)
	{
		WriteToFile(root->right, fp);
		
		fprintf(fp, "%s %s %d %d", root->firstName, root->lastName, root->course, root->group, root->currentAverageMark, root->rise);
		
		for (int numOfTerms = 0; numOfTerms < root->course * 2; numOfTerms++)
		{
			for (int i = 0; i < NUM_OF_MARKS; i++)
			{
				fprintf(fp, " %d", root->termMarks[numOfTerms].marks[i]);
			}
		}
		fprintf(fp, "\n");

		WriteToFile(root->left, fp);
	}
}

//добавление студента
void AddStudent(Student **root)
{
	system("cls");
	int numOfTerms = 0;
	Student* st = (Student*)malloc(sizeof(Student));

	st->firstName = (char*)malloc(20 * sizeof(char));
	st->lastName = (char*)malloc(20 * sizeof(char)); 
	st->rank = 0;
	st->prevRank = 0;
	st->totalAverageMark = 0;

	printf("first name - ");
	scanf("%s", st->firstName);
	printf("last name - ");
	scanf("%s", st->lastName);

	printf("course - ");
	scanf("%d", &st->course);
	printf("group - ");
	scanf("%d", &st->group);

	for (numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
	{
		st->termMarks[numOfTerms].averageMark = 0;
	}

	for (numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
	{
		printf("%d term's marks: ", numOfTerms + 1);

		for (int i = 0; i < NUM_OF_MARKS; i++)
		{
			scanf("%d", &st->termMarks[numOfTerms].marks[i]);
			st->termMarks[numOfTerms].averageMark += st->termMarks[numOfTerms].marks[i];
		}
		st->termMarks[numOfTerms].averageMark /= NUM_OF_MARKS;
		st->totalAverageMark += st->termMarks[numOfTerms].averageMark;
	}
	st->totalAverageMark /= numOfTerms;
	st->currentAverageMark = st->termMarks[numOfTerms - 1].averageMark;
	st->rise = st->termMarks[numOfTerms - 1].averageMark - st->termMarks[numOfTerms - 2].averageMark;

	AddNode(root, st);

	SetRanks(root, "a", 0);
}

//добавление нового элемента
void AddNode(Student **root, Student *student)
{
	if (!(*root))
	{
		*root = (Student*)calloc(1, sizeof(Student));
		(*root) = student;
		(*root)->left = (*root)->right = NULL;
	}
	else
	{
		if ((*root)->currentAverageMark > student->currentAverageMark)
		{
			AddNode(&(*root)->left, student);
		}
		else
		{
			AddNode(&(*root)->right, student);
		}
	}
}

//удаление студента
void DeleteStudent(double currentAverageMark, char *firstName, char *lastName, Student **root)
{
	Student *current = *root;
	Student *parent = NULL;
	Student *toDelete;

	while (current)
	{
		if (!strcmp(current->firstName, firstName)
			&& !strcmp(current->lastName, lastName)
			&& current->currentAverageMark == currentAverageMark)
		{
			break;
		}
		else
		{
			parent = current;

			if (currentAverageMark < current->currentAverageMark)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}
	}
	if (!current) return;

	if (!current->right)
	{
		if (!parent)
		{
			toDelete = *root;
			*root = current->left;
		}
		else
		{
			if (current == parent->left)
			{
				toDelete = parent->left;
				parent->left = current->left;
			}
			else
			{
				toDelete = parent->right;
				parent->right = current->left;
			}
		}
	}
	else
	{
		Student *leftMost = current->right;
		parent = NULL;

		while (leftMost->left)
		{
			parent = leftMost;
			leftMost = leftMost->left;
		}
		if (parent)
		{
			toDelete = parent->left;
			parent->left = leftMost->right;
		}
		else
		{
			toDelete = current->right;
			current->right = leftMost->right;
		}
		current->course = leftMost->course;
		current->currentAverageMark = leftMost->currentAverageMark;
		current->totalAverageMark = leftMost->totalAverageMark;
		current->firstName = leftMost->firstName;
		current->group = leftMost->group;
		current->lastName = leftMost->lastName;
		current->prevRank = leftMost->prevRank;
		current->rank = leftMost->rank;
		current->rise = leftMost->rise;

		for (int numOfTerms = 0; numOfTerms < current->course * 2; numOfTerms++)
		{
			for (int i = 0; i < NUM_OF_MARKS; i++)
			{
				current->termMarks[numOfTerms].marks[i] = leftMost->termMarks[numOfTerms].marks[i];
			}
			current->termMarks[numOfTerms].averageMark = leftMost->termMarks[numOfTerms].averageMark;
		}
		current->currentAverageMark = leftMost->currentAverageMark;
	}
	SetRanks(root, "a", 0);

	free(toDelete);
}

//поиск студента по оценке, имени и фамилии
Student* FindStudent(double averageMark, char *firstName, char *lastName, Student *root)
{
	if (root)
	{
		if (!strcmp(root->firstName, firstName) && !strcmp(root->lastName, lastName))
		{
			return root;
		}
		else if (averageMark > root->currentAverageMark)
		{
			FindStudent(averageMark, firstName, lastName, root->right);
		}
		else if(averageMark < root->currentAverageMark)
		{
			FindStudent(averageMark, firstName, lastName, root->left);
		}
		else return NULL;
	}
}

//вывод всех оценок студента
void ShowStudentMarks(Student *st)
{
	if (!st)
	{
		puts("No matches");
		return;
	}
	printf("%s's marks\n", st->firstName);
	
	for (int numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
	{
		printf("%d term's marks: ", numOfTerms + 1);

		for (int i = 0; i < NUM_OF_MARKS; i++)
		{
			printf("%d ", st->termMarks[numOfTerms].marks[i]);
		}
		puts("");
	}
}

//вывод полной инфы по студенту
void ShowStudentInfo(Student* st)
{
	if (!st)
	{
		puts("No matches");
		return;
	}

	printf("Name - %s", st->firstName);
	printf("\nSurname - %s", st->lastName);
	printf("\nCourse - %d", st->course);
	printf("\nGroup - %d", st->group);
	printf("\nTotal average mark - %.2f", st->totalAverageMark);
	printf("\nCurrent average mark - %.2f", st->currentAverageMark);
	
	for (int numOfTerm = 0; numOfTerm < st->course * 2; numOfTerm++)
	{
		printf("\n%d term's marks: ", numOfTerm + 1);

		for (int i = 0; i < NUM_OF_MARKS; i++)
		{
			printf("%d ", st->termMarks[numOfTerm].marks[i]);
		}
	}
}

//размер дерева
int GetSize(Student *root)
{
	if (root)
	{
		return 1 + GetSize(root->left) + GetSize(root->right);
	}
	return 0;
}

//вывод дерева
void PrintTree(Student *root)
{
	if (root)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		PrintTree(root->right);

		printf("# %d", root->rank);

		if (root->prevRank - root->rank > 0)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
		}
		else if (root->prevRank - root->rank < 0)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
		}
		if (root->prevRank - root->rank != 0 && root->prevRank != 0)
			printf("(%+d)", root->prevRank - root->rank);

		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		printf(". %s %s, course %d group %d, average mark - %.2f", root->firstName, root->lastName, root->course, root->group, root->currentAverageMark);

		if (root->rise > 0)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
		}
		else if (root->rise < 0)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
		}

		if (root->rise == 0)
		{
			puts("");
		}
		else
		{
			printf("(%+.2f)\n", root->rise);
		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

		PrintTree(root->left);
	}
}

//удаление дерева
void DeleteTree(Student *root)
{
	if (root)
	{
		DeleteTree(root->left);
		DeleteTree(root->right);
		free(root->firstName);
		free(root->lastName);
		free(root);
	}
}

//балансировка дерева
void BalanceTree(Student **root)
{
	MakeVine(root);
	BalanceVine(root);
}

//назначение места в рейтинге
void SetRanks(Student **root, char field, int fieldValue)
{
	MakeVine(root);

	int rank = 1;
	Student *current = *root;

	while (current)
	{
		switch (field)
		{
		case 'g':
			if (current->group == fieldValue)
			{
				current->prevRank = current->rank;
				current->rank = rank++;
			}
			break;
		case 'c':
			if (current->course == fieldValue)
			{
				current->prevRank = current->rank;
				current->rank = rank++;
			}
			break;
		default:
			current->prevRank = current->rank;
			current->rank = rank++;
			break;
		}
		current = current->left;
	}
	BalanceVine(root);
}

//составление лозы
void MakeVine(Student **root)
{
	Student *current = *root;
	Student *parrent = NULL;

	while (current) 
	{
		if (!current->right) 
		{
			parrent = current;
			current = current->left;
		}
		else 
		{
			RotateLeft(&parrent, &current, root);
		}
	}
}

//балансировка лозы
void BalanceVine(Student **root)
{
	Student *black = NULL;
	Student *red = *root;

	for (int n = 1; n < log(GetSize(*root)) / log(2) - 0.5; n++) 
	{
		for (int i = 0; i < GetSize(*root) / pow(2, n) - 1; i++)
		{
			RotateRight(&black, &red, root);
			black = red;
			red = red->left;
		}
		black = NULL;
		red = *root;
	}
}

//левый поворот для составления лозы
void RotateLeft(Student **parrent, Student **current, Student **root)
{
	Student* subR = (*current)->right;
	Student* subRL = subR->left;

	(*current)->right = subRL;
	subR->left = *current;
	if (*parrent) {
		(*parrent)->left = subR;
	}
	else {
		*root = subR;
	}
	*current = subR;
}

//Правый поворот для балансировки лозы
void RotateRight(Student **parrent, Student **current, Student **root)
{
	Student* subL = (*current)->left;
	Student* subLR = subL->right;

	(*current)->left = subLR;
	subL->right = *current;
	if (*parrent) {
		(*parrent)->left = subL;
	}
	else {
		*root = subL;
	}
	*current = subL;
}

//----------------рейтинг группы
void PrintGroupRating(Student* root, int group)
{
	if (root)
	{
		PrintGroupRating(root->right, group);
		if (root->group == group)
		{
			printf("%d. %s %s, course %d group %d, average mark - %.2f\n", root->rank, root->firstName, root->lastName, root->course, root->group, root->currentAverageMark);
		}
		PrintGroupRating(root->left, group);
	}
}

//----------------рейтинг курса
void PrintCourseRating(Student *root, int course)
{
	if (root)
	{
		PrintCourseRating(root->right, course);
		if (root->course == course)
		{
			printf("%d. %s %s, course %d group %d, average mark - %.2f\n", root->rank, root->firstName, root->lastName, root->course, root->group, root->currentAverageMark);
		}
		PrintCourseRating(root->left, course);
	}
}