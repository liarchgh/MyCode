#include<cstring>
#include<cstdio>
int main()
{
    int t;
    char s[85];
    scanf("%d",&t);
    while(t--)
    {
        int ans = 0;
        scanf("\n\n%s",s);
        int len = strlen(s);
        for(int i=1;i<len;++i)
        {
            if(!(len%i))
            {
                int p=1;
                for(int j=0;j<i;++j)
                    {
                        for(int m=j+i;m<len;m+=i)
                            if(s[j]!=s[m]) {p=0;break;}
                        if(!p) break;
                    }
                if(p)
                    {ans = i;break;}
            }
        }
        if(!ans) ans = len;
        printf("%d\n",ans);
        if(t)
            printf("\n");
    }
    return 0;
}
