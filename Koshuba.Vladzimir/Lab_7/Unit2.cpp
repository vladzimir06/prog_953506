//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <cctype>
#include <conio.h> 

extern List lst;
Node *temp = lst.Head;
const int code_len = 8;
const int count_len = 4;
#define SIZE 128

 double Dialog(FILE *fout)
 {
	Node *temp = lst.Head;
	char answer;
	double discount = 0.0, price = 0.0;

	if(!fout)
		getch();
	printf("Welcome to our Store! :) \n");
	printf("Please, enter book code . \n");
	Dialog_Buy();
	system("cls");
	printf("-----------------\n");
	fprintf(fout, "----------------\n");
	while(temp)
	{
		if(temp->count != 0) //if we have bought smth
		{
			double temp_price = temp->price * temp->count;
			
			printf("%s - %.2lf BYN (%d) = %.2lf \n", temp->name,
				temp->price, temp->count, temp_price);
			fprintf(fout, "%s - %.2lf BYN (%d)  = %.2lf \n", temp->name,
				temp->price, temp->count, temp_price); 
			price += temp_price; 			 			
		} 
		  
		temp = temp->Next;
	}		
	printf("______The Resoult______\n");
	fprintf(fout, "______The Resoult______\n");
	printf("total price: %.2lf", price);
	fprintf(fout, "total price: %.2lf", price);
		printf("\n");

	return price;
 }

 void Dialog_Buy()
 {
	int breakpoint = 0;
	
	while(1)
	{
		char *code = (char*)malloc(code_len*sizeof(char));
		char *count = (char*)malloc(count_len*sizeof(char));
		
		temp = lst.Head; 	
		char ch;

		printf("--------\n");
		//Input:
		printf("enter code: ");
		for(int i = 0; i < code_len; i++)
		{ 						
			ch = getchar();
			code[i] = ch;
			if(i == 1)
				if((code[i] == '\n') && (code[i-1] == '\n')) //if double ENTER pressed - berakpoint;
				{
					breakpoint = 1;
					break;
				}
			if((count[i] == '\n') && i > 1) //when  ENTER pressed - stop
				{
					count[i]= '\0';
					break;
				}
			if(i == code_len-1)
			{
				count[i+1]= '\0';
				break;
			}
		}		
		if (breakpoint) break; //from the while(1)  
		printf(" ");
		getchar();
		
		while(temp) //finding code
		{
			if (strcmp(code, temp->code) == 0) break;
			temp = temp->Next;
		}
		
		if(!temp) 
		{
			printf("No such code! :( \n");
			getch();
			continue;
		}
		else 
			printf("  "); //space

		printf("enter number: ");
		for(int i = 0; i < count_len-1; i++)
		{
			ch = getchar();
			count[i] = ch;
			if((count[i] == '\n') && i == 0) //if ENTER is pressed on i[0]
			{
				temp->count += 1;
				break;
			}
			else
				if((count[i] == '\n') && i != 0) //when  ENTER pressed - stop
				{
					count[i]= '\0';
					break;
				}
			if(i == count_len-2)
			{
				count[i+1]= '\0';
				break;
			}
		}
		if ( isdigit(count[0]) ) // if input is digit
			temp->count += atoi (count);
			
		if(!temp->count) //if count == 0 - new cycle
			continue;
		//Output:
		printf("buying the %s (%d)\n", temp->x, temp->count);

		free(code);
		free(count);
	}
	 printf("Purchases are finished\n");
 }


