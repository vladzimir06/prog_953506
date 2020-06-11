  /* вариант 6.23
   программа представляет собой сборник исходных кодов на разных
   языках программирования и набор статей и комментариев к ним. Пользователь
   может добавлять и редактировать комментарии  к каждому исходнику. Исходные
   коды и статьи можно только просматривать.Программа позволяет выбрать исходник
   по любому языку программирования  и посмотреть код, сопутствующие комментарии */


#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<Windows.h>

struct Manager
{
	char* language;
	char* subjects;
	char* code;
	char* article;
	char* comment;
	int  dateAdded;
};

struct Node
{
	Manager* manager;
	Node* next;
	Node* prev;	
};

struct List
{
	Node* head;
	Node* tail;
	int count;
};

void Init(List* list);
void Push(Manager* temp);
void SortList(Node* head);
bool IsEmpty(List* lst);
void RemoveList(Node* head);
Manager* ManagerRead(FILE* file);
void Menu();
void MenuBar(int i);
void Catalog(Node* head);
void ShowList();
void ShowManager(Manager* tmp, int i);
Manager* Search(Node* head, char* search);
void AddComment(Manager* temp);


List* catalog;

int main()
{
	catalog = (List*)malloc(sizeof(List));
	Init(catalog);
	FILE* mycatalog;
	errno_t err=fopen_s(&mycatalog, "catalog.txt", "r+");
	if (err!=0)
	{
		printf("file open error");
		return -1;
	}
	
	while (!feof(mycatalog))
		Push(ManagerRead(mycatalog));
	while (true)
		Menu();
	fclose(mycatalog);
}

void Init(List* list)
{
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
}

void Push(Manager* temp)
{
	Node* newNode = (Node*)malloc(sizeof(Manager));
	newNode->next = nullptr;
	newNode->manager = temp;

	if (catalog->head == nullptr)
	{
		catalog->head = newNode;
		catalog->tail = newNode;
	}
	else
	{
		catalog->tail->next = newNode;
		newNode->prev = catalog->tail;
		catalog->tail = newNode;
	}

	catalog->count++;
}

bool IsEmpty(List* lst)
{
	return 1 ? lst->head : 0;
}

void Menu()
{
	int i = 0;
	printf("\t\t\t\tMenu\n");
	printf("\t\t\t1.Show catalog SOURCE\n");
	printf("\t\t\t2.Add a comment\n");
	printf("\t\t\t3.Edit comment\n");
	printf("\t\t\t4.View source\n");
	printf("\t\t\t5.Add a new code\n");
	printf("\t\t\t6.Save all\n");
	printf("\t\t\t7.Sort\n");
	printf("\t\t\t8.Exit\n\n\n");	
	printf("\t\t\tmake a choice\n");
	while (!scanf_s("%d", &i) || i <= 0 || i > 8)
	{
		printf("repeat input \n");
		while (getchar() != '\n');
	}
	MenuBar(i);
}

void MenuBar(int i)
{
	switch (i)
	{
	case 1:
	{
		ShowList();
		break;
	}

	case 2:
	{
		char language[20];

		printf("language to add a comment to\n");
		scanf_s("%s",language,20);
		Manager* search = Search(catalog->head, language);
		if (search == NULL)
			printf("this language is not in the catalog\n");
		else
			AddComment(search);
		system("cls");
		printf("comment added");
		break;
	}

	case 3:
	{
		char buf[100];
		char language[20];
		printf("enter new comment\n");
		scanf_s("%s", buf, 100);
		printf("language to add a comment to\n");
		scanf_s("%s", language, 20);
		Manager* search = Search(catalog->head, language);
		if (search == NULL)
		{
			printf("this language is not in the catalog\n");
		}
		else
		{
			search->comment = (char*)realloc(search->comment, strlen(buf) + 3);
			memset(search->comment, 0, strlen(buf) + 3);
			for (int i = 0; i < strlen(buf); i++)		
				search->comment[i] = buf[i];			
		}
		break;
	}

	case 4:
	{
		system("cls");
		Catalog(catalog->head);
		break;
	}
	case 5:
	{
		char buf[100];
		char language[20];
		system("cls");
		printf("language to add a comment to\n");
		scanf_s("%s", language, 20);
		Manager* search = Search(catalog->head, language);
		if (search == NULL)
		{
			printf("this language is not in the catalog\n");
		}
		else
		{
			printf("enter new code(max 100 char\n");
			scanf_s("%s", buf, 100);
			search->code = (char*)realloc(search->code, strlen(buf) + 3);
			memset(search->code, 0, strlen(buf) + 3);
			for (int i = 0; i < strlen(buf); i++)
				search->code[i] = buf[i];
		}
		break;
	}
	case 6:
	{
		FILE* save;
		errno_t err = fopen_s(&save,"SAVE.txt","w");
		if (err != 0)
		{
			printf("file open error");
			exit(-1);
		}

		Node* temp = catalog->head;
		while (temp)
		{
			fprintf_s(save, "%s\n", temp->manager->language);
			fprintf(save, "%s\n", temp->manager->subjects);
			fprintf(save, "%s\n", temp->manager->code);
			fprintf(save, "%s\n", temp->manager->article);
			fprintf(save, "%s\n", temp->manager->comment);
			fprintf(save, "%d\n", temp->manager->dateAdded);
			temp = temp->next;
		}
		printf("Saved\n");
		fclose(save);
		break;
	}
	case 7:
	{
		SortList(catalog->head);
		break;
	}
	case 8:
	{
		RemoveList(catalog->head);
		delete catalog;
		system("cls");
		exit(1);
		break;
	}
	}

}

char* Read(FILE* file)
{
	char buffer[300];
	fgets(buffer, 300, file);
	int lenght = strlen(buffer);

	char* string = (char*)calloc(++lenght, sizeof(char));
	if (string == NULL)
	{
		printf_s("memory allocation error");
		exit(-1);
	}
	strcpy_s(string,lenght,buffer);
	return string;
}

Manager* ManagerRead(FILE* file)
{
	Manager* temp = (Manager*)malloc(sizeof(Manager));
	temp->language = Read(file);
	temp->subjects = Read(file);
	temp->code = Read(file);
	temp->article = Read(file);
	temp->comment = Read(file);
	char* digit = Read(file);
	temp->dateAdded = atoi(digit);
	return temp;
}

void ShowList()
{
	system("cls");
	Node* temp = catalog->head;
	int  choice = 0;
	printf("1.programming languages\n");
	printf("2.article\n");
	printf("3.subjects\n");

	printf("\t\t\tmake a choice\n");
	while (!scanf_s("%d", &choice) || choice <= 0 || choice > 3)
	{
		printf("repeat input \n");
		while (getchar() != '\n');
	}
	int count = 1;
	system("cls");
	while (temp)
	{
		printf("%d.", count++);
		ShowManager(temp->manager, choice);
		temp = temp->next;
	}
}

void ShowManager(Manager * tmp,int i)
{
	if (i == 1)
		printf("%s\n", tmp->language);
	if (i == 2)
		printf("%s\n", tmp->article);
	if (i == 3)
		printf("%s\n", tmp->subjects);

}

void AddComment(Manager* temp)
{
	char string[100];
	printf("your comment(100 character limit):\n");
	scanf_s("%s",string,100);
	int lenght = strlen(string);
	temp->comment = (char*)realloc(temp->comment, strlen(temp->comment)+lenght);
	if (temp->comment == NULL)
		printf("memory allocation error");
	int len = strlen(temp->comment);
	for (int i = 0; i < lenght; i++)
		temp->comment[len + i] = string[i];	
}

Manager* Search(Node* head,char * search)
{
	Node* temp = head;
	while (temp)
	{
		int k = strlen(search);
		for (int i = 0; i < strlen(search); i++)
		{
			if (search[i] == temp->manager->language[i])
				k--;
		}
		if (k == 0) return temp->manager;
		temp = temp->next;
	}
	return NULL;
}

void Catalog(Node* head)
{
	Node* temp = head;
	while (temp)
	{
		printf("%s\n", temp->manager->language);
		printf("%s\n", temp->manager->subjects);
		printf("%s\n", temp->manager->code);
		printf("%s\n", temp->manager->article);
		printf("%s\n", temp->manager->comment);
		printf("%d\n", temp->manager->dateAdded);
		printf("-----------------------------\n");
		temp = temp->next;
	}
}

	void SortList(Node * head)
	{
		Node* temp, * min, * search = head;
		while (search)
		{
			temp = search;
			min = search;
			while (temp)
			{
				if (temp->manager->dateAdded < min->manager->dateAdded)
					min = temp;
				temp = temp->next;
			}
			temp = search->next;
			if (search == head)
			{
				if (min == search->next)
				{
					head = min;
					if (min->next)
						min->next->prev = search;
					min->prev = 0;
					search->prev = min;
					search->next = min->next;
					min->next = search;
				}
				else if (search != min)
				{
					head = min;
					if (min->next)
						min->next->prev = min->prev;
					search->next = min->next;
					min->next = search;
					min->prev = search->prev;
					search->prev = min;
				}

			}
			else if (min == search->next)
			{
				search->prev->next = min;
				min->prev = search->prev;
				if (min->next)
					min->next->prev = search;
				search->prev = min;
				search->next = min->next;
				min->next = search;
			}
			else if (search != min)
			{
				search->prev->next = min;
				if (min->next)
					min->next->prev = min->prev;
				search->next = min->next;
				min->next = search;
				min->prev = search->prev;
				search->prev = min;
			}
			search = temp;
		}
	}

	void RemoveList(Node* head)
	{
		Node* temp;
		while (head)
		{
			temp = head;
			delete head->manager->article;
			delete head->manager->code;
			delete head->manager->comment;
			delete head->manager->language;
			delete head->manager->subjects;
			delete head->manager;
			head = head->next;
			delete temp;
			
		}
	}	
