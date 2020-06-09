#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    char first[50], second[50];
    int* A, * B, * C, length, l;
    gets_s(first);
    gets_s(second);
	A = (int*)(malloc(sizeof(int)*strlen(first)));
	B = (int*)(malloc(sizeof(int)*strlen(second)));

    for (int i = 0; i < strlen(first); i++)
        A[i] = first[strlen(first) - i - 1] - '0';
    for (int i = 0; i < strlen(second); i++)
        B[i] = second[strlen(second) - i - 1] - '0';

    length = strlen(first) + strlen(second) - 1;
    l = length;
	C = (int*)(malloc(sizeof(int)*length));
	
    for (int ix = 0; ix < length; ix++)
    {
        C[ix] = 0;
    }

    for (int ix = 0; ix < strlen(first); ix++)
    {
        for (int jx = 0; jx < strlen(second); jx++)
        {
            C[ix + jx] += A[ix] * B[jx];
        }
    }

    for (int ix = 0; ix < length - 1; ix++)
    {
        C[ix + 1] += C[ix] / 10;
        C[ix] %= 10;
    }

    while (C[length] == 0)
        length--;
    for (int i = length - 1; i > -1; i--) 
        printf("%d", C[i]);

}
