#include<stdio.h>
#include<math.h>

double func (double x)
{
    return pow(2.718281828459045235360287471352662498,x)-x-2;
    //return pow(x,3)-9*x+3;
    //return pow(x,2)-7;
}

double numero_iteracao (double a,double b,double c) {
    return ceil((log10(b-a)-log10(c))/log10(2));
}

void  metodo_bissecao (double a,double b,double c)
{
    int count = 0;
    double x,e = b - a;

    while (e >= c)
    {

        x = (a+b) / 2;

        //printf("func(%f) = %f  , func(%f) = %f , func(%f) = %f\n",a,func(a),b,func(b),x,func(x));
        if ((func(a) < 0 && func(x) > 0) || (func(a) > 0 && func(x) < 0))
        {
            b = x;
        }
        else if (((func(x) < 0 && func(b) > 0) || (func(x) > 0 && func(b) < 0)) || func (a)*func(b) > 0)
        {
            a = x;
        }
        e = b - a;

        printf("func(%f) = %f , e = %f \n I = (%f,%f) \n",x,func(x),e,a,b);
        count++;

    }
    printf("c = %d , x = %f \n",count,x);
}


void main()
{
    metodo_bissecao(1,2,pow(10,-3));
    printf("%f \n",numero_iteracao(1,2,pow(10,-3)));

}
