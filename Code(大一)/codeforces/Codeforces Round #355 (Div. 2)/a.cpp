#include<cstdio>
int main()
{
    int n,k,t,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&t);
        if(t>k) ans+=2;
        else ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
