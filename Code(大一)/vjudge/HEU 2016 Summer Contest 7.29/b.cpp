#include<cstdio>

int n,a[5005],ans;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            for(int j=0;j<i;++j) if(a[j]>a[i]) ++ans;
        }
        int t=ans;
        for(int i=0;i<n-1;++i)
        {
            t=t-a[i]+n-a[i]-1;
            ans=ans>t?t:ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
