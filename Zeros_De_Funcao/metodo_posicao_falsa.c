#include<stdio.h>
#include<math.h>

double func (double x)
{
    //return pow(x,3)-9*x+3;
    return pow(x,2)-7;
}
double modulo (double m)
{
    return (m > 0) ? m : -m;
}
double numero_iteracao (double a,double b,double c)
{
    return ceil((log10(b-a)-log10(c))/log10(2));
}

void  metodo_posicao_falsa (double a,double b,double c)
{
    int count = 0;
    double x,e = b - a;

    while (1)
    {

        x = (a*func(b)-b*func(a)) / (func(b)-func(a));

        if ((func(a) < 0 && func(x) < 0) || (func(a) > 0 && func(x) > 0))
        {
            a = x;
        }
        else if ((func(x) < 0 && func(b) < 0) || (func(x) > 0 && func(b) > 0))
        {
            b = x;
        }
        printf("func(%f) = %lf  , e = %lf \n",x,func(x),e);

        count++;
        if(modulo(func(x)) < c) break;
        e = b - a;

    }
    printf("x = %f e f(x) = %f ,c = %d \n",x,modulo(func(x)),count);
}


void main()
{

    metodo_posicao_falsa(2,3,5*pow(10,-7));

}

