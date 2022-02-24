#include<stdio.h>
#include<math.h>

double func (double x)
{
    //return powf(x,3)-9*x+3;
    //return powf(2.718281828459045235360287471352662498,x);
    //return ((pow(x-1,2))/(pow(x,2)+1));
    return pow(x,-3.0/2);
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
    double h = (b-a)/n,e = 0.0,f = 0.0f;
    int i;
    double s = 0;
    s += func(a);
    for (i = 1; i < n; i += 2)
        e += func(a+i*h);
    for (i = 2; i < n; i += 2)
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
        printf(" e = %f , x = %f\n modulo = %f \n\n",e,x,modulo(x-e));
    }
    printf("count = %d \n",count);
}


void main()
{

//metodo_simpson (0,1<<30,pow(10,1));

//    printf("%d \n",soma_area(1,1<<30,17));
    /*for (i = 1; 1; i++)
    {
        q = soma_area(0,1,i);
        if (modulo(q-l) < pow(10,-2)) break;
        printf("Executando!!\n");
    }
    printf("i = %d \n",i);*/
//    printf("%.5f\n",soma_area(1,2,6));

}
