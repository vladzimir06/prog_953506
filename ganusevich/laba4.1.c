#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
 
char* GetString(int size);
void MaxWord(char* mass);
void MaxSentensis(char* mass);
void main()
{
	system("cls");

	int valueStr; int len = 0, len0 = 0;
	char *buffer;
	char** text1;
	printf("Enter value lines: ");
	scanf_s("%d", &valueStr);

	text1 = (char**)malloc(valueStr * sizeof(char*));
	for (int i = 0; i < valueStr; i++)
		text1[i] = (char*)malloc(128);
	for (int i = -1; i < valueStr; i++)
		text1[i] = GetString(128);	
	for (int i = 0; i < valueStr; i++)
		len += strlen(text1[i]);

	buffer = (char*)malloc((len + valueStr + 1) * sizeof(char));
	buffer[0] = '\0';
	for (int i = 0; i < valueStr; i++)
	{
		strcat_s(buffer, len + valueStr + 1, text1[i]);
		free(text1[i]);
	}
	//printf("%s\n", buffer);
	MaxSentensis(_strdup(buffer));
	printf("\n");
	MaxWord(_strdup(buffer));
	free(buffer);
}

char* GetString(int size)
{
	char buffer[128];
	int i = 0;
	char c;
	if ((size > 128) || (size <= 0))
		size = 128;
	while (--size > 0)
	{
		c = getchar();
		if (c == '\n')
			size = 0;
		else
		{
			buffer[i++] = c;
		}
	}
	buffer[i] = ' ';
	buffer[i + 1] = '\0';
	return _strdup(buffer);
	
}

void MaxWord(char* mass)
{
	char* p, * c;
	int lenght;
	int lenghtMax = 0;
	char* token = NULL;
	c = p = strtok_s(mass, " ", &token);
	while (p)
	{
		lenght = strlen(p);
		if (lenght > lenghtMax)
		{
			lenghtMax = lenght;
			c = _strdup(p);
		}
		p = strtok_s(NULL, " ", &token);
	}
	if (c[strlen(c) - 1] == '.')
		c[strlen(c) - 1] = '\0';
	if (c[0] == '\n')
		for (int i = 1, len = strlen(c); i < len; i++)
			printf("%c", c[i]);
	else
		printf("%s", c);
}

void MaxSentensis(char* mass)
{
	char* p, * c;
	int lenght;
	int lenghtMax = 0;
	char* token = NULL;
	c = p = strtok_s(mass, ".!?", &token);
	while (p)
	{
		lenght = strlen(p);
		if (lenght > lenghtMax)
		{
			lenghtMax = lenght;
			c = _strdup(p);
		}
		p = strtok_s(NULL, ".!?", &token);
	}
	if (c[0] == ' ')
		for (int i = 1, len = strlen(c); i < len; i++)
			printf("%c", c[i]);
	else
		printf("%s", c);
}