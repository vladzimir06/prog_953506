/*В текстовом файле находится произвольный текст. Разработать
программу проверки правильности расстановки скобок (круглых,
квадратных, фигурных). Критерий проверки: если встречается одна
из закрывающих скобок, то последняя открывающая должна быть
такого же типа; количество скобок каждого типа должно совпадать.
Между скобками допустима запись любых символов. */
#include<stdlib.h>
#include<stdio.h>

//организация стека
typedef struct item
{
	char data;
	struct item* next;
}Item;
Item* top = NULL;

void push(char value)
{
	Item* p;
	p = (Item*)malloc(sizeof(Item));
	p->data = value;
	if (top == NULL)
	{
		top = p;
		top->next = NULL;
	}
	else
	{
		p->next = top;
		top = p;
	}
}

void pop(char value)
{
	Item* p = top;
	top = p->next;
	free(p);
}

bool empty()
{
	if (top == NULL)
		return true;
	else
		return false;
}

//функции со собками
bool isOpenBracket(char symbol) {
		return symbol == '(' || symbol == '{' || symbol == '[';
	}

	bool isClosingBracket(char symbol) {
		return symbol == ')' || symbol == '}' || symbol == ']';
	}

	char getOpenBracketPair(char bracket) {
		return (bracket == '}') ? '{' : (bracket == ')') ? '(' :
			(bracket == ']') ? '[' : '\0';
	}

	bool areParenthesesGood(const char* source, int lenalpha) {
		for (int i = 0; i < lenalpha; ++i) {
			if (isOpenBracket(source[i])) {
				push(source[i]);                                            //если встречается открывающая скобка, помещаем её в стек
			}                                                                    
			else {
				if (isClosingBracket(source[i]))
				{
					char openBracket = getOpenBracketPair(source[i]);       //если первая закрывающая скобка такого же типа, то удаляем её из стека    
					if (!empty() && top->data == openBracket) {           
						pop(source[i]);                                             
					}
					else {
						return false;
					}
				}
			}
		}
		return empty();
	}


int main()
{
	system("chcp 1251");
	system("cls");
	char buf;
	int lenalpha = -1;
	FILE* myfile;

	if (fopen_s(&myfile, "lr4.2.8.txt", "r"))     // открывем файл
		printf("файл не найден");
	while (!feof(myfile))                        // читаем информацию, пока не достигнут конец записи и считаем длину
	{
		buf = fgetc(myfile);
		lenalpha++;
	}
	char* str = (char*)calloc(lenalpha, sizeof(char));
	if (!str)
		printf_s("что-то не то");
	fseek(myfile, 0, 0);
	for (int i = 0; i < lenalpha; i++)
	{
		buf = fgetc(myfile);
		 str[i] = buf;
	}
	for (int i = 0; i < lenalpha; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	if(areParenthesesGood(str, lenalpha))
		printf("Молодец! Все скобки раставлены правильно!\n");
	else
		printf("ОЙ! Ты ошибся. Не печалься:)\n");
	fclose(myfile);
}