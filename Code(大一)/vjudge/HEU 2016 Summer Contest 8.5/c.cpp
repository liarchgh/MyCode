////ctrl+c
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#define MS(x,y) memset(x,y,sizeof(x))
//#define pi acos(-1.0)
//using namespace std;
//void fre() {freopen("t.txt","r",stdin);}
//typedef long long LL;
//typedef unsigned long long ULL;
//const int mod = 1e9 + 7;
//const int inf = (1<<63)-1;
//const double eps = 1e-8;
//int dp[11][11];
//void init()
//{   int i,j,k;
//    for(i = 0; i <=9; ++i) dp[1][i] = 1;
//    dp[1][4] = 0;
//    for(i = 2; i <= 6; ++i)
//    {   for(j = 0; j <= 9; ++j)
//        {   if(j==4)continue;
//            for(k = 0; k <= 9; ++k)
//            {   if(k!=4&&!(j==6&&k==2)) dp[i][j] += dp[i-1][k]; }
//
//        } } }
//int solve(int n)
//{   int i,j,k,digit[10];
//    int len = 0,ans = 0;
//    while(n!=0)
//    {   digit[++len] = n%10;
//        n/=10; }
//    digit[len+1] = 0;
//    for(i = len; i > 0; --i)
//    {   for(j = 0; j < digit[i]; ++j)
//        {   if(j==4 || (digit[i+1]==6 && j == 2))continue;
//            ans += dp[i][j]; }
//        if(digit[i]==4||(digit[i]==2&&digit[i+1]==6))break;  //£¡£¡£¡¹Ø¼ü²»ÄÜÍü
//    }
//    return ans; }
//int main()
//{   //fre();
//    init();
//    int l,r;
//    while(~scanf("%d%d",&l,&r))
//    {   if(l==0 && r==0) break;
//        printf("%d\n",solve(r+1)-solve(l)); }
//    return 0; }

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[8][2],digit[8];

int dfs(int len,bool state,bool fp)
{   if(!len)
        return 1;
    if(!fp && dp[len][state] != -1)
        return dp[len][state];
    int ret = 0 , fpmax = fp ? digit[len] : 9;
    for(int i=0; i<=fpmax; i++)
    {   if(i == 4 || state && i == 2)
            continue;
        ret += dfs(len-1,i == 6,fp && i == fpmax); }
    if(!fp)
        dp[len][state] = ret;
    return ret; }

int f(int n)
{   int len = 0;
    while(n)
    {   digit[++len] = n % 10;
        n /= 10; }
    return dfs(len,false,true); }

int main()
{   int a,b;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d%d",&a,&b),a||b)
    {   printf("%d\n",f(b)-f(a-1)); }
    return 0; }
