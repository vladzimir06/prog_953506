// Задание 1.2(21) Стельмашук В.А.(гр. №953506)

/*Напечатать столбиком пример на деление натурального числа k на
натуральное l (k делится на l нацело). 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int Convert(const char s[]) //проверо4ки и конвертирование 
{
    if (s[0] == '-') 
    {
        printf("Error, numbers don't natural!\n");
        return -1;
    }

    int i = 0, sum = 0;
    while (s[i] != '\0' && s[i] != '\n' && s[i] != ' ') 
    {
        if (s[i] <= '9' && s[i] >= '0') 
        {
            sum = sum * 10 + (s[i] - '0');
            i++;
        }
        else
        {
            printf("Error, you must enter numbers!\n");
            return -1;
        }
    }
    return sum;
}

int power(int x, unsigned int y) //бинарное возведение в степень
{
    int temp;

    if (y == 0) 
    {
        return 1;
    }

    temp = power(x, y / 2);

    if ((y % 2) == 0)
    {
        return temp * temp;
    }
    else 
    {
        return x * temp * temp;
    }
}

int sizeOfNumber(int number) //длина делимого
{
    if (number < 10)
    {
        return 1;
    }
    else 
    {
        return 1 + sizeOfNumber(number / 10);
    }
}

int rankDivision(int* k) //поразрядное деление 
{
    int maxRank = *k / power(10, sizeOfNumber(*k) - 1) * power(10, sizeOfNumber(*k) - 1);
    *k -= maxRank;
    free(k);
    return maxRank;
}

int main(int argc, const char* argv[]) {

    int k = 0, l = 0, m = 0;
    char dividend[10] = "";
    char divsor[10] = "";

    printf("Enter dividend:\n");
    gets_s(dividend, 10);
    k = Convert(dividend);

    printf("Enter divsor:\n");
    gets_s(divsor, 10);
    l = Convert(divsor);
    // еще проверо4ки
    if (l == 0) 
    {
        printf("Error! Cannot be divided by 0\n\n");
        return 0;
    }
    
    if (k % l != 0) 
    {
        printf("Error! Numbers should be shared\n\n");
        return 0;
    }

    int lenght_k = sizeOfNumber(k);
    m = k / l;

    // оформление
    printf("%d | %d = %d\n", k, l, m);
    while (k != 0) {
        int temp = rankDivision(&m) * l;
        for (int i = 0; i < lenght_k - sizeOfNumber(temp); i++) 
        {
            printf(" ");
        }
        printf("%d\n", temp);
        for (int i = 0; i < lenght_k; i++)
        {
            printf("_");
        }
        printf("\n");
        k -= temp;
        for (int i = 0; i < lenght_k - sizeOfNumber(k); i++) 
        {
            printf(" ");
        }
        printf("%d\n", k);
    }
    return 0;
}