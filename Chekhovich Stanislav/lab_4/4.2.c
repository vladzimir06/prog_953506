//Задание 4.2 Вариант 27
#include <stdio.h>
#include <stdlib.h>

#define STR_MAX_SIZE 100

struct var
{
    char name[2];
    double value;
};

int strLen(char *str);

int strSplit(char *str, char result[][STR_MAX_SIZE], char del);

double strToDouble(char *str);

double strCalculate(char *str, struct var vars[], int n);

void Priority(char zn[][2], double nums[], int n);

double Sum(char zn[][2], double nums[], int m);

int strEquals(char* str1, char* str2);

void strCopy(char* str1, char* str2);

int main()
{
    ////ИНИЦИАЛИЗАЦИЯ ПЕРЕМЕННЫХ//////////////////////////////////////////////////////////
    FILE *fp;
    if ((fp = fopen("myFile.txt", "r")) == NULL)
    {
        printf("Can't open the file");
        exit(1);
    }
    char** variables = (char**)malloc(10 * sizeof(char*));
    for(int i = 0; i < 10; i++)
    {
        variables[i] = (char *)malloc(STR_MAX_SIZE * sizeof(char));
    }
    int n = 0;
    while(!feof(fp))
    {
        fscanf(fp, "%s", variables[n]);
        n++;
    }
    fclose(fp);
    struct var vars[n];
    for(int i = 0; i < n; i++)
    {
        int k = 0;
        char value[100];
        vars[i].name[0] = variables[i][0];
        vars[i].name[1] = '\0';
        for(int j = 2; j < strLen(variables[i]); j++, k++)
        {
            value[k] = variables[i][j];
        }
        value[k] = '\0';
        vars[i].value = strToDouble(value);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%s = %f\n", vars[i].name, vars[i].value);
    }
    printf("\n");
    //////////////////////////////////////////////////////////////////////////////////////
    if ((fp = fopen("myFile2.txt", "r")) == NULL)
    {
        printf("Can't open the file");
        exit(2);
    }
    char** expression = (char**)malloc(10 * sizeof(char*));
    for(int i = 0; i < 10; i++)
    {
        expression[i] = (char *)malloc(STR_MAX_SIZE * sizeof(char));
    }
    int n1 = 0;
    while(!feof(fp))
    {
        fgets(expression[n1], STR_MAX_SIZE, fp);
        n1++;
    }
    fclose(fp);
    for(int i = 0; i < n1; i++)
    {
        printf("%s = ", expression[i]);
        printf("%f\n", strCalculate(expression[i], vars, n));
    }
    free(fp);
    for(int i = 0; i < 10; i++)
    {
        free(expression[i]);
        free(variables[i]);
    }
    free(expression);
    free(variables);
    return 0;
}


double strCalculate(char *str, struct var vars[], int n)
{
    char parts[100][STR_MAX_SIZE];
    char zn[100][2];
    char numbers[100][STR_MAX_SIZE];
    double nums[STR_MAX_SIZE];
    int k1 = 0, k2 = 0;
    int n1 = strSplit(str, parts, ' ');
    for(int i = 0; i < n1; i++)
    {
        if(strEquals(parts[i], "+") || strEquals(parts[i], "-")  || strEquals(parts[i], "*") || strEquals(parts[i], "/"))
        {
            strCopy(parts[i], zn[k1]);
            k1++;
        }
        else
        {
            strCopy(parts[i], numbers[k2]);
            int exit = 0;
            for(int i = 0; i < n; i++)
            {
                if(strEquals(vars[i].name, numbers[k2]))
                {
                    nums[k2] = vars[i].value;
                    k2++;
                    exit = 1;
                }
            }
            if(exit)
            {
                exit = 0;
                continue;
            }
            nums[k2] = strToDouble(numbers[k2]);
            k2++;
        }
    }
    for (int i = 1, j = 0; j < k1; i++, j++)
    {
        if (strEquals(zn[j], "-"))
        {
            nums[i] *= (-1);
            zn[j][0] = '+';
            zn[j][1] = '\0';
        }
    }
    Priority(zn, nums, k2);
    return Sum(zn, nums, k1);
}

void Priority(char zn[][2], double nums[], int n)
{
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        if (strEquals(zn[j], "*"))
        {
            zn[j][0] = '+';
            zn[j][1] = '\0';
            nums[i + 1] *= nums[i];
            nums[i] = 0;
        }
        else if (strEquals(zn[j], "/"))
        {
            zn[j][0] = '+';
            zn[j][1] = '\0';
            nums[i + 1] = nums[i] / nums[i + 1];
            nums[i] = 0;
        }
    }
}

double Sum(char zn[][2], double nums[], int m)
{
    double sum = 0;
    for (int i = 1, j = 0; j < m; i++, j++)
    {
        if (i == 1 && (strEquals(zn[j], "*") || strEquals(zn[j], "/")))
        {
            sum = nums[i];
        }
        else if (i == 1 && (strEquals(zn[j], "+") || strEquals(zn[j], "-")))
        {
            sum = nums[i - 1];
        }
        if (strEquals(zn[j], "+"))
        {
            sum += nums[i];
        }
    }
    return sum;
}

void strCopy(char* str1, char* str2)
{
    int i;
    for(i = 0; i < strLen(str1); i++)
    {
        if(str1[i] == '\n')
        {
            continue;
        }
        str2[i] = str1[i];
    }
    str2[i] = '\0';
}

int strEquals(char* str1, char* str2)
{
    if(strLen(str1) == strLen(str2))
    {
        int equals = 1;
        for(int i = 0; i < strLen(str1); i++)
        {
            if(str1[i] != str2[i])
            {
                equals = 0;
            }
        }
        return equals;
    }
    else
    {
        return 0;
    }
}

int strLen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

int strSplit(char *str, char result[][STR_MAX_SIZE], char del)
{
    int temp = 0;
    int n = 0, t = 0;
    for(int i = 0; i < strLen(str); i++)
    {
        if(str[i] == del)
        {
            for(int j = temp, k = 0; j < i; j++, k++)
            {
                result[n][k] = str[j];
                t = k;
            }
            t++;
            result[n][t] = '\0';
            n++;
            temp = i + 1;
        }
    }
    for(int i = temp, j = 0; i < strLen(str); i++, j++)
    {
        result[n][j] = str[i];
        t = j;
    }
    t++;
    result[n][t] = '\0';
    n++;
    return n;
}

double strToDouble(char *str)
{
    double a = 0;
    char parts[2][STR_MAX_SIZE];
    int n = strSplit(str, parts, ',');
    if(n == 1)
    {
        if(parts[0][0] == '-')
        {
            for(int i = 1; i < strLen(parts[0]); i++)
            {
                a = a * 10 - (parts[0][i] - '0');
            }
        }
        else
        {
            for(int i = 0; i < strLen(parts[0]); i++)
            {
                a = a * 10 + (parts[0][i] - '0');
            }
        }
    }
    else if(n == 2)
    {
        double b = 0;
        if(parts[0][0] == '-')
        {
            for(int i = 1; i < strLen(parts[0]); i++)
            {
                a = a * 10 - (parts[0][i] - '0');
            }
        }
        else
        {
            for(int i = 0; i < strLen(parts[0]); i++)
            {
               a = a * 10 + (parts[0][i] - '0');
            }
        }

        for(int i = 0; i < strLen(parts[1]); i++)
        {
            if(parts[0][0] == '-')
            {
                b -= (parts[1][i] - '0') * pow(0.1, i + 1);
            }
            else
            {
                b += (parts[1][i] - '0') * pow(0.1, i + 1);
            }
        }
        a += b;
    }
    return a;
}
