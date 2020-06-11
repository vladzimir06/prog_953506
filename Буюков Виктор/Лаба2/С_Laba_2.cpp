// Вариант 26 
/*Алгебраический полином. Разработать программу, меню которой позволяет выполнить 
  следующие функции: 
  1. Ввод полинома 3 степени. 
  2. Вывод полинома. 
  3. Нормализация полинома. 
  4. Дифференцирование полинома. 
  5. Интегрирование полинома. 
  6. Вычисление значения полинома для заданного х. 
  7. Информация о версии и авторе программы. 
  8. Выход из программы. 
  */

#include <stdio.h>
#include <stdlib.h>// подключил для очистки консоли

#define TRUE 1

void InputPolynomial(int &a, int& b, int& c, int& d, int& e, int& normalize)
{
    system("cls");
    printf("Choose form of polynomial:\n"
        "1.ax^3+bx^2+cx+d\n"
        "2.e(ax^3+bx^2+cx+d)\n"
        "3.e(ax^3+bx^2+cx)+d\n"
        "4.e(ax^3+bx^2)+cx+d\n"
        "5.ex(ax^2+bx+c)+d\n"
        "6.ex^2(ax+b)+cx+d\n"
    );
    scanf_s("%d", &normalize);
    switch (normalize)
    {
    case 1:
    {       
        printf("\na = ");
        scanf_s("%d", &a);

        printf("\nb = ");
        scanf_s("%d", &b);

        printf("\nc = ");
        scanf_s("%d", &c);

        printf("\nd = ");
        scanf_s("%d", &d);
    } break;

    case 2:
    {       
        printf("\na = ");
        scanf_s("%d", &a);

        printf("\nb = ");
        scanf_s("%d", &b);

        printf("\nc = ");
        scanf_s("%d", &c);

        printf("\nd = ");
        scanf_s("%d", &d);

        printf("\ne = ");
        scanf_s("%d", &e);
    } break;

    case 3:
    {      
        printf("\na = ");
        scanf_s("%d", &a);

        printf("\nb = ");
        scanf_s("%d", &b);

        printf("\nc = ");
        scanf_s("%d", &c);

        printf("\nd = ");
        scanf_s("%d", &d);

        printf("\ne = ");
        scanf_s("%d", &e);
    } break;

    case 4:
    {       
        printf("\na = ");
        scanf_s("%d", &a);

        printf("\nb = ");
        scanf_s("%d", &b);

        printf("\nc = ");
        scanf_s("%d", &c);

        printf("\nd = ");
        scanf_s("%d", &d);

        printf("\ne = ");
        scanf_s("%d", &e);
    } break;

    case 5:
    {
        printf("\na = ");
        scanf_s("%d", &a);

        printf("\nb = ");
        scanf_s("%d", &b);

        printf("\nc = ");
        scanf_s("%d", &c);

        printf("\nd = ");
        scanf_s("%d", &d);
    } break;

    case 6:
    {
        printf("\na = ");
        scanf_s("%d", &a);

        printf("\nb = ");
        scanf_s("%d", &b);

        printf("\nc = ");
        scanf_s("%d", &c);

        printf("\nd = ");
        scanf_s("%d", &d);
    } break;

    default:
    {
        printf("\na = ");
        scanf_s("%d", &a);

        printf("\nb = ");
        scanf_s("%d", &b);

        printf("\nc = ");
        scanf_s("%d", &c);

        normalize = 1;
    }
    }  
}

void OutputPolynomial(int& a, int& b, int& c, int& d, int& e, int& normalize)
{
    switch (normalize)
    {        
     case 1:
     {
         if (a > 0) printf("%dx^3", a);
         if (a < 0) printf("-%dx^3", a);

         if (b > 0) printf("%dx^2", b);
         if (b < 0) printf("-%dx^2", b);

         if (c > 0) printf("%dx", c);
         if (c < 0) printf("-%dx", c);

         if (d > 0) printf("%d", d);
         if (d < 0) printf("-%d", d);
     }break;

     case 2:
     {
         if (e > 0) printf("%d(", e);
         if (e < 0) printf("-%d(", e);

         if (a > 0) printf("%dx^3", a);
         if (a < 0) printf("-%dx^3", a);

         if (b > 0) printf("%dx^2", b);
         if (b < 0) printf("-%dx^2", b);

         if (c > 0) printf("%dx", c);
         if (c < 0) printf("-%dx", c);

         if (d > 0) printf("%d)", d);
         if (d < 0) printf("-%d)", d);
     }break;

     case 3:
     {
         if (e > 0) printf("%d(", e);
         if (e < 0) printf("-%d(", e);
         if (e != 0) 
         {
             if (a > 0) printf("%dx^3", a);
             if (a < 0) printf("-%dx^3", a);

             if (b > 0) printf("%dx^2", b);
             if (b < 0) printf("-%dx^2", b);

             if (c > 0) printf("%dx)", c);
             if (c < 0) printf("-%dx)", c);
         }

         if (d > 0) printf("%d", d);
         if (d < 0) printf("-%d", d);
     }break;

     case 4:
     {
         if (e > 0) printf("%d(", e);
         if (e < 0) printf("-%d(", e);
         if (e != 0) 
         {
             if (a > 0) printf("%dx^3", a);
             if (a < 0) printf("-%dx^3", a);

             if (b > 0) printf("%dx^2)", b);
             if (b < 0) printf("-%dx^2)", b);
         }        

         if (c > 0) printf("%dx", c);
         if (c < 0) printf("-%dx", c);

         if (d > 0) printf("%d", d);
         if (d < 0) printf("-%d", d);
     }break;

     case 5:
     {
         if (e > 0) printf("%d(", e);
         if (e < 0) printf("-%d(", e);
         if (e != 0)
         {
             if (a > 0) printf("%dx^3", a);
             if (a < 0) printf("-%dx^3", a);

             if (b > 0) printf("%dx^2", b);
             if (b < 0) printf("-%dx^2", b);

             if (c > 0) printf("%dx)", c);
             if (c < 0) printf("-%dx)", c);
         }

         if (d > 0) printf("%d", d);
         if (d < 0) printf("-%d", d);
     }break;

     case 6:
     {
         if (e > 0) printf("%dx^2(", e);
         if (e < 0) printf("-%dx^2(", e);
         if (e != 0)
         {
             if (a > 0) printf("%dx", a);
             if (a < 0) printf("-%dx", a);

             if (b > 0) printf("%d)", b);
             if (b < 0) printf("-%d)", b);
         }

         if (c > 0) printf("%dx", c);
         if (c < 0) printf("-%dx", c);

         if (d > 0) printf("%d", d);
         if (d < 0) printf("-%d", d);
     }break;

     case -1:
     {
         if (a > 0) printf("%dx^2", a);
         if (a < 0) printf("-%dx^2", a);

         if (b > 0) printf("%dx", b);
         if (b < 0) printf("-%dx", b);

         if (c > 0) printf("%d", c);
         if (c < 0) printf("-%d", c);        
     }break;

     case -2:
     {
         printf("x^4/4 + x^3/3 + x^2/2 + x");
     }break;
    }
}

void NormalizePolynomial(int& a, int& b, int& c, int& d, int& e, int& normalize)
{
    switch (normalize)
    {
    case 0: printf("You don't input polynomial"); break;
    case 1: printf("Your polynomial normalize"); break;
    case 2:
    {
        a = a * e;
        b = b * e;
        c = c * e;
        d = d * e;
        normalize = 1;
        printf("%dx^3+%dx^2+%dx+%d", a, b, c, d);
    } break;

    case 3:
    {
        a = a * e;
        b = b * e;
        c = c * e;
        normalize = 1;
    } break;

    case 4:
    {
        a = a * e;
        b = b * e;
        normalize = 1;
    } break;

    case 5:
    {
        a = a * e;
        b = b * e;
        c = c * e;
        normalize = 1;
    } break;

    case 6:
    {
        a = a * e;
        b = b * e;
        normalize = 1;
    } break;
    }
}

void DifferentiatePolynomial(int& a, int& b, int& normalize)
{
    switch (normalize)
    {
    case 0: printf("You don't input polynomial"); break;
    case 1:
    {       
        a = a * 3;
        b = b * 2;
        normalize = -1;
    }break;

    default:
    {
        printf("Normalize your polynomial");
    }break;

    }
}

void IntegratePolynomial(int& a, int& b, int& c, int& normalize)
{
    switch (normalize)
    {
    case 0: printf("You don't input polynomial"); break;

    case 1:
    {
        a = a / 4;
        b = b / 3;
        c = c / 2;
        normalize = -2;
    }break;

    case -1:
    {
        printf("Differentiate polynomial");
    }break;

    case -2:
    {
        printf("Integrate polynomial");
    }break;

    default:
    {
        printf("Normalize your polynomial");
    }break;

    }
}

void CalculatePolynomialValueForAGivenX(int& a, int& b, int& c, int& d, int& x, double& rez, int& normalize)
{
    switch (normalize)
    {
    case 1:
    {        
            printf("x = ");
            scanf_s("%d", &x);

            int res = a * x * x * x + b * x * x + c * x + d;
            printf("result = %d", res);      
    }break;

    case -1:
    {
        printf("x = ");
        scanf_s("%d", &x);

        int res = a * x * x + b * x + c;
        printf("result = %d", res);
    }break;

    case -2:
    {
        printf("x = ");
        scanf_s("%d", &x);

        int res = a / (x * x * x * x) + b / (x * x * x) + c / (x * x);
        printf("result = %d", res);
    }break;

    default:
        break;
    }
}


int main()
{
    int N, a = 0, b = 0, c = 0, d = 0, e = 0, x = 1, normalize = 0;
    double rez = 0;

    while (TRUE)
    {   
        printf("This program is created to do operations "
            "with polynomials\n"
            "\nWhat do you want to do?\n"
            "1.Input polynomial\n"
            "2.Output polynomial\n"
            "3.Normalize polynomial\n"
            "4.Differentiate polynomial\n"
            "5.Integrate polynomial\n"
            "6.Calculate polynomial value for a given x\n"            
            "7.Exit the program\n");
        scanf_s("%d", &N);

        switch (N)
        {
        case 1:
        {  
          InputPolynomial(a, b, c, d, e, normalize);
        } break;

        case 2: 
        {
            OutputPolynomial(a, b, c, d, e, normalize);
        } break;

        case 3:
        {
            NormalizePolynomial(a, b, c, d, e, normalize);
        } break;

        case 4:
        {
            DifferentiatePolynomial(a,b,normalize);
        } break;

        case 5:
        {   
            IntegratePolynomial(a, b, c, normalize);
        }break;

        case 6:
        {  
            CalculatePolynomialValueForAGivenX(a,b,c,d,x,rez,normalize);
        }break;

        case 7: return 0; break;

        }
        if ((e == 0)&&(normalize==2)) return 0;
        }

    system("cls");
}



