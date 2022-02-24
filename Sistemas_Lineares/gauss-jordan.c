#include<stdio.h>
#include<stdlib.h>
#define Max 100

int main()
{

    float a[Max][Max+1],t,det=1;
    int i,j,k,N;

    printf("Digite o numero de variaveis : ");
    scanf("%d",&N);
    printf("\nDigite os elementos da matriz :\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N+1; j++)
        {
            scanf("%f",&a[i][j]);
        }
    }

    float max,mult;
    int z,l;
    int h = 0;
    for (k = 0; k < N-1; k++)
    {
        max = abs(a[k][k]);
        l = k;
        /* procurar o maior da coluna onde esta o pivot */
        for (i = k+1; i < N; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                l = i;
            }
        }
        /* se o maior nao e o pivo... */
        if (l != k)
        {
            /* troca a linha onde esta o pivo atual pela linha onde esta o novo pivo */

            for (j = k; j <= N; j++)
            {
                float aux = a[k][j];
                a[k][j] = a[l][j];
                a[l][j] = aux;
            }
        }
        //eliminacao de Gauss.
        for (i = k+1; i < N; i++)
        {
            mult = a[i][k]/a[k][k];
            a[i][k] = 0;
            for (j = k+1; j <= N; j++)
            {
                a[i][j] -= mult * a[k][j];
            }

        }
    }
    //processo de gauss-jordan.
    for(i=0; i < N; i++)
    {
        for(j=0; i > j; j++)
        {
            t = a[j][i]/a[i][i];
            for(k=0; k<N+1; k++)
            {
                a[j][k]-=a[i][k]*t;
            }
        }
    }

    printf("\nA matriz de Gauss-Jordan eh :\n\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N+1; j++)
            printf("%.5f ",a[i][j]);
        printf("\n");
    }

    for(i=0; i<N; i++)
    {
        det *= a[i][i];
    }
    printf("Deteminante = %f\n", det);
    printf("\nSolucao :\n\n");
    for(i = 0; i < N; i++)
    {
        //printf("a[%d][%d]  / a[%d][%d] . \n",i,N,i,i);
        printf("x[%d] = %.3f\n",i+1,a[i][N]/a[i][i]);
    }

//    getch();
    system("pause");
    return 0;
}



