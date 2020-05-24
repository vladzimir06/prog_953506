#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[500];
    FILE* fp;
    bool flag = true;
    int value = 0, valueComm = 0;

    fp = fopen("prog.txt", "r");
    if (!fp) exit(1);
    while (fgets(buffer, 500, fp))
    {
        int chechComm = 0;
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (flag)
                if (buffer[i] == '/')
                {
                    if (buffer[i + 1] == '/')
                    {
                        valueComm += strlen(buffer) - i + 1;
                        value += strlen(buffer);
                        break;
                    }
                    else if (buffer[i + 1] == '*')
                    {
                        flag ^= 1;
                        chechComm = i;
                    }
                }
                else
                {
                    if (buffer[i] == '*' && buffer[i + 1] == '/')
                    {
                        flag ^= 1;
                        valueComm += i + 2 - chechComm;
                    }
                }
        }
        if (!flag)
            valueComm += strlen(buffer) - chechComm + 1;
        value += strlen(buffer);
    }
    fclose(fp);
    if (value)
    {
        float a = (float)valueComm * 100 / value;
        printf("%f%%", a);
    }
    else
        printf("0%%");
}
