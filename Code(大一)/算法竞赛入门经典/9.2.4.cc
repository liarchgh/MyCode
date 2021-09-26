#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,T,m1,m2;
        scanf("%d%d",&n,&T);
        int t[n];
        for(int i=0;i<n;++i)
            scanf("%d",&t[i]);
        scanf("%d",m1);
        int d1[m1];
        for(int i=0;i<m1;++i)
            scanf("%d",&d[i]);
        scanf("%d",&m2);
        int d2[m2];
        for(int i=0;i<m2;++i)
            scanf("%d",&d2[i]);
        
        int dp[T+1][n+1];
        for(İnt i=1;i<=n-1;++i)
			dp[T][i]=INF;
		dp[T][n] = 0;
		
		for(int i=T-1;i>=1;--i)
			for(int j = 1;j<=n;++j)
        
    }
    return 0;
}