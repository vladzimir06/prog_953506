#include <iostream>
#include <malloc.h>
#include <fstream>


int main(){
	FILE* fp;
	char name[] = "1.txt";
	int n = 0, count1 = 0, count2 = 0, counter = 0, position = 0, counter1 = 0, counter2 = 0, k = 0;;
	char *a = (char*) malloc(100 * sizeof(char));
	
	if ((fp = fopen(name, "rt")) == NULL)
    {
        printf("fail");
        getchar();
        return 0;
    }
    else
    {
        while (fin >> N)
        {
            a[k++] = N;
        }
	
std::cout << "Enter the string: \n";
gets(a);

	while (a[n] != '\0')
	{
		n++;
	}
	
	for (int i = 0; i < n; i++)
	{
		if(a[i] == '[' || a[i] == '(' || a[i] == '{' )
		{
			count1++;
		}
		if(a[i] == ']' || a[i] == ')' || a[i] == '}')
		{
			count2++;
		}	
	}
	if(count1 == count2)
	{
		
		for (int i = 0; i < n; i++)
		{
			//ñheking for {}
			if(a[i] == '}')
			{
				if (i == '0')
				{
					printf("brackets are not placed correctly \n");	
					break;
				}
			counter = i;
			
				while(counter != 0)
				{
					if(a[counter] == '{')
					{
						position = counter;
						break;
					}
					counter--;
				}
				if(position == 0){
					printf("brackets are not placed correctly \n");	
					break;
				}
				for(int i = position; i <= counter; i++)
				{
						if(a[i] == '[' || a[i] == '(' || a[i] == '{' )
						{
							counter1++;
						}
						if(a[i] == ']' || a[i] == ')' || a[i] == '}')
						{
							counter2++;
						}	
				}
				if (counter1 != counter2)
				{
					printf("brackets are not placed correctly \n");	
					break;	
				}
			}
			//ñheking for []
			if(a[i] == ']')
			{
				if (i == '0')
				{
					printf("brackets are not placed correctly \n");	
					break;
				}
			counter = i;
			
				while(counter != 0)
				{
					if(a[counter] == '[')
					{
						position = counter;
						break;
					}
					counter--;
				}
				if(position == 0){
					printf("brackets are not placed correctly \n");	
					break;
				}
					for(int i = position; i <= counter; i++)
				{
						if(a[i] == '[' || a[i] == '(' || a[i] == '{' )
						{
							counter1++;
						}
						if(a[i] == ']' || a[i] == ')' || a[i] == '}')
						{
							counter2++;
						}	
				}
				if (counter1 != counter2)
				{
					printf("brackets are not placed correctly \n");	
					break;	
				}
			}
			//ñheking for ()
			if(a[i] == ')')
			{
				if (i == '0')
				{
					printf("brackets are not placed correctly \n");	
					break;
				}
			counter = i;
			
				while(counter != 0)
				{
					if(a[counter] == '('){
						position = counter;
						break;
					}
					counter--;
				}
				if(position == 0)
				{
					printf("brackets are not placed correctly \n");	
					break;
				}
					for(int i = position; i <= counter; i++)
				{
						if(a[i] == '[' || a[i] == '(' || a[i] == '{' )
						{
							counter1++;
						}
						if(a[i] == ']' || a[i] == ')' || a[i] == '}')
						{
							counter2++;
						}	
				}
				if (counter1 != counter2)
				{
					printf("brackets are not placed correctly \n");	
					break;	
				}
			}
		}		
		
	}
	else
	{
		printf("brackets are not placed correctly \n");
		printf("the number of brackets of each type does not match");
	}

	return 0;
}
