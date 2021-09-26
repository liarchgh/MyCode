#include<cstdio>
int main()
{
    int s[8]={1,1},t,a,b,n;
    while(scanf("%d%d%d",&a,&b,&n),a||b||n)
    {
        t=2;int p=0;
        while(1)
        {
            s[t++]=(a*s[t-1]+b*s[t-2])%7;
            for(int i=1;i<t;++i)
            {
                if(s[t-1] == s[i] && s[t-2] == s[i-1])
                    {p=1;break;}
            }
            if(p) break;
        }
        printf("%d\n",s[(n-1)%t]);
    }
    return 0;
}
