#include<cstring>
#include<cstdio>
int jc[205][210]= {{0},{1}};
void cheng(int *a,int b,int *c)
{
    int wa;
    for(wa=209; !a[wa]; --wa) ;
    for(int i=0; i<=wa; ++i)
    {
        c[i]+=a[i]*b;
        if(c[i]>=1000)
        {
            c[i+1]+=c[i]/1000;
            c[i]%=1000;
            if(c[i+1]>=1000)
            {
                c[i+2]+=c[i+1]/1000;
                c[i+1]%=1000;
            }
        }
    }
}
void chu(int *a,int b)
{
    int wa;
    for(wa=209; !a[wa]; --wa) ;
    int d=0;
    for(int i=wa; i>=0; --i)
    {
        d+=a[i];
        a[i]=d/b;
        if(d%b)
            d=d%b*1000;
        else
            d=0;
    }
}
int main()
{
    memset(jc,0,sizeof(jc));
    jc[0][0]=0;jc[1][0]=1;
    int m,n,cas=1;
    for(int i=2; i<=202; ++i)
        cheng(jc[i-1],i,jc[i]);
    while(scanf("%d%d",&m,&n),m || n)
    {
        printf("Test #%d:\n",cas++);
        if(m<n) {printf("0\n");continue;}
        int ans[210]={0};
        cheng(jc[m+n],m+1-n,ans);
        chu(ans,m+1);
        int w;
        for(w=209; !ans[w]; --w) ;
        printf("%d",ans[w]);
        for(int i=w-1;i>=0;--i)
            printf("%03d",ans[i]);
        putchar('\n');
    }
    //putchar('\n');
    return 0;
}
