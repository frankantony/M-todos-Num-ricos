#include<stdio.h>
#include<stdlib.h>
#define Max 100

int main()
{

    float a[Max][Max],t,det=1;
    int i,j,k,N;

    printf("Digite a ordem da matriz : ");
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
            for (j = k+1; j < N; j++)
            {
                a[i][j] -= mult * a[k][j];
            }

        }
    }

    printf("Matriz resultante : \n");

    for(i = 0;i < N;i++) {
        for (j = 0;j < N;j++) {
            printf("%f ",a[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<N; i++)
    {
        det*=a[i][i];
    }

    printf("\nDeterminante = %.2f\n",det);

    return 0;
}


