#include<stdio.h>
#include<math.h>

double func (double x)
{
    //return powf(x,3)-9*x+3;
    //return powf(2.718281828459045235360287471352662498,x);
    //return ((pow(x-1,2))/(pow(x,2)+1));
    return sqrt(x);
}

double metodo_dupla_exponenciacao (double a,double b,double y) {
    double x_y = 0.5*(a+b+(b-a)*tanh(3.14/2*sinh(y))) , d_x_y = (b-a)*((3.14/2*cosh(y)))/(cosh(3.14/2*sinh(y))*cosh(3.14/2*sinh(y)));
    return func(x_y)/d_x_y;
}


void main()
{

    double r = metodo_dupla_exponenciacao (0,1,pow(10,-3));
    printf("%.7f\n",r);
}



