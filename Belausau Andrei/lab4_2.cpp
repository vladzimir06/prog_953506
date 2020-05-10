/*
    Вариант 4
    Длина строк текстового файла не превышает 80 символов.
Разработать программу центрирования строк: короткие строки
дополняются пробелами и размещаются по центру. 
*/

#include <stdio.h>

int strlen(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int main()
{
    char buffer[80], str[80];
    int i;
    const int indexCenter = 40;
    FILE *fp;

    fopen_s(&fp, "input.txt", "r");

    if (!fp) return -1;

    while (fgets(buffer, 80, fp)) {
        for (i = 0; i < 80; i++)
            str[i] = ' ';

        for (i = 0; i < strlen(buffer) && buffer[i] != '\n'; i++) {
            str[indexCenter - strlen(buffer) / 2 + i] = buffer[i];
        }
        str[indexCenter + i - 1] = '\0';
        printf("%s\n", str);
    }
    fclose(fp);
    return 0;
}