#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
#include <conio.h>
#include <math.h>

int _tmain(int argc, _TCHAR* argv[]) 
{  int n, sum0 = 0, sum1 = 1;
srand(time(NULL));
printf("n:");
scanf("%d", &n);
int cube[n][n][n];
for (int i = 0; i < n; i++){
   for (int j = 0; j <n; j++){
	  for (int k = 0; k < n; k++){
		 cube[i][j][k] = rand() % 2;
			printf ("%d ", cube[i][j][k]);
			if(cube[i][j][k] == 0){sum0++;}
			else if(cube[i][j][k] == 1){sum1++;}
	  }
		printf("\n");
		
   }
}
printf("\n%d", sum0);
printf("\n%d", sum1);
printf("\n");

getch();
return 0;
}
