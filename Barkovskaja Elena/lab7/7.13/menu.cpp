#include "menu.h"
void Menu()
{
    printf("1. Ordering a product\n");
    printf("2. Accept a new product\n");
    printf("3. Show info\n");
    printf("0. Exit\n");
    printf("Select a number: ");
}
int check_borders(int left_border, int right_border)
{
    int ch;
    while (!scanf("%d", &ch) || ch < left_border || ch > right_border)
    {
        rewind(stdin);
        printf("Wrong input try again: ");
    }
    return ch;
}
void check_string(char* f)
{
    rewind(stdin);
    fgets(f, max_str_length, stdin);
    if (strlen(f) > max_str_length)
    {
        printf("The word is too long! Try again( < 30 characters): ");
        check_string(f);
    }
}
Lombard* get_item(LombardItems* list, char* s)
{
    Lombard* temp;
    for (temp = list->head; temp != NULL; temp = temp->next)
        if (!strcmp(temp->nameItem, s)) return temp;
    return NULL;
}
void delete_Item(LombardItems* list, char* s)
{
    Lombard* temp = NULL;
    temp = get_item(list, s);
    if (temp == NULL) exit(5);
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (!temp->prev) list->head = temp->next;
    if (!temp->next) list->tail = temp->prev;

    free(temp);
    change_item(list);
    list->size--;
}
int get_sum(LombardItems* list, int fl)
{
    Lombard* tmp = list->head;
    int sum = 0;
    while (tmp) {

        if (fl == 1) sum += tmp->assessed_value * tmp->items_amount;
        else if (fl == 2) sum += tmp->price * tmp->items_amount;
        else sum += tmp->items_amount;
        tmp = tmp->next;
    }
    return sum;
}
void order_history()
{
    LombardItems* order = read_items(2);
    Lombard* temp = order->head;
    printf("Ordered items:\n");
    while (temp) {
        printf("\n%s%s", "Customer: ", temp->customer);
        printf("%s%s", "Name item: ", temp->nameItem);
        printf("%s%d\n", "Amount item: ", temp->items_amount);
        printf("%s%d%s\n", "The price of this: ", temp->price, " BYN");
        printf("%s%d%s\n", "Purchased for: ", temp->price * temp->items_amount, " BYN");
        temp = temp->next;
    }
    int sum = 0, ord_count = 0;
    int benefit = 0, sum_in = 0;
    int purchase_amount = 0;
    temp = order->head;
    while (temp) {
        ord_count++;
        purchase_amount += temp->items_amount;
        sum += temp->price * temp->items_amount;
        sum_in += temp->assessed_value * temp->items_amount;
        temp = temp->next;
    }
    benefit = sum - sum_in;
    printf("\n%s%d\n", "Total amount of orders: ", ord_count);
    printf("%s%d\n", "Total amount of sold items: ", purchase_amount);
    printf("%s%d%s\n", "Total storage`s profit from sale is: ", sum, " BYN");
    printf("%s%d%s\n", "Total storage`s benefit from sale is: ", benefit, " BYN");
    printf("\n");
    delete_lobard_items(order);
}
void make_order(LombardItems* lst)
{
    int y_or_n;
    char* string = (char*)malloc(max_str_length * sizeof(char));
    Lombard* temp;
    do
    {
        print_items(lst);
        printf("Choose item to order: ");
        do {
            printf("Enter item name: ");
            rewind(stdin);
            scanf("%s", string);
            strcat(string, "\n");
            temp = get_item(lst, string);
        } while (temp == NULL);
        printf("Enter count of chosen item to order: ");
        int count = check_borders(0, temp->items_amount);
        int price = count * temp->price;
        load_items_to_file(temp, 2, count);
        printf("%s%d%s\n", "Price: ", price, " BYN");
        temp->items_amount -= count;
        if (temp->items_amount == 0) delete_Item(lst, string);
        change_item(lst);
        printf("Do you want to order more items? (1 - yes, 0 - no)\n");
        rewind(stdin);
        y_or_n = check_borders(0, 1);
    } while (y_or_n != 0);
}
void print_info(LombardItems* lst)
{
    printf("\n%s%d\n", "Total number of items in storage: ", get_sum(lst, 3));
    printf("%s%d%s\n", "Total cost from purchase: ", get_sum(lst, 1), " BYN");
    printf("%s%d%s\n", "Total cost for sale: ", get_sum(lst, 2), " BYN");
    print_items(lst);
    order_history();
}
