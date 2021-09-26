#include<cstring>
#include<cstdio>
char a[2][1010],s[1010];
int main()
{
    int t,len[2],c;
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        len[0]=len[1]=0;
        printf("Case %d:\n",i);
        memset(a,0,sizeof(a));
        scanf("%s",s);printf("%s + ",s);
        for(int j=strlen(s)-1;j>=0;--j)
        {
            a[0][len[0]++] = s[j]-'0';
        }
        scanf("%s",s);printf("%s = ",s);
        for(int j=strlen(s)-1;j>=0;--j)
        {
            a[1][len[1]++] = s[j]-'0';
        }
        c=0;int w=len[0]>len[1]?len[0]+5:len[1]+5;
        for(int j=0;j<w;++j)
        {
            if((a[0][j]+=(c+a[1][j]))>=10)
                {
                    c=a[0][j]/10;
                    a[0][j]%=10;
                }
        }
        int m=0;
        for(int j=w;j>=0;--j)
            if(m)
                printf("%d",a[0][j]);
            else if(a[0][j])
                {
                    m=1;printf("%d",a[0][j]);
                }
        if(!m) printf("0");
        putchar('\n');
        if(i<t) putchar('\n');
        }
    return 0;
}
