#include<cstdio>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long int ans=n/k+1;
    ans*=k;
    printf("%I64d\n",ans);
    return 0;
}
