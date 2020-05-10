

#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void Avto(float c, float g, float v, float s) {
	printf("cena:");
	  scanf("%f", &c);
	  printf("let:");
	  scanf("%f", &g);
	  printf("V:");
	  scanf("%f", &v);
	  printf("S:");
	  scanf("%f", &s);
}

void List(float c, float g, float v, float s){
printf("cena:");
printf(&c);
printf("let:");
printf(&g);
printf("obyom:");
printf(&v);
printf("Pyt':");
printf(&s);
}

float Rast(float g, float v, float s)
{
float R;
if(g <= 3){R = v*0.6;}
  else if(g > 3 && g <10){
	if(v < 2500){R = v*0.35;}
   else {R = v*0.6;}
  }
 else if(g >= 10 && g < 14){R = v*0.6;}
 else if(g >= 14){R = v*2;}

 return R;
}

void print_menu() {
	system("cls");  // очищаем экран
	printf("----------------Menu-----------------\n");
	printf("1. Write a list\n");
	printf("2. show resault\n");
	printf("3. Exit\n");
	printf(">");
}

int _tmain(int argc, _TCHAR* argv[]) {
	int variant;
	float c, g, v, s, R, G;

	do {
		print_menu(); // выводим меню на экран
        scanf("%d",&variant);
		switch (variant) {
			case 1:
				Avto(c,g,v,s);
				break;

			case 2:
				  printf("\n peregon = %f", s*0.5);
				  Rast (g,v,s);
				  printf("\n rastomoska: %f",Rast(g, s, v));
				  G = R + s*0.5 + c;
				  printf("\n coast avto = %f",G);
				break;

		}

		if (variant != 3)
			system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнени€ выбранного пункта
	} while (variant !=3);

	return 0;
}
