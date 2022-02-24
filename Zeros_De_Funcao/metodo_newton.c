#include<stdio.h>
#include<math.h>


double func (double x)
{
    //return powf(x,3)-9*x+3;
    //return powf(x,2)-7;
    return ((pow(x-1,2))/(pow(x,2)+1));
    //return 35*pow(x,4) - 30*pow(x,2) + 3;
}

double modulo (double m)
{
    return (m > 0) ? m : -m;
}

double derivada (double x,double e) {
    return (func(x+e)-func(x))/e;
}

double numero_iteracao (double a,double b,double c)
{
    return ceil((log10(b-a)-log10(c))/log10(2));
}

void  metodo_newton (double a,double c)
{
    int count = 0;
    double x,e = a,d = 0;
    printf("func (%f) =  %f \n",a,func(a));

    while (1)
    {

        //x = a-((func(a))/(3*powf(a,2)-9));
        x = a-((func(a))/ derivada(a,c));  //*((2*pow(a,2)-2)/(pow(a,4)+2*pow(a,2)+1)))*/

        if(modulo(func(x)) < c || modulo(x-a) < c)  break;
        a = x;
        printf("func(%.15f) = %.15f \n",x,func(x));

        count++;
        //e = a;
    }
    printf("x = %.15f e f(x) = %.15f ,c = %d \n",x,func(x),count);
}


void main()
{

    metodo_newton (0,1*powf(10,-3));

}
