#include<stdio.h>
#include<math.h>

double func(double x)
{
    return pow(2.718281828459045235360287471352662498,x);
//    return sqrt(x);
}

double metodo_area_trapezio (double a,double b,double s)
{
    double r = 0.0,e,divisao = (b-a)/s;
    int i;
    double area = (func(a)+func(b))*(b-a);
    double m = func(b)-func(a);
    r += func(a);
    for(i = 1; i < s; i++)
    {
        e += func(divisao*i);
    }

    r += func((b-a));
    r += 2*e;
    return (divisao/2)*r;
}

void main()
{
    double y,z;
    double i;
    //printf("Digite as subdivisoes \n");
    //scanf("%f%f",&y,&z);

    double s = metodo_area_trapezio(0,1,10);

    printf("A soma das areas do trapezio para 10 divisoes eh : %.10f \n",s);


}
