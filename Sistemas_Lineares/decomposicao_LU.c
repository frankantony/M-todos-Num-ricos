#include<stdio.h>
#define Max 20

int main()
{
    float A[Max][Max]= {0},L[Max][Max]= {0}, U[Max][Max];


    float B[Max]= {0}, X[Max]= {0};
    int i,j,k,n;

    printf("Entre com a ordem da matriz quadrada : ");
    scanf("%d",&n);
    printf("\nEntre com os elementos da matriz : \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("A[%d][%d] = ", i+1,j+1);
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nEntre com os termos constantes : \n");
    for(i=0; i<n; i++)
    {
        printf("B[%d] = ",i+1);
        scanf("%f",&B[i]);
    }
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
//            printf("i = %d , j = %d  \n",i,j);
            if(i<=j)
            {
                U[i][j]=A[i][j];
//                printf("Entrou aqui!!");
                for(k=0; k < i; k++)
                {
                    U[i][j]-=L[i][k]*U[k][j];
//                    printf("U[%d][%d] = L[%d][%d]*U[%d][%d] \n",i+1,j+1,i+1,k+1,k+1,j+1);
                }
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=L[i][k]*U[k][j];
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }
    printf("\n[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }
    printf("\n\n[U]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",U[i][j]);
        printf("\n");
    }
    for(i=n-1; i>=0; i--)
    {
//        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j] ;
        }
        X[i]/=U[i][i];
    }
    printf("\n\n[X]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",X[i]);
    }
    return 0;
}
