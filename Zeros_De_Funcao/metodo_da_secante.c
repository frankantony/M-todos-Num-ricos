#include<stdio.h>
#include<math.h>

double func (double x)
{
    return powf(x,2)+x-6;
}

double modulo (double m) {
    return (m > 0) ? m : -m;
}

double numero_iteracao (double a,double b,double c)
{
    return ceil((log10(b-a)-log10(c))/log10(2));
}

void  metodo_secante (double a,double b,double c)
{
    int count = 0;
    double x,e = b - a;

    while (1)
    {

        x = (a*func(b)-b*func(a)) / (func(b)-func(a));
        a = b;
        b = x;
        printf("func(%f) = %f \n",x,func(x));

        count++;
        e = x - a;
        printf("modulo(func(a)) = %f \n",modulo(func(x)));
        if(modulo(e) < c ||  modulo(func(x)) < c)  break;

    }
    printf("x = %f e f(x) = %f ,c = %d \n",x,func(x),count);
}


void main()
{
    metodo_secante (1.5,1.7,powf(10,-5));

}

