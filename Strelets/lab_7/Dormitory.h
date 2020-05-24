#include <malloc.h>
#include <iostream>
#ifndef DormitoryH
#define DormitoryH
//---------------------------------------------------------------------------
#endif
#define size = 50;
#define floors = 7;

using namespace std;

typedef char tSurname[20];
typedef char tName[20];
typedef int tKurs;
typedef int tGroup;
typedef char tViolations[5];
typedef char tNumber[20];
typedef int tRoom;
typedef int tFloor;

enum Faculty
{
    FKP = 1,
    FITU,
    FKSIS,
    FRE,
    FIK,
    IEF,
    VF
};

struct node
{
    tRoom room;
    tFloor floor;
    tSurname surname;
    tName name;
    tKurs kurs;
    tGroup group;
    tViolations violations;
    Faculty faculty;
    struct node* Next, * Prev;
};

struct list
{
    int length;
    struct node* Head;
};

struct list* Init()
{
    struct list* lst;
    lst = (struct list*)malloc(sizeof(struct list));
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    lst->Head = head;
    lst->Head->Prev = nullptr;
    lst->Head->Next = nullptr;
    lst->length = 0;
    return(lst);
}

struct Workers
{
    tName name;
    tNumber number;
};

int Size = 0;

void LoadWorkers(Workers* work)
{
    FILE* file;
    fopen_s(&file, "DormitoryWorkers.txt", "r");
    tName str;

    if(!file)
        exit(0);
    else
    {
        for(int i = 0; i < 5; i++)
        {
            fgets(work[i].name, 20, file);
            fgets(work[i].number, 20, file);
        }
        fclose(file);
        return;
    }
}

void AddToBase(list* List)
{
    FILE* fp;
    fp = fopen("Dormitory.txt", "w");  
    while (List->Head->Prev != nullptr)
        List->Head = List->Head->Prev;

    char* mass = (char*)malloc(2 * sizeof(char));
    int num = List->Head->room;
    mass[0] = num + '0';
    mass[1] = '\0';
    while (List->Head != nullptr)
    {
        fprintf(fp, List->Head->name);
        fprintf(fp, "\n");
        fprintf(fp, List->Head->surname);
        fprintf(fp, "\n");
        fprintf(fp, mass);
        fprintf(fp, "\n");
        List->Head = List->Head->Next;
    }

    fclose(fp);
}

void AddMember(list* List)
{
    List->length++;
    int value = 0;
    if(List->length == 1)
    {
        printf("\nEnter Name: ");
        scanf("%s", List->Head->name);
        printf("\nEnter surname: ");
        scanf("%s", List->Head->surname);
        printf("\nEnter kurs: ");
        scanf("%d", &value);
        List->Head->kurs = value;
        printf("\nEnter group: ");
        scanf("%d", &value);
        List->Head->group = value;
        printf("\nEnter faculty: ");
        scanf("%d", &value);
        printf("Enter + if he have violtaions");
        scanf("%s", List->Head->violations);
        List->Head->faculty = (Faculty)value;
        List->Head->room = ++Size;
        List->Head->floor = (Faculty)value;

    }
    else
    {
        node* prev = (node*)malloc(sizeof(node));
        prev = List->Head;
        List->Head = List->Head->Next;
        node* head = (node*)malloc(sizeof(node));
        List->Head = head;
        List->Head->Next = nullptr;
        List->Head->Prev = prev;
        printf("\nEnter Name: ");
        scanf("%s", List->Head->name);
        printf("\nEnter surname: ");
        scanf("%s", List->Head->surname);
        printf("\nEnter kurs: ");
        scanf("%d", &value);
        List->Head->kurs = value;
        printf("\nEnter group: ");
        scanf("%d", &value);
        List->Head->group = value;
        printf("\nEnter faculty: ");
        scanf("%d", &value);
        printf("Enter + if he have violtaions");
        scanf("%s", List->Head->violations);
        List->Head->faculty = (Faculty)value;
        List->Head->room = ++Size;
        List->Head->floor = (Faculty)value;
    }
    return;
}

void DeleteMember(list* lst)
{
    printf_s("Enter name: ");
    tName namehelp;
    scanf("%s", &namehelp);
    while (lst->Head->Prev != nullptr)
        lst->Head = lst->Head->Prev;
    while (lst->Head->Next != nullptr)
    {
        for (int i = 0; namehelp[i] != '\0' || lst->Head->name[i] != '\0'; i++)
            if (namehelp[i] != lst->Head->name[i])
            {
                lst->Head = lst->Head->Next;
                break;
            }
        if (lst->Head->Prev && lst->Head->Next)
        {
            node *help1 = (node*)malloc(sizeof(node));
            node *help2 = (node*)malloc(sizeof(node));
            help1 = lst->Head->Prev;
            help2 = lst->Head->Next;
            help1->Next = help2;
            help2->Prev = help1;
        }
    }
    for (int i = 0; namehelp[i] != '\0' || lst->Head->name[i] != '\0'; i++)
        if (namehelp[i] != lst->Head->name[i])
        {
            break;
        }
    if (lst->Head->Prev && lst->Head->Next)
    {
        node* help1 = (node*)malloc(sizeof(node));
        node* help2 = (node*)malloc(sizeof(node));
        help1 = lst->Head->Prev;
        help2 = lst->Head->Next;
        help1->Next = help2;
        help2->Prev = help1;
    }
    
    
}

void SearchName(list* lst)
{
    printf_s("Enter name: ");
    tName namehelp;
    scanf("%s", &namehelp);
    while (lst->Head->Prev != nullptr)
        lst->Head = lst->Head->Prev;
    while (lst->Head->Next != nullptr)
    {
        for(int i = 0; namehelp[i] != '\0' || lst->Head->name[i] != '\0'; i++)
            if (namehelp[i] != lst->Head->name[i])
            {
                lst->Head = lst->Head->Next;
                break;
            }
        printf_s("\nName: %s", lst->Head->name);
        printf_s("\nSurname: %s", lst->Head->surname);
        printf_s("\nKurs: %d", lst->Head->kurs);
        printf_s("\nGroup: %d", lst->Head->group);
        printf_s("\nFaculty: %d", (int)lst->Head->faculty);
        printf_s("\nRoom: %d", lst->Head->room);
        printf_s("\nFloor: %d", lst->Head->floor);
    }
    for (int i = 0; namehelp[i] != '\0' || lst->Head->name[i] != '\0'; i++)
        if (namehelp[i] != lst->Head->name[i])
        {
            break;
        }
    printf_s("\nName: %s", lst->Head->name);
    printf_s("\nSurname: %s", lst->Head->surname);
    printf_s("\nKurs: %d", lst->Head->kurs);
    printf_s("\nGroup: %d", lst->Head->group);
    printf_s("\nFaculty: %d", (int)lst->Head->faculty);
    printf_s("\nRoom: %d", lst->Head->room);
    printf_s("\nFloor: %d", lst->Head->floor);
}

void Report(list *lst)
{
    while (lst->Head->Prev != nullptr)
    {
        printf_s("\nName: %s", lst->Head->name);
        printf_s("\nSurname: %s", lst->Head->surname);
        printf_s("\nKurs: %d", lst->Head->kurs);
        printf_s("\nGroup: %d", lst->Head->group);
        printf_s("\nFaculty: %d", (int)lst->Head->faculty);
        printf_s("\nRoom: %d", lst->Head->room);
        printf_s("\nFloor: %d", lst->Head->floor);
        lst->Head= lst->Head->Prev;
    }
    printf_s("\nName: %s", lst->Head->name);
    printf_s("\nSurname: %s", lst->Head->surname);
    printf_s("\nKurs: %d", lst->Head->kurs);
    printf_s("\nGroup: %d", lst->Head->group);
    printf_s("\nFaculty: %d", (int)lst->Head->faculty);
    printf_s("\nRoom: %d", lst->Head->room);
    printf_s("\nFloor: %d", lst->Head->floor);
}

void SearchRoom(list* lst)
{
    printf_s("Enter room: ");
    tRoom namehelp;
    scanf("%d", &namehelp);
    while (lst->Head->Prev != nullptr)
        lst->Head = lst->Head->Prev;
    while (lst->Head->Next != nullptr)
    {
        if (lst->Head->room == namehelp)
        {
            printf_s("\nName: %s", lst->Head->name);
            printf_s("\nSurname: %s", lst->Head->surname);
            printf_s("\nKurs: %d", lst->Head->kurs);
            printf_s("\nGroup: %d", lst->Head->group);
            printf_s("\nFaculty: %d", (int)lst->Head->faculty);
            printf_s("\nRoom: %d", lst->Head->room);
            printf_s("\nFloor: %d", lst->Head->floor);
        }
        else
            lst->Head = lst->Head->Next;
    }
    if (lst->Head->room == namehelp)
    {
        printf_s("\nName: %s", lst->Head->name);
        printf_s("\nSurname: %s", lst->Head->surname);
        printf_s("\nKurs: %d", lst->Head->kurs);
        printf_s("\nGroup: %d", lst->Head->group);
        printf_s("\nFaculty: %d", (int)lst->Head->faculty);
        printf_s("\nRoom: %d", lst->Head->room);
        printf_s("\nFloor: %d", lst->Head->floor);
    }
}

void Delete(list* lst, Workers* work)
{
    free(work);
    while (lst->Head->Next != nullptr)
    {
        lst->Head = lst->Head->Next;
        free(lst->Head->Prev);
    }
    free(lst->Head);
}


