#include<cstdio>
int xiang(int a, int b, int m)
{
    if(b==1) return b%m;
    int x=xiang(a,b/2,m);
    x*=x;
    if(b&1) x*=a%m;
    return x%m;
}
int main()
{
    int a, b, n, m=0;
    scanf("%d",&n);
    int fei[n*n + 2];
    fei[0] = fei[1]=1;
    for(int i=2; i<n*n; ++i)
    {
        fei[i]=fei[i-1]+fei[i-2];
        for(int j=1; j<i; ++j)
        {
            if((fei[j] == fei[i]) && (fei[j-1] == fei[i-1])) {m=i+1;break;}
        }
        if(m) break;
    }
    scanf("%d%d",&a,&b);
    int ans=xiang(a,b,m);
    printf("%d\n",ans);
    return 0;
}
