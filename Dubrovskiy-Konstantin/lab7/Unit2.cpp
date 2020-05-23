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
const char FILE_DISCOUNT[] = "c:\\work\\prog\\laba7\\discount.txt";
#define SIZE 128

 double Dialog(FILE *fout)
 {
	Node *temp = lst.Head;
	char answer;
	double discount = 0.0, price = 0.0;
	
	if(!fout) 
		exit(1);
	printf("Welcome to our supermarket! :) \n");
	printf("Please, enter product code and the amount of products. \n");
	Dialog_Buy();
	printf("Do you have a discount card? \n");
	scanf(" %c", &answer);
	if((answer == 'y')|| (answer == '1'))
		discount = Dialog_Discount();
	system("cls");
	printf("______Your Bill______\n");
	fprintf(fout, "______Your Bill______\n");
	while(temp)
	{
		if(temp->count != 0) //if we have bought smth
		{
			double temp_price = temp->price * temp->count;
			
			printf("%s - %.2lf BYN in the amount of %d  = %.2lf \n", temp->name, 
				temp->price, temp->count, temp_price);
			fprintf(fout, "%s - %.2lf BYN in the amount of %d  = %.2lf \n", temp->name, 
				temp->price, temp->count, temp_price); 
			price += temp_price; 			 			
		} 
		  
		temp = temp->Next;
	}		
	printf("______IN TOTAL______\n");
	fprintf(fout, "______IN TOTAL______\n");
	printf("total price: %.2lf", price);
	fprintf(fout, "total price: %.2lf", price);
	if(discount > 0)
	{
		price = price - price*(discount/100); 
		printf(", price whith discount(%.2lf): %.2lf \n", discount, price);
		fprintf(fout, ", price whith discount(%.2lf): %.2lf \n", discount, price);
	}
	else
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
		printf("buying the %s in the amount of %d\n", temp->x, temp->count);
		
		free(code);
		free(count);		
	}    
	 printf("Purchases are finished\n");
 }

 double Dialog_Discount()
 {
	char code[code_len], buffer[SIZE];
	char * str; 
	FILE *fp;

	printf("Enter the card code: ");
	scanf("%s", buffer);
	strncpy(code, buffer, code_len);
	code[code_len] = '\0';
	
	fp = fopen(FILE_DISCOUNT, "r");
	if(!fp)
	{
		printf("FILE_DISCOUNT is not open! ");
		return 0.0;
	}
	while (fgets(buffer, SIZE, fp) != NULL)
	{
		str = strtok (buffer, " \n");
		if( strcmp(code, str) == 0)
		{
			str = strtok(NULL, " \n");
			fclose(fp);
			return atof(str);	
		}
	}
	fclose(fp);
	return 0.0;
 }
