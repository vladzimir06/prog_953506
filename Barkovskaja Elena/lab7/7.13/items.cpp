#include "items.h"
#include "menu.h"
int file_size(FILE* f)
{
    int c = 0;
    while (!feof(f)) {
        if (fgetc(f) == '\n') {
            c++;
        }
    }
    return c;
}

void delete_lobard_items(LombardItems* lst)
{
    Lombard* temp = lst->head;
    Lombard* pNext = nullptr;
    while (temp) {
        pNext = temp->next;
        free(temp);
        temp = pNext;
    }
    free(lst);
}
void add_to_lombard_list(LombardItems* lst, Lombard* p)
{
    Lombard* temp = (Lombard*)malloc(sizeof(Lombard));
    if (!temp) exit(1);
    strcpy(temp->customer, p->customer);
    strcpy(temp->nameItem, p->nameItem);
    strcpy(temp->requisites, p->requisites);
    strcpy(temp->date_of_completion, p->date_of_completion);
    strcpy(temp->shelf_life, p->shelf_life);
    temp->items_amount = p->items_amount;
    temp->assessed_value = p->assessed_value;
    temp->price = p->price;
    temp->next = lst->head;
    temp->prev = nullptr;
    if (lst->head) lst->head->prev = temp;
    lst->head = temp;
    if (!lst->tail) lst->tail = temp;
}

LombardItems* read_items(int fl)
{
    FILE* file;
    if (fl == 1) file = fopen("items.txt", "r");
    else file = fopen("order.txt", "r");
    if (!file) exit(2);
    LombardItems* temp = (LombardItems*)malloc(sizeof(LombardItems));
    temp->size = file_size(file) / 8;
    temp->head = temp->tail = nullptr;
    rewind(file);
    int i;
    for (i = 0; i < temp->size; i++) {
        add_to_lombard_list(temp, load_items_from_file(file));
    }
    fclose(file);
    return temp;
}
Lombard* load_items_from_file(FILE* file)
{
    Lombard* temp = (Lombard*)malloc(sizeof(Lombard));
    if (!temp) exit(1);
    char buf[6];
    fgets(temp->customer, max_str_length, file);
    fgets(temp->nameItem, max_str_length, file);
    fgets(temp->requisites, max_str_length, file);
    fgets(temp->date_of_completion, max_str_length, file);
    fgets(temp->shelf_life, max_str_length, file);
    fgets(buf, 6, file);
    temp->items_amount = atoi(buf);
    fgets(buf, 6, file);
    temp->assessed_value = atoi(buf);
    fgets(buf, 6, file);
    temp->price = atoi(buf);
    return temp;
}
Lombard* add_item()
{
    printf("Enter items data.\n");
    Lombard* temp = (Lombard*)malloc(sizeof(Lombard));
    if (!temp) exit(1);

    printf("Enter item customer: ");
    check_string(temp->customer);
    printf("Enter item name: ");
    check_string(temp->nameItem);
    printf("Enter item requisites: ");
    check_string(temp->requisites);
    printf("Enter date of completion:");
    check_string(temp->date_of_completion);
    printf("Enter shelf life:");
    check_string(temp->shelf_life);
    printf("Enter item amount: ");
    rewind(stdin);
    scanf_s("%d", &temp->items_amount);
    printf("Enter item cost for purchase: ");
    rewind(stdin);
    scanf_s("%d", &temp->assessed_value);
    printf("Enter item cost for sale: ");
    rewind(stdin);
    scanf_s("%d", &temp->price);

    load_items_to_file(temp, 1, 0);
    return temp;
}
void load_items_to_file(Lombard* item, int fl, int count) 
{
    FILE* file;
    if (fl == 1) file = fopen("items.txt", "a");
    else file = fopen("order.txt", "a");
    if (!file) exit(2);
    char* buf = (char*)malloc(5 * sizeof(char));
    fputs(item->customer, file);
    fputs(item->nameItem, file);
    fputs(item->requisites, file);
    fputs(item->date_of_completion, file);
    fputs(item->shelf_life, file);
    if (fl == 1) _itoa(item->items_amount, buf, radix);
    else _itoa(count, buf, radix);
    strcat(buf, "\n");
    fputs(buf, file);
    _itoa(item->assessed_value, buf, radix);
    strcat(buf, "\n");
    fputs(buf, file);
    _itoa(item->price, buf, radix);
    strcat(buf, "\n");
    fputs(buf, file);
    free(buf);
    fclose(file);
}
void change_item(LombardItems* list)
{
    FILE* file = fopen("items.txt", "w");
    if (!file) exit(2);
    Lombard* temp = list->head;
    while (temp)
    {
        char* buf = (char*)malloc(5 * sizeof(char));
        fputs(temp->customer, file);
        fputs(temp->nameItem, file);
        fputs(temp->requisites, file);
        fputs(temp->date_of_completion, file);
        fputs(temp->shelf_life, file);
        _itoa(temp->items_amount, buf, radix);
        strcat(buf, "\n");
        fputs(buf, file);
        _itoa(temp->assessed_value, buf, radix);
        strcat(buf, "\n");
        fputs(buf, file);
        _itoa(temp->price, buf, radix);
        strcat(buf, "\n");
        fputs(buf, file);
        free(buf);
        temp = temp->next;
    }
    fclose(file);
}

void print_items(LombardItems* list)
{
    Lombard* temp = list->head;
    while (temp) {
        printf("\n%s%s", "Customer: ", temp->customer);
        printf("%s%s", "Name item: ", temp->nameItem);
        printf("%s%s", "Requisites: ", temp->requisites);
        printf("%s%s", "Date of completion:", temp->date_of_completion);
        printf("%s%s", "Shelf life:", temp->shelf_life);
        printf("%s%d\n", "Amount item: ", temp->items_amount);
        printf("%s%d\n", "Price for purchase: ", temp->assessed_value);
        printf("%s%d\n", "Price for sale: ", temp->price);
        temp = temp->next;
    }
    printf("\n");
}