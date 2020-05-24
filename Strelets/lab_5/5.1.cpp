//Вариант 21
#include <iostream>


struct list
{
    int field;
    struct list* next;
    struct list* prev;
};

struct list* Init(int a)
{
    struct list* lst;
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->next = NULL;
    lst->prev = NULL;
    return(lst);
}

struct list* Addelem(list* lst, int number)
{
    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->next;
    lst->next = temp;
    temp->field = number;
    temp->next = p;
    temp->prev = lst;
    if (p != nullptr)
        p->prev = temp;
    return(temp);
}

void Listprint(list* lst)
{
    struct list* p;
    p = lst;
    do {
        printf("%d ", p->field);
        p = p->next;
    } while (p != NULL);
}

void Count(int& a, int b)
{
    while (b)
    {
        b /= 10;
        a++;
    }
}

int Equals(list* lst, list* lst2)
{
    if (lst->field == lst2->field)
        return 1;
    else if (lst->field < lst2->field)
        return -1;
    else
        return 0;
}

int List_size(list* lst)
{
    int size = 0;
    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return size;
}

void CompareList(list* lst, list* lst2)
{
    int size = List_size(lst);
    int size2 = List_size(lst2);
    int equal = 0;
    bool cycler = true;
    if (size == size2)
    {
        while (cycler)
        {
            equal = Equals(lst, lst2);
            if (equal != 1)
            {
                switch (equal)
                {
                case 0: printf_s("First is bigger"); break;
                case -1: printf_s("Second is bigger"); break;
                }
                cycler = false;
                break;
            }
            else
            {
                lst = lst->next;
                lst2 = lst2->next;
            }
        }

    }
    else
    {
        if (size > size2)
            printf_s("First number is bigger");
        else
            printf_s("Second number is bigger");
    }
}

struct list* ToLastPointer(list* lst)
{
    while (true)
    {
        lst = lst->next;
        if (lst->next == nullptr)
            break;
    }
    return lst;
}

void LongModShort(list* lst, int num)
{
    lst = ToLastPointer(lst);
    int answer = 0, i = 1;

    while (true)
    {
        if (lst->field == 0) break;
        answer += lst->field % num;
        lst = lst->prev;
        lst->field *= powl(10, i);
        i++;
    }

    if (answer >= num)
        answer %= num;

    printf_s("Your answer: %d", answer);
}

void LongDivShort(list* lst, short int num)
{
    lst = ToLastPointer(lst);
    int answer = 0, i = 0;
    bool cycler = true;
    while (cycler)
    {
        if (lst->field == 0) break;
        answer += lst->field;
        i++;
        lst = lst->prev;
    }
    answer /= num;
    printf_s("Your answer = %d", answer);
}

void LongMulShort(list* lst, int num, list* lst2)
{
    lst = ToLastPointer(lst);
    bool cycler = true;
    int answer = 0;
    while (cycler)
    {
        if (lst->field == 0) break;
        answer += lst->field;
        lst->field = 0;
        lst = lst->prev;
    }
    answer *= num;
    while (answer)
    {
        int curr = answer % 10;
        answer /= 10;
        Addelem(lst2, curr);
    }
}

void Delete(list* lst)
{
    lst = ToLastPointer(lst);
    while (lst)
    {
        lst = lst->prev;
        free(lst->next);
    }
}



int main()
{
    printf_s("Enter first number ");
    int number = 0;
    scanf_s("%d", &number);
    printf_s("Enter second number ");
    int number2 = 0;
    scanf_s("%d", &number2);
    int counter = 0, counter2 = 0, cnt = 0;
    printf_s("Enter short number for all operations ");
    int divider = 0;
    scanf_s("%d", &divider);
    list firstnum = *Init(0);
    list secondnum = *Init(0);
    list thirdnum = *Init(0);

    Count(counter, number);
    Count(counter2, number2);

    while (number)
    {
        int curr = number % 10;
        number /= 10;
        Addelem(&firstnum, curr);
    }
    while (number2)
    {
        int curr = number2 % 10;
        number2 /= 10;
        Addelem(&secondnum, curr);
    }

    list firstnum2 = firstnum;
    list secondnum2 = secondnum;

    CompareList(&firstnum, &secondnum);

    printf_s("\n");
    Listprint(&firstnum2);
    printf_s("\n");
    Listprint(&secondnum2);
    printf_s("\n");
    LongModShort(&firstnum2, divider);
    printf_s("\n");
    LongDivShort(&firstnum2, divider);
    printf_s("\n");
    LongMulShort(&firstnum, divider, &thirdnum);
    Listprint(&thirdnum);

    Delete(&firstnum);
    Delete(&secondnum);
    Delete(&firstnum2);
    Delete(&secondnum2);
    Delete(&thirdnum);

}

