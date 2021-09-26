#include <cstdio>

int main()
{   int n,s,a[45],d[45][10005];
    while(scanf("%d",&n),n)
    {   scanf("%d",&s);
        for(int i=1; i<=n<<1; ++i)
        {   scanf("%d",&a[i]); }
        for(int i=1; i<=2*n; ++i)
        {   d[i][0]=1;
            //printf("%d %d %d\n",0,i,d[i][0]);
        }
        for(int i=1; i<=s; ++i)
        {   for(int j=1; j<=n<<1; ++j)
            {   int p=0;
                int a1=(j+1)%(2*n);
                if(!a1) a1=2*n;
                for(int k=1; k<=a[j] && k<=i; ++k)
                {   //printf("%d %d %d %d\n",j,a1,i-k,d[a1][i-k]);
                    if(!d[a1][i-k])
                    {   p=1;
                        break; } }
                d[j][i]=p;
                //printf("%d %d %d\n",j,i,p);
                } }
        printf("%d\n",d[1][s]); }
    return 0; }
//
//dp[i][j]表示轮到第i个人的时候还剩j颗石子
//j为0的时候，dp[i][j]=1
//#include<iostream>
//#include<cstdlib>
//#include<stdio.h>
//#include<memory.h>
//using namespace std;
//int dp[22][8200];
//int a[22];
//int n,s;
//int dfs(int x,int S)
//{
//    if(dp[x][S]!=-1) return dp[x][S];
//    for(int i=1;i<=a[x];i++)
//    {
//        int t=S-i;
//        if(t<0) break;
//        int yy;
//        if(x+1>=2*n) yy=0;
//        else yy=x+1;
//        if(dfs(yy,t)==0) return dp[x][S]=1;
//    }
//    return dp[x][S]=0;
//}
//int main()
//{
//   while(scanf("%d",&n)&&n)
//   {
//       scanf("%d",&s);
//       for(int i=0;i<2*n;i++)
//       {
//           scanf("%d",&a[i]);
//       }
//       memset(dp,-1,sizeof(dp));
//       for(int i=0;i<2*n;i++)
//       dp[i][0]=1;
//       int ans=dfs(0,s);
//       if(ans==0) puts("0");
//       else puts("1");
//   }
//}
//
