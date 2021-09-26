#include<cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int s[n+4][n+4],vis[n+4][n+4];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
            scanf("%d",&s[i][j]);
    }
    for(int i=n-2;i>=0;--i)
    {
        for(int j=0;j<=i;++j)
            s[i][j]+=max(s[i+1][j],s[i+1][j+1]);
    }
    printf("%d\n",s[0][0]);
    return 0;
}
