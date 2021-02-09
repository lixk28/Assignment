#include <stdio.h>

const long long mod = 1e9 + 7;

typedef struct Matrix {
    int m[20][20];
}Matrix;

Matrix A;
Matrix E;
long long n,k;
long long X[20],Y[20];

Matrix Multiply(Matrix M, Matrix N)
{
    Matrix C;
    for(int i=0;i<k;++i)
        for(int j=0;j<k;++j)
            C.m[i][j] = 0;
        
    for(int i=0;i<k;++i)
        for(int j=0;j<k;++j)
            for(int m=0;m<k;++m)
                C.m[i][j] = C.m[i][j]%mod + ((M.m[i][m]%mod) * (N.m[m][j]%mod))%mod;
    return C;
}

Matrix Quick_Pow(Matrix M, long long n)
{
    Matrix ans = A;
    while(n)
    {
        if(n&1)
            ans = Multiply(ans,M);
        M = Multiply(M,M);
        n>>=1;
    }
    return ans;
}

int main()
{
    scanf("%d %d",&k,&n);

    for(int i=k-1;i>=0;i--)      
        scanf("%lld",&X[i]);

    for(int i=0;i<k;i++)        
        scanf("%lld",&A.m[0][i]);
    int flag=0;
    for(int i=1;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(j == flag)
                A.m[i][j]=1;
            else
                A.m[i][j]=0;
        }
        flag++;
    }

    A = Quick_Pow(A,n-k-1);

    for(int row=0;row<k;row++)
    {
        long long sum=0;
        for(int col=0;col<k;col++)
        {
            long long temp=0;
            temp = ((A.m[row][col]%mod) * (X[col]%mod)) % mod;
            sum = (sum + temp) % mod;
        }
        Y[row]=sum;
    }
    for(int i=0;i<k;i++)
        X[i]=Y[i];
    
    printf("%lld", X[0]);

    return 0;
}
    