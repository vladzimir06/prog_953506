//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#endif
#define SIZE 128

typedef struct node
 {
	 char x[SIZE];
	 char code[9];
	 char name[20];
	 double price;
     int count;
	 struct node *Next, *Prev;
 } Node;

 typedef struct list
 {
	 int length;
	 Node *Head;
	 Node *Tail;
 } List;

 void MyList_Initialize();
 void MyList_Clear();
 void MyList_Add(char x[SIZE]);
 void MyList_Show();

