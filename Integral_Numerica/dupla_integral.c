#include<stdio.h>
#include<math.h>

double funcS (double x)
{
    //return powf(x,3)-9*x+3;
    return powf(2.718281828459045235360287471352662498 , x);
    //return ((pow(x-1,2))/(pow(x,2)+1));
}
double funcC (double x)
{
    //return powf(x,3)-9*x+3;
    return 3 + pow(2.718281828459045235360287471352662498 , x/5);
    //return ((pow(x-1,2))/(pow(x,2)+1));
}

double funcD (double x)
{
    //return powf(x,3)-9*x+3;
    return log(x);
    //return ((pow(x-1,2))/(pow(x,2)+1));
}

double func (double x,int y)
{
    //return powf(x,3)-9*x+3;
    return sin(x+y);
    //return ((pow(x-1,2))/(pow(x,2)+1));
}

double modulo (double m)
{
    return (m > 0) ? m : -m;
}

//double area (double a,double b)
//{
//    return ((b-a)/2)*func(a)+func(b);
//}

//Essa funcao abaixo retorna a soma das areas dos trapezios, entre intervalos [a,b]  da funcao func (x) , sendo que foram divididos em n trapezios.

double soma_area (double a , double b,int n,int g)
{
    double e = 0.0,f = 0.0f,h = (b-a) / n;
    int i;
    double s = 0;
    s += func(a,g);
    for (i = 1; i < n; i += 2) {
        e += func(a+i*h,g);
    }
    for (i = 2; i < n; i += 2) {
        f += func(a+i*h,g);
    }
    s += 4*e;
    s += 2*f;

    return (h/3)*(s+func(b,g));
}

double dupla_integracao (double a,double b)
{
    double s = 0,h = (b-a)/2;
    double med = (a+b)/2;

    s += (soma_area(funcD(a),funcC(a),2,a) + soma_area(funcD(b),funcC(b),2,b));
    s += 4*soma_area(funcD(med),funcC(med),2,med);
    return s*(h/3);

}

void main()
{
    printf("dupla = %f \n",dupla_integracao(1,3));

}


