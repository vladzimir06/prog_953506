#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <alloc.h>
#include <string.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

/* Структура, описывающая элемент двунаправленного списка */
typedef struct item {
int digit;
struct item *next;
struct item *prev;
} Item;

/* Структура, описывающая многоразрядное число */
typedef struct mnumber {
Item *head;
Item *tail;
int n;
} MNumber;

MNumber CreateMNumber(char *initStr);
void AddDigit(MNumber *number, int digit);
void PrintMNumber(MNumber number);
MNumber EqualMNumber (MNumber n1, MNumber n2);
MNumber LongMulShortMNumber (MNumber n1, MNumber n2);
MNumber SumMNumber(MNumber n1, MNumber n2);
MNumber RaznMNumber(MNumber n1, MNumber n2);

int _tmain(int argc, _TCHAR* argv[])
{
MNumber a = CreateMNumber("123456789123456789");//123456789123456789
MNumber b = CreateMNumber("987654321987654321");//987654321987654321
MNumber c = LongMulShortMNumber (a,b);
MNumber d = SumMNumber(a,b);
MNumber e = RaznMNumber(a,b);
EqualMNumber (a, b);
PrintMNumber(a);
PrintMNumber(b);
PrintMNumber(c);
PrintMNumber(d);
PrintMNumber(e);
getch();
return 0;
}

MNumber EqualMNumber (MNumber n1, MNumber n2)         //Сравнение
{
MNumber equal = CreateMNumber("");
Item *p1 = n1.head, *p2 = n2.head;
int digit, pos = 0, s1, s2;
while (p1 || p2) {
if (p1) { s1 = p1->digit; p1 = p1->next; }
else s1 = 0;
if (p2) { s2 = p2->digit; p2 = p2->next; }
else s2 = 0;
AddDigit(&equal, digit);
}
if(s1 == s2){printf("Equal : 0");}
else if(s1 > s2){printf("Equal : 1");}
else if(s1 < s2){printf("Equal : -1");}
return equal;
}

MNumber LongMulShortMNumber (MNumber n1, MNumber n2)     //Умножение на int
{
MNumber Mul = CreateMNumber("");
Item *p1 = n1.head; //*p2 = n2.head;
int digit, pos = 0, s1, s2;
while (p1) {
if (p1) { s1 = p1->digit; p1 = p1->next; }
else s1 = 0;
digit = (s1 * 2 + pos) %10 ;
pos = (s1 * 2 + pos) /10;
AddDigit(&Mul, digit);
}

if (pos) AddDigit(&Mul, pos);
return Mul;
}

MNumber SumMNumber(MNumber n1, MNumber n2)
{
MNumber sum = CreateMNumber("");
Item *p1 = n1.head, *p2 = n2.head;
int digit, pos = 0, s1, s2;
while (p1 || p2){
if (p1){s1 = p1->digit; p1 = p1->next;}
else {s1 = 0;}
if (p2){s2 = p2->digit; p2 = p2->next;}
else {s2 = 0;}
digit = (s1 + s2 + pos) % 10;
pos = (s1 + s2 + pos) / 10;
AddDigit(&sum, digit);
}

if (pos) AddDigit(&sum, pos);
return sum;
}

 MNumber RaznMNumber(MNumber n1, MNumber n2)
{
MNumber razn = CreateMNumber("");
Item *p1 = n1.head, *p2 = n2.head;
int digit = 0, pos = 0, s1 = 0, s2 = 0;
while (p1 || p2){
if (p1){
if((s1 - s2) >= 0) {s1 = p1->digit;}
else s1 = p1->digit - 1;
p1 = p1->next;
}
else s1 = 0;
if (p2){s2 = p2->digit; p2 = p2->next;}
else {s2 = 0;}
if ((s1 - s2) >= 0) digit = (s1 - s2 + pos) % 10;
else digit = (10 + s1 - s2 + pos) % 10;
pos = (s1 + s2 + pos) / 10;
AddDigit(&razn, digit);
}

if (pos) AddDigit(&razn, pos);
return razn;
}

MNumber CreateMNumber(char initStr[])
{
MNumber number = {NULL, NULL, 0};
int n;
for (n = strlen(initStr)-1; n >= 0; n--)
AddDigit(&number, initStr[n]-'0');
return number;
}

void AddDigit(MNumber *number, int digit)
{
Item *p = (Item *)malloc(sizeof(Item));
p->digit = digit;
p->next = p->prev = NULL;
if (number->head == NULL)
number->head = number->tail = p;
else {
number->tail->next = p;
p->prev = number->tail;
number->tail = p;
}

number->n++;
}

/* Выводит многоразрядное число на экран */
void PrintMNumber(MNumber number)
{
Item *p = number.tail;
printf("\nNumber: ");
while (p) {
printf("%d", p->digit);
p = p->prev;
}
}
