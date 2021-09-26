#include<cstring>
#include<cstdio>

int n,f[105][105],d[105][105];
int dp(int i,int j);
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(d,-1,sizeof(d));
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<=i;++j)
                scanf("%d",&f[i][j]);
        }
        printf("%d\n",dp(0,0));
    }
    return 0;
}

int dp(int i,int j)
{
    int &a = d[i][j];
    if(a>=0) return a;
    if(i == n-1) return a = f[i][j];
    a = (dp(i+1,j) > dp(i+1,j+1)?dp(i+1,j) : dp(i+1,j+1)) + f[i][j];
    return a;
}
