//不太明白为什么两种写法一个AC一个WA
#include<cstdio>
#include<cstring>

int main()
{
    int n,m,a[35];
    while(scanf("%d%d",&n,&m),m||n)
    {
        memset(a,0,sizeof(a));
//        a[0]=1;
//        for(int i=1;i<n;++i)
//        {
//            for(int j=1;j<=m && i-j>=0;++j)
//            {
//                a[i]+=a[i-j];
//            }
//        }
        a[1]=1;
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(j+i<=n) a[i+j]+=a[i];
            }
        }
            printf("%d\n",a[n]);
    }
    return 0;
}
