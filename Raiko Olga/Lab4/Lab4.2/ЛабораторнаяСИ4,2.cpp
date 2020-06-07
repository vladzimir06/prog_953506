/*4.2 В текстовом файле находится произвольный текст. Найти и
распечатать пары слов (анаграммы), при прочтении которых в
обратном направлении образуется другое слово пары, например:
(ПОЛК КЛОП), (БАР РАБ). */

#include <iostream>

using namespace std;
int main()
{
    FILE* file;
    char* str = new char[1024];
    char array[100];
    int i = 0, j, k = 0;
    ifstream base ("TextFile1.txt");//путь к текстовому файлу
    while (!base.eof())//ищем конец текста
    {
        base.getline(str, 1024, ' ');
        k++;
    }
    base.close();
    delete str;// очистим
    file = fopen("TextFile1.txt", "r");
    fgets(&array[i], 99, file); //чтение строки из текстового файла
    printf("%s\n", &array[i]);

    string str1 = string(array);

    reverse(str1.begin(), str1.end()); //отражение текста
    char Mass[100];
    strcpy(Mass, str1.c_str());
    printf(Mass);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (array[i] == Mass[j] && i != j)
            {
               printf(array);
            }
        }
    }
    fclose(file);//закрываем файл
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
