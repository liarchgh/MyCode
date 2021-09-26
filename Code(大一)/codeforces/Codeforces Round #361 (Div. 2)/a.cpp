#include<cstdio>
int main()
{
    int t,a[10]={0},ans;
    char c,pr[2][5]={"YES\n","NO\n"};
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        c=getchar()-'0';
        if(!a[c]) ++a[c];
    }
    int b[4]={!!(a[1]+a[2]+a[3]),!!(a[7]+a[9]),
                !!(a[1]+a[4]+a[7]),!!(a[3]+a[6]+a[9])};
    if(a[0])
    {
        if(b[0]) ans=0;
        else ans=1;
    }
    else
    {
        if(b[0]&&b[1]&&b[2]&&b[3]) ans=0;
        else ans=1;
    }
    getchar();
    puts(pr[ans]);
    return 0;
}
