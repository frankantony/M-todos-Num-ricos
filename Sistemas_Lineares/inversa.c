#include<stdio.h>
#include<stdlib.h>
#define Max 10

float a[Max][Max+1],inversa[Max][Max+1];

void imprime (int n,float mat[][n])
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%f ",mat[i][j]);
        }
        printf("\n");
    }
}

void constroi_identidade (int n) {
    int i,j;
    for (i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            if (i == j) inversa[i][j] = 1;
            else inversa[i][j] = 0;
        }
    }

}

void operacao (int N) {

    float max,mult,t;
    int z,l,k;
    int h = 0,i,j;
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

}

int main()
{

    float t,det=1;
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
    constroi_identidade(N);

    operacao(N);



    for(i=0; i<N; i++)
    {
        det*=a[i][i];
    }

    printf("\nDeterminante = %.2f\n",det);
    if(det==0)
    {
        printf("\nMatriz não tem solução ou tem infinitas soluções .\n");
        exit(1);
    }

    printf("\nA matriz de Gauss-Jordan eh :\n\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%.5f ",a[i][j]);
        printf("\n");
    }

    system("pause");
    return 0;
}


