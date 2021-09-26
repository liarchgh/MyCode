#include<cstdio>
int main()
{
    int t,n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=2*n*n-n+1;
        printf("%d\n",ans);
    }
    return 0;
}
