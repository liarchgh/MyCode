#include<cstdio>
#include<fstream>
const int wm=10000000;
int dui[1005][155]= {{0},{1},{2},{4},{7}};
void jia(int *a,int *b,int *c,int *ans)
{
    int la,lb,lc;
    for(la=152; a[la] && la>0; --la) ;
    for(lb=152; b[lb] && lb>0; --lb) ;
    for(lc=152; c[lc] && lc>0; --lc) ;
    int w;
    w=la>lb?la:lb;
    w=w>lc?w:lc;
    for(int i=0; i<=w; ++i)
    {
        ans[i]+=a[i]+b[i]+c[i];
        if(ans[i]>=wm)
                {ans[i+1]+=ans[i]/wm;
                ans[i]%=wm;}
    }
}
void suan()
{
    int a=7;
    for(int i=5; i<1005; ++i)
    {
        jia(dui[i-1],dui[i-2],dui[i-4],dui[i]);
        //printf("%I64d\n",dui[i]);
    }
}
int main()
{
    int n;
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    suan();
    for(n=1;n<=1000;++n)
    {
        int la;
        for(la=151; !dui[n][la] && la>0; --la) ;
        printf("%d",dui[n][la]);
        for(int i=la-1;i>=0;--i)
            printf("%06d",dui[n][i]);
        printf("\n");
    }
    return 0;
}

/*
#include <stdio.h>
int a[1001][101]={0};
void add(int n)
{
    int k=0,j;
    for(j = 1;j<101;j++)
    {
        k += a[n-1][j] + a[n-2][j] + a[n-4][j];
        a[n][j] = k%10000;
        k = k/10000;
       // printf("%d",k);
    }
    while(k)
    {
        a[n][j++] = k%10000;
        k = k/10000;
    }

}
int main()
{
    a[1][1] = 1;
    a[2][1] = 2;
    a[3][1] = 4;
    a[4][1] = 7;
    int n,i;
    for(i = 5;i<1001;i++)
    {
        add(i);
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(i = 100;i > 0;i--)
        {
            if(a[n][i]!=0)break;
        }
        printf("%d",a[n][i]);
        for(i=i-1;i>0;i--)
        {
            printf("%04d",a[n][i]);
        }
        printf("\n");
    }
    return 0;
}
*/
