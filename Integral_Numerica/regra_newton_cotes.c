#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double func (double x)
{
    //return powf(x,3)-9*x+3;
    //return powf(x,2)-7;
    //return ((pow(x-1,2))/(pow(x,2)+1));
    //return pow(2.718281828459045235360287471352662498,x);
    return sqrt(x);
}

///Essa funcao abaixo retorna a soma das areas dos trapezios , entre intervalos [a,b]  da funcao func (x) , sendo que foram divididos em n trapezios.

double soma_area (double a , double b,int n)
{
    double h = (b-a)/n,e = 0.0;
    int i;
    double s = 0;
    s += func(a);
    for (i = 1; i < n; i++)
        e += func(a+i*h);
    s += 2*e;
    return (h/2)*(s+func(b));
}

void  metodo_trapezio (double a,double b,double c)
{
    int count = 0,i;
    double x,e;
    for (i = 2; 1; i++)
    {
        count++;
        e = soma_area(a,b,i);
        x = soma_area(a,b,i+1);
        printf("e = %lf , x = %lf \n modulo = %d\n",e,x,abs(x-e));
        if (abs(e-x) <  c)
        {
            break;
        }
    }
///    printf("count = %d , dividindo em %d trapezios e %d trapezios obtemos uma aproximacao \n",count,i-1,i);
//    printf("%f , %f \n",soma_area(a,b,i-1),soma_area(a,b,i));
    printf("A integral para esse erro eh : %lf \n",soma_area(a,b,i));
}


void main()
{
    printf("soma_area para 4 subintervalos = %lf \n",soma_area(0,2,4));

    metodo_trapezio (0,2,pow(10,-3));
}


