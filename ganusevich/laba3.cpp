#include <malloc.h>
#include <iostream>
#include <iomanip>

using namespace std;
void main()
{
    int** mass;
    system("chcp 1251");
    system("cls");
    int n = 0, m = 0;

    printf("введите размеры массива\n");
    cin >> n >> m;
    system("cls");

    mass = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        mass[i] = ((int*)malloc(m * sizeof(int)));
    if (mass)
    {
        int j, k = 1, p = 1;

        for (int p = 1; p - 1 < n * m; k++)
        {
            for (j = k - 1; j < m - k + 1; j++, p++)
                mass[k - 1][j] = p;

            for (j = k; j < n - k + 1; j++, p++)
                mass[j][m - k] = p;

            for (j = m - k - 1; j >= k - 1; j--, p++)
                mass[n - k][j] = p;

            for (j = n - k - 1; j >= k; j--, p++)
                mass[j][k - 1] = p;
        }

        for (int q = 0; q < n; q++)
        {
            for (int w = 0; w < m; w++)
            {
                cout << setw(4) << mass[q][w];
            }
            cout << endl;
        }
        for (int i = 0; i < n; i++)
            free(mass[i]);
        free(mass);
    }
}