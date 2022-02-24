#include<stdio.h>
#include<math.h>

///funcao
double func_2(double x)
{
//    return pow(2.718,x);
    return pow(2.718,-(x*x)/2);
}
///calcula a integral no intervalo  [-1,1]
double func_integral (double x) {
    return func_2(-sqrt(3)/3) + func_2(sqrt(3)/3);
}

///adapta para que possa calcular a integral no intervalo [a,b].
double integral_gaus_legendre (double a,double b) {
    return ((b-a)/2)*func_integral(((b-a)/2) + ((b+a)/2));
}

double func_3 (double x)
{
    return pow(x,3);
}

void main()
{
    printf("A integral utilizando %f \n",(1.0f/sqrt(2*3.14))*integral_gaus_legendre(0,2));
    printf("integral correspodente para n = 2 : %f \n",func_2(-sqrt(3)/3) + func_2(sqrt(3)/3));
    printf("integral correspodente para n = 3 : %f \n",(5.0f/9)*(func_2(0.774596669) + func_2(-0.774596669)) + (8.0f/9)*func_2(0));
    printf("integral correspodente para n = 3 : %f\n",0.3478548451*func_2(-0.8611363115)+0.6521451548*func_2(-0.3399810435)
            + 0.6521451548*func_2(+0.3399810435) + 0.3478548451*func_2(+0.8611363115));

}
