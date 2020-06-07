#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

const int max_str_length = 30;
const int radix = 10;

struct Lombard
{
    char customer[max_str_length];//покупатель
    char nameItem[max_str_length];//номер элемента
    char requisites[max_str_length];//сведения о покупателе
    char date_of_completion[max_str_length]; // дата завершения хранения
    char shelf_life[max_str_length]; // срок хранения
    int items_amount;//количество продуктов
    int assessed_value; // оценочная стоимость
    int price;//цена
    Lombard* next, * prev;//указатели на следующий и предыдущий элементы
};
struct LombardItems
{
    Lombard* head, * tail;
    int size;
};

int file_size(FILE* file);//возвращает размер файла
void delete_lobard_items(LombardItems* lst);//удаляяет все данные о ломбарде
void add_to_lombard_list(LombardItems* lst, Lombard* book);//добавляет элемент в список
Lombard* load_items_from_file(FILE* file);//загружает элементы из файла
void load_items_to_file(Lombard* item, int fl, int coun);//загружает информацию в файл
void change_item(LombardItems* lst);//изменяет элемент
Lombard* add_item();//добавляет элемент в файл
void print_info(LombardItems* lst);//выводит информацию о всем ломбарде
void print_items(LombardItems* lst);//выводит информацию об элементе
LombardItems* read_items(int flag);//считывает элементы из файла
