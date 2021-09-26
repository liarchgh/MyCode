#include<cstdio>
__int64 ans[55]={1,1};
void fun()
{
    for(int i=2;i<=50;++i)
        ans[i]=ans[i-1]+ans[i-2];
}
int main()
{
    int t,a,b;
    scanf("%d",&t);
    fun();
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%I64d\n",ans[b-a]);
    }
    return 0;
}
