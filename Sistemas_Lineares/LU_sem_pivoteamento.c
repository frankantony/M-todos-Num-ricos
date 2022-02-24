#include<stdio.h>
#include<stdlib.h>
#define Max 100

int main()
{

    float a[Max][Max],t,det=1;
    int i,j,k,N;

    printf("Digite o numero de variaveis : ");
    scanf("%d",&N);
    printf("\nDigite os elementos da matriz :\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%f",&a[i][j]);
        }
    }

    float max,mult;
    int z,l;
    int h = 0;
    for (k = 0; k < N-1; k++)
    {
        printf("Iteracao %d \n",k+1);
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
                printf("%.5f ",a[i][j]);
            printf("\n");
        }
        //eliminacao de Gauss.
        for (i = k+1; i < N; i++)
        {
            mult = a[i][k]/a[k][k];
            a[i][k] = mult;
            for (j = k+1; j <= N; j++)
            {
                a[i][j] -= mult * a[k][j];
            }
        }
    }

    printf("\nA matriz Resultante do processo LU sem pivoteamento eh :\n\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%.5f ",a[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}

