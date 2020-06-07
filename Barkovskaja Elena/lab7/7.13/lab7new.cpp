#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "items.h"
#include "menu.h"

int main()
{
    LombardItems* lst = read_items(1);
    char name[25];
    while (true)
    {
        Menu();
        int choice = check_borders(0, 3);
        switch (choice)
        {
        case 1:
            make_order(lst);
            system("pause");
            system("cls");
            break;
        case 2:
            add_to_lombard_list(lst, add_item());
            lst->size++;
            system("cls");
            break;
        case 3:
            print_info(lst);
            system("pause");
            system("cls");
            break;
        case 0:
            delete_lobard_items(lst);
            return 0;
        }
    }
}   

