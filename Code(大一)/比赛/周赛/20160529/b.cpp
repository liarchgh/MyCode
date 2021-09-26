#include<cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int a[15][15]={0};
    scanf("%d",&a[0][0]);
    a[0][0]*=1<<n;
    int ans=0;
    //printf("%d\n",a[0][0]);
    if(a[0][0]>=1<<n) ++ans;
    for(int i=1;i<n;++i)
        for(int j=0;j<=i;++j)
            {
                if(j>0 && a[i-1][j-1]>=(1<<n))
                a[i][j] = (a[i-1][j-1]-(1<<n))/2;
                else a[i][j]=0;
                if(j<i && a[i-1][j]>=(1<<n))
                    a[i][j]+=((a[i-1][j]-(1<<n))/2);
                if(a[i][j]>=(1<<n)) ++ans;//printf("%d  %d  %d\n",i,j,a[i][j]);
            }
            printf("%d\n",ans);
    return 0;
}
