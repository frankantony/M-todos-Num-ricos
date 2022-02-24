#include<stdio.h>

double func(double x,double y)
{
    return 2*x-3*y*y;
}

void main()
{
    int i,j,mx = 2,my = 4;
    double a = -1,b = 1,c = 0,d = 2;

    int ci[] = {1,2,1},cj[] = {1,4,2,4,1};
    double x[mx],y[my];
    double hx = (b-a)/mx,hy = (d-c)/my;

    for (i = 0; i <= mx; i++)
    {
        x[i] = a + i*hx;
    }

    for (i = 0; i <= my; i++)
    {
        y[i] = c + i*hy;
    }

    double r = 0.0;
    for (i = 0; i <= mx; i++)
    {
        for(j = 0; j <= my; j++)
        {
            r += ci[i]*cj[j]*func(x[i],y[j]);
//            printf("%d  %f  %d  %d  %f  %d  %f\n",i,x[i],ci[i],j,y[j],cj[j],func(x[i],y[j]));
        }
//        printf("\n");
    }
    printf("%f \n",r*((1.0f/2)*hx*(1.0f/3)*hy));
}

