#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h >

struct Contacts
{
    unsigned int number;
    char email[30];
};

struct BuyerBase {
    char name[60];
    Contacts contact;
    char desiredBrand[15];
    int year;
    bool state;
    int maxPrice;
    BuyerBase* next, * prev;
};

BuyerBase* addBuyer(char* n, Contacts c, char* dB, int y, int st, int mP, BuyerBase* head)
{
    int i = 0;
    BuyerBase* newItem = (BuyerBase*)calloc(1, sizeof(BuyerBase));
    if (!newItem)
    {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    for (i = 0; n[i] != '\0'; i++)
        newItem->name[i] = n[i];
    newItem->contact = c;
    for (i = 0; dB[i] != '\0'; i++)
        newItem->desiredBrand[i] = dB[i];
    newItem->year = y;
    if (st == 1)
        newItem->state = 1;
    else newItem->state = 0;
    newItem->maxPrice = mP;
    if (!head)
    {
        head = newItem;
    }
    else
    {
        BuyerBase* current = head;
        for (i = 1; current->next != NULL; i++)
            current = current->next;
        if (current->next)
        {
            current->next->prev = newItem;
        }
        newItem->next = current->next;
        current->next = newItem;
        newItem->prev = current;
        current = newItem;
    }
    return head;
}

void showBuyer(BuyerBase* head)
{
    if (head)
    {
        printf("%s%s%s", "ФИО: ", head->name, "\n");
        printf("%s%d%s%s%s", "Телефон: ", head->contact.number, "\nПочта: ", head->contact.email, "\n");
        printf("%s%s%s", "Желаемая марка: ", head->desiredBrand, "\n");
        printf("%s%d%s", "Год: ", head->year, "\n");
        if (head->state == 1)
        {
            printf("Cостояние автомобиля: новый\n");
        }
        else printf("Cостояние автомобиля: б/у\n");
        printf("%s%d%s", "Финансовые возможности: ", head->maxPrice, "\n");
        printf("\n");
        showBuyer(head->next);
    }
    else printf("\n");
}

void delAllBuyer(BuyerBase* head)
{
    if (head) {
        delAllBuyer(head->next);
        free(head);
    }
}

struct CarBase
{
    char brand[15];
    int year;
    int engineVolume;
    bool state;
    int price;
    CarBase* next, * prev;
};

CarBase* addByStep(char* b, int y, int enV, int st, int p, CarBase* head)
{
    int i = 0;
    CarBase* newItem = (CarBase*)calloc(1, sizeof(CarBase));
    if (!newItem)
    {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    for (i = 0; b[i] != '\0'; i++)
        newItem->brand[i] = b[i];
    newItem->year = y;
    newItem->engineVolume = enV;
    if (st == 1)
        newItem->state = 1;
    else newItem->state = 0;
    newItem->price = p;
    if (!head)
    {
        head = newItem;
    }
    else
    {
        CarBase* current = head;
        for (i = 1; current->next != NULL; i++)
            current = current->next;
        if (current->next)
        {
            current->next->prev = newItem;
        }
        newItem->next = current->next;
        current->next = newItem;
        newItem->prev = current;
        current = newItem;
    }
    return head;
}

CarBase* add(CarBase* newItem, CarBase* head)
{
    int i = 0;
    if (!head)
    {
        head = newItem;
    }
    else
    {
        CarBase* current = head;
        for (i = 1; current->next != NULL; i++)
            current = current->next;
        if (current->next)
        {
            current->next->prev = newItem;
        }
        newItem->next = current->next;
        current->next = newItem;
        newItem->prev = current;
        current = newItem;
    }
    return head;
}

CarBase* search(CarBase* head, int num)
{
    CarBase* temp = head;
    CarBase* tmp = NULL;
    char tmpStr[15];
    int tmpNum = 0;
    bool st;
    switch (num) {
    case 1:
        printf("Введите марку: ");
        scanf("%s", tmpStr);
        while (temp) {
            if (!strcmp(temp->brand, tmpStr)) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;
    case 2:
        printf("Введите год: ");
        scanf("%d", &tmpNum);
        while (temp) {
            if (tmpNum == temp->year) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;
    case 3:
        printf("Введите объем двигателя в см^3: ");
        scanf("%d", &tmpNum);
        while (temp) {
            if (tmpNum == temp->engineVolume) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;
    case 4:
        printf("Введите состояние автомобиля:\n1)новый\t2)б/у\n ");
        scanf("%d", &tmpNum);
        if (tmpNum == 1) {
            st = 1;
        }
        else st = 0;
        while (temp) {
            if (st == temp->state) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;
    case 5:
        printf("Введите цену: ");
        scanf("%d", &tmpNum);
        while (temp) {
            if (tmpNum == temp->price) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;

    default:
        printf("Вы должны выбрать один из указаных критериев поиска.\n");
        return NULL;
        break;
    }
}

CarBase* sortPrice(CarBase* head, CarBase* buff, int right)
{
    int i = 0, j = 0, t = 0;
    CarBase* tmp = (CarBase*)calloc(1, sizeof(CarBase));
    buff = head;
    if (!tmp)
    {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    for (i = 0; i < right - 1; i++)
    {
        for (j = 0; j < right - i - 1; buff = buff->next, j++)
        {
            if (buff->price > buff->next->price)
            {
                for (t = 0; buff->brand[t] != '\0'; t++)
                    tmp->brand[t] = buff->brand[t];
                memset(buff->brand, 0, 15);
                tmp->year = buff->year;
                tmp->engineVolume = buff->engineVolume;
                tmp->state = buff->state;
                tmp->price = buff->price;
                for (t = 0; buff->next->brand[t] != '\0'; t++)
                    buff->brand[t] = buff->next->brand[t];
                memset(buff->next->brand, 0, 15);
                buff->year = buff->next->year;
                buff->engineVolume = buff->next->engineVolume;
                buff->state = buff->next->state;
                buff->price = buff->next->price;
                for (t = 0; tmp->brand[t] != '\0'; t++)
                    buff->next->brand[t] = tmp->brand[t];
                memset(tmp->brand, 0, 15);
                buff->next->year = tmp->year;
                buff->next->engineVolume = tmp->engineVolume;
                buff->next->state = tmp->state;
                buff->next->price = tmp->price;
            }
        }
        buff = head;
    }
    return buff;
}

CarBase* sortYear(CarBase* head, CarBase* buff, int right)
{
    int i = 0, j = 0, t = 0;
    CarBase* tmp = (CarBase*)calloc(1, sizeof(CarBase));
    buff = head;
    if (!tmp)
    {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    for (i = 0; i < right - 1; i++)
    {
        for (j = 0; j < right - i - 1; buff = buff->next, j++)
        {
            if (buff->year > buff->next->year)
            {
                for (t = 0; buff->brand[t] != '\0'; t++)
                    tmp->brand[t] = buff->brand[t];
                memset(buff->brand, 0, 15);
                tmp->year = buff->year;
                tmp->engineVolume = buff->engineVolume;
                tmp->state = buff->state;
                tmp->price = buff->price;
                for (t = 0; buff->next->brand[t] != '\0'; t++)
                    buff->brand[t] = buff->next->brand[t];
                memset(buff->next->brand, 0, 15);
                buff->year = buff->next->year;
                buff->engineVolume = buff->next->engineVolume;
                buff->state = buff->next->state;
                buff->price = buff->next->price;
                for (t = 0; tmp->brand[t] != '\0'; t++)
                    buff->next->brand[t] = tmp->brand[t];
                memset(tmp->brand, 0, 15);
                buff->next->year = tmp->year;
                buff->next->engineVolume = tmp->engineVolume;
                buff->next->state = tmp->state;
                buff->next->price = tmp->price;
            }
        }
        buff = head;
    }
    return buff;
}

void show(CarBase* head)
{
    if (head)
    {
        printf("%s%s%s", "Марка: ", head->brand, "\n");
        printf("%s%d%s", "Год: ", head->year, "\n");
        printf("%s%d%s", "Объем двигателя в см^3: ", head->engineVolume, "\n");
        if (head->state == 1)
        {
            printf("Cостояние автомобиля: новый\n");
        }
        else printf("Cостояние автомобиля: б/у\n");
        printf("%s%d%s", "Стоимость: ", head->price, "\n");
        printf("\n");
        show(head->next);
    }
    else printf("\n");
}

int count(CarBase* head)
{
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void delAll(CarBase* head)
{
    if (head) {
        delAll(head->next);
        free(head);
    }
}

int currenYear = 2020;

CarBase* Car = NULL;
BuyerBase* Buyer = NULL;

float makeFullPrice(CarBase* itm);
CarBase* showSelOption(CarBase* head, BuyerBase* first, char* name);

int main(int argc, const char* argv[]) {

    int res, f, state, year, enV, price, num, i = 0, a, b, cou = 0;
    double income = 0;
    char brand[15] = { "\0" }, name[60] = { "\0" }, email[30] = { "\0" };
    char* ptr, * ptrmail, * ptrdB;
    CarBase* tmp = NULL, * s = NULL, * temp = NULL;
    Contacts con;
    CarBase* selOp;
    FILE* fCar;
    FILE* fBuyer;
    CarBase* addit;
    fCar = fopen("C:/Users/свят/Desktop/C/3/CarDataBase.txt", "r");
    fBuyer = fopen("C:/Users/свят/Desktop/C/3/BuyerDataBase.txt", "r");
    if (fCar == NULL) {
        printf("Не удалось открыть файл с базой автомобилей\n");
        return 1;
    }

    if (fBuyer == NULL) {
        printf("Не удалось открыть файл с базой покупателей\n");
        return 1;
    }
    while (true) {
        printf("\t\t\tМЕНЮ:\n1)Загрузить базу автомобилей\n2)Загрузить базу покупателей\n3)Поиск в базе автомобилей\n4)Сортировка автомобилей\n5)Подбор вариантов для покупателя\n6)Формирование заявки для поставщика\n7)Расчет прибыли компании\n8)Завершение программы\n");
        res = scanf("%d", &f);
        if (!res)
        {
            printf("You must enter an integer. Try again. \n");
            return 0;
        }
        switch (f) {
        case 1:
            while (!feof(fCar)) {
                ptr = fgets(brand, sizeof(brand), fCar);
                if (ptr[0] == '\n')
                    continue;
                ptr[strcspn(ptr, "\n")] = '\0';
                fscanf(fCar, "%d", &year);
                fscanf(fCar, "%d", &enV);
                fscanf(fCar, "%d", &state);
                if (state == 1)
                    state = 1;
                else
                    state = 0;
                fscanf(fCar, "%d", &price);
                addit = (CarBase*)calloc(1, sizeof(CarBase));
                if (!addit) {
                    printf("Ошибка выделения памяти.\n");
                }
                for (i = 0; ptr[i] != '\0'; i++)
                    addit->brand[i] = ptr[i];
                addit->year = year;
                addit->engineVolume = enV;
                addit->state = state;
                addit->price = price;
                Car = add(addit, Car);
                ptr = NULL;
            }
            tmp = Car;
            show(Car);
            break;
        case 2:
            while (!feof(fBuyer)) {
                ptr = fgets(name, sizeof(name), fBuyer);
                ptr[strcspn(ptr, "\n")] = '\0';
                fscanf(fBuyer, "%d", &num);
                ptrmail = fgets(email, sizeof(email), fBuyer);
                if (ptrmail[0] == '\n') {
                    ptrmail[strcspn(ptrmail, "\n")] = '\0';
                    ptrmail = fgets(email, sizeof(email), fBuyer);
                }
                ptrmail[strcspn(ptrmail, "\n")] = '\0';
                ptrdB = fgets(brand, sizeof(brand), fBuyer);
                ptrdB[strcspn(ptrdB, "\n")] = '\0';
                fscanf(fBuyer, "%d", &year);
                fscanf(fBuyer, "%d", &state);
                if (state == 1)
                    state = 1;
                else
                    state = 0;
                fscanf(fBuyer, "%d", &price);
                con.number = num;
                for (i = 0; ptrmail[i] != '\0'; i++)
                    con.email[i] = ptrmail[i];
                Buyer = addBuyer(ptr, con, ptrdB, year, state, price, Buyer);
                ptr = fgets(name, sizeof(name), fBuyer);
                ptr = NULL;
            }
            showBuyer(Buyer);
            break;
        case 3:

            if (!Car)
            {
                printf("База авомобилей пуста.\n");
                break;
            }
            printf("Выберите поле для поиска:\n1)Марка\n2)Год выпуска\n3)Объем двигателся в см^3\n4)Состояние автомобиля\n5)стоимость\n");
            b = scanf("%d", &a);
            if (!b)
            {
                printf("You must enter an integer. Try again. \n");
                return 0;
            }
            s = NULL;
            s = search(Car, a);
            printf("\n");
            show(s);
            break;
        case 4:
            if (!Car)
            {
                printf("База авомобилей пуста.\n");
                break;
            }
            printf("Сортировать по:\n1)Цене\n2)Году производства\n");
            res = scanf("%d", &f);
            if (!res)
            {
                printf("You must enter an integer. Try again. \n");
                return 0;
            }
            cou = count(Car);
            if (f <= 1)
            {
                temp = NULL;
                Car = sortPrice(Car, temp, cou);
                show(temp);
            }
            else if (f >= 2)
            {
                temp = NULL;
                temp = sortYear(Car, temp, cou);
                show(temp);
            }
            break;
        case 5:
            if (!Car)
            {
                printf("База авомобилей пуста.\n");
                break;
            }
            if (!Buyer)
            {
                printf("База покупателей пуста.\n");
                break;
            }
            printf("Введите ФИО покупателя: ");
            fflush(stdin);
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            selOp = showSelOption(Car, Buyer, name);
            printf("\n");
            if (!selOp) {
                printf("Не найдено подходящих результатов или неверно введено ФИО.\n");
                break;
            }
            show(selOp);
            break;
        case 6:
            if (!Car) {
                printf("База авомобилей пуста.\n");
                break;
            }
            tmp = Car;
            printf("Компания Атлант-М хочет приобрести автомобили: ");
            while (tmp)
            {
                if (!tmp->next) {
                    printf("%s%s", tmp->brand, ". ");
                    break;
                }
                printf("%s%s", tmp->brand, ", ");
                tmp = tmp->next;
            }
            printf("Стоимость и комплектация каждой отдельной модели будет обсуждаться в индвидуальном порядке.\n\tС уважением руководство Атлант-М!\n");
            break;
        case 7:
            if (!Car) {
                printf("База авомобилей пуста.\n");
                break;
            }
            tmp = Car;
            income = 0;
            while (tmp)
            {
                income += tmp->price + makeFullPrice(tmp);
                tmp = tmp->next;
            }
            income *= 0.15;
            printf("%s%.2f%s", "При реализации всех автомобилей, с учетом доставки и выплаты растомаживания компания заработает: \n", income, " евро\n");
            break;
        default:
            printf("Программа завершена.\n");
            delAll(Car);
            delAllBuyer(Buyer);
            return 0;
            break;
        }
    }

    return 0;
}


float makeFullPrice(CarBase* itm)
{
    float fPrice = 250, tam = 0;

    if (currenYear - itm->year < 0)
    {
        printf("Невернно введены данные(год производства автомобиля или текущий год)\n");
        return 0;
    }
    else if (currenYear - itm->year <= 3)
    {
        tam = 0.6 * itm->engineVolume;
    }
    else if (currenYear - itm->year <= 10)
    {
        if (itm->engineVolume < 2500)
            tam = 0.35 * itm->engineVolume;
        else
            tam = 0.6 * itm->engineVolume;
    }
    else if (currenYear - itm->year < 14)
    {
        tam = 0.6 * itm->engineVolume;
    }
    else
    {
        tam = 2 * itm->engineVolume;
    }

    fPrice += tam;

    return fPrice;
}

CarBase* showSelOption(CarBase* head, BuyerBase* first, char* name)
{
    int i = 0;
    BuyerBase* temp = first;
    CarBase* tmp = head;
    CarBase* selOp = NULL;
    char dBrand[15] = { "\0" };
    int mPrice = 0;
    while (temp)
    {
        if (!strcmp(temp->name, name))
        {
            for (i = 0; temp->desiredBrand[i] != '\0'; i++) {
                dBrand[i] = temp->desiredBrand[i];
            }
            mPrice = temp->maxPrice;
            break;
        }
        temp = temp->next;
    }

    while (tmp)
    {
        if (!strcmp(tmp->brand, dBrand))
        {
            if (1.15 * (tmp->price + makeFullPrice(tmp)) <= mPrice)
            {
                selOp = addByStep(tmp->brand, tmp->year, tmp->engineVolume, tmp->state, tmp->price, selOp);
                tmp = tmp->next;
            }
        }
        tmp = tmp->next;
    }
    return selOp;
}