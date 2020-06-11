#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#define N 128

int main()
{
    char buffer[N];
    int number = 0, i = 0, elements = 0, numeric = 0;
    double output;
        
    FILE* fp;

    fp = fopen("TEXT.txt", "r");
    if (!fp) exit(1);

    while(fgets(buffer, N, fp)!=NULL)
    {
        while (buffer[i] != '\0')
        {
            if (buffer[i] == '-')
                while (buffer[i] != ' ')
                {
                    i++;
                }
            else if (buffer[i] != ' ')
            {
                while (buffer[i] >=0x30 && buffer[i]<=0x39)
                {
                    numeric = numeric + (buffer[i] & 0x0F);
                    numeric = numeric * 10;
                    i++;
                }
                numeric = numeric / 10;
                number = number + numeric;
                if(numeric != 0) elements++;
                numeric = 0;                              
            } 
            i++;
        }
        i = 0;
    }
    output = number/elements;
    printf("answer = %f", output);  
}
