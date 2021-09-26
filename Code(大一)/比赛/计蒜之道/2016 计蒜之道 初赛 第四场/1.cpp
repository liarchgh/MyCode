#include<cstdio>
#include<cstring>
int n,sum[3]={0};
int suan(int x);
int main()
{
    int a;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a);
        sum[i%2]+=a;
        if(i==n-2) sum[2]=sum[(n-1)%2];
        if(i==n) sum[2]+=a;
    }
    int ans=sum[0];
    ans=ans>sum[1]?ans:sum[1];
    ans=ans>sum[2]?ans:sum[2];
    printf("%d\n",ans);
    return 0;
}
