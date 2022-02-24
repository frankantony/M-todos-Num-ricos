    #include<stdio.h>
    #include<math.h>
    #include<windows.h>

    float* cofator (float *mat,int n,int linha,int coluna) {
        float* h = malloc ((n-1)*(n-1)*sizeof(float));
        int p = 0,i,j;
        for(i = 0;i < n;i++)
            for(j = 0;j < n;j++)
            if(i != linha && j != coluna) h[p++] = mat[i*n+j];
        return h;
    }

    float determinante (float* mat,int n) {
        if(n == 1) return mat[0];
        else {
            float soma = 0;
            int i;
            for(i = 0;i < n;i++){
                float *cof = cofator(mat,n,0,i);
                soma += pow(-1,i)*mat[0*n+i]*determinante(cof,n-1);
            }
            return soma;
        }
    }

   void main() {
       int i,n,j,k,e = 0,r;

       printf("Digite a ordem da Matriz : \n");
       scanf("%d",&n);

       float mat[n*n],d[n],z[n][n];

       for(i = 0;i < n;i++)
        for(j = 0;j < n;j++)
            scanf("%f",&mat[i*n+j]);
            for(i = 0;i < n;i++){
                for(j = 0;j < n;j++){
                    float *p = cofator(mat,n,i,j);
                    z[i][j]  = pow(-1,(i+j))*determinante(p,(n-1));
                }
            }
            float det = determinante(mat,n);
            if (det == 0) {
                printf("A matriz nao possui inversa\n");
                exit(0);
            }
            printf("A matriz inversa : \n\n");
            for(i = 0;i < n;i++){
                for(j = 0;j < n;j++){
                    printf("%f ",(1.0f/determinante(mat,n)*z[j][i]));
                }
                printf("\n");
            }

   }
