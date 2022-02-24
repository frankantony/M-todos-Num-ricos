#include<stdio.h>
#include<math.h>

double func (double x)
{
    //return powf(x,3)-9*x+3;
    //return powf(2.718281828459045235360287471352662498,x);
    //return ((pow(x-1,2))/(pow(x,2)+1));
    return sqrt(x);
}

double modulo (double m)
{
    return (m > 0) ? m : -m;
}

double area (double a,double b)
{
    return ((b-a)/2)*func(a)+func(b);
}

//Essa funcao abaixo retorna a soma das areas dos trapezios , entre intervalos [a,b]  da funcao func (x) , sendo que foram divididos em n trapezios.

double soma_area (double a , double b,int n)
{
    double h = (b-a)/(2*n),e = 0.0,f = 0.0f;
    int i;
    double s = 0;
    s += func(a);
    for (i = 1; i < (2*n); i += 2)
        e += func(a+i*h);
    for (i = 2; i < (2*n); i += 2)
        f += func(a+i*h);
    s += 4*e;
    s += 2*f;
    return (h/3)*(s+func(b));
}

void  metodo_simpson (double a,double b,double c)
{
    int count = 0,i;
    double x,e;
    for (i = 1; 1; i++)
    {
        count++;
        e = soma_area(a,b,i);
        x = soma_area(a,b,i+1);
        if (modulo(e-x) <  c)
        {
            break;
        }
//        printf(" e = %f , x = %f\n modulo = %f \n\n",e,x,modulo(x-e));
    }
    printf("A integral para esse erro eh : %f \n",soma_area(a,b,i));

}


void main()
{
//    printf("soma_area para 2 subintervalos = %f \n",soma_area(0,2,2));

    metodo_simpson (0,2,pow(10,-3));

    printf("soma_area para 4 subintervalos = %f \n",soma_area(0,2,4));
}

