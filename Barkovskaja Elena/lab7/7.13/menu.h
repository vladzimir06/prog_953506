#pragma once
#include "items.h"

void make_order(LombardItems* lst);    //делает заказ(удаляет заданное количество заданных продуктов)
int get_sum(LombardItems* lst, int fl);//считает общюю стоимость от покупки, продажи или количество предметов в зависимости от передаваемых данных
Lombard* get_item(LombardItems* lst, char* str);//возвращает элемент по заданному имени
int check_borders(int l_b, int r_b);//проверяет на соответствие пределам
void check_string(char* str);//проверяет строку на длинну
void order_history();//выводит историю заказов
void Menu();//выводит меню
void print_info(LombardItems* lst);//выводит информацию по get_sum
void delete_Item(LombardItems* list, char* s);//удаляет элемент