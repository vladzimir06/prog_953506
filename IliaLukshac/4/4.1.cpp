#include <iostream>
#include <malloc.h>

int main(){
int n = 0;
char *a = (char*) malloc(100 * sizeof(char));
std::cout << "Enter the string: \n";
gets(a);

	while (a[n] != '\0') {
		n++;
	}

	for (int i = n; i >= 0; i--){
		if(isalpha (a[i])){
			std::cout << a[i];
			
		}
		else{
		
			if (isalpha (a[i + 1]) != 0 && isalpha (a[i]) == 0 ){
				std::cout << " ";
			}
		}
		
		
	}
free(a);
}

	
	

