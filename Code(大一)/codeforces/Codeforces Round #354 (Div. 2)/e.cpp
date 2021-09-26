#include<cstdio>
int n,k;
char s[1000000+5][8];
int main()
{
    int sum=0;
    scanf("%d%d\n",&n,&k);
    for(int i=0;i<=n;++i)
        {gets(s[i]);
        if(s[i][0]=='?') sum++;
        }
    if(k)
    {
        if(sum)
        if(sum%2) printf("No\n");
        else printf("Yes\n");
        else
        {
            long long int a=0;
            for(int i=0;i<=n;++i)
            {
                int t;
                sprintf(s[i],"%d",t);

            a=a*k+t;
            }
            if(a) printf("No\n");
            else printf("Yes\n");
        }
    }
    else
    {
        if(s[n][0]!='0') printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
