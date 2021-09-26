#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,mod;

struct Matrix{
    int arr[4][4];
};

Matrix unit,init;

Matrix Mul(Matrix a,Matrix b){
    Matrix c;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            c.arr[i][j]=0;
            for(int k=0;k<4;k++)
                c.arr[i][j]=(c.arr[i][j]+a.arr[i][k]*b.arr[k][j]%mod)%mod;
            c.arr[i][j]%=mod;
        }
    return c;
}

Matrix Pow(Matrix a,Matrix b,int k){
    while(k){
        if(k&1){
            b=Mul(b,a);
        }
        a=Mul(a,a);
        k>>=1;
    }
    return b;
}

void Init(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            init.arr[i][j]=0;
            unit.arr[i][j]=0;
        }
    unit.arr[0][0]=9,   unit.arr[0][1]=6,   unit.arr[0][2]=4,   unit.arr[0][3]=2;

    init.arr[0][0]=1,   init.arr[0][1]=1,   init.arr[1][2]=1,   init.arr[2][0]=1,
    init.arr[2][3]=1,   init.arr[3][0]=1;
}

int main(){

    //freopen("input.txt","r",stdin);

    Init();
    while(~scanf("%d%d",&n,&mod)){
        if(n<=4){
            if(n==0)
                printf("0");
            else if(n==1)
                printf("%d\n",2%mod);
            else if(n==2)
                printf("%d\n",4%mod);
            else if(n==3)
                printf("%d\n",6%mod);
            else if(n==4)
                printf("%d\n",9%mod);
            continue;
        }
        Matrix res=Pow(init,unit,n-4);
        printf("%d\n",res.arr[0][0]%mod);
    }
    return 0;
}
