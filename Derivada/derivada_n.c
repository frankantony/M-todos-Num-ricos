#include<stdio.h>
#include<math.h>

double func (double x)
{
    //return powf(x,3)-9*x+3;
    //return powf(x,2)-7;
    return pow(x,2);
    //return powf(2,7182818284590452353602874713527,x);
    //return ((pow(x-1,2))/(pow(x,2)+1));
}

double derivada (double x,double e)
{
    return (func(x+e)-func(x))/e;
}

double derivada_n(double x,double e,int n)
{
    int i;
    double d;
    d = derivada(x,e);
    for(i = 0; i < n-1; i++)
    {
        //printf("%f \n",d);
        d = derivada(d,e);
    }
    return d;
}

void main()
{
    int i;
    //printf("%f \n",derivada_n(2,pow(10,-5),1));
    for (i = 1; i < 5; i++)
    {
        double s = derivada_n(1,pow(10,-5),i);

        printf("%f \n",s);
    }

}
